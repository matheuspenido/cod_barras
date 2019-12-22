#include <Arduino.h>
#include "Flash.h"
#include "Timeout.h"
#include "LcdWriter.h"
 

Flash led1 = Flash(4, 200, 200);
Timeout timer1 = Timeout(3000, "ACABOU O TEMPO!");

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {

  long ms = millis();
  bool acabou = timer1.isTimeouted(ms);

  if (acabou)
    Serial.println(timer1.getMessage());

  led1.update(ms);
}