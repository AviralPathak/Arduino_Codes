#include<Servo.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(10,9,5,4,3,6);

int servo=8,buzz=7;
int trig=12,echo=11;
float pingtime,dist,s=13397.244,i,d=50.0;
Servo pointer;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzz,OUTPUT);
  pointer.attach(servo);

}

void loop() {
  // ultrasonic:



//Servo motor motion
for(i=0;i<180;i=i+5)
{
  digitalWrite(trig,LOW);
delayMicroseconds(3000);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
pingtime=pulseIn(echo,HIGH);
pingtime=pingtime/1000000;
dist=pingtime*s;
dist=dist/2;

  pointer.write(i);
  delay(50);
lcd.setCursor(0,0);
lcd.print("OBJECT"); 
 Serial.println(dist);
 if(dist<=5)
{ digitalWrite(buzz,HIGH);
 lcd.setCursor(0,1);
 lcd.print("Too close");
  delay(d);
 lcd.clear();
  }
  else
  {
    digitalWrite(buzz,LOW);
  }
  if(5<dist&&dist<=10)
  { lcd.setCursor(0,1);
    lcd.print("Midway");
     delay(d);
    lcd.clear();
  }
  if(dist>10)
  { lcd.setCursor(0,1);
    lcd.print("Far away");
    delay(d);
    lcd.clear();
  }
  
}
for(i=180;i>=0;i=i-5)
{ digitalWrite(trig,LOW);
delayMicroseconds(3000);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
pingtime=pulseIn(echo,HIGH);
pingtime=pingtime/1000000;
dist=pingtime*s;
dist=dist/2;

  pointer.write(i);
  delay(50);

  Serial.println(dist);
lcd.setCursor(0,0);
lcd.print("OBJECT") ;
 Serial.println(dist);
 if(dist<=5)
{ digitalWrite(buzz,HIGH);
 lcd.setCursor(0,1);
 lcd.print("Too close");
  delay(d);
 lcd.clear();
  }
  else
  {
    digitalWrite(buzz,LOW);
  }
  if(5<dist&&dist<=10)
  { lcd.setCursor(0,1);
    lcd.print("Midway");
     delay(d);
    lcd.clear();
  }
  if(dist>10)
  { lcd.setCursor(0,1);
    lcd.print("Far away");
     delay(d);
    lcd.clear();}
}}

