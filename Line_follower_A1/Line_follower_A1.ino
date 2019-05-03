int mot1=3;
int mot2=9;
int mot3=5;
int mot4=6;

int left_ir=10;
int right_ir=11;

int Left=0;
int Right=0;

void LEFT (void);
void RIGHT (void);
void STOP (void);

void setup()
{
  pinMode(mot1,OUTPUT);
  pinMode(mot2,OUTPUT);
  pinMode(mot3,OUTPUT);
  pinMode(mot4,OUTPUT);

  pinMode(left_ir,INPUT);
  pinMode(right_ir,INPUT);

  digitalWrite(left_ir,HIGH);
  digitalWrite(right_ir,HIGH);
  
  
}

void loop() 
{
 
analogWrite(mot1,200);
analogWrite(mot2,0);
analogWrite(mot3,200);
analogWrite(mot4,0);

while(1)
{
  Left=digitalRead(left_ir);
  Right=digitalRead(right_ir);
  
  if((Left==0 && Right==1)==1)
  LEFT();
  else if((Right==0 && Left==1)==1)
  RIGHT();
}
}
void  LEFT (void)
{
   analogWrite(mot3,0);
   analogWrite(mot4,30);
   
   
   while(Left==0)
   {
    Left=digitalRead(left_ir);
    Right=digitalRead(right_ir);
    if(Right==0)
    {
      int l=Left;
      int r=Right;
      STOP();
      while(((l==Left)&&(r==Right))==1)
      {
         Left=digitalRead(left_ir);
         Right=digitalRead(right_ir);
      }
    }
    analogWrite(mot1,200);
    analogWrite(mot2,0); 
   }
   analogWrite(mot3,200);
   analogWrite(mot4,0);
}

void RIGHT (void)
{
   analogWrite(mot1,0);
   analogWrite(mot2,30);

   while(Right==0)
   {
    Left=digitalRead(left_ir);
    Right=digitalRead(right_ir);
    if(Left==0)
    {
      int l=Left;
      int r=Right;
     STOP();
      while(((l==Left)&&(r==Right))==1)
      {
         Left=digitalRead(left_ir);
         Right=digitalRead(right_ir);
      }
    }
    analogWrite(mot3,200);
    analogWrite(mot4,0);
    }
   analogWrite(mot1,200);
   analogWrite(mot2,0);
}
void STOP (void)
{
analogWrite(mot1,0);
analogWrite(mot2,0);
analogWrite(mot3,0);
analogWrite(mot4,0);
  
}

