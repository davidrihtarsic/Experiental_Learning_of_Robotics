---
grand_parent: Book
parent: C++ Programming
title: Programming Loop
nav_order: 4
---

## PROGRAMMING LOOPs: FOR-NEXT & DO-WHILE

It is very often needed, that we want to repeat some part of code several times. In that case we can use programming loops where we can specify which code should be repeated. In general there are two very often situation where we are using the programming loops:

1. We know `how many times` some code should repeat and
2. The code is `repeated while the condition` is met.

### For-Next Loop

So called `For-Next` loop is used whenever the repetition of the code can be controlled by a `counter`. Counter is a number with some **starting value** and gets incremented by each repetition of the code. When `counter` reaches the given **ending value** repetition will stop. Typical examples where `For-Next` loop is used are:

- filling an array of data,
- summarising of all the costs in the bill
- robot should turn for **8 times** with 45 degree step to complete full rotation.

### Do-While Loop

`Do-While` loop is used in situations where we can not predict the numbers of repetitions in advanced. In this case we must state the `condition` that must be met to repeat the code. The repetition of the code will be terminated when the `condition` will not hold anymore. Typical examples are:

- read the content to end of file,
- divide some number by 2 while we can,
- while no obstacle is in front of the robot it should drive forward

### Task: FOR-NEXT LOOP

1. For example the next [@lst:240_Programming_Loops] repeats the functions **robotLeft()** and **robotRight()** for **10 times** and robot will do a funny \"dancing\" move.

```cpp
#include "RobotMovingFunctions.h"

void setup()
{
  setIOpins();
  // Repeating Left and Right movement
  // for 10 times to make a danging move
  for (int i = 0; i < 10; i++)
  {
    robotLeft();
    delay(100);
    robotRight();
    delay(100);
  }
  stopTheRobot();
}

void loop()
{

}
```
: Programming Loops. {#lst:240_Programming_Loops}

2. Experiment a bit more with such programming techniques and change some code:
    - value of `i`,
    - duration of `delay()` function,
    - add some other functions to the `for-next` loop...

### Task: DO-WHILE LOOP

3. Change the `for-next` loop with this `do-while` loop. Can you predict the result?

```cpp
while ( 1 == 1 ){
  ????robotLeft();
   ??delay(100);
    robotRight();
   ??delay(100);
}
```

Presented `do-while` loop is not an useful example as the condition `( 1 == 1 )` will never change and will be always `true`. So, we created an infinite loop. `Do-While` loop is far more usable if in the condition is some sensor's value, as we will see in next sections.

### Questions:

1. Name the situation  where `for-next` loop can be used.
2. What is the purpose of a `counter` in `for-next` loop?
3. What is the difference between `for-next` and `do-while` loops?

### Summary:

#### For-loop

<++>

### Issues:

#### *Can I measure the execution time of the loop?*

Yes, you can. You must save the time before the loop and save the time after the loop is executed. The difference in these two values is the spent in the execution of the loop. A minimal working example counld look like this:
```cpp
unsigned long start_time = millis();
for (int i = 0; i<100; i++)
{
  //some code in this loop
}
unsigned long stop_time = millis();
unsigned long loop_duration = stop_time - start_time;
```

#### *Can I exit a while loop.*

Yes, you can use the "break" statement to exit a while loop in C++. However, this is not a common practice it is advised to set appropriate condition to exit a while loop.
Here is an example of using "brake" statement:

```cpp
int x = 0;
while (x < 10) {
  Serial.println(x);
  x++;
  if (x == 5) {
    break;
  }
}
```

This code will output the following to the serial port:

```
0
1
2
3
4
```

In this example, the "break" statement is used to exit the while loop when the value of "x" becomes 5. As a result, the loop only executes 5 times, rather than 10 times.

It is also possible to use the "continue" statement to skip the remainder of the current iteration of a loop, without exiting the loop entirely. For example:

```cpp
int x = 0;
while (x < 10) {
  x++;
  if (x % 2 == 1) {
    continue;
  }
  Serial.println(x);
}
```

This code will output the following to the serial port:

```
2
4
6
8
10
```

In this example, the "continue" statement is used to skip the remainder of the current iteration of the loop if the value of "x" is odd. As a result, only the even values of "x" are printed.

