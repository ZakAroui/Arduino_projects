int ledpin = 9;
int piezopin = 5;
int threshold = 120;
int sensorvalue = 0;
float ledvalue = 0;

void setup()
{
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, HIGH); delay(150); digitalWrite(ledpin, LOW); delay(150);
  digitalWrite(ledpin, HIGH); delay(150); digitalWrite(ledpin, LOW); delay(150);
}

void loop()
{
  sensorvalue = analogRead(piezopin);
  if (sensorvalue >= threshold)
  {
    ledvalue = 255;
  }
  analogWrite(ledpin, int(ledvalue) );
  ledvalue = ledvalue - 0.05;
  if (ledvalue <= 0)
  {
    ledvalue = 0;
  }
}
