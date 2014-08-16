//
//  DataLogger.cpp
//  DataLogger
//
//  Created by Emmanuel Silva on 6/16/14.
//  Copyright (c) 2014 Emmanuel Silva. All rights reserved.
//

#include <string>
#include "DataLogger.h"
#include "FormatHelper.h"

using namespace std;

DataLogger::DataLogger() {
    this->fileName = "/Users/portuga/datalogger.txt";
    this->createStream();
}

DataLogger::DataLogger(string fileName) {
    this->fileName = fileName;
    this->createStream();
}

DataLogger::~DataLogger() {
    if (this->stream.is_open()) {
        this->stream.close();
        cout << "Fechando arquivo" << endl;
    }
}

void DataLogger::createStream() {
    cout << "Gravando em: " << fileName << endl;
    stream.open(fileName, stream.app);
}

void DataLogger::log(ReadData data) {
    cout << "Gerando log em arquivo...";
    
    string line;
    line.append(FormatHelper::formatTime(data.time));
    line.append(";");
    line.append(data.data);
    
    /*
    int analogicSize = sizeof(data.analogicData) / sizeof(*data.analogicData);
    int digitalSize = sizeof(data.digitalData) / sizeof(*data.digitalData);
    
    for (int i = 0; i<analogicSize; i++) {
        line.append(to_string(data.analogicData[i]));
        line.append(";");
    }
    
    for (int i = 0; i<digitalSize; i++) {
        line.append(to_string(data.digitalData[i]));
        line.append(";");
    }
     */
    
    stream << line << "\n";
    stream.flush();

}