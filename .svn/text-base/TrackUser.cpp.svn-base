#include "TrackUser.h"
#include "DrawCoin.h"
#include "Ogre.h"

#include <Inventor/nodes/SoRotation.h>

#include "Callbacks.h"
/**
 *	@file	TrackUser.cpp
 *	@date 
 *	@author	Aaron Sújar - asujar at vartficial dot com
 *	@brief	Module to get tracking of user
 */


TrackUser::TrackUser(){
	///
	///Metodo Constructor
	///
	

	// Create context
	rc = context.InitFromXmlFile(SAMPLE_XML_FILE);
	if (rc != XN_STATUS_OK){
			printf("Couldn't initialize: %s\n", xnGetStatusString(rc));
			context.Shutdown();
			//falta exit

	}

	//Buscamos el nodo que usaremos para controlar los user
	rc = context.FindExistingNode(XN_NODE_TYPE_USER, UserGenerator);
	if (rc !=  XN_STATUS_OK){
			printf("Couldn't find user generator: %s\n", xnGetStatusString(rc));
			context.Shutdown();
			//falta exit

	}

	//Buscamos el nodo depth, para calcular la posicion de los puntos
	rc = context.FindExistingNode(XN_NODE_TYPE_DEPTH, DepthGenerator);
	if (rc !=  XN_STATUS_OK){
			printf("Couldn't find depth generator: %s\n", xnGetStatusString(rc));
			context.Shutdown();
			//falta exit
	
	}

	

	
}

TrackUser::TrackUser(xn::Context context2){
	///
	///Metodo Constructor
	///Este le pasan el context, por si estuviera  inicializado en otra clase
	///
	context=context2;
	rc = XN_STATUS_OK;

	rc = context.FindExistingNode(XN_NODE_TYPE_USER, UserGenerator);
	if (rc !=  XN_STATUS_OK){
			printf("Couldn't find user generator: %s\n", xnGetStatusString(rc));
			context.Shutdown();
			//falta exit

	}
	rc = context.FindExistingNode(XN_NODE_TYPE_DEPTH, DepthGenerator);
	if (rc !=  XN_STATUS_OK){
			printf("Couldn't find depth generator: %s\n", xnGetStatusString(rc));
			context.Shutdown();
			//falta exit

	}

}

xn::Context TrackUser::GetContext(){
	///
	///Devuelve el context del objecto
	///

	return context;

}
xn::UserGenerator TrackUser::GetUserGenerator(){
	///
	///Devuelve el UserGenerator
	///

	return UserGenerator;

}

void TrackUser::DrawSkeleton(IplImage* image){
	///
	///Pinta los skeletos disponibles, ninguno si no hay
	///

	XnUserID aUsers[15];
	XnUInt16 nUsers = 15;
	UserGenerator.GetUsers(aUsers, nUsers);
	
	for (int i = 0; i < 1; ++i)
	{

		if (UserGenerator.GetSkeletonCap().IsTracking(aUsers[i]))
		{
			
			DrawLimb(aUsers[i], XN_SKEL_HEAD, XN_SKEL_NECK,image);
			DrawLimb(aUsers[i], XN_SKEL_NECK, XN_SKEL_LEFT_SHOULDER,image);
			DrawLimb(aUsers[i], XN_SKEL_LEFT_SHOULDER, XN_SKEL_LEFT_ELBOW,image);
			DrawLimb(aUsers[i], XN_SKEL_LEFT_ELBOW, XN_SKEL_LEFT_HAND,image);
			DrawLimb(aUsers[i], XN_SKEL_NECK, XN_SKEL_RIGHT_SHOULDER,image);
			DrawLimb(aUsers[i], XN_SKEL_RIGHT_SHOULDER, XN_SKEL_RIGHT_ELBOW,image);
			DrawLimb(aUsers[i], XN_SKEL_RIGHT_ELBOW, XN_SKEL_RIGHT_HAND,image);
			DrawLimb(aUsers[i], XN_SKEL_LEFT_SHOULDER, XN_SKEL_TORSO,image);
			DrawLimb(aUsers[i], XN_SKEL_RIGHT_SHOULDER, XN_SKEL_TORSO,image);
			DrawLimb(aUsers[i], XN_SKEL_TORSO, XN_SKEL_LEFT_HIP,image);
			DrawLimb(aUsers[i], XN_SKEL_TORSO, XN_SKEL_RIGHT_HIP,image);
			DrawLimb(aUsers[i], XN_SKEL_LEFT_HIP, XN_SKEL_RIGHT_HIP,image);
			DrawLimb(aUsers[i], XN_SKEL_LEFT_HIP, XN_SKEL_LEFT_KNEE,image);
			DrawLimb(aUsers[i], XN_SKEL_LEFT_KNEE, XN_SKEL_LEFT_FOOT,image);
			DrawLimb(aUsers[i], XN_SKEL_RIGHT_HIP, XN_SKEL_RIGHT_KNEE,image);
			DrawLimb(aUsers[i], XN_SKEL_RIGHT_KNEE, XN_SKEL_RIGHT_FOOT,image);
			DrawLimb(aUsers[i], XN_SKEL_LEFT_KNEE, XN_SKEL_LEFT_FOOT,image);
			
			Send_Point(XN_SKEL_HEAD,XN_SKEL_HEAD,aUsers[i]);
			Send_Point(XN_SKEL_NECK,XN_SKEL_HEAD,aUsers[i]);
			Send_Point(XN_SKEL_LEFT_SHOULDER,XN_SKEL_HEAD,aUsers[i]);
			Send_Point(XN_SKEL_LEFT_ELBOW,XN_SKEL_HEAD,aUsers[i]);
			Send_Point(XN_SKEL_RIGHT_SHOULDER,XN_SKEL_HEAD,aUsers[i]);
			Send_Point(XN_SKEL_RIGHT_ELBOW,XN_SKEL_HEAD,aUsers[i]);
			Send_Point(XN_SKEL_TORSO, XN_SKEL_HEAD,aUsers[i]);
			Send_Point(XN_SKEL_LEFT_HIP,XN_SKEL_HEAD,aUsers[i]);
			Send_Point(XN_SKEL_LEFT_KNEE,XN_SKEL_HEAD,aUsers[i]);
			Send_Point(XN_SKEL_RIGHT_HIP,XN_SKEL_HEAD,aUsers[i]);
			Send_Point(XN_SKEL_RIGHT_KNEE,XN_SKEL_HEAD,aUsers[i]);
			Send_Point(XN_SKEL_LEFT_HAND,XN_SKEL_HEAD,aUsers[i]);
			Send_Point(XN_SKEL_LEFT_FOOT,XN_SKEL_HEAD,aUsers[i]);
			Send_Point(XN_SKEL_RIGHT_HAND,XN_SKEL_HEAD,aUsers[i]);
			Send_Point(XN_SKEL_RIGHT_FOOT,XN_SKEL_HEAD,aUsers[i]);

			


		}
	}

}





void TrackUser::DrawLimb(XnUserID player, XnSkeletonJoint eJoint1, XnSkeletonJoint eJoint2, IplImage* image)
{
	///
	///Pinta lineas, si la confianza es buena, sino, no los pinta
	///
	if (!UserGenerator.GetSkeletonCap().IsTracking(player))
	{
		printf("not tracked!\n");
		return;
	}



	XnSkeletonJointPosition joint1, joint2;
	UserGenerator.GetSkeletonCap().GetSkeletonJointPosition(player, eJoint1, joint1);
	UserGenerator.GetSkeletonCap().GetSkeletonJointPosition(player, eJoint2, joint2);

	if (joint1.fConfidence < 0.5 || joint2.fConfidence < 0.5)
	{
		return;
	}

	XnPoint3D pt[2];
	pt[0] = joint1.position;
	pt[1] = joint2.position;

	///
	///Hay que convertir las coordenadas reales a proyectivas
	///Ademas añadirle un coeficiente de correción
	///
	
	double corr0 = pt[0].Z * 0.014; 
	double corr1 = pt[1].Z * 0.014; 
	DepthGenerator.ConvertRealWorldToProjective(2,pt,pt);
	
	cvLine(image, cvPointFrom32f( cvPoint2D32f(pt[0].X,pt[0].Y+corr0)),cvPointFrom32f( cvPoint2D32f(pt[1].X,pt[1].Y+corr1)) , CV_RGB(255, 160, 0 ),4);

}

void TrackUser::Send_Point(XnSkeletonJoint eJoint,XnSkeletonJoint eJoint2,XnUserID player){

	XnSkeletonJointOrientation jointOri;
	XnSkeletonJointPosition joint[2];
	UserGenerator.GetSkeletonCap().GetSkeletonJointPosition(player, eJoint, joint[0]);
	UserGenerator.GetSkeletonCap().GetSkeletonJointPosition(player, eJoint2, joint[1]);
	

	if (joint[1].fConfidence < 0.5)
	{
		return;
	}
	SoRotation *rot=new SoRotation;
	if ( eJoint != XN_SKEL_HEAD ){

		joint[0].position.X -=joint[1].position.X; 
		joint[0].position.Y -=joint[1].position.Y;
		joint[0].position.Z -=joint[1].position.Z;

		

		DrawCoin::BuscarNodo(eJoint,joint[0].position);

	}else{
		UserGenerator.GetSkeletonCap().GetSkeletonJointOrientation(player,eJoint, jointOri);

		Ogre::Matrix3 matOri(jointOri.orientation.elements[0],-jointOri.orientation.elements[1],jointOri.orientation.elements[2],
							-jointOri.orientation.elements[3],jointOri.orientation.elements[4],-jointOri.orientation.elements[5],
							jointOri.orientation.elements[6],-jointOri.orientation.elements[7],jointOri.orientation.elements[8]);
		Ogre::Quaternion q;
		q.FromRotationMatrix(matOri);
		
		//Desplazamiento del kinect sobre la pantalla
		//joint[0].position.Z += 3000;
		//joint[0].position.Y += 800;

		rot->rotation.setValue(-q.x,q.y,q.z,q.w);
		DrawCoin::BuscarNodo(eJoint,joint[0].position,rot);
	}

}


int TrackUser::Registrar_Eventos(){
	///
	///Obligatorio
	///Registra los eventos necesarios para la calibracion
	///Contiene StartGeneratingAll
	///

	XnCallbackHandle h;
	
	UserGenerator.RegisterUserCallbacks(NewUser, LostUser, (void*)this, h);
	UserGenerator.RegisterToUserExit(UserExit, (void*)this, h);
	UserGenerator.RegisterToUserReEnter(UserReEnter, (void*)this, h);
	
	UserGenerator.GetSkeletonCap().SetSkeletonProfile(XN_SKEL_PROFILE_ALL);

	/*XnCallbackHandle hCalib;
	XnCallbackHandle hPose;
	UserGenerator.GetSkeletonCap().RegisterCalibrationCallbacks(&CalibrationStart, &CalibrationEnd, (void*)this, hCalib);
	UserGenerator.GetPoseDetectionCap().RegisterToPoseCallbacks(&PoseDetected, NULL, (void*)this, hPose);*/

	XnCallbackHandle hCalibStart, hCalibComplete;
	XnCallbackHandle hPoseDetected;
	UserGenerator.GetSkeletonCap().RegisterToCalibrationStart(CalibrationStart, (void*)this, hCalibStart);
	UserGenerator.GetSkeletonCap().RegisterToCalibrationComplete(CalibrationEnd, (void*)this, hCalibComplete);
	UserGenerator.GetPoseDetectionCap().RegisterToPoseDetected(PoseDetected, (void*)this, hPoseDetected);


	rc = context.StartGeneratingAll();
	if (rc != XN_STATUS_OK){
			printf("StartGenerating");
			return -1;
	}

	return 0;
}


int TrackUser::Main_Loop(){
	///
	///Metodo que incluye el context.WaitUpdate
	///Para incluir en el bucle principal
	///

	if (rc != XN_STATUS_OK){
			printf("Can't run main loop, object not initialize correctly: %s\n", xnGetStatusString(rc));
			return -1;
	}	
	
	//Espero y actualizo
	context.WaitAnyUpdateAll();

	return 0;
}



TrackUser::~TrackUser(){
	///
	///Metodo destructor
	///
	
	context.Shutdown();
}


 
