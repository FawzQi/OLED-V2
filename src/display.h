#ifndef _display_h
#define _display_h

#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <Wire.h>

#include <vector>

using namespace std;

#define SCREEN_WIDTH 128  // OLED width,  in pixels
#define SCREEN_HEIGHT 64  // OLED height, in pixels
#define SDA_PIN 21        // I2C SDA
#define SCL_PIN 22        // I2C SCL

// Gambar bitmap persegi battery
static const unsigned char PROGMEM Square[] =
    {
        0b01111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11000000,
        0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000000,
        0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000000,
        0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000000,
        0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000000,
        0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000000,
        0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000000,
        0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000000,
        0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000000,
        0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000000,
        0b01111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11000000};

// Gambar bitmap persegi silang
static const unsigned char PROGMEM CrossedSquare[] =
    {
        0b11111111, 0b11111111, 0b11000000,
        0b11010101, 0b01010101, 0b01000000,
        0b10101010, 0b10101010, 0b11000000,
        0b11010101, 0b01010101, 0b01000000,
        0b10101010, 0b10101010, 0b11000000,
        0b11010101, 0b01010101, 0b01000000,
        0b10101010, 0b10101010, 0b11000000,
        0b11010101, 0b01010101, 0b01000000,
        0b10101010, 0b10101010, 0b11000000,
        0b11010101, 0b01010101, 0b01000000,
        0b10101010, 0b10101010, 0b11000000,
        0b11111111, 0b11111111, 0b11000000};

const unsigned char PROGMEM frame13[] = {0x00, 0x07, 0xE0, 0x00, 0x00, 0x0C, 0x30, 0x00, 0x00, 0x0C, 0x30, 0x00, 0x00, 0x08, 0x10, 0x00, 0x00, 0x0C, 0x30, 0x00, 0x00, 0x0F, 0xFC, 0x00, 0x00, 0x0F, 0xFC, 0x00, 0x00, 0x0C, 0x30, 0x00, 0x00, 0x08, 0x3C, 0x00, 0x00, 0x0C, 0x1C, 0x00, 0x00, 0x08, 0x30, 0x00, 0x00, 0x0C, 0x1E, 0x00, 0x00, 0x08, 0x30, 0x00, 0x00, 0x0C, 0x1C, 0x00, 0x00, 0x08, 0x3C, 0x00, 0x00, 0x0C, 0x10, 0x00, 0x00, 0x08, 0x3C, 0x00, 0x00, 0x0C, 0x30, 0x00, 0x00, 0x38, 0x1C, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x60, 0x06, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0xC0, 0x02, 0x00, 0x00, 0x60, 0x06, 0x00, 0x00, 0x60, 0x06, 0x00, 0x00, 0x38, 0x1C, 0x00, 0x00, 0x1E, 0xF8, 0x00, 0x00, 0x07, 0xE0, 0x00};

class OLED {
   private:
    const String modeTemplate[10] = {"UTILITY", "MODE_A", "MODE_B", "MODE_C", "MODE_D", "MODE_E", "MODE_F", "MODE_G", "MODE_H", "MODE_XDD"};  // Nama mode dalam menu awal
    const String utilsMenu[5] = {"TORQUE_ON/OFF", "GET_MX", "GET_XL", "GET_INDEX", "SET_INDEX"};                                              // Pilihan menu ketika masuk ke utility
    const String modeMenu[5] = {"INIT", "PLAY", "SERIES", "PAUSE", "RESUME"};                                                                 // Pilihan menu ketika masuk ke mode
    const String indexMenu[6] = {"INDEX_1", "INDEX_2", "INDEX_3", "INDEX_4", "INDEX_5", "INDEX_XDD"};                                         // Pilihan menu ketika masuk ke mode > play > play by index
    const String seriesMenu[6] = {"SERIES_1", "SERIES_2", "SERIES_3", "SERIES_4", "SERIES_5", "SERIES_XDD"};                                  // Pilihan menu ketika masuk ke mode > series

    bool oledFocus = false;
    bool OLED_callback = false;
    bool trigger = false;
    // Boolean untuk mode fokus oled atau tidak
    // bool motionDone = (millis() - modeDuration >= lastDebounceTime ? true : false);

    int battery = 100;                 // Battery percentage
    String currMode = "Just Started";  // Current mode
    String modePlayed = "UwU";         // Mode played

    String line1;  // Line 1 untuk pilihan menu
    String line2;  // Line 2 untuk pilihan menu
    String line3;  // Line 3 untuk pilihan menu

    int mode = 0;          // Mode yang sedang dipilih
    int kursor;            // Posisi Kursor yang sedang dipilih
    int menu[2] = {0, 2};  // Batas banyak pilihan menut

    unsigned long lastDebounceTime = 0;  // Last time the button was pressed
    unsigned long timeOut = 10000;       // Durasi mode yang sedang dipilih

    vector<int> prevMode;    // Mode sebelumnya
    vector<int> path = {0};  // Path yang sedang dipilih

   public:
    String show();                    // Returns the string to be displayed on the OLED
    String getCurrmodeStr();          // Returns the current mode
    String getPath();                 // Returns the current mode
    void setBatteryStr(int s);        // Sets the battery percentage
    void setCurmodeStr(String s);     // Sets the current mode
    void setModePlayedStr(String s);  // Sets the mode played
    void moveKursorUp();              // Moves the cursor up
    void moveKursorDown();            // Moves the cursor down
    void setMode();                   // Choose the mode
    void backMode();                  // Back to previous mode
    void pathCallback();              // Callback for the path
    void switchFocus();               // Switches the focus
    void setOLED_callback();          // Sets the OLED callback
    void trigActive();
    void oledTimeout();
    bool getFocus();          // Returns the focus
    bool getOLED_callback();  // Returns the OLED callback
};

extern OLED displayRobot;

#endif
