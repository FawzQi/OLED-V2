#include <Arduino.h>

#include "display.h"

OLED displayRobot;

EasyButton black(BLACK_BUTTON_PIN, 50, false, true);
EasyButton grey(GREY_BUTTON_PIN, 50, false, true);
EasyButton red(RED_BUTTON_PIN, 50, false, true);
EasyButton green(GREEN_BUTTON_PIN, 50, false, true);

int i = 0;  // Untuk testing baterai 

void setup() {
    Serial.begin(9600);

    setupDisplay();

    green.begin();
    green.onPressed(Button_Trig_Hold_Callback);

    black.begin();
    black.onPressed(Button_Mode_A_Callback);
    black.onSequence(2, 1000, Button_Mode_A_2_Sequence_Callback);
    black.onSequence(3, 1000, Button_Mode_A_3_Sequence_Callback);

    grey.begin();
    grey.onPressed(Button_Mode_B_Callback);
    grey.onSequence(2, 1000, Button_Mode_B_2_Sequence_Callback);
    grey.onSequence(3, 1000, Button_Mode_B_3_Sequence_Callback);

    red.begin();
    red.onPressed(Button_Trig_Callback);
    red.onSequence(2, 1000, Button_Trig_2_Sequence_Callback);
    // red.onPressedFor(1000, Button_Trig_Hold_Callback);
}

void loop() {
    if(millis()/3000>=i){
        i++;
        displayRobot.setBatteryStr(String(random(0,100)));
    }
    black.read();
    grey.read();
    red.read();
    green.read();
    display(displayRobot.show(), displayRobot.getFocus());
    displayLogo();
}
