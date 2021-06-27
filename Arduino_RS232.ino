#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);

  pinMode(13,OUTPUT);
}
String cmd="";
void loop() // run over and over
{
  if (mySerial.available())
  {
    char recive = mySerial.read();
      Serial.write(Serial.read());
    if(recive=='\n')
    {
       if(cmd.equals("HIGH"))
        digitalWrite(13,HIGH);
       else if(cmd.equals("LOW"))
        digitalWrite(13,LOW);
       
       cmd="";
    }
    else
      cmd+=recive;
  }
  if (Serial.available())
    mySerial.write(Serial.read());
}
