int trig=10,echo=11;
int trig2=12,echo2=13;
int trig3=3,echo3=4;
int m1=5,m2=6,m3=7,m4=8;
float dist,pingtime,s=13397.2441;
float dist2,pingtime2,s2=13397.2441;
float dist3,pingtime3,s3=13397.2441;
int led=2,led2=9;


void setup() {
  // put your setup code here, to run once:
  
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(trig3,OUTPUT);
  pinMode(echo3,INPUT);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);

  
}void loop() {
  // put your main code here, to run re
  
digitalWrite(trig,LOW);
delayMicroseconds(3000);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
pingtime=pulseIn(echo,HIGH);
pingtime=pingtime/1000000;
dist=pingtime*s;
dist=dist/2;


digitalWrite(trig2,LOW);
delayMicroseconds(3000);
digitalWrite(trig2,HIGH);
delayMicroseconds(10);
digitalWrite(trig2,LOW);
pingtime2=pulseIn(echo2,HIGH);
pingtime2=pingtime2/1000000;
dist2=pingtime2*s2;
dist2=dist2/2;

digitalWrite(trig3,LOW);
delayMicroseconds(3000);
digitalWrite(trig3,HIGH);
delayMicroseconds(10);
digitalWrite(trig3,LOW);
pingtime3=pulseIn(echo3,HIGH);
pingtime3=pingtime3/1000000;
dist3=pingtime3*s3;
dist3=dist3/2;


 digitalWrite(m1,HIGH);
  digitalWrite(m2,LOW);
   digitalWrite(m4,LOW);
    digitalWrite(m3,HIGH);
digitalWrite(led,LOW);
digitalWrite(led2,LOW);

    if(dist<=5)
    {
      digitalWrite(m2,LOW);
  digitalWrite(m1,HIGH);
   digitalWrite(m3,LOW);
    digitalWrite(m4,HIGH);
    delay(400);
    }

 if(dist2<=5)
    {
      digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
   digitalWrite(m4,LOW);
    digitalWrite(m3,HIGH);
    delay(400);
    digitalWrite(led,HIGH);
    }
    if(dist3<=5)
    {
      digitalWrite(m2,LOW);
  digitalWrite(m1,HIGH);
   digitalWrite(m3,LOW);
    digitalWrite(m4,HIGH);
    delay(200);
    digitalWrite(led2,HIGH);
    }
      
    }
 


