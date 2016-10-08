float sinval;
int toneval;

void setup()
{
  pinMode(8, OUTPUT);
}
void loop()
{
  for (int x; x<180; x++)
  {
    sinval = (sin(x*(3.1412/180)));
    toneval = 2000 + (int(sinval*1000));
    tone(8, toneval);
    delay(10);
  }
}
