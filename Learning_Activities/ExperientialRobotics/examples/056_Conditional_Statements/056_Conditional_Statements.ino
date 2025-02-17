const int BUMPER_PIN          = A0;
const int TEST_BUMPER_LED_PIN = 3;
void setup(){
  pinMode(BUMPER_PIN, INPUT);
  pinMode(TEST_BUMPER_LED_PIN, OUTPUT);
}

void loop(){
  ifTheBumperIsPressedTurnTheLED_ON();
}

void ifTheBumperIsPressedTurnTheLED_ON(){
  if ( digitalRead(BUMPER_PIN) == HIGH ) digitalWrite(TEST_BUMPER_LED_PIN, HIGH);
}
