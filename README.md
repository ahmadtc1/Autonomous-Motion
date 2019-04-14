# Autonomous-Motion
### Overview
An autonomous robot navigating its way to the future through ultrasonic sensors

### Sensors
The Arduino microcontroller is connected to 3 HC-SR04 sensors. One at the front, and one on either side. These three sensors provide the robot with information about its surroundings, based off which it's able to navigate environments autonomously

### Arduino
The robot as programmed using Arduino, essentially using C++/C as the Arduino language is essentially a set of C++/C functions.


### Future Scope
* Installing a camera at the front and implementing a computer vision model to recognize certain objects
* Incorporating more accurate sensors instead of HC-SR04 sensors, such as LV-MAXSONAR-EZ sensors
* Adding sensors at the back to increase robot awareness and receive more data regarding its surroundings
* Cleaning up wiring and creating a more sleek, streamlined physical design

### Formats
Both the digital and analog program files exist within this repository. 

The digital file writes to the motors using discrete HIGH and LOW values. 

The analog file writes to the motors using continuous values between 0 and 255, allowing for a more precise write. 

When I first used the digital values, the robot would not navigate in a perfectly straight path, and so I utilised analog values and callibrated the motor writes so that the robot would follow a straighter path.

### Image
![Robot](/Images/robot.jpg)
