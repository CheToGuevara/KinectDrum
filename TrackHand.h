// OpenNI headers
#include <XnOpenNI.h>
// NITE headers
#include <XnVSessionManager.h>
#include <XnVWaveDetector.h>

/**
 * \class TrackHand
 *
 * \ingroup SmartInteractive
 * 
 *
 * \brief Clase para hacer Traking de manos
 *
 * Esta clase nos proporciona lo necesario para poder trackear una 
 * mano con el dispositivo 
 *
 * 
 * \author Aaron Sujar
 *
 * \version 0.5
 *
 */

///
///Necesita Cabeceras de los callbacks disponibles
///
#include "Callbacks.h"

///
/// \def  Archivo XML de configuración
///
#define SAMPLE_XML_FILE "./SamplesConfig.xml"

class TrackHand{



public:
	///
	///Constructor 
	///
	TrackHand();

	///
	///Constructor si alguien ya ha iniciado el contexto
	///
	TrackHand(xn::Context g_Context);


	///
	///Destructor
	///
	~TrackHand();

private:
	///
	///Variable Contexto
	///
	xn::Context context;
	///
	///Variable para checkear el status
	///
	XnStatus rc;
	///
	///Variable que controla la session
	///
	XnVSessionManager* pSessionManager;
	///
	///Registrador de eventos de gestos (opcional)
	///
	XnVWaveDetector wc;

public:
	///
	///Metodos
	///

	///
	///Obligatorios
	///
	///
	///Registra los eventos de inicio/fin/progress sesion
	///
	int Registrar_Eventos();
	///
	///Bucle para el funcionamiento
	///Contiene un WaitUpdate
	///
	int Main_Loop();

	///
	///Devuelve el contexto
	///
	xn::Context GetContext();

	///
	///Opcionales
	///

	///
	///Registrar evento WAVE
	///
	int Registrar_Wave();
	///
	///Registrar Movimiento de punto
	///
	int Registrar_PointUpdate();
	///
	///Registrar el evento de QRFocus	
	///
	int Registrar_QuickRefocus(long timeout=10000);
	

};