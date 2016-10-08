#include <TimerOne.h>

int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

byte frame = 0;

byte oneFrame[8];

byte led[8][8] = {{0, 56, 92, 158, 158, 130, 68, 56},
                  {0, 56, 124, 186, 146, 130, 68, 56},
                  {0, 56, 116, 242, 242, 130, 68, 56},
                  {0, 56,68, 226, 242, 226, 68, 56},
                  {0, 56,68,130, 242, 242, 116, 56},
                  {0, 56, 68,130,146, 186, 124, 56},
                  {0, 56,68,130, 158, 158, 92, 56},
                  {0, 56,68,142, 158, 142, 68, 56}};

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  oneFrame[0] = B00001100;
oneFrame[1] = B00011100;
oneFrame[2] = B00001100;
oneFrame[3] = B00000000;
oneFrame[4] = B00011100;
oneFrame[5] = B00001000;
oneFrame[6] = B00011100;
oneFrame[7] = B00001000;
  
  Timer1.initialize(10000);
  Timer1.attachInterrupt(screenUpdate);
}

void loop() {
//  for (int i=0; i<8; i++){
//    for (int j=0; j<8; j++){
//      led[i][j]=led[i][j]<<1 | led[i][j] >> 7;
//    }
//  }
//  frame++;
//  if (frame>7) {frame =0;}

  for (int i=0; i<8; i++){
      oneFrame[i]=oneFrame[i]<<1 | oneFrame[i] >> 7;
  }
  
  delay(50);
}

void screenUpdate(){
  byte row = B10000000;
  for (byte k = 0; k<9; k++){
    digitalWrite(latchPin, LOW);
    shiftIt(~oneFrame[k]);
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
