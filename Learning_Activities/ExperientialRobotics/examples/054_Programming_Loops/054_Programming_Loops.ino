#include <RobotMovingFunctions.h>

void setup()
{
  setIOpins();
  // Repeating Left and Right movement
  // for 10 times to make a danging move
  for (int i = 0; i < 10; i++)
  {
    moveLeft();
    delay(100);
    moveRight();
    delay(100);
  }
  stopTheRobot();
}

void loop()
{

}
