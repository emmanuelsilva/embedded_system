//
//  Reader.cpp
//  DataLogger
//
//  Created by Emmanuel Silva on 6/15/14.
//  Copyright (c) 2014 Emmanuel Silva. All rights reserved.
//

#include "Reader.h"

using namespace std;

Reader::Reader(int channel) {
    this->channel = channel;
}

Reader::~Reader() {
    
}

int Reader::getChannel() {
    return this->channel;
}

int Reader::getValue() {
    return 0;
}

