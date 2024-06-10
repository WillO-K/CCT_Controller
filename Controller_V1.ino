// Authored by Willoughby Kemble
// Designed specifically for a custom PCB using an ATMEGA8A-AU, but can be used on any Arduino-based device or board using ATMEGA chips similar to the 8A


const int WarmWhiteOutput = 9;
const int ColdWhiteOutput = 10;
const int WarmWhiteIncreaseButton = 2;
const int ColdWhiteIncreaseButton = 3;
const int MaxBrightnessButton = 4;

const int MaxBrightness = 255;

int WarmWhiteBrightness = 0; 
int ColdWhiteBrightness = 255; 

const int ButtonValue = ButtonValue;

const int debounceVal = 200;

void setup() {
    pinMode(WarmWhiteOutput, OUTPUT);
    pinMode(ColdWhiteOutput, OUTPUT);
    pinMode(WarmWhiteIncreaseButton, INPUT_PULLUP);
    pinMode(ColdWhiteIncreaseButton, INPUT_PULLUP);

    analogWrite(WarmWhiteOutput, WarmWhiteBrightness);
    analogWrite(ColdWhiteOutput, ColdWhiteBrightness);

    Serial.begin(9600);
}

int constrainBrightness(int brightness) {
    return constrain(brightness, 0, 255);
}

void loop() {
    if (digitalRead(WarmWhiteIncreaseButton) == LOW) {
        WarmWhiteBrightness += ButtonValue;
        ColdWhiteBrightness -= ButtonValue;
        
        WarmWhiteBrightness = constrainBrightness(WarmWhiteBrightness);
        ColdWhiteBrightness = constrainBrightness(ColdWhiteBrightness);
        
        analogWrite(WarmWhiteOutput, WarmWhiteBrightness);
        analogWrite(ColdWhiteOutput, ColdWhiteBrightness);
        
        delay(debounceVal);
    }

    if (digitalRead(ColdWhiteIncreaseButton) == LOW) {
        WarmWhiteBrightness -= ButtonValue; 
        ColdWhiteBrightness += ButtonValue; 
        
        WarmWhiteBrightness = constrainBrightness(WarmWhiteBrightness);
        ColdWhiteBrightness = constrainBrightness(ColdWhiteBrightness);
        
        analogWrite(WarmWhiteOutput, WarmWhiteBrightness);
        analogWrite(ColdWhiteOutput, ColdWhiteBrightness);
        
        delay(debounceVal);
    }

    if (digitalRead(MaxBrightnessButton) == LOW) {
      WarmWhiteBrightness +=MaxBrightness;
      ColdWhiteBrightness +=MaxBrightness;

        WarmWhiteBrightness = constrainBrightness(WarmWhiteBrightness);
        ColdWhiteBrightness = constrainBrightness(ColdWhiteBrightness);
        
        analogWrite(WarmWhiteOutput, WarmWhiteBrightness);
        analogWrite(ColdWhiteOutput, ColdWhiteBrightness);
        
        delay(debounceVal);
    }
}