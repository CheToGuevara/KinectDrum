/**
 *	@file	Sequencer.cpp
 *	@date 
 *	@author	Santiago Ruiz - sruizv at vartficial dot com
 *	@brief	Module to get a thread block
 */

#include "Sequencer.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>
//#include "Plavia_LOG.h"

#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif
#ifdef LEAK_TRACE
#define MEMDEB_JUST_DECLARE
#include "memdeb.cpp"
#endif

Sequencer::Sequencer(int _fps)
{
	//Plavia_LOG::LOG(PLVDEBUG, "SEQUENCER: CREATE");
	
	fps = _fps;
	if (fps != 0)
	{
		//Plavia_LOG::LOG(PLVTRACE, "SEQUENCER: Setting max fps = %d", _fps);
		time_of_loop = (1000/fps); //ms
	}
	else
	{
		//Plavia_LOG::LOG(PLVTRACE, "SEQUENCER: Setting default max fps = 10");
		time_of_loop = 100;
	}
	diff_clock = 0;
	last_secs = clock()/CLOCKS_PER_SEC;
	current_secs = clock()/CLOCKS_PER_SEC;
}

Sequencer::~Sequencer(void)
{
	//Plavia_LOG::LOG(PLVDEBUG, "SEQUENCER: DESTROY");
}

void Sequencer::Sequence()
{
	diff_clock = (((unsigned long)clock()) - last_clock );
	int diff_ms = (diff_clock*1000)/CLOCKS_PER_SEC;
	if (diff_ms < time_of_loop)
		Sleep(time_of_loop - diff_ms);
	//else
		//Plavia_LOG::LOG(PLVDEBUG, "SEQUENCER: Time of last loop exceded defined time in sequencer");
	last_clock = (unsigned long) clock();

	//for console keep alive
	current_secs = clock()/CLOCKS_PER_SEC;
	if ((current_secs - last_secs) >= 60)
	{
		printf("Keep alive sent." );
		last_secs = current_secs;
	}
}