# CCT_Controller
## What does it do?

This program allows you to adjust the warm white and cold white channels on a CCT (dual white) 'dumb' LED strip. 

## Board setup

The code was written with the intention of being used on a custom PCB using an ATMEGA8A-AU, but can be used on any Arduino board, so long as you have 2 PWM pins you can use for the white channels. You'll need 3 buttons; these control the brightness of the each channel, as well as one button setting the brightness of both channels to the maximum, and (more than likely), a method of stepping your voltage down to whatever is suitable for your board, as CCT strips usually consume 12V-24V. 

If you're building a board or using a microcontroller on it's own (for example, the popular ATMEGA328-PU), you should consider the following:
- MOSFETS to control the signal to the LED strip.
- 10K resistors as pullup resistors for the buttons.
- A step-down converter, most CCT strips are 12V, the microcontroller can't handle this, so you'll need a step-down converter to step it down to 5V (or whatever working voltage your particular MC uses, some are 3.3V I think).
- Decoupling capacitors - to remove noise and keep things stable. 

## How to use

Once your board is setup, open the .ino file in Arduino IDE, select your board, and hit the "Upload" button. 
