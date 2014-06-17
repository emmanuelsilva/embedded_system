//
//  Structure.h
//  DataLogger
//
//  Created by Emmanuel Silva on 6/16/14.
//  Copyright (c) 2014 Emmanuel Silva. All rights reserved.
//

#ifndef DataLogger_Structure_h
#define DataLogger_Structure_h

#include <ctime>

using namespace std;

typedef struct {
    short analogicData[2];
	unsigned short digitalData[6];
    time_t time;
} ReadData;


#endif
