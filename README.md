# PID Car Balancer

## Project Overview

This project implements a **PID-based car balancing system**. The car is placed on a platform, and an ultrasonic sensor is used to measure the distance from the edge of the platform. A **servo motor** adjusts the tilt of the platform to keep the car at a constant distance of **15 cm** from the edge, ensuring stability as the car moves.

The project demonstrates how PID control can be used for balancing systems, with a simple platform to control the tilt and balance of the toy car.

![WhatsApp Image 2025-03-21 at 18 23 52](https://github.com/user-attachments/assets/2614d42c-755f-4cfc-9310-2509881cf0b1) 
![WhatsApp Image 2025-03-21 at 18 23 53](https://github.com/user-attachments/assets/2affc16a-a992-4b5a-892e-fb515b399dd7)

## Components Used

- **Arduino Uno**: The microcontroller that controls the servo motor.
- **Servo Motor**: To tilt the platform and maintain balance.
- **Ultrasonic Sensor (HC-SR04)**: To measure the distance from the car to the edge of the platform.
- **Breadboard and Jumper Wires**: For connections.

## How It Works

1. The **ultrasonic sensor** continuously measures the distance from the car to the edge of the platform.
2. The **PID controller** computes the error between the target distance (15 cm) and the actual measured distance.
3. The **servo motor** adjusts the platform's tilt to bring the car back to the desired position based on the error.
4. The process is repeated in real-time to keep the car balanced at a constant distance from the edge.

## Setup Instructions

1. **Connect the Ultrasonic Sensor**:
   - **VCC** to 5V on the Arduino
   - **GND** to GND on the Arduino
   - **Trigger Pin** to Pin 9 on the Arduino
   - **Echo Pin** to Pin 10 on the Arduino

2. **Connect the Servo Motor**:
   - **VCC** to 5V on the Arduino
   - **GND** to GND on the Arduino
   - **Signal Pin** to Pin 11 on the Arduino
  
## Video Demonstration

Here is a demonstration of the project in action:
Car Balancing Project Video
https://www.linkedin.com/posts/shahazad-abdulla_srishti-pidalgorithm-engineeringinnovation-activity-7168497967065157632-VOMA?utm_source=share&utm_medium=member_android&rcm=ACoAAER34FQBdwFCSpmNsSPj2jwqpQEQoBgFWnM

## How to Run the Project

    Clone the repository to your local machine.
    Upload the code to your Arduino using the Arduino IDE.
    Connect the components as per the wiring diagram above.
    Open the serial monitor to see the distance readings and observe how the PID controller adjusts the servo motor to balance the car.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

