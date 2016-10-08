byte ledPin[] = {4, 5, 6, 7, 8, 9, 10};
int ledDelay;
int directiont = 1;
int currentLED = 0;
unsigned long changeTime;
int potpin = 2;

void setup() 
{
  pinMode(2, OUTPUT);
  for (int x=0; x<10; x++)
  {
    pinMode(ledPin[x], OUTPUT); }
    changeTime = millis();
}
void loop()
{ 
  ledDelay = analogRead(potpin);
  if ((millis() - changeTime) > ledDelay)
  {
    changeLED();
    buzzer();
    changeTime = millis();
    
  }
}
void changeLED()
{
  for (int x=0; x<10; x++)
  {
    digitalWrite(ledPin[x], LOW);
    digitalWrite(2, LOW);
  }
  
  digitalWrite(ledPin[currentLED], HIGH);
  currentLED += directiont;
  if (currentLED == 6) {directiont = -1;}
  if (currentLED == 0) {directiont = 1;}
}
void buzzer()
{
   digitalWrite(2, HIGH);
   delay(ledDelay);
   digitalWrite(2, LOW);
}
