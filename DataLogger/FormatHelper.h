//
//  FormatHelper.h
//  DataLogger
//
//  Created by Emmanuel Silva on 6/16/14.
//  Copyright (c) 2014 Emmanuel Silva. All rights reserved.
//

#ifndef DataLogger_FormatHelper_h
#define DataLogger_FormatHelper_h

#include <string>
#include <ctime>

using namespace std;

class FormatHelper {
public:
    static string formatTime(time_t time) {
        char formated[80];
        strftime(formated, sizeof(formated), "%d/%m/%Y %H:%M:%S", localtime(&time));
        return formated;
    }
};

#endif
