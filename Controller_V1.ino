// Authored by Willoughby Kemble
// Not to be used commercially.
// This is just a really basic test program for my custom PCB to control dual-white LED strips. The board uses an ATMEGA8A-AU to control everything, with a stepdown converter on the board, stepping down the input
// of 12V to 5V so it's acceptable for the ATMEGA, but then providing 12V to the LED's VIN directly. 
// We also have 3 tactile buttons mounted to the board too. We're using MOSFETS for the output of 3 PWM pins on the board to control the warm white and cold white channels on the board.
// You can very easily replicate this setup with an Arduino UNO, Nano or Pro-mini or something similar, 
// as long as you have access to 3 PWM pins, as CCT strips are usually 'dumb' strips and can't use signals like WS2812B (or any WS2xxx series strips/leds) strips can.

// This is only a test program, I do plan to rework the PCB to make it more elegant, and the code a bit more robust, with more features (as the componants on the board may also change during refinement)
// This is only intended for prototyping.

int pwm1 = 9;
int pwm2 = 10;
int buttonPin1 = 2;
int buttonPin2 = 3;
int buttonPin3 = 4;

int brightness1 = 0; // initial brightness value for pwm1 (pwm1 could be warm white or cold white, depends which way you plug them in on the board)
int brightness2 = 255; // initial brightness value for pwm2 (same applies for pwm2)

void setup() {
    pinMode(pwm1, OUTPUT);
    pinMode(pwm2, OUTPUT);
    pinMode(buttonPin1, INPUT_PULLUP); // Using an external pullup resistor of 10K for each button
    pinMode(buttonPin2, INPUT_PULLUP);

    analogWrite(pwm1, brightness1);
    analogWrite(pwm2, brightness2);

    Serial.begin(9600);
}

void loop() {
    // Check if button1 is being pressed, if so then we increase the brightness of 1 channel (being coldwhite or warmwhite depending on which way they're wired), and decrease it for the other
    if (digitalRead(buttonPin1) == LOW) {
        brightness1 += 25; // Increase brightness1 by 25
        brightness2 -= 25; // Decrease brightness2 by 25
        
        // We want to constrain the brightness to 255, which is typical for LEDs. 
        brightness1 = constrain(brightness1, 0, 255);
        brightness2 = constrain(brightness2, 0, 255);
        
        // Set the new brightness values
        analogWrite(pwm1, brightness1);
        analogWrite(pwm2, brightness2);
        
        // Little delay to debounce the button press
        delay(200);
    }

    // Check if button2 is being pressed, if so then we do the reverse of what occurs in the first segment of the loop.
    if (digitalRead(buttonPin2) == LOW) {
        brightness1 -= 25; // Decrease brightness1 by 25
        brightness2 += 25; // Increase brightness2 by 25
        
        brightness1 = constrain(brightness1, 0, 255);
        brightness2 = constrain(brightness2, 0, 255);
        
        analogWrite(pwm1, brightness1);
        analogWrite(pwm2, brightness2);
        
        delay(200);
    }
    // This ones a little different, if we want to set the strip to have both warm white and cold white channels at full brightness, then button3 needs to be pressed.
    // Having both at full brightness does create a different shade of white, and is much brighter. 
    if (digitalRead(buttonPin3) == LOW) {
      brightness1 +=255;
      brightness2 +=255;

        brightness1 = constrain(brightness1, 0, 255);
        brightness2 = constrain(brightness2, 0, 255);
        
        analogWrite(pwm1, brightness1);
        analogWrite(pwm2, brightness2);
        
        delay(200);
    }
}