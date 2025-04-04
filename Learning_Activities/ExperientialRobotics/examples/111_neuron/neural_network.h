#include "Arduino.h"
class Neuron {
  private:
    int inputPin;
    int neuron_input_value;
    int input_reference;
    int outputPin;
    int output_reference;
    int neuron_output_value;
    float weight;
  public:
    Neuron(int inPin, float w, int outPin){
      inputPin = inPin;
      input_reference = 512;
      weight = w;
      outputPin = outPin;
      output_reference = 124;
      pinMode(inputPin, INPUT);
      pinMode( outputPin , OUTPUT);
    }
    int update(){
      neuron_input_value = 0;
      for(int i=0;i<16;i++){
        neuron_input_value += analogRead(inputPin);
      }
      neuron_input_value = (neuron_input_value >> 4);
      neuron_output_value = (neuron_input_value - input_reference) * weight + output_reference;
      //neuron_output_value = constrain(neuron_output_value, 0, 255);
      analogWrite(outputPin, constrain(neuron_output_value,0,255));
      return neuron_output_value;
    }
    setInputReference(int new_input_reference){
      input_reference = new_input_reference;
    }
    setWeight(float w){
      weight = w;
    }
    setOutputReference(int new_output_reference){
      output_reference = new_output_reference;
    }
    int getInputValue(){
      return neuron_input_value;
    }
    int getOutputValue(){
      return neuron_output_value;
    }
};