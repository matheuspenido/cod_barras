#include "Timeout.h"
#include "Arduino.h"

Timeout::Timeout(long timeOn, const String& message) {
    this->timeOn = timeOn;
    this->message = message;
    stopped = true;
    since = 0;
}

bool Timeout::isTimeouted(long currentMillis) {
    
    if (stopped == true) {
        startTime = currentMillis;
        stopped = false;
    }
    else if ((currentMillis - startTime) >= timeOn){
        since = currentMillis;
        stopped = true;
        return true;
    }

    return false;
}

String Timeout::getMessage() {
    return message;
}

void Timeout::reset() {
    startTime = 0;
    stopped = true;
    since = 0;
}

