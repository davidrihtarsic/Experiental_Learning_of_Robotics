---
parent: Book
title: Digital Output
nav_order: 3
has_children: true
---

# DIGITAL OUTPUT

On an Arduino Uno board, a digital output is a pin that can be used to output a digital signal, which can be either high (5 volts) or low (0 volts). Digital outputs are useful for controlling devices that are either on or off, such as LEDs, motors, and relays.

To use a digital output on an Arduino Uno board, you will need to specify which pin you want to use as an output in your code. You can do this using the pinMode function, which takes two arguments: the pin number and the mode (OUTPUT or INPUT). For example, the following code sets digital pin 13 as an output:

```C++
pinMode(13, OUTPUT);
```

Once you have set a pin as an output, you can use the digitalWrite function to set the pin to either a high or low state. For example, the following code sets digital pin 13 to a high state:

```C++
digitalWrite(13, HIGH);
```
