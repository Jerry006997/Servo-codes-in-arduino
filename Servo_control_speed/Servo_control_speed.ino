#include <Servo.h> // includes the servo library
Servo myServo; // makes myServo as the servo name
int servoPin = 9; // store pin number 9 in a variable called servoPin
int servoAngle = 0; // makes the variable name servoAngle set to 0
unsigned long currentTime = 0; // variable to store the current time in milliseconds (from millis()).
unsigned long previousMillis = 0; // stores the last time the servo was updated
unsigned long interval = 30; // sets the variable name interval to 30 milliseconds to tell the servo when to step to next postion
int stepSize = 10; // degrees the servo moves each update (every interval)
void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin); // attach the servo object to pin 9 so Arduino can control it.
}

void loop() {
  // put your main code here, to run repeatedly
  currentTime = millis(); // store the current time (in ms since Arduino started).
  if (currentTime - previousMillis >= interval) { // check if enough time has passed (interval ms) since the last servo update
    previousMillis = currentTime; // previousMillis = currentTime
    servoAngle += stepSize; // servoAngle = servoAngle + stepSize 
    if (servoAngle >= 180 || servoAngle <= 0) { // if servoAngle greaterthan or equal to 180 degrees or if servoAngle lessthan or equal to 0 degrees
    stepSize = -stepSize; // stepSize = -stepSize
    }
  myServo.write(servoAngle); // move the servo to the current angle.
  }
}   
  
