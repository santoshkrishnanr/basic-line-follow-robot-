#include <Servo.h>
Servo leftServo;
Servo rightServo;

#define sensorPincent A2
#define sensorPinright A5
#define sensorPinleft A4



int rv = 0;  
int lv = 0;  
int cv = 0;  
int c=0;
int r=0;
int l=0;


void setup() {
  leftServo.attach(13);
  rightServo.attach(12);
  Serial.begin(9600);
}

void loop() {
//int c=0;
  cv = analogRead(sensorPincent);//b\w 0-170/170-600
  lv = analogRead(sensorPinright);//b\w 0-150/150-400
  rv = analogRead(sensorPinleft);//b\w 0-500/500-1023

  if(cv>200){c=0;}
  else{c=1;}

   if(lv>90){l=0;}
  else{l=1;}

   if(rv>500){r=0;}
  else{r=1;}

  if (( l == 0 && c ==1 && r==0)) {
    fwd();
  }

 if (( l == 1 && c ==1 && r==0)) {
    sright();
  }
 if (( l == 0 && c ==1 && r==1)) {
    sleft();
   
  }
 if (( l == 1 && c ==0 && r==0)) {
    sright();
    delay(3);
  }
  if (( l == 0 && c ==0 && r==1)) {
    sleft();
     delay(3);
  }
 if (( l == 0 && c ==0 && r==0)) {
    fwd();
  }
 if (( l == 1 && c ==1 && r==1)) {
    slowfwd();
   
    
  }


printoutput();
   
}


void left()
{ leftServo.writeMicroseconds(1500); // left
  rightServo.writeMicroseconds(1300);
  
}
void sleft()
{ leftServo.writeMicroseconds(1300); // right
  rightServo.writeMicroseconds(1300);
}

void sright()
{ leftServo.writeMicroseconds(1700); // right
  rightServo.writeMicroseconds(1700);
}
void right()
{ leftServo.writeMicroseconds(1700); // right
  rightServo.writeMicroseconds(1500);
}

void fwd()
{ leftServo.writeMicroseconds(1700); // front
  rightServo.writeMicroseconds(1300);
  
}
void slowleft()
{ leftServo.writeMicroseconds(1500); //  slowleft
  rightServo.writeMicroseconds(1475);
 
}
void slowright()
{ leftServo.writeMicroseconds(1525); // slowright
  rightServo.writeMicroseconds(1500);
 
}
void rew()
{ leftServo.writeMicroseconds(1300); // front
  rightServo.writeMicroseconds(1700);
  
  }

void slowfwd()
{ leftServo.writeMicroseconds(1515); // front
  rightServo.writeMicroseconds(1485);
  
  }

  void rotat()
{ leftServo.writeMicroseconds(1300); // front
  rightServo.writeMicroseconds(1300);
 
  }

 void halt()
{ leftServo.writeMicroseconds(1500); // front
  rightServo.writeMicroseconds(1500);
 
  }

void printoutput(){
  
    Serial.print(lv);
    Serial.print(l);
    
    Serial.print("\t ");
   Serial.print(cv);
    Serial.print(c);
    
    Serial.print("\t ");
  
    Serial.print(   rv);
    Serial.print(r);
    
    Serial.print("\t ");
    Serial.print("\n ");
    delay(2);}
