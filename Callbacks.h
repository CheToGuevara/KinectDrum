#pragma once


#include <XnOpenNI.h>
// NITE headers
#include <XnVSessionManager.h>

/**
 * \class Callbacks
 * 
 * \ingroup Kinect
 * 
 *
 * \brief Clase que va a procesar los eventos que le surjan.
 *
 * 
 * 
 * \author Aaron Sujar
 *
 * \version 0.5
 *
 */


///
///Callbacks for user tracker
///

///
///Callbacks for new user
///
void XN_CALLBACK_TYPE NewUser(xn::UserGenerator& generator, XnUserID user, void* pCookie);
///
///Callbacks when lost user
///
void XN_CALLBACK_TYPE LostUser(xn::UserGenerator& generator, XnUserID user, void* pCookie);
///
///Callbacks for calibration
///
void XN_CALLBACK_TYPE CalibrationStart(xn::SkeletonCapability& skeleton, XnUserID user, void* pCookie);
///
///Callbacks for calibration end
///
void XN_CALLBACK_TYPE CalibrationEnd(xn::SkeletonCapability& skeleton, XnUserID user, XnBool bSuccess, void* pCookie);
///
///Callbacks for user calibration
///
void XN_CALLBACK_TYPE PoseDetected(xn::PoseDetectionCapability& poseDetection, const XnChar* strPose, XnUserID nId, void* pCookie);
