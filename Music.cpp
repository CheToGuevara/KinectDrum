#include "Music.h"
#include <string>
std::string		sonidos[]={"cymbal.wav","hitom.wav","snare.wav"};
///Constructor 
	///
Music::Music(){

	// Initialize Framework
	ALFWInit();

	if (!ALFWInitOpenAL())
	{
		ALFWprintf("Failed to initialize OpenAL\n");
		ALFWShutdown();
		return;
	}

	// Generate an AL Buffer
	alGenBuffers( 3, uiBuffer );
	// Generate a Source to playback the Buffer
    alGenSources( 3, uiSource );

	for(int i=0;i<3;i++){
		// Load Wave file into OpenAL Buffer
		if (!ALFWLoadWaveToBuffer(sonidos[i].c_str(), uiBuffer[i]))
		{
			ALFWprintf("Failed to load %s\n", sonidos[i].c_str());
		}

		// Attach Source to Buffer
		alSourcei( uiSource[i], AL_BUFFER, uiBuffer[i] );
	}

	

	

	// Play Source
    //alSourcePlay( uiSource );
	ALFWprintf("Playing Source ");


}



	///
	///Destructor
	///
Music::~Music(){

		// Clean up by deleting Source(s) and Buffer(s)
	//lSourceStop(uiSource);
   // alDeleteSources(1, &uiSource);
	//alDeleteBuffers(1, &uiBuffer);

	ALFWShutdownOpenAL();

	ALFWShutdown();






}

void Music::playSound(int mode){

			// Get Source State
		alGetSourcei( uiSource[mode], AL_SOURCE_STATE, &iState);
		// Load Wave file into OpenAL Buffer
		//alSourceStop(uiSource[i]);
	
		alSourcePlay(uiSource[mode]);


}