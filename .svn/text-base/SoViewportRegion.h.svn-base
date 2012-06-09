// SoViewportRegion.h: Esta clase indica el view port del resto de la
// escena.
//
//////////////////////////////////////////////////////////////////////

/**
 * \class SoViewportRegion
 * 
 * \ingroup OpenInventor
 * 
 *
 * \brief Clase que hace posible tener dos regiones en el viewport
 *
 * 
 * 
 * \author Marcos Garcia
 *
 * \version 0.5
 *
 */

#ifndef SOVIEWPORTREGION
#define SOVIEWPORTREGION

#include <Inventor/nodes/SoPerspectiveCamera.h>
#include <Inventor/fields/SoSFBool.h> 
#include <Inventor/fields/SoSFFloat.h> 
#include <Inventor/fields/SoSFVec3f.h> 
#include <Inventor/actions/SoGLRenderAction.h>

class SoViewportRegion : public SoNode  
{
SO_NODE_HEADER(SoViewportRegion);

//Métodos
public:
	static void initClass();
	SoViewportRegion();

	void setViewportRegion(const SbViewportRegion vp);
	const SbViewportRegion getViewportRegion();

//Acciones
protected:
	virtual void doAction (SoAction *action); 

	virtual void GLRender(SoGLRenderAction *action);
	virtual void callback(SoCallbackAction *action);
	virtual void getBoundingBox (SoGetBoundingBoxAction *action); 
	virtual void getMatrix (SoGetMatrixAction *action);
	virtual void handleEvent (SoHandleEventAction *action); 
	virtual void pick (SoPickAction *action); 
	virtual void rayPick (SoRayPickAction *action);	

//Destructor
private:
	virtual ~SoViewportRegion();
	unsigned char color[3];

//Campos
public:
	
	SoSFBool changeRatio;
	SoSFBool onTop; 
	SoSFBool setVp;
	SoSFBool clearBuffer;
	SoSFVec3f background;
	SoSFFloat height; //0-1
	SoSFFloat width; //0-1
	SoSFFloat x_pos; //0-1
	SoSFFloat y_pos; //0-1

private:
	SbViewportRegion viewport;
};

#endif 
