#include "LightControl.h"
#include <time.h>

	///
LightControl::LightControl(SoSeparator * escena){

	rojo=new SoSpotLight;
	verde=new SoSpotLight;
	azul=new SoSpotLight;
	rojo->direction.setValue(-0.5,-1,0);
	rojo->color.setValue(1.0f,0.0f,0.f);
	rojo->location.setValue(1.0f,3.f,0.0f);
	verde->direction.setValue(0,-1,0);
	verde->color.setValue(0.0f,1.0f,0.f);
	verde->location.setValue(-1.0f,3.f,0.0f);
	azul->direction.setValue(1,-1,0);
	azul->color.setValue(0.0f,0.0f,1.f);
	azul->location.setValue(0.0f,3.f,0.0f);

	escena->addChild(rojo);
	escena->addChild(azul);
	escena->addChild(verde);

}



	///
	///Destructor
	///
LightControl::~LightControl(){

	






}

void LightControl::playLight(int mode){


		srand ( time(NULL) );
/* generate random number: */
	int numale = rand() % 100 + 1;

	(((numale%4)==0)?rojo->on=FALSE:rojo->on=TRUE);
	(((numale%5)==0)?verde->on=FALSE:verde->on=TRUE);
	(((numale%3)==0)?azul->on=FALSE:azul->on=TRUE);
			

}