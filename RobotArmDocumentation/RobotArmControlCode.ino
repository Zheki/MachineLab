//add servo library
#include <Servo.h>

//define servos for wrist and elbow
Servo wrist;
Servo elbow;



//define joystick
int pot1 = A0;
int pot2 = A5;

//variables to read the values from the joystick (2 pots)
int valPot1;
int valPot2;

void setup()
{

  wrist.attach(11);                  // Wrist servo attached to digital pin 11
  elbow.attach(10);                  // Wrist servo attached to digital pin 10
  pinMode(swout, OUTPUT);
  pinMode(sw, INPUT);
}

void loop()
{
  //reads the value of potentiometers (value between 0 and 1023)

  valPot1 = analogRead(pot1);
  valPot1 = map (valPot1, 0, 1023, 0, 90);   //scale it to use it with the servo (value between 0 and 180)
  elbow.write(valPot1);                      //set the servo position according to the scaled value
  delay(5);

  valPot2 = analogRead(pot2);
  valPot2 = map (valPot2, 0, 1023, 0, 90);
  wrist.write(valPot2);
  delay(5);
}
