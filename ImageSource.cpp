#include "ImageSource.h"

/**
 *	@file	ImageSource.cpp
 *	@date 
 *	@author	Aaron Sújar - asujar at vartficial dot com
 *	@brief	Module to get image from device
 */


ImageSource::ImageSource(xn::Context g_Context){
	///
	///Nos traemos el contexto por los argumentos
	///
	
	//Inicializamos el objeto.
	context=g_Context;
	
	//Buscamos en el contexto, el nodo depth
	
	rc = context.FindExistingNode(XN_NODE_TYPE_DEPTH,depthGenerator);
	if (rc != XN_STATUS_OK){
		printf("Can't run - no depth generator is present!\n");
		getchar();
		exit(0);
	}
	//Buscamos en el contexto, el nodo image
	rc = context.FindExistingNode(XN_NODE_TYPE_IMAGE,rgbGenerator); 
	
	if (rc != XN_STATUS_OK){
		printf("Can't run - no RGB generator is present!\n");
		getchar();
		exit(0);
	}


}
ImageSource::ImageSource(){
	///
	///Metodo Constructor
	///
	

	// Create context
	rc = context.InitFromXmlFile(SAMPLE_XML_FILE);
	if (rc != XN_STATUS_OK){
			printf("Couldn't initialize: %s\n", xnGetStatusString(rc));
			context.Shutdown();
			getchar();
			exit(0);
			

	}
	//Buscamos el nodo depth
	rc = context.FindExistingNode(XN_NODE_TYPE_DEPTH,depthGenerator);
	if (rc != XN_STATUS_OK){
		printf("Can't run - no depth generator is present!\n");
		getchar();
		exit(0);
	}
	//Buscamos el nodo image
	rc = context.FindExistingNode(XN_NODE_TYPE_IMAGE,rgbGenerator); 
	
	if (rc != XN_STATUS_OK){
		printf("Can't run - no RGB generator is present!\n");
		getchar();
		exit(0);
	}


}
ImageSource::~ImageSource(){
	
	if(rc==XN_STATUS_OK){
		context.Shutdown();
	}
	rc = XN_STATUS_ERROR;

}

xn::Context ImageSource::GetContext(){
	///Devolvemos el contexto

	return context;

}


IplImage* ImageSource::getRGBImage(){
	///
	///Metodo que consigue RGB
	///return IplImage  NEED RELEASE!!!
	///
	

	xn::ImageMetaData rgbMD;
	rgbGenerator.GetMetaData(rgbMD);
	//const XnRGB24Pixel* pImage = rgbMD.RGB24Data(); 

	IplImage* imgRGB = cvCreateImage(cvSize(640,480),8,3);
	

	const XnUInt8* pImage = rgbMD.Data();
    if(rgbMD.PixelFormat() != XN_PIXEL_FORMAT_RGB24) 
		  printf("Invalid RGB format.");

	///Modificamos la imagen para opencv
	for (int i = 0; i < rgbMD.XRes()*rgbMD.YRes()*3; i += 3){
        
         imgRGB->imageData[i] = pImage[i+2];
		 imgRGB->imageData[i+1] = pImage[i+1];
		 imgRGB->imageData[i+2] = pImage[i];
        
	 }


	

	return imgRGB;

}
IplImage * ImageSource::getDepthImage(IplImage * imgDepth){
	///
	///Metodo que consigue la imagen profundidad
	///IplImage * =cvCreateImage(cvSize(640,480),IPL_DEPTH_16U,1);
	///Hay que hacer un release
	///


	const XnDepthPixel * depthimage=depthGenerator.GetDepthMap();
	IplImage * Depth=cvCreateImage(cvSize(640,480),IPL_DEPTH_16U,1);

		for (int i = 0; i < 640*480; i++){
			((short*) Depth->imageData)[i]=depthimage[i];
		}

	return Depth;
	
}

XnPoint3D ImageSource::ConvertRealWorldToProjective(XnPoint3D punto){


	///Convertimos de coordenadas reales a proyectivas

	XnPoint3D pt[1];
	pt[0]=punto;
	depthGenerator.ConvertRealWorldToProjective(1,pt,pt);
	punto=pt[0];
	return punto;
}
