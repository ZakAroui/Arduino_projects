#include <TimerOne.h>

int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

byte led[8];

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  led[0] = B00111111;
  led[1] = B00100001;
  led[2] = B00111111;
  led[3] = B00000000;
  led[4] = B00111111;
  led[5] = B00101101;
  led[6] = B00101101;
  led[7] = B00111111;
  
  Timer1.initialize(10000);
  Timer1.attachInterrupt(screenUpdate);
  

}

void loop() {
//  for (int i=0; i<8; i++){
//    led[i] = ~led[i];
//  }
//  delay(500);

}

void screenUpdate(){
  byte row = B10000000;
  for (byte k = 0; k<9; k++){
    digitalWrite(latchPin, LOW);
    shiftIt(~led[k]);
    shiftIt(row);
    digitalWrite(latchPin, HIGH);
    row = row >> 1;
  }
}

void shiftIt(byte dataOut){
  boolean pinState;
  digitalWrite(dataPin, LOW);
  
  for (int i= 0; i<8; i++){
    digitalWrite(clockPin, LOW);
    if ( dataOut & (1<<i)){
      pinState = HIGH;
    }
    else {
      pinState = LOW;
    }
    digitalWrite(dataPin, pinState);
    digitalWrite(clockPin, HIGH);
    digitalWrite(dataPin, LOW);
  }
  digitalWrite(clockPin, LOW);
}

