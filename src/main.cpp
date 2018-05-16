#include <Wire.h>
//#include <Adafruit_SSD1331.h>
#include "ssd1331.h" 
#include "examples/bmp/bmp.h"
 
#define WIDTH      96 // Set Width Size
#define HEIGHT     64 // Set Height Size
#define PAGES       8 // Set  Page to 8
 
#define OLED_RST    9  // Set pin REST to MCU Reset Pin
#define OLED_DC     8  //  Set pin DC tot MCU Pin D8
#define OLED_CS    10  // Set pin CS to MCU Pin D10
#define SPI_MOSI   11  // connect to the DIN pin of OLED 
#define SPI_SCK    13  // connect to the CLK pin of OLED 
 
uint8_t oled_buf[WIDTH * HEIGHT / 8];
int speed_factor(0);
 
void setup() {
    /*EXECUTE ONCE*/
    Serial.begin(9600);
    Serial.print("14CORE | OLED RGB TEST CODE\n");
    Serial.print("Initializing..... ");
    delay(4000);

    SSD1331_begin(); //Set start SSD1331 Initialize
    SSD1331_clear(); //Set to clear OLED Screen Display

    SSD1331_mono_bitmap(0, 0, waveshare_logo, 96, 64, BLUE);   /* display an image of bitmap matrix */
    delay(2000);
    SSD1331_clear();


    SSD1331_mono_bitmap(0, 2, Signal816, 16, 8, GOLDEN); 
    SSD1331_mono_bitmap(19, 2, Msg816, 16, 8, GOLDEN); 
    SSD1331_mono_bitmap(38, 2, Bluetooth88, 8, 8, GOLDEN); 
    SSD1331_mono_bitmap(52, 2, GPRS88, 8, 8, GOLDEN); 
    SSD1331_mono_bitmap(66, 2, Alarm88, 8, 8, GOLDEN); 
    SSD1331_mono_bitmap(80, 2, Bat816, 16, 8, GOLDEN); 

    // Set string display color
    SSD1331_string(0, 52, "14CORE", 12, 0, WHITE); 
    SSD1331_string(64, 52, "TEST", 12, 1, WHITE);

    /* Set to display strings 32x16 */
    SSD1331_char3216(0,16, '1', BLUE);
    SSD1331_char3216(16,16, '2', BLUE);
    SSD1331_char3216(40,16, ':', RED);
    SSD1331_char3216(64,16, '3', GREEN);
    SSD1331_char3216(80,16, '4', GREEN);
}
 
void loop() {
    SSD1331_begin();
    //char violet[11] = "violet.bmp";
    //bmpDraw(violet, 0, 0);
    char status[7] = "status";
    SSD1331_string(0, 0, status, 16, 1, RED);
    char status_val[2] = "2";
    SSD1331_string(55, 0, status_val, 16, 1, GOLDEN);
    char vel_name[2] = "v";
    SSD1331_string(0, 16, vel_name, 16, 1, BLUE);
    String in_val(speed_factor*0.1, 1);
    char vel_data[in_val.length()+1];
    in_val.toCharArray(vel_data, in_val.length()+1);
    SSD1331_string(16, 16, vel_data, 16, 1, GOLDEN);
    char speed_heading[8] = "heading";
    SSD1331_string(0, 32, speed_heading, 16, 1, GREEN);
    String heading_val(4);
    char heading_val_char[heading_val.length()+1];
    heading_val.toCharArray(heading_val_char, heading_val.length()+1);
    Serial.print("rand: "+heading_val+"\n");
    SSD1331_string(60, 32, heading_val_char, 16, 1, GOLDEN);
    delay(500);
    SSD1331_clear();
    speed_factor += 1;
    if (speed_factor > 20) {
        speed_factor = 0;
    }
}