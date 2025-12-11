// Created by Jeriah Koenig
#include <Servo.h> // tells arduino to include Servo library

Servo myServo; // sets myServo as your object
int servoPin = 9;  // sets pin nine as the name servoPin
int servoAngle = 90; // starts the servo at 90 degrees
 
void setup() { // runs once
  Serial.begin(9600); // begins the Serial monitor at 9600 baud
  myServo.attach(servoPin); // attaches the pin 9 to the servo
  myServo.write(servoAngle); // tells the servo to move to 90 degrees
}

void loop() { // runs forever
  if (Serial.available() > 0) { // checks the serial monitor 
    String input = Serial.readStringUntil('\n'); // read until Enter
    input.trim();                                // remove spaces/newlines
    int angle = input.toInt();                   // convert to integer

    if (angle >= 0 && angle <= 180) { // only reads angles that are between 0 and 180
      servoAngle = angle; // sets servoAngle to equal angle
      myServo.write(servoAngle); // tells the servo to move to the servoAngle which is now the angle
      Serial.print("Servo set to: "); // prints in the serial monitor Servo set to
      Serial.println(servoAngle); // Writes in front of Servo set to the servo angle then moves to a new line
    } else { // if none of that happend do whats in the else
      Serial.println("Angle out of range (0–180)"); // print Angle out of range (0-180) then moves to new line
    }
  }
}
