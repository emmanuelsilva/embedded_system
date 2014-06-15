//
//  DigitalReader.h
//  DataLogger
//
//  Created by Emmanuel Silva on 6/15/14.
//  Copyright (c) 2014 Emmanuel Silva. All rights reserved.
//

#ifndef __DataLogger__DigitalReader__
#define __DataLogger__DigitalReader__

#include <iostream>
#include "Reader.h"

using namespace std;

class DigitalReader : public Reader {
public:
    DigitalReader(int channel);
    int getValue();
};

#endif /* defined(__DataLogger__DigitalReader__) */
