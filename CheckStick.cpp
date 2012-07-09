#include "CheckStick.h"
#include "DrawCoin.h"


///Constructor 
	///
CheckStick::CheckStick(SoTransform * _head, SoTransform * _lhand, SoTransform * _rhand){

	head=_head;
	lhand=_lhand;
	rhand=_rhand;

	mymusic=new Music();


}



	///
	///Destructor
	///
CheckStick::~CheckStick(){

	delete mymusic;


}

void CheckStick::checkHands(){

	float x,y,z;
	lhand->translation.getValue().getValue(x,y,z);

	printf("X=%f,Y=%f,Z=%f\n",x,y,z);


	///comprobamos la mano izquierda
	//podemos mirar la velocidad
	if ( x>0.5f && x<0.70f && y>-0.35f && y<-0.15f && z>-1.30f && z<-1.0f ){
		mymusic->playSound(CYMBAL);
	}
	if ( x>0 && x<2 && y>0 && y<1 && z>-1.30 && z<1 ){
		mymusic->playSound(SNARE);
	}
	if ( x>-0.7f && x<-0.5 && y>-0.35f && y<-0.15f &&  z>-1.30f && z<-1.0f){
		mymusic->playSound(HIHAT);
	}
	if ( x>0 && x<2 && y>0 && y<1 && z>0 && z<1 ){
		mymusic->playSound(TOMTOM);
	}
	if ( x>0 && x<2 && y>0 && y<1 && z>0 && z<1 ){
		mymusic->playSound(DRUM);
	}

	///comprobamos la mano derecha
	//podemos mirar la velocidad
	rhand->translation.getValue().getValue(x,y,z);

	printf("X=%f,Y=%f,Z=%f\n",x,y,z);
	
	if ( x>0.5f && x<0.70f && y>-0.35f && y<-0.15f && z>-1.30f && z<-1.0f ){
		mymusic->playSound(CYMBAL);
	}
	if ( x>0 && x<2 && y>0 && y<1 && z>0 && z<1 ){
		mymusic->playSound(SNARE);
	}
	if ( x>-0.7f && x<-0.5 && y>-0.35f && y<-0.15f &&  z>-1.30f && z<-1.0f ){
		mymusic->playSound(HIHAT);
	}
	if ( x>0 && x<2 && y>0 && y<1 && z>0 && z<1 ){
		mymusic->playSound(TOMTOM);
	}
	if ( x>0 && x<2 && y>0 && y<1 && z>0 && z<1 ){
		mymusic->playSound(DRUM);
	}
	
	

}