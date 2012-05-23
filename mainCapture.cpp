//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
// General headers
#include <stdio.h>
#include <Windows.h>

#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

#include <Inventor/nodes/SoPerspectiveCamera.h>
#include <Inventor/nodes/SoDirectionalLight.h>
#include <Inventor/nodes/SoFrustumCamera.h> 
#include <Inventor/nodes/SoSpotLight.h> 
#include <Inventor/nodes/SoUnits.h> 
#include <Inventor/Win/viewers/SoWinExaminerViewer.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoFile.h>
#include <Inventor/nodes/SoEventCallBack.h>
#include <Inventor/events/SoKeyboardEvent.h>
#include <Inventor/events/SoEvent.h>
#include <Inventor/Win/SoWin.h>
#include <Inventor/sensors/SoTimerSensor.h>
#include <Inventor/actions/SoGLRenderAction.h> 
#include <Inventor/engines/SoCalculator.h>

#include "SoViewportRegion.h"


#include "Sequencer.h"
#include "TrackUser.h"
#include "ImageSource.h"
#include "DrawCoin.h"








/** @mainpage Kinect Windows
	*   @par Description:
	*   - Dispositivo profundidad
	*   
	*
	*   @par  more information:
	*
	*   Authors Aaron Sújar y Fco Roman Gonzalez 
		
	*	\defgroup Kinect Tracker's Class
	*	\brief Clases que controlan el dispositivo de profundidad
	*	\defgroup OpenInventor OpenInventor's Class
	*	\brief Clases que controlan la escena
	*	\defgroup Other Others Class
	*   \brief 
	*
*/




DWORD WINAPI Thread( LPVOID lpParam ){
	ImageSource * myImgSrc= new ImageSource();
	TrackUser * myTrack	= new TrackUser(myImgSrc->GetContext());
	
	Sequencer *S=new Sequencer(25);

	cvNamedWindow("Image", CV_WINDOW_AUTOSIZE);

	if(myTrack->Registrar_Eventos()){
		printf("no ha podido registrar los eventos");
	}

	while(true){
	//Bucle principal
		

		if(myTrack->Main_Loop()){
			printf("WaitUpdate no se ha podido realizar");
			getchar();
			exit(-1);
		}
		
		S->Sequence();
		IplImage * RGB=myImgSrc->getRGBImage();
		myTrack->DrawSkeleton(RGB);
	
		if(RGB!=NULL){
			cvShowImage("Image", RGB);
		}
		
		cvReleaseImage(&RGB);
	
		
		if( (cvWaitKey(1) & 255) == 27) {
			break;
		}
		
	}
	cvDestroyWindow("Image");

	delete myTrack;
	delete myImgSrc;
	delete S;
	

	return 0;
}




//Constantes
#define FPS 1.0f/25.0f  //Frames por segundo
#define W_SCREEN 0.405f
#define H_SCREEN 0.235f
#define ADJUST 1.0f


///Variables globales
bool modo=false;
SoFrustumCamera * cam2;
SoTransform * cabeza;
SoRotation * rotacion;

///Esta función es llamada para realizar cada renderizado
void renderCallback (void *userData, SoSensor * sensor)
{

	if(modo){
		///Traemos la posicion de la cabeza.
		SbVec3f posicion=cabeza->translation.getValue();
		float x,y,z;
		float ndis;
		posicion.getValue(x,y,z);
		ndis = cam2->nearDistance.getValue();
		

		///Convertimos de milimetros con corrección a metros sin corrección
		/*x += ADJUST;
		y += ADJUST;
		z += ADJUST;*/

		///Ajustamos la camara
		cam2->left = ( (-W_SCREEN - x ) / z ) * ndis;
		cam2->right = ( (W_SCREEN - x ) / z ) * ndis;
		cam2->top = ( (H_SCREEN - y ) / z ) * ndis;
		cam2->bottom = ( (-H_SCREEN - y ) / z ) * ndis;
		

	}

	//WINDOWS
	SoWinExaminerViewer * viewer=(SoWinExaminerViewer *) userData;
	viewer->render();
}

void
handle_keyboard(void *userData, SoEventCallback *eventCB)
{// EVENTOS DE TECLADO

	SoFrustumCamera *camara = (SoFrustumCamera *) userData;
	const SoEvent *event = eventCB->getEvent();
	// Check for the Up and Down arrow keys being pressed.
	if (SO_KEY_PRESS_EVENT(event, M)) {

		if ( modo ){
			modo=false;
			cam2->orientation.connectFrom(&rotacion->rotation);
			cam2->top=0.5f;cam2->bottom=-0.5f;cam2->left=-0.5f;cam2->right=0.5f;
			
		}else{
			modo=true;
			cam2->orientation.disconnect();
			cam2->orientation.setValue(SbVec3f(0,0,1),0);
			
		}


	}
	eventCB->setHandled();
}




int main(int argc, char** argv)
{

	// init Inventor
	HWND w = SoWin::init(argv[0]);
	SoWinExaminerViewer * v = new SoWinExaminerViewer(w);
	
	//Preguntar donde iria
	SoViewportRegion::initClass();

	// Iniciamos la escena
	SoSeparator *root = new SoSeparator;
	root->ref();
	root->addChild(new SoUnits);


	

	//De este separador colgará la escena que se carga de 
	//fichero, así como las cámaras y luces encargadas de 
	//mostrarla
	SoSeparator *ojo_izq= new SoSeparator;
	
	
    //Partimos la pantalla
    SoViewportRegion *vp1 = new SoViewportRegion();
    vp1->height=0.4f;
    vp1->width=0.2f;
	vp1->y_pos=0.6f;
    vp1->x_pos=0.0f;
    vp1->onTop=TRUE; 
    
    ojo_izq->addChild(vp1);
    
	//Introducimos una nueva cámara. Esta cámara pintará
	//los draggers siempre en la misma posición 
	SoFrustumCamera *cam = new SoFrustumCamera();	
	ojo_izq->addChild(cam);

	



	SoSeparator * escena = new SoSeparator;
 

	SoSeparator *habitacion=new SoSeparator;
	SoTransform * centrar = new SoTransform;

	//centrar->translation.setValue(60.0f,-60.0f,60.0f);
	centrar->translation.setValue(0,0,-3.0f);
	centrar->scaleFactor.setValue(0.001f,0.001f,0.001f);
	habitacion->addChild(centrar);
	//Desplazamiento de la pantalla 

	 // model
	  SoFile *model = new SoFile;
	  if (argc > 1) model->name.setValue(argv[1]);
	  else model->name.setValue("drums.wrl");
	  habitacion->addChild(model);

	escena->addChild(habitacion);

	SoSeparator * esqueleto= new SoSeparator;

	DrawCoin::CrearEsqueleto(esqueleto);
	

	escena->addChild(esqueleto);

	ojo_izq->addChild (escena);
	//Colocamos la camara de modo que pueda ver toda la escena
	cam->viewAll(escena,vp1->getViewportRegion());

	//De este separador colgará la escena que se carga de 
	//fichero, así como las cámaras y luces encargadas de 
	//mostrarla
	SoSeparator *ojo_der= new SoSeparator;
	root->addChild (ojo_der);
		root->addChild (ojo_izq);
    //Partimos la pantalla
    SoViewportRegion *vp2 = new SoViewportRegion();
    vp2->height=1.0f;
    vp2->width=1.0f;
    vp2->x_pos=0.0f;
    vp2->onTop=FALSE; 
    
    ojo_der->addChild(vp2);
    
	//Introducimos una nueva cámara. Esta cámara pintará
	//los draggers siempre en la misma posición 
	cam2 = new SoFrustumCamera();	

	//cam2->farDistance = 3.f;

	ojo_der->addChild(cam2);


	cabeza=DrawCoin::Get_Cabeza_Pos();
	rotacion=DrawCoin::Get_Cabeza_Rot();
	cam2->position.connectFrom(&cabeza->translation);
	
	ojo_der->addChild (escena);

	//Colocamos la camara de modo que pueda ver toda la escena
	cam2->viewAll(escena,vp2->getViewportRegion());
	cam2->viewportMapping = SoCamera::LEAVE_ALONE;
	cam2->position.setValue(0.0f,0.0f,0.0f);
	
	int Data_Of_Thread = 1;
    HANDLE Handle_Of_Thread;

	Handle_Of_Thread = CreateThread( NULL, 0, Thread, &Data_Of_Thread, 0, NULL);  
    if ( Handle_Of_Thread == NULL) ExitProcess(Data_Of_Thread);



	//Creamos un sensor encargado del render
	SoTimerSensor*   rendertimer = new SoTimerSensor(renderCallback,(void *)v);
	rendertimer->setInterval(FPS); 
	rendertimer->schedule();


	SoEventCallback *eventCB = new SoEventCallback;
	eventCB->addEventCallback(SoKeyboardEvent::getClassTypeId(),handle_keyboard, cam2);
	root->addChild(eventCB);
	
	
	v->setBackgroundColor(SbColor(0.0f, 0.2f, 0.3f));
	v->setFeedbackVisibility(TRUE);
	v->setSceneGraph(root);
	//v->setViewing(FALSE);
	v->setTitle("Kinect Tracking");
	v->setAutoRedraw(FALSE);
	///v->setDecoration(FALSE);

	
	SoWin::show(w);
	SoWin::mainLoop();


	root->unref();
	delete v;
	
	
	
	
	return 0;
}