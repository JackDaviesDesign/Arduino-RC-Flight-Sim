/* 
 * This program uses an 2.4GHz RC reciever and enables it to be used 
 * as a game controller input for Mac, PC & Linux systems.
 * 
 * Only tested on an Arduiono Pro Micro, however a Leonardo should work fine too.
 * 
 * For build instructions and wiring diagram please visit - 
 * 
 * Written by Jack Davies - jackdaviesdesign.com
 */
 
#include <Joystick.h>

// Create the Joystick
Joystick_ Joystick;

int ch1; // Here's where we'll keep our channel values (raw data from reciever)
int val1; // Here's the value after mapping the raw data from the reciever to the data passed to the computer
int ch2;
int val2;
int ch3;
int val3;
int ch4;
int val4;

void setup() {
                     // Initialize Button Pins
  pinMode(6, INPUT); // Set our input pins
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);

// Initialize Joystick Library
  Joystick.begin();
  
}

void loop() {

  // Read pin values
  ch1 = pulseIn(6, HIGH, 25000); // Read the pulse width of the input from the RX
  ch2 = pulseIn(7, HIGH, 25000);  
  ch3 = pulseIn(8, HIGH, 25000);
  ch4 = pulseIn(9, HIGH, 25000);
  val1 = map(ch1, 1000, 1900, 10, 1050); // Map the raw data to a range that the computer will be able to use
  val2 = map(ch2, 1000, 1900, 10, 1050);
  val3 = map(ch3, 1000, 1900, 10, 1050);
  val4 = map(ch4, 1000, 1900, 10, 1050);
  
  Joystick.setXAxis(val1);  // Send the data to the computer for each axis
  Joystick.setYAxis(val2);  
  Joystick.setZAxis(val3);
  Joystick.setRxAxis(val4);

  delay(40);
}
