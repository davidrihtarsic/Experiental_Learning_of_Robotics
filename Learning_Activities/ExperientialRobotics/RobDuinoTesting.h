#ifndef ROBDUINO_TESTING
#define ROBDUINO_TESTING

/* testing function is using
 * serialEvent()
 * which is declared in
 * Arduino.h but not defined...
 */
#include <Arduino.h>
#include <HardwareSerial.h>

void printTestingMenu();
void getIO_data();
void respondToUserCommand(String &command);
void serialEvent();

// Testing IO pins...
bool testing_is_running = false;

static bool serialInitialized = false;

// Function to check if pin is OUTPUT by reading DDR registers
bool isOutput(int pin) {
  if (pin >= 0 && pin <= 7) {
    return (DDRD & (1 << pin)) != 0;
  } else if (pin >= 8 && pin <= 13) {
    return (DDRB & (1 << (pin - 8))) != 0;
  }
  return false; // Analog pins or invalid
}

void serialEvent(){
  if (!serialInitialized) {
    Serial.begin(115200);
    Serial.println(F("\n\n*** RobDuino Testing Mode Initialized ***"));
    Serial.println(F("* baud rate: 115200"));
    Serial.println(F("* Type 'test' to enter testing mode"));
    serialInitialized = true;
  }
  String test_string = Serial.readString();
  test_string.trim();
  test_string.toLowerCase(); // Make trigger commands case insensitive
  if (test_string == "test"){
      Serial.println(F("\nWelcome to RobDuino Testing Mode!"));
      Serial.println(F("Use 'help' for commands, 'exit' to quit."));
      printTestingMenu();
    while (test_string != "exit") {
      test_string = Serial.readString();
      test_string.trim();
      respondToUserCommand(test_string);
      if (testing_is_running) getIO_data();
    }
  } else if (test_string != ""){
    Serial.println("\n" + test_string + " - is not valid command.");
  }
}

void respondToUserCommand(String &command){
  command.trim();
  command.toLowerCase(); // Make commands case insensitive
  if (command.startsWith("toggle d")) {
    int pin = command.substring(8).toInt();
    if (pin >= 0 && pin <= 13) {      if (!isOutput(pin)) {
        pinMode(pin, OUTPUT); // Ensure pin is OUTPUT for toggle
      }      digitalWrite(pin, !digitalRead(pin));
      Serial.print(F("\n\t -> Toggled D"));
      Serial.println(pin);
      getIO_data();
    } else {
      Serial.println(F("Invalid pin. Use 0-13."));
    }
  } else if (command.startsWith("set d")) {
    int space = command.indexOf(' ', 5);
    if (space > 0) {
      int pin = command.substring(5, space).toInt();
      String state = command.substring(space + 1);
      if (pin >= 0 && pin <= 13) {
        if (state == "high") {
          digitalWrite(pin, HIGH);
          Serial.print(F("\n\t -> Set D"));
          Serial.print(pin);
          Serial.println(F(" to HIGH"));
          getIO_data();
        } else if (state == "low") {
          digitalWrite(pin, LOW);
          Serial.print(F("\n\t -> Set D"));
          Serial.print(pin);
          Serial.println(F(" to LOW"));
          getIO_data();
        } else {
          Serial.println(F("\n\t -> Invalid state. Use HIGH or LOW."));
          Serial.print(F("Enter command: "));   
        }
      } else {
        Serial.println(F("\n\t -> Invalid pin. Use 0-13."));
        Serial.print(F("Enter command: "));
      }
    } else {
      Serial.println(F("\n\t -> Invalid format. Use: set D<PIN> HIGH/LOW"));
      Serial.print(F("Enter command: "));
    }
  } else if (command.startsWith("mode d")) {
    int space = command.indexOf(' ', 6);
    if (space > 0) {
      int pin = command.substring(6, space).toInt();
      String mode = command.substring(space + 1);
      if (pin >= 0 && pin <= 13) {
        if (mode == "in") {
          pinMode(pin, INPUT);
          Serial.print(F("\n\t -> Set D"));
          Serial.print(pin);
          Serial.println(F(" to INPUT"));
          getIO_data();
        } else if (mode == "out") {
          pinMode(pin, OUTPUT);
          Serial.print(F("\n\t -> Set D"));
          Serial.print(pin);
          Serial.println(F(" to OUTPUT"));
          getIO_data();
        } else {
          Serial.println(F("\n\t -> Invalid mode. Use INPUT or OUTPUT."));
          Serial.print(F("Enter command: "));
        }
      } else {
        Serial.println(F("\n\t -> Invalid pin. Use 0-13."));
        Serial.print(F("Enter command: ")); 
      }
    } else {
      Serial.println(F("\n\t -> Invalid format. Use: mode D<PIN> INPUT/OUTPUT"));
      Serial.print(F("Enter command: "));
    }
  } else if (command == "read all") {
    getIO_data();
  } else if (command == "monitor on") {
    testing_is_running = true;
    Serial.println(F("\n\t -> Monitoring started."));
  } else if (command == "monitor off") {
    testing_is_running = false;
    Serial.println(F("\n\t -> Monitoring stopped."));
    Serial.print(F("Enter command: "));
  } else if (command == "help") {
    printTestingMenu();
    testing_is_running = false;
  } else if (command == "exit") {
    Serial.println(F("\n\t -> Exiting testing mode.\n\t -> Back to normal operation."));
    // Handled in serialEvent
  } else if (command.charAt(0) == 'D' && command.length() <= 3) { // Legacy support
    int pin = command.substring(1).toInt();
    if (pin >= 0 && pin <= 13) {
      if (!isOutput(pin)) {
        pinMode(pin, OUTPUT);
      }
      digitalWrite(pin, !digitalRead(pin));
      Serial.print(F("\n\t -> Toggled D"));
      Serial.println(pin);
      getIO_data();
    } else {
      Serial.println(F("\n\t -> Invalid pin."));
    }
  } else if (command.charAt(0) == 'd' && command.length() <= 3) { // New lowercase support
    int pin = command.substring(1).toInt();
    if (pin >= 0 && pin <= 13) {
      if (!isOutput(pin)) {
        pinMode(pin, OUTPUT);
      }
      digitalWrite(pin, !digitalRead(pin));
      Serial.print(F("\n\t -> Toggled D"));
      Serial.println(pin);
      getIO_data();
    } else {
      Serial.println(F("\n\t -> Invalid pin."));
    }
  } else if (command == "run") { // Legacy
    testing_is_running = !testing_is_running;
    Serial.print(F("\n\t -> Monitoring "));
    Serial.println(testing_is_running ? F("started") : F("stopped"));
    Serial.print(F("Enter command: "));
  } else if (command != "") {
    Serial.print(F("\nUnknown command: "));
    Serial.println(command);
    Serial.println(F("Type 'help' for available commands."));
    Serial.print(F("Enter command: "));
  }
}

void printTestingMenu(){
      Serial.println(F("*** RobDuino Testing Mode Menu ***"));
      Serial.println(F("* Available commands:"));
      Serial.println(F("*   test                - Enter testing mode"));
      Serial.println(F("*   help                - Show this menu"));
      Serial.println(F("*   toggle D<PIN>       - Toggle digital pin (0-13)"));
      Serial.println(F("*   set D<PIN> HIGH/LOW - Set digital pin state"));
      Serial.println(F("*   mode D<PIN> IN/OUT  - Set pin mode"));
      Serial.println(F("*   read all            - Print current pin status"));
      Serial.println(F("*   monitor on/off      - Start/stop continuous monitoring"));
      Serial.println(F("*   run                 - Start/stop continuous monitoring"));
      Serial.println(F("*   exit                - Exit testing mode"));
      Serial.println(F("*---------------------------------------------"));
      Serial.print(F("Enter command: "));
}

void getIO_data(){
  Serial.println(F("\n=== Current Pin Status ==="));
  Serial.println(F("Digital IO D0-D7\tDigital IO D8-D13\tAnalog In. A0-A5"));
  Serial.println(F("Pin\tState\tDir\tPin\tState\tDir\tPin\tValue"));

  for (int i = 0; i <= 7; i++) {
    // Column 1: D0-D7
    Serial.print(F("D"));
    Serial.print(i);
    Serial.print(F(":\t"));
    Serial.print(digitalRead(i));
    Serial.print(F("\t("));
    Serial.print(isOutput(i) ? F("OUT") : F("IN"));
    Serial.print(F(")\t"));

    // Column 2: D8-D13
    if (i <= 5) {
      Serial.print(F("D"));
      Serial.print(i + 8);
      Serial.print(F(":\t"));
      Serial.print(digitalRead(i + 8));
      Serial.print(F("\t("));
      Serial.print(isOutput(i + 8) ? F("OUT") : F("IN"));
      Serial.print(F(")\t"));
    } else {
      Serial.print(F("\t\t\t"));
    }

    // Column 3: A0-A5
    Serial.print(F("A"));
    Serial.print(i);
    Serial.print(F(":\t"));
    if (i <= 5) {
      Serial.print(analogRead(i));
    }
    Serial.println();
  }
  Serial.println(F("========================"));
  Serial.print(F("Enter command: "));
}

#endif
