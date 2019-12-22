#include "Flash.h"
#include "Arduino.h"

Flash::Flash(int pin, long on, long off) {
      
    ledPin = pin;
    pinMode(ledPin, OUTPUT);

    onTime = on;
    offTime = off;

    ledState = LOW;
    previousMillis = 0;
}

void Flash::setOnTime(long onTime) {
    this->onTime = onTime;
}

void Flash::setOffTime(long offTime) {
    this->offTime = offTime;
}

//Esse método verificará a última vez que o LED teve o estado alterado, através disso pode verificar se está no momento de liga-lo
//ou desliga-lo, como foi definido através dos valores: onTime e offTime.
void Flash::update(unsigned long currentMillis) {
     
    //Se estiver desligado e o tempo para liga-lo foi alcançado ou mesmo seja superior, deverá ligar.
    if ((ledState == LOW) && (currentMillis - previousMillis >= onTime))
    {
        ledState = HIGH;                 //Liga o LED.
        previousMillis = currentMillis;  //Mantém o tempo da última vez que foi atualizado.
        digitalWrite(ledPin, ledState);
    }
    else if ((ledState == HIGH) && (currentMillis - previousMillis >= offTime))
    {
        ledState = LOW;                  //Desliga o LED.
        previousMillis = currentMillis;  //Mantém o tempo da última vez que foi atualizado.
        digitalWrite(ledPin, ledState);
    }
}

void Flash::powerOff() {
    if (ledState == HIGH) {
        ledState = LOW;
        digitalWrite(ledPin, ledState);
    }
}