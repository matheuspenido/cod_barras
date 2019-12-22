#ifndef Flash_h
#define Flash_h

#include "Arduino.h"

class Flash
{
    private: 
        //Membros da classe (variáveis)
        //São inicializadas pelo construtor para cada LED.
        int ledPin;                   //Número do pino do LED.
        long onTime;                  //Milisegundos que o LED irá ligar.
        long offTime;                 //Milisegundos que o LED irá desligar.

        int ledState;                 //Armazena o estado do LED.

        unsigned long previousMillis; //Armazena a última atualização do LED.

    public:
        Flash(int pin, long on, long off); 
        void setOnTime(long onTime);
        void setOffTime(long offTime);
        void update(unsigned long currentMillis);
        void powerOff();
};

#endif