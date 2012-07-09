#pragma once

/**
 * \class DrawCoin
 * 
 * \ingroup OpenInventor
 * 
 *
 * \brief Clase que va a procesar los eventos que le surjan.
 *
 * 
 * 
 * \author Aaron Sujar
 *
 * \version 0.5
 *
 */
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/nodes/SoRotation.h>
#include "Ogre.h"
#include <XnVSessionManager.h>

class DrawCoin{

public:

	static void CrearEsqueleto(SoSeparator * root);
	static void DestruirEsqueleto(SoSeparator * root);
	static void BuscarNodo(int articulacion,XnPoint3D punto,SoRotation * rot=NULL);
	static SoTransform * Get_Cabeza_Pos();
	static SoRotation * Get_Cabeza_Rot();
	
	

	static SoTransform * t_cabeza;
	static SoRotation * t_rot_cabeza;
	static SoTransform * t_cuello; 
	static SoTransform * t_hombro_izq; 
	static SoTransform * t_hombro_der; 
	static SoTransform * t_codo_izq; 
	static SoTransform * t_codo_der; 
	static SoTransform * t_mano_izq; 
	static SoTransform * t_mano_der; 
	static SoTransform * t_torso; 
	static SoTransform * t_cadera_der; 
	static SoTransform * t_cadera_izq; 
	static SoTransform * t_rodilla_der; 
	static SoTransform * t_rodilla_izq; 
	static SoTransform * t_pie_der; 
	static SoTransform * t_pie_izq; 

	

};