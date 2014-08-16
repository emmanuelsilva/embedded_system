//
//  SchedulerReadTask.cpp
//  DataLogger
//
//  Created by Emmanuel Silva on 6/16/14.
//  Copyright (c) 2014 Emmanuel Silva. All rights reserved.
//

#include <unistd.h>
#include "Reader.h"
#include "SchedulerReadTask.h"
#include "FormatHelper.h"

SchedulerReadTask::SchedulerReadTask(int period, int interval) : reader("/dev/tty.usbmodemfa131") {
    this->period = period;
    this->interval = interval;
}

SchedulerReadTask::~SchedulerReadTask() {

}

void SchedulerReadTask::write(ReadData data) {
    this->logger.log(data);
}

ReadData SchedulerReadTask::read(time_t currentTime) {
    ReadData data = reader.getValue();
    data.time = time(&currentTime);
    return data;
}

void SchedulerReadTask::start() {
    bool running = true;
    time_t now, currentTime;
    struct tm periodTime;
    
    time(&now);
    periodTime = *localtime(&now);
    //periodTime.tm_hour = +period; //usar em producao... tempo em horas
    periodTime.tm_sec += period; //usar para testes.... tempo em segundos
    
    time_t formatedPeriodTime = mktime(&periodTime);
    string strFormatedPeriodTime = FormatHelper::formatTime(formatedPeriodTime);
    cout << "Vai rodar ate: " << strFormatedPeriodTime << endl;
    
    while (running) {
        time(&currentTime);
        ReadData data = this->read(currentTime);
        this->write(data);
        
        running = difftime(currentTime, mktime(&periodTime)) < 0;
        
        string formatedCurrentTime = FormatHelper::formatTime(currentTime);
        cout << "Executou em: " << formatedCurrentTime << endl;
        
        sleep(this->interval - 1); //em segundos
    }
    
    cout << "Fim da execucao" << endl;
}



