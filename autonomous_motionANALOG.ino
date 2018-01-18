/*
 HC-SR04 Ping distance sensor:
 VCC to arduino 5v 
 GND to arduino GND
 Echo to Arduino pin 7 
 Trig to Arduino pin 8

 EchoLeft to Arduino pin 2
 Trig Left to Arduino pin 3

 EchoRight to Arduino pin 5
 Trig Right to Arduino pin 4
 This sketch originates from Virtualmix: http://goo.gl/kJ8Gl
 Has been modified by Winkle ink here: http://winkleink.blogspot.com.au/2012/05/arduino-hc-sr04-ultrasonic-distance.html
 And modified further by ScottC here: http://arduinobasics.blogspot.com.au/2012/11/arduinobasics-hc-sr04-ultrasonic-sensor.html
 on 10 Nov 2012.
 */
/*
 Further edited by AhmadC for Autonomous Motion
 */

const int LeftmotorPin1 = 12; // Assign Digital pin 12 of Arduino to Left Motor Pin1
const int LeftmotorPin2 = 11; // Assign Digital pin 11 of Arduino to Left Motor Pin2
const int RightmotorPin3 = 10; // Assign Digital pin 10 of Arduino to Right Motor Pin3
const int RightmotorPin4 = 9; // Assign Digital pin 9 of Arduino to Right Motor Pin4` 
#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED

#define echoPinLeft 2
#define trigPinLeft 3 

#define echoPinRight 5
#define trigPinRight 4

int maximumRange = 30; // Maximum range needed
int minimumRange = 10; // Minimum range needed
long durationFront, distanceFront; // Duration used to calculate distance
long durationLeft, distanceLeft; //Duration used to calculate left distance
long durationRight, distanceRight; //Distance used to calculate right distance

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);

  pinMode(trigPinLeft, OUTPUT);
 pinMode(echoPinLeft, INPUT);

  pinMode(trigPinRight, OUTPUT);
 pinMode(echoPinRight, INPUT);
 
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 durationFront = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distanceFront = (durationFront/2) / 29.1;




//Repeat the process for the Left Sensor
  digitalWrite(trigPinLeft, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPinLeft, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPinLeft, LOW);
 durationLeft = pulseIn(echoPinLeft, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distanceLeft = (durationLeft/2) / 29.1;


//Repeat the process for the Right Sensor
  digitalWrite(trigPinRight, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPinRight, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPinRight, LOW);
 durationRight = pulseIn(echoPinRight, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distanceRight = (durationRight/2) / 29.1;



//if there are no objects within 40cm, both motors will turn forward
 if (distanceFront > 40) {
  analogWrite(LeftmotorPin1, 0);//set leg 1 of the H-bridge low
  analogWrite(LeftmotorPin2, 177);//set leg 2 of the H-bridge high
  analogWrite(RightmotorPin3, 0);//set leg 1 of the H-bridge low
  analogWrite(RightmotorPin4, 255);//set leg 2 of the H-bridge high
 }
 
//if there is an object in the way, turn right by setting the left motor
//forward and stopping the right motor
 else if (distanceFront < 40 && distanceRight > distanceLeft){
  analogWrite(LeftmotorPin1, 0);//set leg 1 of the H-bridge low
  analogWrite(LeftmotorPin2, 255);//set leg 2 of the H-bridge high
  analogWrite(RightmotorPin3, 0);//set leg 1 of the H-bridge low
  analogWrite(RightmotorPin4, 0);//set leg 2 of the H-bridge LOW
 }

 else if (distanceFront < 40 && distanceRight < distanceLeft){
  analogWrite(LeftmotorPin1,0 );//Set leg 1 of the H-bridge low
  analogWrite(LeftmotorPin2,0 );//Set leg 2 of the H-bridge low
  analogWrite(RightmotorPin3,0 );//Set leg 1 of the H-bridge low
  analogWrite(RightmotorPin4, 255);//Set leg 2 of the H-bridge high
 }

 else if (distanceFront < 40 && distanceLeft == distanceRight) {
  analogWrite(LeftmotorPin1, 0);//set leg 1 of the H-bridge low
  analogWrite(LeftmotorPin2, 255);//set leg 2 of the H-bridge high
  analogWrite(RightmotorPin3, 0);//set leg 1 of the H-bridge low
  analogWrite(RightmotorPin4, 0);//set leg 2 of the H-bridge LOW
 }
 
 //Delay 100ms before next reading.
 delay(30);
}
