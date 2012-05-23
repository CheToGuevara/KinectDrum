#pragma once

// OpenNI headers
#include <XnOpenNI.h>
// NITE headers
#include <XnVSessionManager.h>
#include <XnVWaveDetector.h>

#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

/**
 * \class TrackUser
 *
 * \ingroup Kinect
 * 
 *
 * \brief Clase para hacer Traking de personas
 *
 * Esta clase nos proporciona lo necesario para poder trackear una 
 * persona, y da la posibilidad de pintarla con el dispositivo 
 *
 *
 * 
 * \author Aaron Sujar
 *
 * \version 0.5
 *
 */





///
///Necesita Cabeceras de los callbacks disponibles
///



///
///Archivo XML de configuración
///
#define SAMPLE_XML_FILE "./SamplesConfig.xml"

class TrackUser{



public:
	///
	///Constructor 
	///
	TrackUser();
	TrackUser(xn::Context context);


	///
	///Destructor
	///
	~TrackUser();

private:
	///
	///Contexto
	///
	xn::Context context;

	///
	///Atributo que contiene el user
	///
	xn::UserGenerator UserGenerator;
	///
	///Atributo que contiene el depth
	///
	xn::DepthGenerator DepthGenerator;
	///
	///Variable para checkear el status
	///
	XnStatus rc;
	
	
	

public:
	///
	///Metodos
	///

	///
	///Obligatorios
	///

	///
	///Registra los eventos de calibracion de User
	///
	int Registrar_Eventos();

	///
	///Metodo que incluye el context.WaitUpdate
	///Para incluir en el bucle principal
	///
	int Main_Loop();

	///
	///Metodo para conseguir el context, por si a otro nodo le hace falta(PE: ImageSource)
	///
	xn::Context GetContext();
	///
	///Metodo para conseguir el usergenerator, por si a otro nodo le hace falta(PE: Callbacks)
	///
	xn::UserGenerator GetUserGenerator();

	///
	///Metodo para si queremos pintar Skeleton
	///
	void DrawSkeleton(IplImage* image);

private:


	///
	///Metodo para pintar las lineas de Skeleton
	///
	void DrawLimb(XnUserID player, XnSkeletonJoint eJoint1, XnSkeletonJoint eJoint2, IplImage* image);

	void Send_Point(XnSkeletonJoint eJoint1,XnSkeletonJoint eJoint2,XnUserID player);
	

};