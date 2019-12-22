#ifndef Timeout_h
#define Timeout_h

#include "Arduino.h"

class Timeout {

    private:
        unsigned long timeOn;
        String message;
        unsigned long startTime;
        bool stopped;
        unsigned long since;

    public:
        Timeout(long timeOn, const String& message);
        bool isTimeouted(long currentMillis);
        String getMessage();
        void reset();

};

#endif
