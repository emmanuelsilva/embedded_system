//
//  SchedulerReadTask.h
//  DataLogger
//
//  Created by Emmanuel Silva on 6/16/14.
//  Copyright (c) 2014 Emmanuel Silva. All rights reserved.
//

#ifndef __DataLogger__SchedulerReadTask__
#define __DataLogger__SchedulerReadTask__

#include <iostream>
#include <time.h>
#include "Structure.h"
#include "DataLogger.h"
#include "Reader.h"

class SchedulerReadTask {
private:
    int period;
    int interval;
    DataLogger logger;
    Reader *reader;
    
public:
    SchedulerReadTask(int period, int interval);
    ~SchedulerReadTask();
    ReadData read(time_t currentTime);
    void write(ReadData data);
    void start();
};

#endif /* defined(__DataLogger__SchedulerReadTask__) */
