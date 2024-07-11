// Define the pins for the motors and sensors
int leftMotorInput1 = 2;
int leftMotorInput2 = 3;
int rightMotorInput1 = 4;
int rightMotorInput2 = 5;
// Set the motor speeds
int motorSpeed = 255;
void setup() {
 // Define the motor pins as outputs
 pinMode(leftMotorInput1, OUTPUT);
 pinMode(leftMotorInput2, OUTPUT);
 pinMode(rightMotorInput1, OUTPUT);
 pinMode(rightMotorInput2, OUTPUT);
 // Move forward
 digitalWrite(leftMotorInput1, HIGH);
 digitalWrite(leftMotorInput2, LOW);
 digitalWrite(rightMotorInput1, HIGH);
 digitalWrite(rightMotorInput2, LOW);
 } 
 // Turn left
 digitalWrite(leftMotorInput1, LOW);
 digitalWrite(leftMotorInput2, HIGH);
 digitalWrite(rightMotorInput1, HIGH);
 digitalWrite(rightMotorInput2, LOW);
 } 
 // Turn right
 digitalWrite(leftMotorInput1, HIGH);
 digitalWrite(leftMotorInput2, LOW);
 digitalWrite(rightMotorInput1, LOW);
 digitalWrite(rightMotorInput2, HIGH);
 } 
else {
 // Stop and wait
 digitalWrite(leftMotorInput1, LOW);
 digitalWrite(leftMotorInput2, LOW);
 digitalWrite(rightMotorInput1, LOW);
 digitalWrite(rightMotorInput2, LOW);
 delay(1000); // Wait for 1 second
 }
}
#include <AFMotor.h> // Include motor library
AF_DCMotor motor1(1); // Create motor object for channel 1
AF_DCMotor motor2(2); // Create motor object for channel 2
void setup() {
 // Setup serial communication (optional)
 Serial.begin(9600);
 // Set motor speed
 motor1.setSpeed(200);
 motor2.setSpeed(200);
 // Set motor direction (forward)
 motor1.run(FORWARD);
 motor2.run(FORWARD);
}
void loop() {
 // Move forward
 moveForward();
 // Turn left
 turn("left");
 // Move backward
 moveBackward();
 // Turn right
 turn("right");
}
void moveForward() {
 // Set motor direction (forward)
 motor1.run(FORWARD);
 motor2.run(FORWARD);
 // Increase motor speed gradually
 for (int i = 0; i <= 200; i++) {
 motor1.setSpeed(i);
 motor2.setSpeed(i);
 delay(10);
 }
 // Print message (optional)
 Serial.println("Moving forward");
}
void moveBackward() {
 // Set motor direction (backward)
 motor1.run(BACKWARD);
 motor2.run(BACKWARD);
 // Decrease motor speed gradually
 for (int i = 200; i >= 0; i--) {
 motor1.setSpeed(i);
 motor2.setSpeed(i);
 delay(10);
 }
 // Print message (optional)
 Serial.println("Moving backward");
}