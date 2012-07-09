
#include "DrawCoin.h"

#include <Inventor/nodes/SoCone.h>
#include <Inventor/nodes/SoCube.h>
#include <Inventor/nodes/SoCylinder.h>
#include <Inventor/nodes/SoBlinker.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoRotation.h>
#include <Inventor/nodes/SoSphere.h>
#include <Inventor/nodes/SoFile.h>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/nodes/SoTexture2.h>

#include <XnOpenNI.h>
#include <XnVSessionManager.h>


SoTransform * DrawCoin::t_cabeza;
SoRotation * DrawCoin::t_rot_cabeza;
SoTransform * DrawCoin::t_cuello; 
SoTransform * DrawCoin::t_hombro_izq; 
SoTransform * DrawCoin::t_hombro_der; 
SoTransform * DrawCoin::t_codo_izq; 
SoTransform * DrawCoin::t_codo_der; 
SoTransform * DrawCoin::t_mano_izq; 
SoTransform * DrawCoin::t_mano_der; 
SoTransform * DrawCoin::t_torso; 
SoTransform * DrawCoin::t_cadera_der; 
SoTransform * DrawCoin::t_cadera_izq; 
SoTransform * DrawCoin::t_rodilla_der; 
SoTransform * DrawCoin::t_rodilla_izq; 
SoTransform * DrawCoin::t_pie_der; 
SoTransform * DrawCoin::t_pie_izq; 


void DrawCoin::CrearEsqueleto(SoSeparator * root){

	t_cabeza=new SoTransform;
	t_rot_cabeza= new SoRotation;
	SoSphere *esfera =new SoSphere;
	esfera->radius=0.1f;
	SoCylinder *cilindro =new SoCylinder;
	cilindro->radius=0.1f;
	cilindro->height=0.1f;

	root->addChild(t_cabeza);

	SoSeparator * cabeza = new SoSeparator;
	SoMaterial * text_cabeza=new SoMaterial;
	SoTransform * scala=new SoTransform;
	scala->scaleFactor.setValue(0.01f,0.01f,0.01f);
	
	root ->addChild(cabeza);
	cabeza->addChild(text_cabeza);
	cabeza->addChild(t_rot_cabeza);
	cabeza->addChild(scala);


	SoFile *modelcabeza = new SoFile;
	modelcabeza->name.setValue("cabeza.wrl");
	cabeza->addChild(modelcabeza);
	
	

	t_cuello=new SoTransform;
	SoSeparator * cuello = new SoSeparator;
	SoMaterial * m_cuello=new SoMaterial;
	
	root->addChild(cuello);
	cuello->addChild(t_cuello);
	cuello->addChild(m_cuello);
	cuello->addChild(esfera);

	t_hombro_izq=new SoTransform;
	SoSeparator * hombro_izq = new SoSeparator;
	SoMaterial * m_hombro_izq=new SoMaterial;
	
	root->addChild(hombro_izq);
	hombro_izq->addChild(t_hombro_izq);
	hombro_izq->addChild(m_hombro_izq);
	hombro_izq->addChild(esfera);

	t_hombro_der=new SoTransform; 
	SoSeparator * hombro_der = new SoSeparator;
	SoMaterial * m_hombro_der=new SoMaterial;

	root->addChild(hombro_der);
	hombro_der->addChild(t_hombro_der);
	hombro_der->addChild(m_hombro_der);
	hombro_der->addChild(esfera);

	t_codo_izq=new SoTransform; 
	SoSeparator * codo_izq = new SoSeparator;
	SoMaterial * m_codo_izq=new SoMaterial;

	root->addChild(codo_izq);
	codo_izq->addChild(t_codo_izq);
	codo_izq->addChild(m_codo_izq);
	codo_izq->addChild(esfera);

	t_codo_der=new SoTransform; 
	SoSeparator * codo_der = new SoSeparator;
	SoMaterial * m_codo_der=new SoMaterial;

	root->addChild(codo_der);
	codo_der->addChild(t_codo_der);
	codo_der->addChild(m_codo_der);
	codo_der->addChild(esfera);

	t_mano_izq=new SoTransform; 
	SoSeparator * mano_izq = new SoSeparator;
	SoMaterial * m_mano_izq=new SoMaterial;

	// model
	SoFile *model = new SoFile;
	model->name.setValue("mano.wrl");
	

	root->addChild(mano_izq);
	mano_izq->addChild(t_mano_izq);
	mano_izq->addChild(m_mano_izq);
	mano_izq->addChild(scala);
	mano_izq->addChild(model);

	t_mano_der=new SoTransform;
	SoSeparator * mano_der = new SoSeparator;
	SoMaterial * m_mano_der=new SoMaterial;

	root->addChild(mano_der);
	mano_der->addChild(t_mano_der);
	mano_der->addChild(m_mano_der);
	mano_der->addChild(scala);
	mano_der->addChild(model);

	t_torso=new SoTransform;
	SoSeparator * torso = new SoSeparator;
	SoMaterial * m_torso=new SoMaterial;

	root->addChild(torso);
	torso->addChild(t_torso);
	torso->addChild(m_torso);
	torso->addChild(esfera);

	t_cadera_der=new SoTransform;
	SoSeparator * cadera_der = new SoSeparator;
	SoMaterial * m_cadera_der=new SoMaterial;

	root->addChild(cadera_der);
	cadera_der->addChild(t_cadera_der);
	cadera_der->addChild(m_cadera_der);
	cadera_der->addChild(esfera);

	t_cadera_izq=new SoTransform;
	SoSeparator * cadera_izq = new SoSeparator;
	SoMaterial * m_cadera_izq=new SoMaterial;

	root->addChild(cadera_izq);
	cadera_izq->addChild(t_cadera_izq);
	cadera_izq->addChild(m_cadera_izq);
	cadera_izq->addChild(esfera);

	t_rodilla_der=new SoTransform;
	SoSeparator * rodilla_der = new SoSeparator;
	SoMaterial * m_rodilla_der=new SoMaterial;

	root->addChild(rodilla_der);
	rodilla_der->addChild(t_rodilla_der);
	rodilla_der->addChild(m_rodilla_der);
	rodilla_der->addChild(esfera);

	t_rodilla_izq=new SoTransform; 
	SoSeparator * rodilla_izq = new SoSeparator;
	SoMaterial * m_rodilla_izq=new SoMaterial;

	root->addChild(rodilla_izq);
	rodilla_izq->addChild(t_rodilla_izq);
	rodilla_izq->addChild(m_rodilla_izq);
	rodilla_izq->addChild(esfera);

	t_pie_der=new SoTransform;
	SoSeparator * pie_der = new SoSeparator;
	SoMaterial * m_pie_der=new SoMaterial;

	root->addChild(pie_der);
	pie_der->addChild(t_pie_der);
	pie_der->addChild(m_pie_der);
	pie_der->addChild(esfera);


	t_pie_izq=new SoTransform;
	SoSeparator * pie_izq = new SoSeparator;
	SoMaterial * m_pie_izq=new SoMaterial;

	root->addChild(pie_izq);
	pie_izq->addChild(t_pie_izq);
	pie_izq->addChild(m_pie_izq);
	pie_izq->addChild(esfera);
	

	
	

}
void DrawCoin::DestruirEsqueleto(SoSeparator * root){




}
SoTransform * DrawCoin::Get_Cabeza_Pos(){


	return t_cabeza;

}
SoRotation * DrawCoin::Get_Cabeza_Rot(){


	return t_rot_cabeza;

}


void DrawCoin::BuscarNodo(int articulacion,XnPoint3D punto, SoRotation *rot ){


	punto.X=punto.X/500;
	punto.Y=punto.Y/500;
	punto.Z=punto.Z/500;
	switch(articulacion){

		case  XN_SKEL_HEAD :

			t_cabeza->translation.setValue(punto.X,punto.Y,punto.Z);
			t_rot_cabeza->rotation=rot->rotation;
			break;

		case  XN_SKEL_TORSO :

			t_torso->translation.setValue(punto.X,punto.Y,punto.Z);

			break;

		case  XN_SKEL_NECK :

			t_cuello->translation.setValue(punto.X,punto.Y,punto.Z);

			break;

		case  XN_SKEL_LEFT_ELBOW :

			t_codo_izq->translation.setValue(punto.X,punto.Y,punto.Z);

			break;

		case  XN_SKEL_LEFT_SHOULDER :

			t_hombro_izq->translation.setValue(punto.X,punto.Y,punto.Z);

			break;

			
		case  XN_SKEL_RIGHT_ELBOW :

			t_codo_der->translation.setValue(punto.X,punto.Y,punto.Z);

			break;


		case  XN_SKEL_RIGHT_SHOULDER :

			t_hombro_der->translation.setValue(punto.X,punto.Y,punto.Z);

			break;

		case  XN_SKEL_LEFT_KNEE :

			t_rodilla_izq->translation.setValue(punto.X,punto.Y,punto.Z);

			break;

		case  XN_SKEL_LEFT_HIP :

			t_cadera_izq->translation.setValue(punto.X,punto.Y,punto.Z);

			break;

		case  XN_SKEL_RIGHT_KNEE :

			t_rodilla_der->translation.setValue(punto.X,punto.Y,punto.Z);

			break;
		case  XN_SKEL_RIGHT_HIP :

			t_cadera_der->translation.setValue(punto.X,punto.Y,punto.Z);

			break;
		case  XN_SKEL_LEFT_HAND :

			t_mano_izq->translation.setValue(punto.X,punto.Y,punto.Z);

			break;

		case  XN_SKEL_LEFT_FOOT :

			t_pie_izq->translation.setValue(punto.X,punto.Y,punto.Z);

			break;

		case  XN_SKEL_RIGHT_HAND :

			t_mano_der->translation.setValue(punto.X,punto.Y,punto.Z);

			break;
		case  XN_SKEL_RIGHT_FOOT :

			t_pie_der->translation.setValue(punto.X,punto.Y,punto.Z);

			break;
		default :
			break;
	
	}


}