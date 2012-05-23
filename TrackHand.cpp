#include "TrackHand.h"

/**
 *	@file	TrackHand.cpp
 *	@date 
 *	@author	Aaron Sújar - asujar at vartficial dot com
 *	@brief	Module that get tracking hand
 */

TrackHand::TrackHand(){
	///
	///Metodo Constructor
	///


	// Create context
	rc = context.InitFromXmlFile(SAMPLE_XML_FILE);
	if (rc != XN_STATUS_OK){
			printf("Couldn't initialize: %s\n", xnGetStatusString(rc));
			context.Shutdown();
			getchar();
			exit(-1);

	}

	pSessionManager = new XnVSessionManager();
	//Inicializo el control de session: context, gesto para empezar la session, gesto reconocido por quickrefocus
	//Disponibles: "Wave" "Click" "RaiseHand"
	rc = pSessionManager->Initialize(&context, "Click", "RaiseHand");

	if (rc != XN_STATUS_OK){
			printf("Session Manager couldn't initialize: %s\n", xnGetStatusString(rc));
			context.Shutdown();
			delete pSessionManager;
			getchar();
			exit(-1);
			
	}

	pSessionManager->AddListener(&wc);//Añadimos el controlador de eventos de gestos de la session
}

TrackHand::TrackHand(xn::Context g_Context){
	///
	///Metodo Constructor
	///
	
	///
	///Nos pasan el context
	///
	context=g_Context;
	rc=XN_STATUS_OK;

	pSessionManager = new XnVSessionManager();
	//Inicializo el control de session: context, gesto para empezar la session, gesto reconocido por quickrefocus
	//Disponibles: "Wave" "Click" "RaiseHand"
	rc = pSessionManager->Initialize(&context, "Click", "RaiseHand");

	if (rc != XN_STATUS_OK){
			printf("Session Manager couldn't initialize: %s\n", xnGetStatusString(rc));
			context.Shutdown();
			delete pSessionManager;
			getchar();
			exit(-1);
	}

	pSessionManager->AddListener(&wc);//Añadimos el controlador de eventos de la session
}

xn::Context TrackHand::GetContext(){


	return context;

}

int TrackHand::Registrar_Eventos(){
	///
	///Hay que registrar los eventos necesarios para el control de la session
	///
	if (rc != XN_STATUS_OK){
			printf("Can't registrer events, object not initialize correctly: %s\n", xnGetStatusString(rc));
			return -1;
	}	


	//Registro los eventos de session, definidos en Callbacks.h
	if(Registry_Events(pSessionManager)){
		printf("Events not registred");
		return -1;
	}

	// Initialization done. Start generating
	context.StartGeneratingAll();
	return 0;
}

int TrackHand::Registrar_Wave(){
	///
	///Poisibilidad de registrar el evento de wave
	///
	if (rc != XN_STATUS_OK){
			printf("Can't registrer wave event, object not initialize correctly: %s\n", xnGetStatusString(rc));
			return -1;
	}		
	wc.RegisterWave(NULL, OnWaveCB); // OnWaveCB definido en Callbacks.h
	

	return 0;
}
int TrackHand::Registrar_PointUpdate(){
	///
	///Poisibilidad de registrar el evento que da puntos actuales
	///
	if (rc != XN_STATUS_OK){
			printf("Can't registrer PointUpdate event, object not initialize correctly: %s\n", xnGetStatusString(rc));
			return -1;
	}	
	wc.RegisterPointUpdate(NULL, OnPointUpdate);
	
	return 0;

}
int TrackHand::Registrar_QuickRefocus(long timeout){
	///
	///Poisibilidad de registrar el evento de quickrefocus
	///
	if (rc != XN_STATUS_OK){
			printf("Can't registrer QuickRefocus event, object not initialize correctly: %s\n", xnGetStatusString(rc));
			return -1;
	}

	XnVPointControl* pPointControl=new XnVPointControl;
	//Registramos el evento NoHands definido en Callbacks.h
	pPointControl->RegisterNoPoints (NULL, NoHands);
	pSessionManager->AddListener(pPointControl);


	//Change the timeout for the quick refocus gesture. Default is 15000 (15 seconds)
	pSessionManager->SetQuickRefocusTimeout(timeout);


	return 0;
}
int TrackHand::Main_Loop(){
	///
	///Bucle para el funcionamiento
	///Contiene un WaitUpdate
	///
	if (rc != XN_STATUS_OK){
			printf("Can't run main loop, object not initialize correctly: %s\n", xnGetStatusString(rc));
			return -1;
	}	
	
		//Espero y actualizo
		rc=context.WaitAnyUpdateAll();
	if (rc != XN_STATUS_OK){
			printf("Can't run main loop, object not initialize correctly: %s\n", xnGetStatusString(rc));
			return -1;
	}	
		
		pSessionManager->Update(&context);
		return 0;
}



TrackHand::~TrackHand(){
	//Metodo Destructor
	//wc.~XnVWaveDetector;
	if(rc==XN_STATUS_OK){

		delete pSessionManager;
		context.Shutdown();
	}
}