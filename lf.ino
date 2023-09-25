#define rin1 8                                                                                
#define rin2 12
#define lin3 11
#define lin4 13
#define re1 9
#define le2 10
int ms1 =100;
int ms2 =100;
int s1,s2,s3,s4,s5,s6;
int e;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(2,INPUT);
  pinMode(rin1, OUTPUT);
  pinMode(rin2, OUTPUT);
  pinMode(lin3, OUTPUT);
  pinMode(lin4, OUTPUT);
  pinMode(re1, OUTPUT); 
  pinMode(le2, OUTPUT);
   
}
void readsensor()
{
   s1 = digitalRead(3);  
 s2 = digitalRead(4);  
 s3 = digitalRead(5);  
 s4 = digitalRead(6);  
 s5 = digitalRead(7);  
 s6 = digitalRead(2);   


Serial.print(s1);  
Serial.print(" ");  
Serial.print(s2);  
Serial.print(" ");  
Serial.print(s3);  
Serial.print(" ");  
Serial.print(s4);  
Serial.print(" ");  
Serial.print(s5);  
Serial.print(" ");  
Serial.print(s6);  
Serial.print(" ");
 
 

Serial.println("");  
delay(100); 
}
void straight()
{
  analogWrite(re1, ms1); 
  analogWrite(le2, ms2); 
  digitalWrite(rin1, LOW);
  digitalWrite(rin2, HIGH);
  digitalWrite(lin3, HIGH);
  digitalWrite(lin4, LOW);
}

void stopm()
{
  analogWrite(re1, 0); 
  analogWrite(le2, 0); 
  digitalWrite(rin1, HIGH);
  digitalWrite(rin2, HIGH);
  digitalWrite(lin3, HIGH);
  digitalWrite(lin4, HIGH);
}
void sright()
{
  analogWrite(re1, ms1/2); 
  analogWrite(le2, ms2); 
  digitalWrite(rin1, HIGH);
  digitalWrite(rin2, LOW);
  digitalWrite(lin3, HIGH);
  digitalWrite(lin4, LOW);
}
void sleft()
{
  analogWrite(re1, ms1); 
  analogWrite(le2, ms2/2); 
  digitalWrite(rin1, HIGH);
  digitalWrite(rin2, LOW);
  digitalWrite(lin3, HIGH);
  digitalWrite(lin4, LOW);
}
void right()
{
  analogWrite(re1, ms1); 
  analogWrite(le2, ms2); 
  digitalWrite(rin1, LOW);
  digitalWrite(rin2, HIGH);
  digitalWrite(lin3, HIGH);
  digitalWrite(lin4, LOW);
}
void left()
{
  analogWrite(re1, ms1); 
  analogWrite(le2, ms2); 
  digitalWrite(rin1, HIGH);
  digitalWrite(rin2, LOW);
  digitalWrite(lin3, LOW);
  digitalWrite(lin4, HIGH);
}
void error()
{
  readsensor();
  if(s1==0&&s2==0&&s3==0&&s4==0&&s5==1&&s6==0)
  e=1;
  else if(s1==0&&s2==0&&s3==1&&s4==1&&s5==0&&s6==1)
  e=2;
  else if(s1==0&&s2==1&&s3==0&&s4==0&&s5==0&&s6==0)
  e=-1;
  else if(s1==1&&s2==0&&s3==0&&s4==0&&s5==0&&s6==0)
  e=-2;
  
  while(e!=0)
  {
    if(e<0)
    {
      sleft();
    }
    else if(e>0)
    {
      sright();
    }
    readsensor();
  } 
}
void loop() {
  // put your main code here, to run repeatedly:
  readsensor();
  if(s1==0&&s2==0&&s3==1&&s4==1&&s5==0&&s6==0)
    {
      straight();
      Serial.print("Straight");
    }

    else if(s1==0&&s2==0&&s3==1&&s4==1&&s5==1&&s6==1)
    {
      right();
      Serial.print("Right");
    }

    else if(s1==1&&s2==1&&s3==1&&s4==1&&s5==0&&s6==0)
    {
      left();
      Serial.print("Left");
    }

    else if(s1==1&&s2==1&&s3==1&&s4==1&&s5==1&&s6==1)
    {
      stopm();
      Serial.print("Stop");

    }
    else if(s1==0&&s2==0&&s3==0&&s4==0&&s5==1&&s6==0||s1==0&&s2==0&&s3==1&&s4==1&&s5==0&&s6==1||s1==0&&s2==1&&s3==0&&s4==0&&s5==0&&s6==0||s1==1&&s2==0&&s3==0&&s4==0&&s5==0&&s6==0)
    {Serial.print("Error");
    error();
    }
    
}
