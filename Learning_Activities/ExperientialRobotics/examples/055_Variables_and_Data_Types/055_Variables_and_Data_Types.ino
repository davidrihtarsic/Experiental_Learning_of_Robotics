#include <RobotMovingFunctions.h>
void setup()
{
  setIOpins();

  moveForward();
  delay(3000);
  moveBack();
  delay(3000);
  stopTheRobot();
}
void loop()
{
}
