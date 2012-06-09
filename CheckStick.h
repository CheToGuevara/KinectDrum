#pragma once


#include "Music.h"
#include <Inventor/nodes/SoTransform.h>


/**
 * \class CheckStick
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

class CheckStick{



public:
	///
	///Constructor 
	///
	CheckStick(SoTransform * _head, SoTransform * _lhand, SoTransform * _rhand);



	///
	///Destructor
	///
	~CheckStick();


	///Method to check if  play a sound
	checkHands();
private:

	SoTransform * head;
	SoTransform * lhand;
	SoTransform * rhand;
	Music * mymusic;





	

};