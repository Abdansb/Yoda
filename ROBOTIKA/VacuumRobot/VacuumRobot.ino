#include <Servo.h>         
#include <NewPing.h>   
#include <SoftwareSerial.h>

// BT init
SoftwareSerial softSerial(0, 1); // RX on Pin 8, TX on Pin 9 (Change these as required!)

int update_interval=100; // time interval in ms for updating panel indicators 
unsigned long last_time=0; // time of last update
char data_in; // data received from serial link

//L298N 
const int LeftMotorForward = 11;
const int LeftMotorBackward = 12;
const int RightMotorForward = 10;
const int RightMotorBackward = 13;

const int BTState = 2; //STATE pin of Bluetooth (when bluetooth not connected it is LOW)
const int buzz = 4;
const int led = 6;

//sensor pin
#define trig_pin 7 //data pin ultra
#define echo_pin 7 //data pin ultra
#define maximum_distance 250
boolean goesForward = false;
int distance = 150;

NewPing sonar(trig_pin, echo_pin, maximum_distance); 
Servo servo_motor; //servo

void setup(){

  Serial.begin(9600);
  softSerial.begin(9600);

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(BTState, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(buzz, HIGH);
  delay(100);
  digitalWrite(buzz, LOW);

  servo_motor.attach(9); //servo pin

  servo_motor.write(115);
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

void loop(){
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (digitalRead(BTState) == LOW)
  {
  /////////////Autonomous MODE///////////////
    if (distance <= 20){
      moveStop();
      delay(300);
      moveBackward();
      delay(400);
      moveStop();
      delay(300);
      distanceRight = lookRight();
      delay(300);
      distanceLeft = lookLeft();
      delay(300);

      if (distance >= distanceLeft){
        turnRight();
        moveStop();
      }
      else{
        turnLeft();
        moveStop();
      }
      }
      else{
        moveForward(); 
      }
  }else
{
  
  ////////////////////////BT MODE////////////////////////////
  if (softSerial.available()){
    data_in=softSerial.read();  //Get next character 

    if(data_in=='Q'){ //Button Pressed
      digitalWrite(RightMotorForward, HIGH);
      
    }
    if(data_in=='q'){ // Button Released 
      digitalWrite(RightMotorForward, LOW);
    }

    if(data_in=='A'){ //Button Pressed
      digitalWrite(LeftMotorForward, HIGH);
      digitalWrite(RightMotorBackward, HIGH); 
    }
    if(data_in=='a'){ // Button Released 
      digitalWrite(LeftMotorForward, LOW);
      digitalWrite(RightMotorBackward, LOW);
    }

    if(data_in=='P'){ //Button Pressed
      digitalWrite(LeftMotorForward, HIGH);
    }
    if(data_in=='p'){ // Button Released 
      digitalWrite(LeftMotorForward, LOW);
    }

    if(data_in=='L'){ //Button Pressed
      digitalWrite(LeftMotorBackward, HIGH);
      digitalWrite(RightMotorForward, HIGH);
    }
    if(data_in=='l'){ // Button Released 
      digitalWrite(LeftMotorBackward, LOW);
      digitalWrite(RightMotorForward, LOW);
    }

    if(data_in=='B'){ //Button Pressed
      digitalWrite(buzz, HIGH); 
    }
    if(data_in=='b'){ // Button Released 
      digitalWrite(buzz, LOW); 
    }

    if(data_in=='E'){ //Button Pressed
      servo_motor.write(170);

    }
    if(data_in=='e'){ // Button Released 
      servo_motor.write(115); 
    }
    if(data_in=='F'){ //Button Pressed
      servo_motor.write(50);;

    }
    if(data_in=='f'){ // Button Released 
      servo_motor.write(115); 
    }
    if(data_in=='C'){ //Button Pressed
      digitalWrite(led, HIGH);

    }
    if(data_in=='c'){ // Button Released 
      digitalWrite(led, LOW); 
    }
  
    }
   }distance = readPing();
 }
 



int lookRight(){  
  servo_motor.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
}

int lookLeft(){
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){

  if(!goesForward){

    Serial.println("==moveForward==");

    goesForward=true;
    
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
  }
}

void moveBackward(){

  goesForward=false;

  Serial.println("==moveBackward==");

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
}

void turnRight(){

  Serial.println("==turnRight==");
  digitalWrite(buzz, HIGH);
    delay(100);
  digitalWrite(buzz, LOW);
  delay(30);
  digitalWrite(buzz, HIGH);
    delay(100);
  digitalWrite(buzz, LOW);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
 
  
  
}

void turnLeft(){

  Serial.println("==turnLeft==");
  digitalWrite(buzz, HIGH);
    delay(100);
  digitalWrite(buzz, LOW);
  delay(30);
  digitalWrite(buzz, HIGH);
    delay(100);
  digitalWrite(buzz, LOW);

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}