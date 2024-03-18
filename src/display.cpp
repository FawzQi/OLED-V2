#include "display.h"

void OLED::switchFocus() {
    OLED::oledFocus = !OLED::oledFocus;
    OLED::mode = 0;
    OLED::kursor = 0;
    OLED::currMode = "Just Switched";
    OLED::modePlayed = "Just switched";
}

String OLED::show() {
    if (OLED::oledFocus) {
        if (OLED::mode == 0) {
            OLED::line1 = OLED::modeTemplate[OLED::menu[0]] + (OLED::kursor == OLED::menu[0] ? " <<" : "");
            OLED::line2 = OLED::modeTemplate[OLED::menu[0] + 1] + (OLED::kursor == OLED::menu[0] + 1 ? " <<" : "");
            OLED::line3 = OLED::modeTemplate[OLED::menu[0] + 2] + (OLED::kursor == OLED::menu[0] + 2 ? " <<" : "");
            return "Battery : " + OLED::battery + "%\n---------------------\nChoose mode:\n\n" + OLED::line1 + "\n" + OLED::line2 + "\n" + OLED::line3 + "\n";
        } else if (OLED::mode == 1) {
            OLED::line1 = OLED::utilsMenu[OLED::menu[0]] + (OLED::kursor == OLED::menu[0] ? " <<" : "");
            OLED::line2 = OLED::utilsMenu[OLED::menu[0] + 1] + (OLED::kursor == OLED::menu[0] + 1 ? " <<" : "");
            OLED::line3 = OLED::utilsMenu[OLED::menu[0] + 2] + (OLED::kursor == OLED::menu[0] + 2 ? " <<" : "");
            return "Battery : " + OLED::battery + "%\n---------------------\n" + OLED::modeTemplate[0] + "\n\n" + OLED::line1 + "\n" + OLED::line2 + "\n" + OLED::line3 + "\n";
        } else if (OLED::mode == 2) {
            OLED::line1 = OLED::modeMenu[OLED::menu[0]] + (OLED::kursor == OLED::menu[0] ? " <<" : "");
            OLED::line2 = OLED::modeMenu[OLED::menu[0] + 1] + (OLED::kursor == OLED::menu[0] + 1 ? " <<" : "");
            OLED::line3 = OLED::modeMenu[OLED::menu[0] + 2] + (OLED::kursor == OLED::menu[0] + 2 ? " <<" : "");
            return "Battery : " + OLED::battery + "%\n---------------------\n" + OLED::modeTemplate[OLED::path[1]] + "\n\n" + OLED::line1 + "\n" + OLED::line2 + "\n" + OLED::line3 + "\n";
        } else if (OLED::mode == 3) {
            OLED::line1 = (OLED::kursor == OLED::menu[0] ? "Play Full <<" : "Play Full");
            OLED::line2 = (OLED::kursor == OLED::menu[0] + 1 ? "Play by Index <<" : "Play by Index");
            return "Battery : " + OLED::battery + "%\n---------------------\n" + modeTemplate[path[1]] + " Play?\n\n" + OLED::line1 + "\n" + OLED::line2 + "\n";
        } else if (OLED::mode == 4) {
            OLED::line1 = OLED::seriesMenu[OLED::menu[0]] + (OLED::kursor == OLED::menu[0] ? " <<" : "");
            OLED::line2 = OLED::seriesMenu[OLED::menu[0] + 1] + (OLED::kursor == OLED::menu[0] + 1 ? " <<" : "");
            OLED::line3 = OLED::seriesMenu[OLED::menu[0] + 2] + (OLED::kursor == OLED::menu[0] + 2 ? " <<" : "");
            return "Battery : " + OLED::battery + "%\n---------------------\n" + modeTemplate[OLED::path[1]] + " Series?\n\n" + OLED::line1 + "\n" + OLED::line2 + "\n" + OLED::line3 + "\n";
        } else if (OLED::mode == 5) {
            OLED::line1 = OLED::indexMenu[OLED::menu[0]] + (OLED::kursor == OLED::menu[0] ? " <<" : "");
            OLED::line2 = OLED::indexMenu[OLED::menu[0] + 1] + (OLED::kursor == OLED::menu[0] + 1 ? " <<" : "");
            OLED::line3 = OLED::indexMenu[OLED::menu[0] + 2] + (OLED::kursor == OLED::menu[0] + 2 ? " <<" : "");
            return "Battery : " + OLED::battery + "%\n---------------------\n" + modeTemplate[OLED::path[1]] + " Play Index?\n\n" + OLED::line1 + "\n" + OLED::line2 + "\n" + OLED::line3 + "\n";
        } else {
            OLED::line3 = "";
            for (int i = 0; i < OLED::path.size(); i++) {
                OLED::line3 += String(OLED::path[i]);
            }
            OLED::line1 = OLED::modeTemplate[OLED::path[1]];
            OLED::line2 = (OLED::path[1] == 0 ? OLED::utilsMenu[OLED::path[2]] : OLED::modeMenu[OLED::path[2]]);

            return "Battery : " + OLED::battery + "%\n---------------------\n\n" + OLED::line1 + "\n" + OLED::line2 + "\n" + OLED::line3 + "\n";
        }
    } else {
        return "Battery : " + OLED::battery + "%\n\nChoosen Mode:\n" + OLED::currMode + "\n\nMode Played:\n" + OLED::modePlayed + "\n";
    }
}

String OLED::getCurrmodeStr() {
    return OLED::currMode;
}

void OLED::setBatteryStr(String s) {
    OLED::battery = s;
}

void OLED::setCurmodeStr(String s) {
    OLED::currMode = s;
}

void OLED::setModePlayedStr(String s) {
    OLED::modePlayed = s;
}

void OLED::moveKursorUp() {
    OLED::kursor--;
    if (kursor < OLED::menu[0] && OLED::menu[0] > 0) {
        OLED::menu[0] -= 1;
        OLED::menu[1] -= 1;
    }
    if (OLED::kursor < 0) {
        OLED::kursor = 0;
    }
}

void OLED::moveKursorDown() {
    OLED::kursor++;
    if (OLED::mode == 0) {
        if (kursor > OLED::menu[1] && OLED::menu[1] < sizeof(OLED::modeTemplate) / sizeof(OLED::modeTemplate[0]) - 1) {
            OLED::menu[0] += 1;
            OLED::menu[1] += 1;
        }
        if (OLED::kursor > sizeof(OLED::modeTemplate) / sizeof(OLED::modeTemplate[0]) - 1) {
            OLED::kursor = sizeof(OLED::modeTemplate) / sizeof(OLED::modeTemplate[0]) - 1;
        }
    } else if (OLED::mode == 1) {
        if (kursor > OLED::menu[1] && OLED::menu[1] < sizeof(OLED::utilsMenu) / sizeof(OLED::utilsMenu[0]) - 1) {
            OLED::menu[0] += 1;
            OLED::menu[1] += 1;
        }
        if (OLED::kursor > sizeof(OLED::utilsMenu) / sizeof(OLED::utilsMenu[0]) - 1) {
            OLED::kursor = sizeof(OLED::utilsMenu) / sizeof(OLED::utilsMenu[0]) - 1;
        }
    } else if (OLED::mode == 2) {
        if (kursor > OLED::menu[1] && OLED::menu[1] < sizeof(OLED::modeMenu) / sizeof(OLED::modeMenu[0]) - 1) {
            OLED::menu[0] += 1;
            OLED::menu[1] += 1;
        }
        if (OLED::kursor > sizeof(OLED::modeMenu) / sizeof(OLED::modeMenu[0]) - 1) {
            OLED::kursor = sizeof(OLED::modeMenu) / sizeof(OLED::modeMenu[0]) - 1;
        }
    } else if (OLED::mode == 3) {
        if (kursor > OLED::menu[1] && OLED::menu[1] < 1) {
            OLED::menu[0] += 1;
            OLED::menu[1] += 1;
        }
        if (OLED::kursor > 1) {
            OLED::kursor = 1;
        }
    } else if (OLED::mode == 4) {
        if (kursor > OLED::menu[1] && OLED::menu[1] < sizeof(OLED::indexMenu) / sizeof(OLED::indexMenu[0]) - 1) {
            OLED::menu[0] += 1;
            OLED::menu[1] += 1;
        }
        if (OLED::kursor > sizeof(OLED::indexMenu) / sizeof(OLED::indexMenu[0]) - 1) {
            OLED::kursor = sizeof(OLED::indexMenu) / sizeof(OLED::indexMenu[0]) - 1;
        }
    } else if (OLED::mode == 5) {
        if (kursor > OLED::menu[1] && OLED::menu[1] < sizeof(OLED::seriesMenu) / sizeof(OLED::seriesMenu[0]) - 1) {
            OLED::menu[0] += 1;
            OLED::menu[1] += 1;
        }
        if (OLED::kursor > sizeof(OLED::seriesMenu) / sizeof(OLED::seriesMenu[0]) - 1) {
            OLED::kursor = sizeof(OLED::seriesMenu) / sizeof(OLED::seriesMenu[0]) - 1;
        }
    }
}

void OLED::setMode() {
    if (OLED::mode == 0) {
        OLED::prevMode.push_back(OLED::mode);
        OLED::path.push_back(OLED::kursor);
        OLED::mode = (OLED::kursor == 0 ? 1 : 2);
        OLED::kursor = 0;
        OLED::menu[0] = 0;
        OLED::menu[1] = 2;

    } else if (OLED::mode == 2 && OLED::kursor == 1) {
        OLED::prevMode.push_back(OLED::mode);
        OLED::path.push_back(OLED::kursor);
        OLED::mode = 3;
        OLED::kursor = 0;
        OLED::menu[0] = 0;
        OLED::menu[1] = 1;

    } else if (OLED::mode == 2 && OLED::kursor == 2) {
        OLED::prevMode.push_back(OLED::mode);
        OLED::path.push_back(OLED::kursor);
        OLED::mode = 4;
        OLED::kursor = 0;
        OLED::menu[0] = 0;
        OLED::menu[1] = 2;

    } else if (OLED::mode == 3 && OLED::kursor == 1) {
        OLED::prevMode.push_back(OLED::mode);
        OLED::path.push_back(OLED::kursor);
        OLED::mode = 5;
        OLED::kursor = 0;
        OLED::menu[0] = 0;
        OLED::menu[1] = 2;
    } else {
        if (OLED::mode != 99) {
            OLED::prevMode.push_back(OLED::mode);
            OLED::path.push_back(OLED::kursor);
            OLED::mode = 99;
            OLED::kursor = 0;
            OLED::menu[0] = 0;
            OLED::menu[1] = 2;
        }
    }
}

void OLED::backMode() {
    if (OLED::prevMode.size() > 0) {
        OLED::mode = OLED::prevMode.back();
        OLED::kursor = 0;
        OLED::prevMode.pop_back();
        OLED::path.pop_back();
    }
}

void OLED::pathCallback() {
    for (int i = 0; i < OLED::path.size(); i++) {
        OLED::line3 += String(OLED::path[i]);
    }
}

String OLED::getPath() {
    String s = "";
    for (int i = 0; i < OLED::path.size(); i++) {
        s += String(OLED::path[i]);
    }
    return s;
}

bool OLED::getFocus() {
    return OLED::oledFocus;
}



// Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_SH1106 oled(-1);
void setupDisplay() {
    Serial.begin(9600);

    Wire.begin(SDA_PIN, SCL_PIN);
    oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    // if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    //     Serial.println(F("failed to start SSD1306 OLED"));
    //     // Tambahkan kode penangan kesalahan jika diperlukan
    // }

    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(WHITE);
    oled.setCursor(0, 2);
    oled.println("VI-ROSE");
    oled.display();
}

void display(String s, int n) {
    oled.setTextSize(1);
    oled.setTextColor(WHITE);
    oled.setCursor(0, 2);
    oled.clearDisplay();
    oled.println(s);
    oled.drawBitmap(100, 0, (n ? Square : CrossedSquare), 18, 12, WHITE);
    oled.display();
}

void displayLogo() {
}