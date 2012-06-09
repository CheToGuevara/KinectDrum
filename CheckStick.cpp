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

checkHands(){



}