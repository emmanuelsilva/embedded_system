//
//  Reader.h
//  DataLogger
//
//  Created by Emmanuel Silva on 6/15/14.
//  Copyright (c) 2014 Emmanuel Silva. All rights reserved.
//

#ifndef __DataLogger__Reader__
#define __DataLogger__Reader__

#include <fstream>
#include <iostream>
#include "Structure.h"

using namespace std;

class Reader {
    
private:
  string port;
  string getDataFromArduino();
  void openSerialConnection();
  void closeSerialConnection();
  
    
public:
    Reader(string port);
    virtual ~Reader();
    string getPort();
    ReadData getValue();
  
};

#endif /* defined(__DataLogger__Reader__) */
