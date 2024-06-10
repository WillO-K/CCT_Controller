// Authored by Willoughby Kemble
// Designed specifically for a custom PCB using an ATMEGA8A-AU, but can be used on any Arduino-based device or board using ATMEGA chips similar to the 8A


int WarmWhiteOutput = 9;
int ColdWhiteOutput = 10;
int WarmWhiteIncreaseButton = 2;
int ColdWhiteIncreaseButton = 3;
int MaxBrightnessButton = 4;

int WarmWhiteBrightness = 0; 
int ColdWhiteBrightness = 255; 

void setup() {
    pinMode(WarmWhiteOutput, OUTPUT);
    pinMode(ColdWhiteOutput, OUTPUT);
    pinMode(WarmWhiteIncreaseButton, INPUT_PULLUP);
    pinMode(ColdWhiteIncreaseButton, INPUT_PULLUP);

    analogWrite(WarmWhiteOutput, WarmWhiteBrightness);
    analogWrite(ColdWhiteOutput, ColdWhiteBrightness);

    Serial.begin(9600);
}

void loop() {
    if (digitalRead(WarmWhiteIncreaseButton) == LOW) {
        WarmWhiteBrightness += 25;
        ColdWhiteBrightness -= 25;
        
        WarmWhiteBrightness = constrain(WarmWhiteBrightness, 0, 255);
        ColdWhiteBrightness = constrain(ColdWhiteBrightness, 0, 255);
        
        analogWrite(WarmWhiteOutput, WarmWhiteBrightness);
        analogWrite(ColdWhiteOutput, ColdWhiteBrightness);
        
        delay(200);
    }

    if (digitalRead(ColdWhiteIncreaseButton) == LOW) {
        WarmWhiteBrightness -= 25; 
        ColdWhiteBrightness += 25; 
        
        WarmWhiteBrightness = constrain(WarmWhiteBrightness, 0, 255);
        ColdWhiteBrightness = constrain(ColdWhiteBrightness, 0, 255);
        
        analogWrite(WarmWhiteOutput, WarmWhiteBrightness);
        analogWrite(ColdWhiteOutput, ColdWhiteBrightness);
        
        delay(200);
    }

    if (digitalRead(MaxBrightnessButton) == LOW) {
      WarmWhiteBrightness +=255;
      ColdWhiteBrightness +=255;

        WarmWhiteBrightness = constrain(WarmWhiteBrightness, 0, 255);
        ColdWhiteBrightness = constrain(ColdWhiteBrightness, 0, 255);
        
        analogWrite(WarmWhiteOutput, WarmWhiteBrightness);
        analogWrite(ColdWhiteOutput, ColdWhiteBrightness);
        
        delay(200);
    }
}