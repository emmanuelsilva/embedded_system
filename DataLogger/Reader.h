//
//  Reader.h
//  DataLogger
//
//  Created by Emmanuel Silva on 6/15/14.
//  Copyright (c) 2014 Emmanuel Silva. All rights reserved.
//

#ifndef __DataLogger__Reader__
#define __DataLogger__Reader__

#include <iostream>

class Reader {
    
private:
    int channel;
    
public:
    Reader(int channel);
    virtual ~Reader();
    int getChannel();
    int getValue();
  
};

#endif /* defined(__DataLogger__Reader__) */
