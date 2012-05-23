#pragma once


/**
 * \class ImageSource
 *
 * \ingroup Kinect
 * 
 *
 * \brief Clase para conseguir imagenes
 *
 * Esta clase nos proporciona lo necesario para poder acceder a 
 * las imagenes de RGB y DEPTH con el dispositivo 
 *
 * 
 * \author Aaron Sujar
 *
 * \version 0.5
 *
 */




#include <XnOpenNI.h>
#include <XnVSessionManager.h>
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

#define SAMPLE_XML_FILE "./SamplesConfig.xml"

class ImageSource{

public:
	
	
	///Constructor con context ya inicializado por parametros
	
	ImageSource(xn::Context g_Context);
	
	///Constructor si se necesita la clase sola
	ImageSource();


	///Destructor
	~ImageSource();

private:
	
	///Contexto
	
	xn::Context context;


	
	///Depth nodo
	
	xn::DepthGenerator depthGenerator;
	
	///Image nodo
	
	xn::ImageGenerator rgbGenerator;
	
	///Status
	
	XnStatus rc;
	

public:


	
	///Devuelve el contexto por si lo utilizan otras clases
	
	xn::Context GetContext();
	
	///Metodo que consigue RGB
	///return IplImage  NEED RELEASE!!!
	
	IplImage*getRGBImage();
	
	///Metodo que consigue la imagen profundidad
	///No devuelve nada todavía
	
	IplImage*getDepthImage(IplImage * imgDepth=NULL);

	///Metodo que consigue las coordenadas projectivas
	XnPoint3D ConvertRealWorldToProjective(XnPoint3D punto);

	

};