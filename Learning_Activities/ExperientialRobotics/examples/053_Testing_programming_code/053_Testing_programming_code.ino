#include "RobotMovingFunctions.h"
//include <RobDuinoSerialTesting.h>

void setup()
{
  Serial.begin(115200);

  Serial.print("Setting IO pins .."); // Reporting start of function.
  setIOpins();                        // Function execution.
  Serial.println("..DONE");           // Reporting end of function.

  moveForward();
  delay(3000);
  stopTheRobot();
  
}

void loop() { }

