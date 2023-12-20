#include "RobotMovingFunctions.h"
//#include "TestingIOpins.h"
#include <ExperientalRobotics.h>

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
  /*
    test naj bo ena funkcija, tista ki je v skripti...
    v programu naj bo TestingIOpins.h zakomentiran
    in naj bodo ena navodila, da naj sprobajo tudi
    funkcijo, ki je v hederju....
    pa mogoče nekaj slik...
  */
}

/* Ta funkcija je že v Testing...h
void serialEvent(){
  String test_string = Serial.readString();
  if      (test_string == "forward")  moveForward();
  else if (test_string == "stop")     stopTheRobot();
  else Serial.println("\n" + test_string + " is not valid command.");
}
*/
