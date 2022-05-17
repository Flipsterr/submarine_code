
#include <Servo.h>
Servo myservo;

int val;

void setup() {
// servo
  myservo.attach(5);

//Activation
  pinMode(7, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);

//Motor 1
  pinMode(01, INPUT_PULLUP); 
  pinMode(02, INPUT_PULLUP);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

//Motor 2
  pinMode(03, INPUT_PULLUP); 
  pinMode(04, INPUT_PULLUP); 
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}



void loop() {
  
//Motor 1
  if (digitalRead(01) == LOW){
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
  }

  if (digitalRead(02) == LOW){
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
  }

   if (digitalRead(01) == HIGH && digitalRead(02) == HIGH){
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  }

//Motor 2
  if (digitalRead(03) == LOW){
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
  }

  if (digitalRead(04) == LOW){
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
  }

   if (digitalRead(03) == HIGH && digitalRead(04) == HIGH){
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }

  //Activation
 digitalWrite(13, HIGH);
 
//Servo
  val = analogRead(1);
  val = map(val, 0, 1023, 0, 180);
  myservo.write(val); 
  
  delay(15);


  
}
