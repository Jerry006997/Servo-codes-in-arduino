#include <Servo.h> // include Servo library
int servoPin = 9; // set pin 9 as the varible name servoPin
int servoAngle = 0; // variable to store servo position
Servo servo; // create servo object

void setup() {
  // put your setup code here, to run once:
  servo.attach(servoPin); // attach servo to pin 9
}

void loop() {
  // put your main code here, to run repeatedly:
  for (servoAngle = 0; servoAngle <= 180; servoAngle += 3) { // sweep from 0 to 180
    servo.write(servoAngle); // write the servo to servoAngle
    delay(15); // wait for servo to reach 
  }
  for (servoAngle = 180; servoAngle >= 0; servoAngle -= 3) { // sweep back to 180 to 0
    servo.write(servoAngle); // write servo to servoAngle
    delay(15); // wait for servo to reach
  }
}
