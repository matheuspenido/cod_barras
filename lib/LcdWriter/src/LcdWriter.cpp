#include "LcdWriter.h"
#include <LiquidCrystal.h>
#include "Arduino.h"

LcdWriter::LcdWriter(int RS, int E, int D4, int D5, int D6, int D7, int c, int l) {
    lcd = LiquidCrystal(RS, E, D4, D5, D6, D7);
    columns = c;
    lines = l;
    lcd.begin(c, l);
    writed = false;
}

void LcdWriter::displayMessage(int c, int l, const String& message) {
    
    if (!message.equals(this->message)) {
        lcd.clear();
        lcd.setCursor(c,l);
        lcd.print(message);
        this->message = message;
        writed = true;
    }
}

void LcdWriter::reset() {
    
    if (writed) {
        writed = false;
        lcd.setCursor(0,0);
    }
}