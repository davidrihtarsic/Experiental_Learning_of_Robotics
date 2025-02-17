#include <RobotMovingFunctions.h>
const int LIGHT_SENSOR_PIN = A0;
const int SURFACE_BRIGHTNESS_REFERENCE = 400;
int time_on_black = 0;
int time_on_white = 0;

void setup(){
  setIOpins();
  pinMode(LIGHT_SENSOR_PIN , INPUT);
}
void loop(){
  if ( endOfLineIsDetected() ) makeATurnAndFindTheLine(); else followTheLine();
}

void followTheLine(){
  int light_sensor_value = analogRead(LIGHT_SENSOR_PIN );
  if ( light_sensor_value < SURFACE_BRIGHTNESS_REFERENCE ){
    moveLeft();
    delay(100);
  } else {
    moveRight();
    delay(100);
  }
}

bool endOfLineIsDetected(){
  int light_sensor_value = analogRead(LIGHT_SENSOR_PIN );
  if ( light_sensor_value < SURFACE_BRIGHTNESS_REFERENCE ){
    // BLACK line is detected
    time_on_white = 0;  // reset time on white
    time_on_black++;    // meas. time on black
    return false;
  } else {
    //WHITE area
    // Do similar measurement
    // of time on white
    
    // If time is signif. longer:
    if (time_on_white > 20)
      return true //endOfLineDetected
  }
}

makeATurnAndFindTheLine(){
  stopTheRobot();
  // To do:
  // - make some moves and
  // - try to find the line
  exit(0);
}
