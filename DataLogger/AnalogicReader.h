//
//  AnalogicReader.h
//  DataLogger
//
//  Created by Emmanuel Silva on 6/16/14.
//  Copyright (c) 2014 Emmanuel Silva. All rights reserved.
//

#ifndef __DataLogger__AnalogicReader__
#define __DataLogger__AnalogicReader__

#include <iostream>

#include "Reader.h"

using namespace std;

class AnalogicReader : public Reader {
public:
    AnalogicReader(int channel);
    int getValue();
};

#endif /* defined(__DataLogger__AnalogicReader__) */
