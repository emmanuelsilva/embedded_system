//
//  DataLogger.h
//  DataLogger
//
//  Created by Emmanuel Silva on 6/16/14.
//  Copyright (c) 2014 Emmanuel Silva. All rights reserved.
//

#ifndef __DataLogger__DataLogger__
#define __DataLogger__DataLogger__

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Structure.h"

using namespace std;

class DataLogger {
private:
    string fileName;
    ofstream stream;
    
    void createStream();
    
public:
    DataLogger();
    DataLogger(string fileName);
    ~DataLogger();
    void log(ReadData data);
    
};


#endif /* defined(__DataLogger__DataLogger__) */
