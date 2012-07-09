#pragma once

#include <Inventor/nodes/SoSpotLight.h>
#include <Inventor/nodes/SoSeparator.h>



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






class LightControl{



public:
	///
	///Constructor 
	///
	LightControl(SoSeparator * escena);



	///
	///Destructor
	///
	~LightControl();

	void playLight(int mode);

private:

	
SoSpotLight * rojo;
SoSpotLight * verde;
SoSpotLight * azul;
	

};