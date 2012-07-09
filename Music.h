#pragma once
#include "Framework.h"



/**
 * \class Music
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

#define CYMBAL 0
#define HIHAT 1
#define SNARE 2
#define TOMTOM 3
#define DRUM 4




class Music{



public:
	///
	///Constructor 
	///
	Music();



	///
	///Destructor
	///
	~Music();

	void playSound(int mode);

private:

	
ALuint      uiBuffer[3];
ALuint      uiSource[3];  
ALint       iState;

	

};