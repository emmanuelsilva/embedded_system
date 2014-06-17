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
    int period, interval;
    
    cout << "Informe o período para coleta (em segundos):" << endl;
    cin >> period;
    
    cout << "Informe o intervalo (em segundos): " << endl;
    cin >> interval;
    
    SchedulerReadTask scheduler(period, interval);
    scheduler.start();
    //teste
    return 0;
}

