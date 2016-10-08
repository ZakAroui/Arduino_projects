//#include <TimerOne.h>

int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

byte led[8];

byte r = B00000000;
byte c = B11111111;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  led[0] = B11111111;
  led[1] = B10000001;
  led[2] = B10111101;
  led[3] = B10100101;
  led[4] = B10100101;
  led[5] = B10111101;
  led[6] = B10000001;
  led[7] = B11111111;
  
//  Timer1.initialize(10000);
//  Timer1.attachInterrupt(testy);
  

}

void loop() {
//  for (int i=0; i<8; i++){
//    led[i] = ~led[i];
//  }
//  delay(500);

testy();

}

void testy(){
 digitalWrite(latchPin, LOW);
shiftIt(r);
shiftIt(c);
//delay(5000);
digitalWrite(latchPin, HIGH);
  
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

