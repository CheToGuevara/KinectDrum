#pragma once
/**
 *	@file	Sequencer.h
 *	@date 
 *	@author	Santiago Ruiz - sruizv at vartficial dot com
 *	@brief	Module to get a thread block
 *  \ingroup Other
 *	\brief Module to get a thread block
 */
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//#include "config.h"

class Sequencer
{
public:
	Sequencer(int _fps);
	~Sequencer(void);
	void Sequence();

private:
	bool sequencer;
	int fps;
	unsigned long last_clock, diff_clock, time_of_loop;
	unsigned long current_secs, last_secs; 
};
