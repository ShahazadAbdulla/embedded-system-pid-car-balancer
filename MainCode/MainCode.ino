#include <Servo.h>

// Define pins
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 11;

// Servo setup
Servo myServo;
int servoAngle = 90;  // Initial position of the servo (center)

// PID constants
float Kp = 1.0;   // Proportional constant
float Ki = 0.0;   // Integral constant
float Kd = 0.0;   // Derivative constant

float previousError = 0;
float integral = 0;
float setPoint = 15.0;  // Target distance (in cm)

void setup() {
  Serial.begin(9600);
  
  // Set up the ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Attach the servo
  myServo.attach(servoPin);
  myServo.write(servoAngle);  // Initial position

  delay(1000); // Wait for the servo to move to initial position
}

void loop() {
  // Read the distance from the ultrasonic sensor
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;  // Calculate distance in cm

  // Print distance for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Calculate the error
  float error = setPoint - distance;

  // PID calculations
  integral += error;   // Accumulate the sum of errors
  float derivative = error - previousError;  // Difference between current and previous error
  float output = Kp * error + Ki * integral + Kd * derivative;

  // Calculate the new servo angle
  servoAngle = constrain(servoAngle + output, 0, 180); // Limit servo angle to between 0 and 180 degrees

  // Move the servo
  myServo.write(servoAngle);

  // Save error for next iteration
  previousError = error;

  // Wait before the next reading
  delay(100);
}
