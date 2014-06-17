//
//  main.cpp
//  DataLogger
//
//  Created by Emmanuel Silva on 6/15/14.
//  Copyright (c) 2014 Emmanuel Silva. All rights reserved.
//

#include <iostream>
#include "SchedulerReadTask.h"

int main(int argc, const char * argv[])
{
    SchedulerReadTask scheduler(60, 10); //nos proximos 60 segundos de 10 em 10 segundos
    scheduler.start();
    //teste
    return 0;
}

