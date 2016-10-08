int piezopin = 8;
int ldrpin = 0;
int ldrvalue = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  ldrvalue = analogRead(ldrpin);
  Serial.println(ldrvalue);
  tone(piezopin, 1500);
  delay(250);
  noTone(piezopin);
  delay(ldrvalue);
}
