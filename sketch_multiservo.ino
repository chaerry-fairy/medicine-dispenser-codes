#include <Servo.h>

// Create servo objects
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

// Set the servo pins
int servoPin1 = 3;
int servoPin2 = 5;
int servoPin3 = 6;
int servoPin4 = 9;
int servoPin5 = 10;


// Set the initial position and target position for each servo
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;
int pos5 = 0;
int targetPos = 360; // Rotate 180 degrees for each servo

// Set the delay time for each step (adjust to control the speed)
int delayTime = 10000;

void setup() {
  // Attach the servos to their respective pins
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  servo5.attach(servoPin5);
}

void loop() {
  // Rotate the servos 3 times in one direction
  for (int i = 0; i < 3; i++) {
    // Move all servos to their target position simultaneously
    while (pos1 < targetPos && pos2 < targetPos && pos3 < targetPos && pos4 < targetPos) {
      servo1.write(pos1);
      servo2.write(pos2);
      servo3.write(pos3);
      servo4.write(pos4);
      servo5.write(pos5);
      delay(delayTime);
      pos1++;
      pos2++;
      pos3++;
      pos4++;
      pos5++;
    }

    // Reset the position of the servos
    pos1 = 0;
    pos2 = 0;
    pos3 = 0;
    pos4 = 0;
    pos5 = 0;
  }
}