//
//  main.cpp
//  DataLogger
//
//  Created by Emmanuel Silva on 6/15/14.
//  Copyright (c) 2014 Emmanuel Silva. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include "SchedulerReadTask.h"
#include "Reader.h"


int main(int argc, const char * argv[])
{
    int period, interval;
    bool ok;
    
    period = 0;
    interval = 0;
    ok = false;

    while (!ok) {
        cout << "Informe o período para coleta (em segundos):" << endl;
        cin >> period;
        
        cout << "Informe o intervalo (em segundos): " << endl;
        cin >> interval;
        
        ok = interval >= 2;
        
        if (!ok) {
            cout << "O intervalo minimo é de 2 segundos" << endl;
        }
    }
    
    SchedulerReadTask scheduler(period, interval);
    scheduler.start();
    
    return 0;
}

