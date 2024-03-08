#include <RobotMovingFunctions.h>

void setup()
{
  setIOpins();

repeating_moves:
  moveForeward();
  delay(1000);
  moveLeft();
  delay(550);
  robotStop();
  delay(1000);
goto repeating_moves;

}

void loop()
{

}
