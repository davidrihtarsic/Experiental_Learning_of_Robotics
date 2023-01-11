---
parent: Book
title: Reading Input
nav_order: 3
has_children: true
---

# READING INPUT SIGNAL

To read an input signal on an Arduino, you can use one of the digital input pins or one of the analog input pins. Digital input pins can only read two states: high (5 volts) or low (0 volts). They are often used to read switches or buttons, or to detect the presence or absence of a signal.

To read a digital input signal on an Arduino, you can use the digitalRead function, which takes a pin number as an argument and returns either HIGH or LOW. For example, to read the state of digital pin 2, you could use the following code:

```cpp
int pin = 2;
int state = digitalRead(pin);
```

Analog input pins, on the other hand, can read a range of voltage levels, from 0 to 5 volts. They are often used to read sensors that output an analog signal, such as a temperature sensor or a potentiometer.

To read an analog input signal on an Arduino, you can use the analogRead function, which takes a pin number as an argument and returns a value between 0 and 1023, corresponding to the voltage level on the pin. For example, to read the voltage on analog pin 0, you could use the following code:

```cpp
int pin = 0;
int value = analogRead(pin);
```

