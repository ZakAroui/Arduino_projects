char buffer[18];
int red, green, blue;

int redpin = 11;
int greenpin = 10;
int bluepin = 9;

void setup()
{
  Serial.begin(9600);
  Serial.flush();
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
}

void loop()
{
  if (Serial.available() > 0)
  {
    int index=0;
    delay(100);
    int numchar = Serial.available();
    if (numchar>15)
    {
      numchar=15;
    }
    while (numchar--)
    {
      buffer[index++] = Serial.read();
    }
    splitString(buffer);
  }
}

void splitString(char* data)
{ 
  Serial.print("data entered: ");
  Serial.println(data);
  char* parameter;
  parameter = strtok (data, " ,");
  while (parameter != NULL)
  {
    setled(parameter);
    parameter = strtok (NULL, " ,");
  }
  for (int x=0; x<16; x++)
  {
    buffer[x]='\0';
  }
  Serial.flush();
}

void setled(char* data)
{
  if ((data[0] == 'r') || (data[0] == 'R'))
  {
    int Ans = strtol(data+1, NULL, 10);
    Ans = constrain(Ans, 0, 255);
    analogWrite(redpin,Ans);
    Serial.print("red is set to: ");
    Serial.println(Ans);
  }
  if ((data[0] == 'g') || (data[0] == 'G'))
  {
    int Ans = strtol(data+1, NULL, 10);
    Ans = constrain(Ans, 0, 255);
    analogWrite(greenpin,Ans);
    Serial.print("green is set to: ");
    Serial.println(Ans);
  }
  if ((data[0] == 'b') || (data[0] == 'B'))
  {
    int Ans = strtol(data+1, NULL, 10);
    Ans = constrain(Ans, 0, 255);
    analogWrite(bluepin,Ans);
    Serial.print("blue is set to: ");
    Serial.println(Ans);
  }
}
