int ledpin1 = 9;
int ledpin2 = 10;
int ledpin3 = 11;

void setup()
{
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(ledpin3, OUTPUT);
}

void loop()
{
  analogWrite(ledpin1, random(120)+135);
  analogWrite(ledpin2, random(120)+135);
  analogWrite(ledpin3, random(120)+135);
  delay(random(100));
}
