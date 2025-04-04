#include "neural_network.h"
const int LIGHT_INPUT_PIN = A0;
const int LEFT_MOTOR_PIN = 6;
const int RIGHT_MOTOR_PIN = 3;

Neuron Left_neuron(LIGHT_INPUT_PIN, -0.5, LEFT_MOTOR_PIN);
Neuron Right_neuron(LIGHT_INPUT_PIN, 0.5, RIGHT_MOTOR_PIN);

void setup() {
}

void loop() {
  Left_neuron.update();
  Right_neuron.update();
  delay(100);
}
