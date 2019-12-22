#ifndef LcdWriter_h
#define LcdWriter_h

#include "Arduino.h"
#include <LiquidCrystal.h>

class LcdWriter {

    private:
        LiquidCrystal lcd;
        bool writed;
        String message;
        int columns;
        int lines;

    public:
        LcdWriter(int RS, int E, int D4, int D5, int D6, int D7, int c, int l);
        void displayMessage(int c, int l, const String& message);
        void reset();
};

#endif