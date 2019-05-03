int m1=3,m2=5,m3=6,m4=9;
void setup() {
  // put your setup code here, to run once:
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
   while(Serial.available())
  {
    char In=Serial.read();
    
    if(In=='f' || In=='F')     // Forward
    {
      digitalWrite(m1,HIGH);
      digitalWrite(m2,LOW);
      digitalWrite(m3,HIGH);
      digitalWrite(m4,LOW);
    }

  else if(In=='b' || In=='B')     // Backward
    {
      digitalWrite(m2,HIGH);
      digitalWrite(m1,LOW);
      digitalWrite(m4,HIGH);
      digitalWrite(m3,LOW);
    }

   else if(In=='r' || In=='R')     // to turn right
    {
      digitalWrite(m1,HIGH);
      digitalWrite(m2,LOW);
      digitalWrite(m4,HIGH);
      digitalWrite(m3,LOW);
    }

  else if(In=='l' || In=='L')     // to tun left
    {
      digitalWrite(m2,HIGH);
      digitalWrite(m1,LOW);
      digitalWrite(m3,HIGH);
      digitalWrite(m4,LOW);
    }

 else if(In=='s' || In=='S')     // Stop
    {
      digitalWrite(m1,LOW);
      digitalWrite(m2,LOW);
      digitalWrite(m3,LOW);
      digitalWrite(m4,LOW);
    }
 else
    {
      
    }
  }
}


