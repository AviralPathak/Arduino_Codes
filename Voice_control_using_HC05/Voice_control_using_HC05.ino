#include <SoftwareSerial.h>
SoftwareSerial BT(2,3);
String voice;
int R=9,G=10,B=11;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(R,OUTPUT);
pinMode(G,OUTPUT);
pinMode(B,OUTPUT);

analogWrite(R,0);
analogWrite(G,0);
analogWrite(B,0);

}


void loop() {
  // put your main code here, to run repeatedly:
  while(SoftwareSerial.available())
  {
    delay(10);
    char c=SoftwareSerial.read();
    if(c=='#');
    {break;
    }
voice=voice+c;
}
if(voice.length()>0)
{
  Serial.println(voice);

  if(voice=="*RED")
  {
    analogWrite(R,255);
    analogWrite(G,0);
    analogWrite(B,0);
   }

else if(voice=="*GREEN")
{
  analogWrite(R,0);
    analogWrite(G,255);
    analogWrite(B,0);
}
else if (voice=="*BLUE")
{
  analogWrite(R,0);
    analogWrite(G,0);
    analogWrite(B,255);
}
else if(voice=="*RANDOM")
{
  analogWrite(R,255);
  delay(500);
  analogWrite(R,0);
  delay(500);
  analogWrite(G,255);
  delay(500);
  analogWrite(G,0);
  delay(500);
  analogWrite(B,255);
  delay(500);
  analogWrite(B,0);
  delay(500);
  
}
voice=="";
}
}

