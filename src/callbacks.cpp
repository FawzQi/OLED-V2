#include <display.h>
// void on_serial_recv_cb(const uint8_t *data, int len, uint8_t mac_index) {
//     DEBUG_PRINTF("[SERIAL] RECV Data: ");
//     for (int i = 0; i < len; i++) DEBUG_PRINTF("%d ", data[i]);
//     DEBUG_PRINTF("\n");

//     COMMAND receive_cmd = (COMMAND)data[0];

//     switch (receive_cmd) {
//         case 0 ... 30:
//             postCommand(receive_cmd, (uint8_t *)data, len, mac_index);
//             break;
//         case 31 ... 60:
//             getCommand(receive_cmd, mac_index);
//             break;
//         default:
//             break;
//     }
// }

// void on_data_sent_cb(const uint8_t *mac, esp_now_send_status_t status) {
//     uint8_t mac_index = getMACIndex(mac);

//     DEBUG_PRINTF("[ESP-NOW] SEND to %d, Status: %d\n", mac_index, status);
// }

// void on_data_recv_cb(const uint8_t *mac, const uint8_t *data, int len) {
//     int8_t mac_index = getMACIndex(mac);

//     DEBUG_PRINTF("[ESP-NOW] RECV from %d, Data: ", mac_index);
//     for (int i = 0; i < len; i++) DEBUG_PRINTF("%d ", data[i]);
//     DEBUG_PRINTF("\n");

//     COMMAND receive_cmd = (COMMAND)data[0];

//     switch (receive_cmd) {
//         case 0 ... 30:
//             postCommand(receive_cmd, (uint8_t *)data, len, mac_index);
//             break;
//         case 31 ... 60:
//             getCommand(receive_cmd, mac_index);
//             break;
//         default:
//             break;
//     }
// }

// uint8_t data_button[2];
// uint8_t mac_index = ESP_MAC_INDEX == 0 ? 1 : 3;

void Button_Mode_A_Callback() {
    if (!displayRobot.getFocus()) {
        displayRobot.setCurmodeStr("MODE_A");
    } else {
        displayRobot.moveKursorUp();
    }
    // DEBUG_PRINTF("[Button] Mode A\n");
    // data_button[0] = POST_MOTION_PLAY;
    // data_button[1] = 0;
}

void Button_Mode_A_Hold_Callback() {
    // DEBUG_PRINTF("[Button] Mode A Hold 1s\n");
    // data_button[0] = POST_SERVO_ACTIVE_TORQUE;
    displayRobot.setCurmodeStr("MODE_A_HOLD_1S");
}

void Button_Mode_A_2_Sequence_Callback() {
    if (!displayRobot.getFocus()) {
        displayRobot.setCurmodeStr("MODE_A_2_SEQUENCE");
    }
    // DEBUG_PRINTF("[Button] Mode A Sequence\n");
    // data_button[0] = POST_MOTION_PLAY;
    // data_button[1] = 1;
}

void Button_Mode_A_3_Sequence_Callback() {
    if (!displayRobot.getFocus()) {
        displayRobot.setCurmodeStr("MODE_A_3_SEQUENCE");
    }
    // DEBUG_PRINTF("[Button] Mode A Sequence\n");
}

void Button_Mode_B_Callback() {
    if (!displayRobot.getFocus()) {
        displayRobot.setCurmodeStr("MODE_B");
    } else {
        displayRobot.moveKursorDown();
    }
    // DEBUG_PRINTF("[Button] Mode B\n");
    // data_button[0] = POST_MOTION_PLAY;
    // data_button[1] = esp_info.index;
}

void Button_Mode_B_Hold_Callback() {
    // DEBUG_PRINTF("[Button] Mode B Hold 1s\n");
    // data_button[0] = POST_SERVO_ACTIVE_TORQUE;
    if (!displayRobot.getFocus()) {
        displayRobot.setCurmodeStr("MODE_B_HOLD_1S");
    }
}

void Button_Mode_B_2_Sequence_Callback() {
    // DEBUG_PRINTF("[Button] Mode B Sequence\n");
    // data_button[0] = POST_MOTION_PAUSE;
    if (!displayRobot.getFocus()) {
        displayRobot.setCurmodeStr("MODE_B_2_SEQUENCE");
    }
}

void Button_Mode_B_3_Sequence_Callback() {
    // DEBUG_PRINTF("[Button] Mode B Sequence\n");
    // data_button[0] = POST_MOTION_RESUME;
    if(!displayRobot.getFocus()){
    
    displayRobot.setCurmodeStr("MODE_B_3_SEQUENCE");}
}

void Button_Trig_Callback() {
    // DEBUG_PRINTF("[Button] Trigger\n");
    // esp_now_send(mac_addresses[mac_index], data_button, 2);
    if(!displayRobot.getFocus()){
    displayRobot.setModePlayedStr(displayRobot.getCurrmodeStr());} else
    {displayRobot.setMode();}
    
}

void Button_Trig_2_Sequence_Callback() {
    // DEBUG_PRINTF("[Button] Trig 2 Sequence\n");
    // data_button[0] = POST_MOTION_PAUSE;
    // esp_now_send(mac_addresses[mac_index], data_button, 2);
   if(displayRobot.getFocus()){
    displayRobot.backMode();} 
}

void Button_Trig_Hold_Callback() {
    displayRobot.switchFocus();
    // DEBUG_PRINTF("[Button] Trig Hold 1s\n");
}

// void serial_event() {
//     int serial_cmd = 0;
//     if (Serial.available())
//         serial_cmd = Serial.parseInt();
//     else
//         return;

//     DEBUG_PRINTF("[DEBUG] Serial Command: %d\n", serial_cmd);

//     if (serial_cmd == 1) {
//         int mac_index = Serial.parseInt();
//         int command = Serial.parseInt();

//         uint8_t data_sent[1];
//         data_sent[0] = command;

//         DEBUG_PRINTF("[DEBUG] Send to %d, Command: %d\n", mac_index, command);

//         esp_now_send(mac_addresses[mac_index], data_sent, 1);
//     }

//     if (serial_cmd == 2) {
//         int mac_index = Serial.parseInt();
//         int command = Serial.parseInt();
//         int data = Serial.parseInt();
//         uint16_t data2 = Serial.parseInt();

//         uint8_t data_sent[4];
//         data_sent[0] = command;
//         data_sent[1] = data;
//         data_sent[2] = data2 >> 8;
//         data_sent[3] = data2 & 0xFF;

//         DEBUG_PRINTF("[DEBUG] Send to %d, Command: %d, Data: %d\n", mac_index, command, data);

//         esp_now_send(mac_addresses[mac_index], data_sent, sizeof(data_sent));
//     }

//     if (serial_cmd == 3) {
//         int mac_index = Serial.parseInt();
//         uint8_t data_sent[4];
//         data_sent[0] = POST_MOTION_PLAY;
//         data_sent[1] = 2;
//         data_sent[2] = 100;
//         data_sent[3] = 2;
//         esp_now_send(mac_addresses[mac_index], data_sent, sizeof(data_sent));
//     }

//     while (Serial.available()) Serial.read();
// }