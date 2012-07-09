#pragma once

#include <Inventor/nodes/SoFrustumCamera.h> 
#include <Inventor/Win/viewers/SoWinExaminerViewer.h>
#include "CheckStick.h"
#include "LightControl.h"

/**
 * \class Pointers
 *
 * \ingroup Others
 * 
 *
 * \brief Clase para agrupar punteros
 *
 * Esta clase nos proporciona los punteros necesarios para
 * comunicar los distintos metodos
 *
 * 
 * \author Aaron Sujar
 *
 * \version 0.5
 *
 */






class Pointers{



public:
	
	Pointers(){

	};

	~Pointers();

	SoFrustumCamera * camera2;
	LightControl * lights;
	CheckStick * sticks;
	SoWinExaminerViewer * viewer;

	

};