#include <RobotMovingFunctions.h>
const int BUMPER_PIN = A0;
void setup()
{
  setIOpins();
  pinMode(BUMPER_PIN, INPUT);

  driveForwardUntilYouDetectAnObstacle();
}
void loop(){
}

void driveForwardUntilYouDetectAnObstacle(){
  if ( digitalRead(BUMPER_PIN) ){
    stopTheRobot();
  } else {
    moveForward();
  }
}
