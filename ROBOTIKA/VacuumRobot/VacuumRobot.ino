/*
*  Arduino Vacuum Cleaner Robot
* Abdan Subekti
*/
#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>

// Alokasi Pin
#define TriggerPin 8
#define EchoPin 9
#define JarakMaks 200
#define Speed 190

// Deklarasi Sensor & Motor
Servo HitecServo;
NewPing ultrasonic(TriggerPin, EchoPin, JarakMaks);

AF_DCMotor motor1(10, MOTOR12_1KHZ);
AF_DCMotor motor2(11, MOTOR12_1KHZ);

boolean goesForward=false;
int distance = 100;
int speedSet = 0;

void setup() {
  // Pin Servo  
  HitecServo.attach(9);  
  HitecServo.write(115); 
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
 int distanceR = 0;
 int distanceL =  0;
 delay(40);
 
 if(distance<=15)
 {
  moveStop();
  delay(100);
  moveBackward();
  delay(300);
  moveStop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR>=distanceL)
  {
    turnRight();
    moveStop();
  }else
  {
    turnLeft();
    moveStop();
  }
 }else
 {
  moveForward();
 }
 distance = readPing();
}

int lookRight()
{
    HitecServo.write(50); 
    delay(500);
    int distance = readPing();
    delay(100);
    HitecServo.write(115); 
    return distance;
}

int lookLeft()
{
    HitecServo.write(170); 
    delay(500);
    int distance = readPing();
    delay(100);
    HitecServo.write(115); 
    return distance;
    delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

void moveStop() {
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  } 
  
void moveForward() {

 if(!goesForward)
  {
    goesForward=true;
    motor1.run(FORWARD);      
    motor2.run(FORWARD);
    motor3.run(FORWARD); 
    motor4.run(FORWARD);     
   for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
   {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
   }
  }
}

void moveBackward() {
    goesForward=false;
    motor1.run(BACKWARD);      
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);  
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
  }
}  

void turnRight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);     
  delay(500);
  motor1.run(FORWARD);      
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);      
} 
 
void turnLeft() {
  motor1.run(BACKWARD);     
  motor2.run(BACKWARD);  
  motor3.run(FORWARD);
  motor4.run(FORWARD);   
  delay(500);
  motor1.run(FORWARD);     
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}














/*
int pwmA = 10;
int pwmB = 11;
int enA = 12;
int enB = 13;
int buz = 4;
void setup() {
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(buz, OUTPUT);
}
void loop() {
  for (int x = 50; x < 200; x++) {
    digitalWrite(enA, HIGH);
    digitalWrite(enB, HIGH);
    analogWrite(pwmA, x);
    analogWrite(pwmB, x);
    delay(10);
  }
  for (int y = 200; y > 50; y--) {
    digitalWrite(enA, HIGH);
    digitalWrite(enB, HIGH);
    digitalWrite(buz, HIGH);
    analogWrite(pwmA, y);
    analogWrite(pwmB, y);
    delay(1);
  }
  digitalWrite(buz, LOW);
  delay(1000);
}
*/