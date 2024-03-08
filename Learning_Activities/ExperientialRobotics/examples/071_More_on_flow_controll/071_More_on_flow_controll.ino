#include <RobotMovingFunctions.h>
const int LIGHT_SENSOR_PIN = A0;
const int SURFACE_BRIGHTNESS_REFERENCE = 400;
const int TIME_LINIT = 30;

enum Modes {
  LINE_FOLLOWER,
  END_LINE_TURN,
  LINE_ALIGHMENT,
  IDLE
}

Modes robotMode = IDLE;

int time_on_white = 0;
void followTheLine();
bool isEndLineTurnCompleted();

void setup() {
  setIOpins();
  pinMode(LIGHT_SENSOR_PIN , INPUT);
}

void loop() {
  switch(robotMode){
    case LINE_FOLLOWER  : followTheLine();
                          if (time_on_white > TIME_LINIT){
                            time_on_white = 0;
                            robotMode = END_LINE_TURN;
                          }
                          break;
    case END_LINE_TURN  : if (isEndLineTurnCompleted()){
                            robotMode = LINE_ALIGHMENT;
                          }
                          break;
    case LINE_ALIGHMENT : alignTheRobotWithALine();
                          break;
    case IDLE           : stopTheRobot();
                          break;
    default             : stopTheRobot();
                          break;
  }
}

void followTheLine(){
  int light_sensor_value = analogRead(LIGHT_SENSOR_PIN );
  if ( light_sensor_value < SURFACE_BRIGHTNESS_REFERENCE ){
    moveLeft();         // dark area - back to white
    delay(100);
    time_on_white = 0;  // reset time_on_white
  } else {
    moveRight();        // white area - back to dark
    delay(100);
    time_on_white++;    // increase time_on_white
  }
}
