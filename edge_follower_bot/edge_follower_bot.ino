int trig=10,echo=11;
int trig2=12,echo2=8;
int trig3=4,echo3=7;
int m1=5,m2=6,m3=3,m4=9;
float dist,pingtime,s=13397.2441;
float dist2,pingtime2,s2=13397.2441;
float dist3,pingtime3,s3=13397.2441;

int d=200;




void setup() {
  // put your setup code here, to run once:
  
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(trig3,OUTPUT);
  pinMode(echo3,INPUT);
  
Serial.begin(9600);
  
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  
  
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

analogWrite(m1,d);
  analogWrite(m2,0);
   analogWrite(m4,d);
    analogWrite(m3,0);




Serial.println(dist);
 
if(dist>8)
{
  analogWrite(m1,d);
  analogWrite(m2,0);
   analogWrite(m4,0);
    analogWrite(m3,d);

}
    /*   {if(dist2>8)
           {
               analogWrite(m2,0);
                   analogWrite(m1,d);
                 analogWrite(m3,d);
                    analogWrite(m4,0);
    
                       }*/
           
            if(dist2>8)
                {
                  analogWrite(m2,0);
                   analogWrite(m1,d);
                 analogWrite(m3,d);
                    analogWrite(m4,0);
                   
                  
                
                }
               
             if(dist3<8)
                {
              analogWrite(m2,d);
               analogWrite(m1,0);
              analogWrite(m3,0);
            analogWrite(m4,d);
 }      
 if(dist>8&&dist3<8)
 {
  analogWrite(m1,d);
  analogWrite(m2,0);
   analogWrite(m4,0);
    analogWrite(m3,d);

}
}
                                 
      
    
        
 


