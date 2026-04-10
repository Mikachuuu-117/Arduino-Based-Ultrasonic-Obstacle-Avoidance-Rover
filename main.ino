#include <Servo.h> //implementing the servo library

// I need to define the motor pins
#define ENA 5   // Left Motor Speed
#define IN1 4   // Left Motor Control 1
#define IN2 3   // Left Motor Control 2
#define ENB 6   // Right Motor Speed
#define IN3 2   // Right Motor Control 1
#define IN4 7   // Right Motor Control 2

// Defining Ultrasonic Sensor Pins
#define TRIG_PIN 9
#define ECHO_PIN 8

// Defining Servo Pin
#define SERVO_PIN 10
Servo Servo;

void setup() {

    // Motor control pins
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    // Ultrasonic sensor pins
    pinMode(TRIG_PIN, OUTPUT); //pulse sending pin
    pinMode(ECHO_PIN, INPUT);  //pulse recieving pin

    // Attach servo
    Servo.attach(SERVO_PIN);
    Servo.write(90);  // Sets the starting position of the Ultrasound module to face the front

    // Set motor speeds
    analogWrite(ENA, 200);
    analogWrite(ENB, 200);
}

// function for moving the car forward
void moveForward() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

// function for moving the car backward
void moveBackward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

// Function to stop the motors
void stopMotors() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

// Function to turn left
void turnLeft() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(500);
    stopMotors();
}

// Function to turn right
void turnRight() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(500);
    stopMotors();
}

// Function to measure the distance from object
int getDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);  //sends out a pulse
    delayMicroseconds(10);         //for 10 micro seconds
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);     //measures the time for echo to return
    int distance = duration * 0.034 / 2; // Converting time to distance in cm. speed of sound = 340 m/s 
    return distance;
}



void loop() {
    int distance = getDistance();  //gets the distance of an obstical    

    if (distance > 20 || distance == 0) {   //if the obstical is far away or there isnt one then move forward
        moveForward();
    } else {                                //otherwise stop
        stopMotors();
        delay(500);

        // scan left and right
        Servo.write(0);
        delay(500);
        int leftDist = getDistance();

        Servo.write(180);
        delay(500);
        int rightDist = getDistance();

        Servo.write(90);  // Reset to the center

        if (leftDist > rightDist) {     //Turn whichever direction has more space
            turnLeft();
        } else {
            turnRight();
        }
    }
}
