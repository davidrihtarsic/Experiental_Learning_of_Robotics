#include "RobotMovingFunctions.h"
//#include <RobDuinoSerialTesting.h>

void setup()
{
  Serial.begin(115200);
  setIOpins();
  moveForward();
  delay(3000);
  stopTheRobot();
}

void loop()
{

}

void serialEvent(){
  String test_string = Serial.readString();
  if      (test_string == "forward")  moveForward();
  else if (test_string == "stop")     stopTheRobot();
  else Serial.println("\n" + test_string + " is not valid command.");
}

