#include "Callbacks.h"
// OpenNI headers
#include <XnOpenNI.h>
// NITE headers
#include <XnVSessionManager.h>
#include <XnVWaveDetector.h>
#include "TrackUser.h"
///-----------------------------------------------------------------------------
/// Callbacks
///-----------------------------------------------------------------------------


///
///Callbacks for user tracker
///

///
///Callbacks for new user
///
void XN_CALLBACK_TYPE NewUser(xn::UserGenerator& generator, XnUserID user, void* pCookie)
{
	printf("New user identified: %d\n", user);
	TrackUser * mytrack=(TrackUser *)pCookie;
	xn::UserGenerator usergenerator=mytrack->GetUserGenerator();
	usergenerator.GetPoseDetectionCap().StartPoseDetection("Psi", user);
}

///
///Callbacks when lost user
///
void XN_CALLBACK_TYPE LostUser(xn::UserGenerator& generator, XnUserID user, void* pCookie)
{
	printf("User %d lost\n", user);
}


///
///Callbacks for calibration
///
void XN_CALLBACK_TYPE CalibrationStart(xn::SkeletonCapability& skeleton, XnUserID user, void* pCookie)
{
	printf("Calibration start for user %d\n", user);
}

///
///Callbacks for calibration end
///
void XN_CALLBACK_TYPE CalibrationEnd(xn::SkeletonCapability& skeleton, XnUserID user, XnBool bSuccess, void* pCookie)
{
	printf("Calibration complete for user %d: %s\n", user, bSuccess?"Success":"Failure");
	if (bSuccess)
	{
		skeleton.StartTracking(user);
	}
	else
	{
			TrackUser * mytrack=(TrackUser *)pCookie;
	xn::UserGenerator usergenerator=mytrack->GetUserGenerator();
		usergenerator.GetPoseDetectionCap().StartPoseDetection("Psi", user);
	}
}

///
///Callbacks for user calibration
///
void XN_CALLBACK_TYPE PoseDetected(xn::PoseDetectionCapability& poseDetection, const XnChar* strPose, XnUserID nId, void* pCookie)
{
	printf("Pose '%s' detected for user %d\n", strPose, nId);
		TrackUser * mytrack=(TrackUser *)pCookie;
	xn::UserGenerator usergenerator=mytrack->GetUserGenerator();
	usergenerator.GetSkeletonCap().RequestCalibration(nId, FALSE);
	usergenerator.GetPoseDetectionCap().StopPoseDetection(nId);
}