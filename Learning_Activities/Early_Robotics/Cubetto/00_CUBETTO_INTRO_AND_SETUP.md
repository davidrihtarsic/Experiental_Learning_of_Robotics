---
parent: Early Robotics
title: Cubetto
nav_order: 3
has_children: true
---

CUBETTO INTRO AND SETUP
================================================================================

## What Is Cubetto?
Cubetto is a friendly wooden robot designed to introduce children to the basics of coding and problem-solving. Children create simple programs by arranging colored blocks on a control board, then pressing “Go.” Cubetto follows the directions they’ve laid out.

## Main Components
Cubetto Robot – A wooden cube on wheels.
Control Board – A wooden board with slots for coding blocks.
Colored Blocks – Each color represents an action (move forward, turn left, turn right, function call).
Mat or Play Surface – Often a grid mat with thematic imagery to inspire storytelling.

## How It Works
Place the Blocks: Put the colored blocks on the control board in the desired order.
Press Go: Cubetto follows the sequence of instructions.
Observe and Learn: Children see firsthand how each command corresponds to movement.

## Teacher Tips
Encourage children to predict Cubetto’s path.
Use short sequences at first, then let them experiment with longer ones.
Treat mistakes as part of the learning: “We found a bug—how can we fix it?”

## Setup Checklist
Ensure the batteries in Cubetto are charged or fresh.
Clear a small area on the floor or table.
Have the control board, colored blocks, and thematic map laid out where everyone can see.

## More on Cubetto

The Cubetto first appeared on [Kickstarter](https://www.kickstarter.com/projects/primotoys/primo-teaching-programming-logic-to-children-age-4) in 2013. The V1 was a DIY kit with [full documentation](https://emersonmello.me/prototype-documentation/) for assemble it. The programming blocks contained a resistor. When inserted in "controller", it was a part of a voltage divider, and an ADC was measuring the voltage across it. Because there was only 4 different blocks, it was easy to differentiate between those different voltages. There was an Arduino Mega inside the "controller", with 16 analog inputs, so the "controller" had 16 places for programing. It was divided into 12 places for main program, and 4 places for subroutine. The 4 different blocks where: left turn, right turn, forward, jump to the subroutine. Later, the files for this version were uploaded to Github, you can find it [here](https://github.com/primo-io). In there, it is called "primo prototype". You can find all the information for rebuild, source codes, drawings for lasercuting, etc.

In year 2016 the Cubetto appeared on the [Kickstarter](https://www.kickstarter.com/projects/primotoys/cubetto-hands-on-coding-for-girls-and-boys-aged-3) once more. But this time, it was a polished product. It looked much, much better. So it scored a whooping 1.6 million $ in funds. In this V2, the programming block had no more electrical connection to the "controller". There were 3 places for the magnets, and in the "controller" there is a PCB, size of the "controller", with HAL sensors, under the programming places. Different blocks had magnet(s) in different places, so by reading out the 3 HAL sensor, you could find out, are there some blocks, and what type are.

>Source: https://hackaday.io/project/20514-cubetto-clone
