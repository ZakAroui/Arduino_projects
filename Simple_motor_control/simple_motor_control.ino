int potpin = 0;
int transistorpin = 9;
int potvalue = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(transistorpin, OUTPUT);
}

void loop()
{
  potvalue = analogRead(potpin)/4;
  Serial.println(potvalue);
  analogWrite(transistorpin, potvalue);
}
