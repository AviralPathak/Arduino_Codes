 #include<Servo.h>
int ldr1 = A0, ldr2 = A1, ldr3 = A2, ldr4 = A3;
int servo = 11;
int servo2 = 9;
float val1, val2;
float val3, val4;
int i,j;
Servo pointer2;
Servo pointer;


void setup() {
  // put your setup code here, to run once:
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pointer.attach(servo);
  pointer2.attach(servo2);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  val1 = analogRead(ldr1);
  val1 = map(val1, 0, 1023, 0, 180);

  val2 = analogRead(ldr2);
  val2 = map(val1, 0, 1023, 180, 0);

  val3 = analogRead(ldr3);
  val3 = map(val3, 0, 1023, 0, 180);

  val4 = analogRead(ldr4);
  val4 = map(val4, 0, 1023, 180, 0);

  Serial.print("ldr1=");
  Serial.println(val1);
  delay(500);
  Serial.print("ldr2=");
  Serial.println(val2);
  delay(500);


  Serial.print("ldr3=");
  Serial.println(val3);
  delay(500);
  Serial.print("ldr4=");
  Serial.println(val4);
  delay(500);

  if (val1 > val2 && val3 > val4)
  {
    
    
    pointer.write(val1);
    pointer2.write(val3);

  
  }
  else if (val1 > val2 && val4 > val3)
  {
    
    pointer.write(val1);
    pointer2.write(val4);
   
  }
  
  else if (val2 > val1 && val3 > val4)
  { 

      pointer.write(val2);
    
    pointer2.write(val3);
    

  }


  else if (val4 > val3 && val1 < val2)
  {
    
    pointer2.write(val4);
    pointer.write(val2);
    

  }


}

