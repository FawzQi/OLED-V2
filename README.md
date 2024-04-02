# Nama Program

Berisi program untuk pengoperasian oled sesuai kebutuhan dari VIROSE saat ini (Maret 2024). OLED ini dibuat dalam 2 mode 1. saat mode fokus OLED, untuk memilih/memutar mode harus melihat pilihan menu scrolling OLED dan 2. mode tidak fokus OLED, untuk memilih\memutar OLED tidak perlu melakukan scroling pada pilihan menu tapi melakukan kombinasi pencetan tombol.

tampilan oled dalam lib ini ada 2 macam mode

1 mode oled focus

```
ilustrasi tampilan
_____________________________
| Battery : XX%             |
|                           |
|                           |
| UTILITY   <<              |
| MODE_A                    |
| MODE_B                    |
|___________________________|
```

dikontrol denan 2 tombol untuk menggerakkan kursor "<<" atas ke bawah dan 1 tombol sebagai tombol enter.

Struktur pilihan menunya :

- mode
  - init
  - play
    - play full
    - play by index
      - list index
  - series
    - list series
  - pause
  - resume
- utility
  - torque on/off
  - get mx
  - get xl
  - get index
  - send index

2 mode oled focus = false

ilustrasi tampilan

```
tampilan awal                        tampilan saat mode dipilih
_____________________________       _____________________________
| Battery : XX%             |       | Battery : XX%             |
|  ______________________   |       |                           |
|  | "ini gambar inisial |  |       |  choosen mode             |
|  |  mode dengan ukuran |  |       |  name mode                |
|  |  setTextSize(5)"    |  |       |                           |
|  |_____________________|  |       |                           |
|___________________________|       |___________________________|
```

dikontrol dengan melakukan kombinan tekanan tombol untuk mengganti mode

# Instalasi

1. Clone Repository ini
2. Instal Library berikut

```
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <Wire.h>
#include <vector>
```

## Penggunaan

Cara menggunakan program ini:

1. Atur nilai panjang dan lebar layar, serta pin sda dan scl OLED di file display.h

```
#define SCREEN_WIDTH 128  // OLED width,  in pixels
#define SCREEN_HEIGHT 64  // OLED height, in pixels
#define SDA_PIN 25        // I2C SDA
#define SCL_PIN 14        // I2C SCL
```

---

2. Inisiasi class "OLED" untuk mengatur tampilan OLED di file display.h (silahkan ganti nama jika berkenan UwU)

```
OLED displayRobot; //tulis di dalam file main.cpp
extern OLED displayRobot; //tulis di dalam file display.h
```

---

3. Pilihan Isi menu class OLED

```
const String modeTemplate[10] = {"UTILITY", "MODE_A", "MODE_B", "MODE_C", "MODE_D", "MODE_E", "MODE_F", "MODE_G", "MODE_H", "MODE_XDD"};  // Nama mode dalam menu awal

```

- Merupakan tempat untuk menampung banyaknya pilihan menu pada menu utama saat mode focus oled (tambahkan atau kurangi sesuai kebutuhan)

```
const String utilsMenu[5] = {"TORQUE_ON/OFF", "GET_MX", "GET_XL", "GET_INDEX", "SET_INDEX"};                                              // Pilihan menu ketika masuk ke utility

```

- Merupakan tempat untuk menampung banyaknya pilihan menu pada menu utility saat mode focus oled (tambahkan atau kurangi sesuai kebutuhan)

```
const String modeMenu[5] = {"INIT", "PLAY", "SERIES", "PAUSE", "RESUME"};                                                                 // Pilihan menu ketika masuk ke mode

```

- Merupakan tempat untuk menampung banyaknya pilihan menu pada menu mode saat mode focus oled (tambahkan atau kurangi sesuai kebutuhan)

```
const String indexMenu[6] = {"INDEX_1", "INDEX_2", "INDEX_3", "INDEX_4", "INDEX_5", "INDEX_XDD"};                                         // Pilihan menu ketika masuk ke mode > play > play by index

```

- Merupakan tempat untuk menampung banyaknya pilihan menu pada menu mode play by index saat mode focus oled (tambahkan atau kurangi sesuai kebutuhan)

```
const String seriesMenu[6] = {"SERIES_1", "SERIES_2", "SERIES_3", "SERIES_4", "SERIES_5", "SERIES_XDD"};                                  // Pilihan menu ketika masuk ke mode > series
```

- Merupakan tempat untuk menampung banyaknya pilihan menu pada menu mode play by index saat mode focus oled (tambahkan atau kurangi sesuai kebutuhan)

---

4. Fungsi-fungsi
   Setelah menyesuaikan banyak pilihan menu pada oleh, tinggal atur mekanisme pengaturan oled sesuai dengan tombol atau menkanisme kontrol olednya

```
String show();                    // Returns the string to be displayed on the OLED
void switchFocus();               // Switches the focus
bool getFocus();                  // Returns the focus

String getCurrmodeStr();          // Returns the current mode gunakan saat mode tidak fokus oled
void setBatteryStr(String s);     // Sets the battery percentage gunakan saat mode tidak fokus oled
void setCurmodeStr(String s);     // Sets the current mode gunakan saat mode tidak fokus oled
void setModePlayedStr(String s);  // Sets the mode played gunakan saat mode tidak fokus oled

String getPath();                 // Returns the current mode gunakan saat mode fokus oled
void moveKursorUp();              // Moves the cursor up gunakan saat mode fokus oled
void moveKursorDown();            // Moves the cursor down gunakan saat mode fokus oled
void setMode();                   // Choose the mode gunakan saat mode fokus oled
void backMode();                  // Back to previous mode gunakan saat mode fokus oled
void pathCallback();              // Callback for the path gunakan saat mode fokus oled
```

## Kontribusi

Jika kamu ingin berkontribusi pada program ini, silakan ikuti langkah-langkah berikut:

1. Fork repositori ini
2. Buat branch baru
3. Lakukan perubahan
4. Buat pull request

## Lisensi

Ga tau

## Kontak

Jika kamu memiliki pertanyaan atau masukan, silakan hubungi kami di:

- Email: [ahamdfaiqfawwaz@gmail.com]
