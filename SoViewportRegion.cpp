#include "SoViewportRegion.h"
#include <Inventor/actions/SoGLRenderAction.h>
#include <Inventor/actions/SoCallbackAction.h>
#include <Inventor/actions/SoGetBoundingBoxAction.h>
#include <Inventor/actions/SoGetMatrixAction.h>
#include <Inventor/actions/SoHandleEventAction.h>
#include <Inventor/actions/SoPickAction.h>
#include <Inventor/actions/SoRayPickAction.h>
#include <Inventor/sensors/SoFieldSensor.h>




#include <Inventor/elements/SoViewportRegionElement.h>
#include <Inventor/elements/SoWindowElement.h>

#include <Inventor/system/gl.h>




/*Funciones callback*/
static void
colorCallback(void *data, SoSensor *sensor)
{
	unsigned char *color;
	SoSFVec3f *background = (SoSFVec3f *)((SoFieldSensor *)sensor)->getAttachedField();
	color=(unsigned char *) data;

    color[0]=(char)(255.0*background->getValue()[0]);
	color[1]=(char)(255.0*background->getValue()[1]);
	color[2]=(char)(255.0*background->getValue()[2]);    

}



SO_NODE_SOURCE(SoViewportRegion);

void SoViewportRegion::initClass()
{  
   SO_NODE_INIT_CLASS(SoViewportRegion, SoNode, "Node");
   
   SO_ENABLE(SoGLRenderAction, SoViewportRegionElement);
}

SoViewportRegion::SoViewportRegion()
{
	SO_NODE_CONSTRUCTOR(SoViewportRegion);	

	SO_NODE_ADD_FIELD(changeRatio,(TRUE));
	SO_NODE_ADD_FIELD(onTop,(FALSE));
	SO_NODE_ADD_FIELD(setVp,(FALSE));
	SO_NODE_ADD_FIELD(clearBuffer,(FALSE));
	SO_NODE_ADD_FIELD(background,(SbVec3f(0,0,0)));
	SO_NODE_ADD_FIELD(height,(1.0f));
	SO_NODE_ADD_FIELD(width,(1.0f));
	SO_NODE_ADD_FIELD(x_pos,(0.0f));
	SO_NODE_ADD_FIELD(y_pos,(0.0f));

	SoFieldSensor *colorSensor = 
            new SoFieldSensor(colorCallback,color);
	colorSensor->attach(&background);
}

SoViewportRegion::~SoViewportRegion()
{

}

void SoViewportRegion::setViewportRegion(const SbViewportRegion vp)
{
	SbVec2s winSize;
	
	viewport.setViewport(vp.getViewportOrigin(), vp.getViewportSize());
	viewport.setWindowSize (vp.getWindowSize());
	viewport.setViewportPixels(vp.getViewportOriginPixels(), 
		vp.getViewportSizePixels());
}
const SbViewportRegion SoViewportRegion::getViewportRegion(){
	return viewport;
}



void SoViewportRegion::doAction (SoAction *action)
{
	if (changeRatio.getValue())
	{
		SbVec2s winSize;
		float pixelPerInch;

		winSize=SoViewportRegionElement::get(action->getState())
			.getWindowSize();
		pixelPerInch=SoViewportRegionElement::get(action->getState())
			.getPixelsPerInch();
			

		viewport.setViewport(x_pos.getValue(),y_pos.getValue(),
			width.getValue(),height.getValue());
		viewport.setWindowSize (winSize);
		viewport.setPixelsPerInch(pixelPerInch);

		SoViewportRegionElement::set(action->getState(),viewport);
	}else if(setVp.getValue())
	{
		SoViewportRegionElement::set(action->getState(),viewport);
	}

}

void SoViewportRegion::GLRender(SoGLRenderAction *action)
{
	
	
	SoViewportRegion::doAction(action);

	if(clearBuffer.getValue())
	{
		SbVec2s winSize;
		
		winSize=SoViewportRegionElement::get(action->getState()).getViewportSizePixels();
		
		glPixelZoom(winSize[0],winSize[1]);
		glDrawPixels(1,1,GL_RGB,GL_UNSIGNED_BYTE,color);
		glPixelZoom(1,1);

		glClear(GL_DEPTH_BUFFER_BIT);
	}		


	if(onTop.getValue())
		glClear(GL_DEPTH_BUFFER_BIT);
}

void SoViewportRegion::callback(SoCallbackAction *action)
{
	SoViewportRegion::doAction(action);
}

void SoViewportRegion::getBoundingBox (SoGetBoundingBoxAction *action)
{
	SoViewportRegion::doAction(action);
}

void SoViewportRegion::getMatrix (SoGetMatrixAction *action)
{
	SoViewportRegion::doAction(action);
}

void SoViewportRegion::handleEvent (SoHandleEventAction *action)
{
	SoViewportRegion::doAction(action);
}

void SoViewportRegion::pick (SoPickAction *action)
{
	SoViewportRegion::doAction(action);
}

void SoViewportRegion::rayPick (SoRayPickAction *action)
{
	SoViewportRegion::doAction(action);
}


/*int main(int argc, char ** argv)
{
  SoDB::init();
  SoViewportRegionElement::initClass();
  
  return 0;
}*/
