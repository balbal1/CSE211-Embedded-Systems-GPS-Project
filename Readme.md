# GPS Tracking System Project

1. The GPS system stores the coordinates of the start point.
2. After reaching the destination point, the GPS system stores the coordinates
   of the end point and calculates the total distance that was taken by the user.
3. The output will be translated as the following.
   1. Stage 1: The built-in LED will be turned on(green) when the target
      destination is reached.
   2. Stage 2: The built-in LED will be turned on(yellow) when the target
      destination is about to be reached < 5 meters.
   3. Stage 3: The built-in LED will be turned on(red) when the target
      destination is far away by distance > 5 meters.
      
# Video of The Project
https://drive.google.com/file/d/1qOvVeDA646bRYG1yRKwBfUAXW7IUD6Wt/view?usp=share_link
# Flow of Program

* We get the info about our position from the GPS satalites through an antenna.
* Then the GPS module takes this info and determines the position through some calculations.
* Then the GPS module sends this processed info about the position every one second in the form of NMEA sentences.
* The GPS module is connected to tm4c board through serial UART commuincation and inputs the NMEA sentences to the board.
* We recieve the NMEA sentences to the board and extract the coordinates info from it.
* Then we  use the current coordinates to determine the distance to the destination and decide which led color to turn on.
* Also the program computes the total distance traveled by summing the distances between each two positions every second.
* Finally the program prints the total distace traveled on the serial monitor through UART0 on computer program (PuTTY).

# Functions used:

We made three initialization functions of the ports A, B and F:

* initPortA
* initPortB
* initPortF

Two initialization functions of UART0 and UART1: 

* initUART0
* initUART1

A function to write a single character on UART0

* write_UART0

Three print functions on UART0 that uses write_UART0

* printString
* printStringln
* printDouble

A function to read a single character from UART1

* read_UART1

A function that creates the string taken from UART1 (GPS) using read_UART1

* makeInputString

Two functions to get the coordinates from the NMEA sentence and convert it to degrees

* getCoordinates
* fixCoordinate

Functions used in main to make it more readable

* chooseLedColor
* calculateStepsTaken
* distance

Two functions to turn on/off the leds

* ledON
* ledOFF

Systick timer functions

* initSystick
* delayInSeconds
* delay
