#ifndef OLED_H
#define OLED_H
#include <SPI.h>

#define OLED_RESET 13
#define OLED_CS 12
#define OLED_CD A0

//#define CLR_TIM    digitalWrite(9,LOW)
//__asm__("nop\n\t");
//#define SET_TIM    digitalWrite(9,HIGH)

#define CLR_RS    digitalWrite(OLED_CD,LOW)
#define SET_RS    digitalWrite(OLED_CD,HIGH)
#define CLR_RESET digitalWrite(OLED_RESET,LOW)
#define SET_RESET digitalWrite(OLED_RESET,HIGH)
#define CLR_CS    digitalWrite(OLED_CS,LOW)
#define SET_CS    digitalWrite(OLED_CS,HIGH)
#define CLR_MOSI  //UNUSED
#define SET_MOSI  //UNUSED
#define CLR_SCK   //UNUSED
#define SET_SCK   //UNUSED

//============================================================================
void SPI_sendCommand(uint8_t command)
  {
  // Select the OLED's command register
  CLR_RS;
  // Select the OLED controller
  CLR_CS;
  //Send the command via SPI:
  SPI.transfer(command);
  // Deselect the OLED controller
  SET_CS;
  }
//----------------------------------------------------------------------------
void SPI_sendData(uint8_t data)
  {
  // Select the OLED's data register
  SET_RS;
  // Select the OLED controller
  CLR_CS;
  //Send the data via SPI:
  SPI.transfer(data);
  // Deselect the OLED controller
  SET_CS;
  }
//============================================================================
// Defines for the LD7138 registers.
// ref: https://www.crystalfontz.com/controllers/LDT/LD7138/
#define LD7138_0x01_SOFTRES                (0x01)
#define LD7138_0x02_DISPLAY_ON_OFF         (0x02)
#define LD7138_0x03_DISPLAY_STANDBY_ON_OFF (0x03)
#define LD7138_0x04_OSCILLATOR_SPEED       (0x04)
#define LD7138_0x05_WRITE_DIRECTION        (0x05)
#define LD7138_0x06_SCAN_DIRECTION         (0x06)
#define LD7138_0x07_SET_DISPLAY_WINDOW     (0x07)
#define LD7138_0x08_IF_BUS_SEL             (0x08)
#define LD7138_0x09_DATA_MASKING           (0x09)
#define LD7138_0x0A_SET_DATA_WINDOW        (0x0A)
#define LD7138_0x0B_SET_ADDRESS            (0x0B)
#define LD7138_0x0C_DATA_WRITE_READ        (0x0C)
#define LD7138_0x0D_REGISTER_READ          (0x0D)
#define LD7138_0x0E_RGB_CURRENT_LEVEL      (0x0E)
#define LD7138_0x0F_PEAK_CURRENT_LEVEL     (0x0F)
#define LD7138_0x10_SCLK                   (0x10)
#define LD7138_0x1C_PRE_CHARGE_WIDTH       (0x1C)
#define LD7138_0x1C_SET_PEAK_WIDTH         (0x1D)
#define LD7138_0x1E_SET_PEAK_DELAY         (0x1E)
#define LD7138_0x1F_SET_ROW_SCAN           (0x1F)
#define LD7138_0x30_VCC_R_SELECT           (0x30)
#define LD7138_0x34_RGB_MODE               (0x34)
#define LD7138_0x3A_GAMMA_TUNE             (0x3A)
#define LD7138_0x3B_GAMMA_INIT             (0x3B)
#define LD7138_0x3C_SET_VDD_SELECTION      (0x3C)
#define LD7138_0x3E_TEST                   (0x3E)
//============================================================================

const uint8_t FreeSans12pt7bBitmaps[] PROGMEM = {
  0xFF, 0xFF, 0xFF, 0xF0, 0xF0, 0xCF, 0x3C, 0xF3, 0x8A, 0x20, 0x06, 0x30,
  0x31, 0x03, 0x18, 0x18, 0xC7, 0xFF, 0xBF, 0xFC, 0x31, 0x03, 0x18, 0x18,
  0xC7, 0xFF, 0xBF, 0xFC, 0x31, 0x01, 0x18, 0x18, 0xC0, 0xC6, 0x06, 0x30,
  0x04, 0x03, 0xE1, 0xFF, 0x72, 0x6C, 0x47, 0x88, 0xF1, 0x07, 0x20, 0x7E,
  0x03, 0xF0, 0x17, 0x02, 0x3C, 0x47, 0x88, 0xF1, 0x1B, 0x26, 0x7F, 0xC3,
  0xE0, 0x10, 0x02, 0x00, 0x00, 0x06, 0x03, 0xC0, 0x40, 0x7E, 0x0C, 0x0E,
  0x70, 0x80, 0xC3, 0x18, 0x0C, 0x31, 0x00, 0xE7, 0x30, 0x07, 0xE6, 0x00,
  0x3C, 0x40, 0x00, 0x0C, 0x7C, 0x00, 0x8F, 0xE0, 0x19, 0xC7, 0x01, 0x18,
  0x30, 0x31, 0x83, 0x02, 0x1C, 0x70, 0x40, 0xFE, 0x04, 0x07, 0xC0, 0x0F,
  0x00, 0x7E, 0x03, 0x9C, 0x0C, 0x30, 0x30, 0xC0, 0xE7, 0x01, 0xF8, 0x03,
  0x80, 0x3E, 0x01, 0xCC, 0x6E, 0x19, 0xB0, 0x7C, 0xC0, 0xF3, 0x03, 0xCE,
  0x1F, 0x9F, 0xE6, 0x1E, 0x1C, 0xFF, 0xA0, 0x08, 0x8C, 0x66, 0x31, 0x98,
  0xC6, 0x31, 0x8C, 0x63, 0x08, 0x63, 0x08, 0x61, 0x0C, 0x20, 0x82, 0x18,
  0xC3, 0x18, 0xC3, 0x18, 0xC6, 0x31, 0x8C, 0x62, 0x31, 0x88, 0xC4, 0x62,
  0x00, 0x10, 0x23, 0x5B, 0xE3, 0x8D, 0x91, 0x00, 0x0C, 0x03, 0x00, 0xC0,
  0x30, 0xFF, 0xFF, 0xF0, 0xC0, 0x30, 0x0C, 0x03, 0x00, 0xC0, 0xF5, 0x60,
  0xFF, 0xF0, 0xF0, 0x02, 0x0C, 0x10, 0x20, 0xC1, 0x02, 0x0C, 0x10, 0x20,
  0xC1, 0x02, 0x0C, 0x10, 0x20, 0xC1, 0x00, 0x1F, 0x07, 0xF1, 0xC7, 0x30,
  0x6E, 0x0F, 0x80, 0xF0, 0x1E, 0x03, 0xC0, 0x78, 0x0F, 0x01, 0xE0, 0x3C,
  0x0E, 0xC1, 0x9C, 0x71, 0xFC, 0x1F, 0x00, 0x08, 0xCF, 0xFF, 0x8C, 0x63,
  0x18, 0xC6, 0x31, 0x8C, 0x63, 0x18, 0x1F, 0x0F, 0xF9, 0x87, 0x60, 0x7C,
  0x06, 0x00, 0xC0, 0x18, 0x07, 0x01, 0xC0, 0xF0, 0x78, 0x1C, 0x06, 0x00,
  0x80, 0x30, 0x07, 0xFF, 0xFF, 0xE0, 0x3F, 0x0F, 0xF3, 0x87, 0x60, 0x6C,
  0x0C, 0x01, 0x80, 0x70, 0x7C, 0x0F, 0x80, 0x18, 0x01, 0x80, 0x3C, 0x07,
  0x80, 0xD8, 0x73, 0xFC, 0x1F, 0x00, 0x01, 0x80, 0x70, 0x0E, 0x03, 0xC0,
  0xD8, 0x1B, 0x06, 0x61, 0x8C, 0x21, 0x8C, 0x33, 0x06, 0x7F, 0xFF, 0xFE,
  0x03, 0x00, 0x60, 0x0C, 0x01, 0x80, 0x3F, 0xCF, 0xF9, 0x80, 0x30, 0x06,
  0x00, 0xDE, 0x1F, 0xE7, 0x0E, 0x00, 0xE0, 0x0C, 0x01, 0x80, 0x30, 0x07,
  0x81, 0xF8, 0x73, 0xFC, 0x1F, 0x00, 0x0F, 0x07, 0xF9, 0xC3, 0x30, 0x74,
  0x01, 0x80, 0x33, 0xC7, 0xFE, 0xF0, 0xDC, 0x1F, 0x01, 0xE0, 0x3C, 0x06,
  0xC1, 0xDC, 0x71, 0xFC, 0x1F, 0x00, 0xFF, 0xFF, 0xFC, 0x01, 0x00, 0x60,
  0x18, 0x02, 0x00, 0xC0, 0x30, 0x06, 0x01, 0x80, 0x30, 0x04, 0x01, 0x80,
  0x30, 0x06, 0x01, 0x80, 0x30, 0x00, 0x1F, 0x07, 0xF1, 0xC7, 0x30, 0x66,
  0x0C, 0xC1, 0x8C, 0x61, 0xFC, 0x3F, 0x8E, 0x3B, 0x01, 0xE0, 0x3C, 0x07,
  0x80, 0xD8, 0x31, 0xFC, 0x1F, 0x00, 0x1F, 0x07, 0xF1, 0xC7, 0x70, 0x6C,
  0x07, 0x80, 0xF0, 0x1E, 0x07, 0x61, 0xEF, 0xFC, 0x79, 0x80, 0x30, 0x05,
  0x81, 0x98, 0x73, 0xFC, 0x1E, 0x00, 0xF0, 0x00, 0x03, 0xC0, 0xF0, 0x00,
  0x0F, 0x56, 0x00, 0x00, 0x07, 0x01, 0xE0, 0xF8, 0x3C, 0x0F, 0x00, 0xE0,
  0x07, 0xC0, 0x0F, 0x00, 0x3C, 0x00, 0xF0, 0x01, 0xFF, 0xFF, 0xFF, 0x00,
  0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x0E, 0x00, 0x78, 0x01, 0xF0, 0x07,
  0xC0, 0x0F, 0x00, 0x70, 0x1E, 0x0F, 0x03, 0xC0, 0xF0, 0x08, 0x00, 0x1F,
  0x1F, 0xEE, 0x1B, 0x03, 0xC0, 0xC0, 0x30, 0x0C, 0x06, 0x03, 0x81, 0xC0,
  0xE0, 0x30, 0x0C, 0x03, 0x00, 0x00, 0x00, 0x0C, 0x03, 0x00, 0x00, 0xFE,
  0x00, 0x0F, 0xFE, 0x00, 0xF0, 0x3E, 0x07, 0x00, 0x3C, 0x38, 0x00, 0x30,
  0xC1, 0xE0, 0x66, 0x0F, 0xD9, 0xD8, 0x61, 0xC3, 0xC3, 0x07, 0x0F, 0x1C,
  0x1C, 0x3C, 0x60, 0x60, 0xF1, 0x81, 0x83, 0xC6, 0x06, 0x1B, 0x18, 0x38,
  0xEE, 0x71, 0xE7, 0x18, 0xFD, 0xF8, 0x71, 0xE7, 0xC0, 0xE0, 0x00, 0x01,
  0xE0, 0x00, 0x01, 0xFF, 0xC0, 0x01, 0xFC, 0x00, 0x03, 0xC0, 0x03, 0xC0,
  0x03, 0xC0, 0x07, 0xE0, 0x06, 0x60, 0x06, 0x60, 0x0E, 0x70, 0x0C, 0x30,
  0x0C, 0x30, 0x1C, 0x38, 0x18, 0x18, 0x1F, 0xF8, 0x3F, 0xFC, 0x30, 0x1C,
  0x30, 0x0C, 0x70, 0x0E, 0x60, 0x06, 0x60, 0x06, 0xFF, 0xC7, 0xFF, 0x30,
  0x19, 0x80, 0x6C, 0x03, 0x60, 0x1B, 0x00, 0xD8, 0x0C, 0xFF, 0xC7, 0xFF,
  0x30, 0x0D, 0x80, 0x3C, 0x01, 0xE0, 0x0F, 0x00, 0x78, 0x06, 0xFF, 0xF7,
  0xFE, 0x00, 0x07, 0xE0, 0x3F, 0xF0, 0xE0, 0x73, 0x80, 0x66, 0x00, 0x6C,
  0x00, 0x30, 0x00, 0x60, 0x00, 0xC0, 0x01, 0x80, 0x03, 0x00, 0x06, 0x00,
  0x06, 0x00, 0x6C, 0x00, 0xDC, 0x03, 0x1E, 0x0E, 0x1F, 0xF8, 0x0F, 0xC0,
  0xFF, 0x83, 0xFF, 0x8C, 0x07, 0x30, 0x0E, 0xC0, 0x1B, 0x00, 0x7C, 0x00,
  0xF0, 0x03, 0xC0, 0x0F, 0x00, 0x3C, 0x00, 0xF0, 0x03, 0xC0, 0x1F, 0x00,
  0x6C, 0x03, 0xB0, 0x1C, 0xFF, 0xE3, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xC0,
  0x0C, 0x00, 0xC0, 0x0C, 0x00, 0xC0, 0x0C, 0x00, 0xFF, 0xEF, 0xFE, 0xC0,
  0x0C, 0x00, 0xC0, 0x0C, 0x00, 0xC0, 0x0C, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0x00, 0x60, 0x0C, 0x01, 0x80, 0x30, 0x06, 0x00, 0xFF, 0xDF,
  0xFB, 0x00, 0x60, 0x0C, 0x01, 0x80, 0x30, 0x06, 0x00, 0xC0, 0x18, 0x00,
  0x07, 0xF0, 0x1F, 0xFC, 0x3C, 0x1E, 0x70, 0x06, 0x60, 0x03, 0xE0, 0x00,
  0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x7F, 0xC0, 0x7F, 0xC0, 0x03, 0xC0, 0x03,
  0x60, 0x03, 0x60, 0x07, 0x30, 0x0F, 0x3C, 0x1F, 0x1F, 0xFB, 0x07, 0xE1,
  0xC0, 0x1E, 0x00, 0xF0, 0x07, 0x80, 0x3C, 0x01, 0xE0, 0x0F, 0x00, 0x78,
  0x03, 0xFF, 0xFF, 0xFF, 0xF0, 0x07, 0x80, 0x3C, 0x01, 0xE0, 0x0F, 0x00,
  0x78, 0x03, 0xC0, 0x1E, 0x00, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x01,
  0x80, 0xC0, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x01, 0x80, 0xC0, 0x60,
  0x3C, 0x1E, 0x0F, 0x07, 0xC7, 0x7F, 0x1F, 0x00, 0xC0, 0x3B, 0x01, 0xCC,
  0x0E, 0x30, 0x70, 0xC3, 0x83, 0x1C, 0x0C, 0xE0, 0x33, 0x80, 0xDE, 0x03,
  0xDC, 0x0E, 0x38, 0x30, 0x60, 0xC1, 0xC3, 0x03, 0x8C, 0x06, 0x30, 0x1C,
  0xC0, 0x3B, 0x00, 0x60, 0xC0, 0x30, 0x0C, 0x03, 0x00, 0xC0, 0x30, 0x0C,
  0x03, 0x00, 0xC0, 0x30, 0x0C, 0x03, 0x00, 0xC0, 0x30, 0x0C, 0x03, 0x00,
  0xFF, 0xFF, 0xF0, 0xE0, 0x07, 0xE0, 0x07, 0xF0, 0x0F, 0xF0, 0x0F, 0xD0,
  0x0F, 0xD8, 0x1B, 0xD8, 0x1B, 0xD8, 0x1B, 0xCC, 0x33, 0xCC, 0x33, 0xCC,
  0x33, 0xC6, 0x63, 0xC6, 0x63, 0xC6, 0x63, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3,
  0xC3, 0xC1, 0x83, 0xE0, 0x1F, 0x00, 0xFC, 0x07, 0xE0, 0x3D, 0x81, 0xEE,
  0x0F, 0x30, 0x79, 0xC3, 0xC6, 0x1E, 0x18, 0xF0, 0xE7, 0x83, 0x3C, 0x1D,
  0xE0, 0x6F, 0x01, 0xF8, 0x0F, 0xC0, 0x3E, 0x01, 0xC0, 0x03, 0xE0, 0x0F,
  0xFC, 0x0F, 0x07, 0x86, 0x00, 0xC6, 0x00, 0x33, 0x00, 0x1B, 0x00, 0x07,
  0x80, 0x03, 0xC0, 0x01, 0xE0, 0x00, 0xF0, 0x00, 0x78, 0x00, 0x36, 0x00,
  0x33, 0x00, 0x18, 0xC0, 0x18, 0x78, 0x3C, 0x1F, 0xFC, 0x03, 0xF8, 0x00,
  0xFF, 0x8F, 0xFE, 0xC0, 0x6C, 0x03, 0xC0, 0x3C, 0x03, 0xC0, 0x3C, 0x07,
  0xFF, 0xEF, 0xFC, 0xC0, 0x0C, 0x00, 0xC0, 0x0C, 0x00, 0xC0, 0x0C, 0x00,
  0xC0, 0x0C, 0x00, 0x03, 0xE0, 0x0F, 0xFC, 0x0F, 0x07, 0x86, 0x00, 0xC6,
  0x00, 0x33, 0x00, 0x1B, 0x00, 0x07, 0x80, 0x03, 0xC0, 0x01, 0xE0, 0x00,
  0xF0, 0x00, 0x78, 0x00, 0x36, 0x00, 0x33, 0x01, 0x98, 0xC0, 0xFC, 0x78,
  0x3C, 0x1F, 0xFF, 0x03, 0xF9, 0x80, 0x00, 0x40, 0xFF, 0xC3, 0xFF, 0xCC,
  0x03, 0xB0, 0x06, 0xC0, 0x1B, 0x00, 0x6C, 0x01, 0xB0, 0x0C, 0xFF, 0xE3,
  0xFF, 0xCC, 0x03, 0xB0, 0x06, 0xC0, 0x1B, 0x00, 0x6C, 0x01, 0xB0, 0x06,
  0xC0, 0x1B, 0x00, 0x70, 0x0F, 0xE0, 0x7F, 0xC3, 0x83, 0x9C, 0x07, 0x60,
  0x0D, 0x80, 0x06, 0x00, 0x1E, 0x00, 0x3F, 0x80, 0x3F, 0xC0, 0x0F, 0x80,
  0x07, 0xC0, 0x0F, 0x00, 0x3E, 0x00, 0xDE, 0x0E, 0x3F, 0xF0, 0x3F, 0x80,
  0xFF, 0xFF, 0xFF, 0x06, 0x00, 0x60, 0x06, 0x00, 0x60, 0x06, 0x00, 0x60,
  0x06, 0x00, 0x60, 0x06, 0x00, 0x60, 0x06, 0x00, 0x60, 0x06, 0x00, 0x60,
  0x06, 0x00, 0x60, 0xC0, 0x1E, 0x00, 0xF0, 0x07, 0x80, 0x3C, 0x01, 0xE0,
  0x0F, 0x00, 0x78, 0x03, 0xC0, 0x1E, 0x00, 0xF0, 0x07, 0x80, 0x3C, 0x01,
  0xE0, 0x0F, 0x80, 0xEE, 0x0E, 0x3F, 0xE0, 0x7C, 0x00, 0x60, 0x06, 0xC0,
  0x1D, 0xC0, 0x31, 0x80, 0x63, 0x01, 0xC7, 0x03, 0x06, 0x06, 0x0C, 0x1C,
  0x1C, 0x30, 0x18, 0x60, 0x31, 0xC0, 0x73, 0x00, 0x66, 0x00, 0xDC, 0x01,
  0xF0, 0x01, 0xE0, 0x03, 0xC0, 0x07, 0x00, 0xE0, 0x30, 0x1D, 0x80, 0xE0,
  0x76, 0x07, 0x81, 0xD8, 0x1E, 0x06, 0x70, 0x7C, 0x18, 0xC1, 0xB0, 0xE3,
  0x0C, 0xC3, 0x8C, 0x33, 0x0C, 0x38, 0xC6, 0x30, 0x67, 0x18, 0xC1, 0x98,
  0x67, 0x06, 0x61, 0xD8, 0x1D, 0x83, 0x60, 0x3C, 0x0D, 0x80, 0xF0, 0x3E,
  0x03, 0xC0, 0x70, 0x0F, 0x01, 0xC0, 0x18, 0x07, 0x00, 0x70, 0x0E, 0x60,
  0x38, 0xE0, 0x60, 0xE1, 0xC0, 0xC3, 0x01, 0xCC, 0x01, 0xF8, 0x01, 0xE0,
  0x03, 0x80, 0x07, 0x80, 0x1F, 0x00, 0x33, 0x00, 0xE7, 0x03, 0x86, 0x06,
  0x0E, 0x1C, 0x0E, 0x70, 0x0C, 0xC0, 0x1C, 0x60, 0x06, 0x70, 0x0E, 0x30,
  0x1C, 0x38, 0x18, 0x1C, 0x38, 0x0C, 0x30, 0x0E, 0x70, 0x06, 0x60, 0x03,
  0xC0, 0x03, 0xC0, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01,
  0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0xFF, 0xFF, 0xFF, 0xC0, 0x0E,
  0x00, 0xE0, 0x0E, 0x00, 0x60, 0x07, 0x00, 0x70, 0x07, 0x00, 0x30, 0x03,
  0x80, 0x38, 0x03, 0x80, 0x18, 0x01, 0xC0, 0x1C, 0x00, 0xFF, 0xFF, 0xFF,
  0xC0, 0xFF, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCF,
  0xF0, 0x81, 0x81, 0x02, 0x06, 0x04, 0x08, 0x18, 0x10, 0x20, 0x60, 0x40,
  0x81, 0x81, 0x02, 0x06, 0x04, 0xFF, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
  0x33, 0x33, 0x33, 0x3F, 0xF0, 0x0C, 0x0E, 0x05, 0x86, 0xC3, 0x21, 0x19,
  0x8C, 0x83, 0xC1, 0x80, 0xFF, 0xFE, 0xE3, 0x8C, 0x30, 0x3F, 0x07, 0xF8,
  0xE1, 0xCC, 0x0C, 0x00, 0xC0, 0x1C, 0x3F, 0xCF, 0x8C, 0xC0, 0xCC, 0x0C,
  0xE3, 0xC7, 0xEF, 0x3C, 0x70, 0xC0, 0x0C, 0x00, 0xC0, 0x0C, 0x00, 0xC0,
  0x0C, 0xF8, 0xDF, 0xCF, 0x0E, 0xE0, 0x7C, 0x03, 0xC0, 0x3C, 0x03, 0xC0,
  0x3C, 0x03, 0xE0, 0x6F, 0x0E, 0xDF, 0xCC, 0xF8, 0x1F, 0x0F, 0xE7, 0x1B,
  0x83, 0xC0, 0x30, 0x0C, 0x03, 0x00, 0xC0, 0x38, 0x37, 0x1C, 0xFE, 0x1F,
  0x00, 0x00, 0x60, 0x0C, 0x01, 0x80, 0x30, 0x06, 0x3C, 0xCF, 0xFB, 0x8F,
  0xE0, 0xF8, 0x0F, 0x01, 0xE0, 0x3C, 0x07, 0x80, 0xF8, 0x3B, 0x8F, 0x3F,
  0x63, 0xCC, 0x1F, 0x07, 0xF1, 0xC7, 0x70, 0x3C, 0x07, 0xFF, 0xFF, 0xFE,
  0x00, 0xC0, 0x1C, 0x0D, 0xC3, 0x1F, 0xE1, 0xF0, 0x3B, 0xD8, 0xC6, 0x7F,
  0xEC, 0x63, 0x18, 0xC6, 0x31, 0x8C, 0x63, 0x00, 0x1E, 0x67, 0xFD, 0xC7,
  0xF0, 0x7C, 0x07, 0x80, 0xF0, 0x1E, 0x03, 0xC0, 0x7C, 0x1D, 0xC7, 0x9F,
  0xB1, 0xE6, 0x00, 0xC0, 0x3E, 0x0E, 0x7F, 0xC7, 0xE0, 0xC0, 0x30, 0x0C,
  0x03, 0x00, 0xC0, 0x33, 0xCD, 0xFB, 0xC7, 0xE0, 0xF0, 0x3C, 0x0F, 0x03,
  0xC0, 0xF0, 0x3C, 0x0F, 0x03, 0xC0, 0xF0, 0x30, 0xF0, 0x3F, 0xFF, 0xFF,
  0xF0, 0x33, 0x00, 0x03, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3F,
  0xE0, 0xC0, 0x18, 0x03, 0x00, 0x60, 0x0C, 0x01, 0x83, 0x30, 0xC6, 0x30,
  0xCC, 0x1B, 0x83, 0xF0, 0x77, 0x0C, 0x61, 0x8E, 0x30, 0xE6, 0x0C, 0xC1,
  0xD8, 0x18, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xCF, 0x1F, 0x6F, 0xDF, 0xFC,
  0x78, 0xFC, 0x18, 0x3C, 0x0C, 0x1E, 0x06, 0x0F, 0x03, 0x07, 0x81, 0x83,
  0xC0, 0xC1, 0xE0, 0x60, 0xF0, 0x30, 0x78, 0x18, 0x3C, 0x0C, 0x18, 0xCF,
  0x37, 0xEF, 0x1F, 0x83, 0xC0, 0xF0, 0x3C, 0x0F, 0x03, 0xC0, 0xF0, 0x3C,
  0x0F, 0x03, 0xC0, 0xC0, 0x1F, 0x07, 0xF1, 0xC7, 0x70, 0x7C, 0x07, 0x80,
  0xF0, 0x1E, 0x03, 0xC0, 0x7C, 0x1D, 0xC7, 0x1F, 0xC1, 0xF0, 0xCF, 0x8D,
  0xFC, 0xF0, 0xEE, 0x06, 0xC0, 0x3C, 0x03, 0xC0, 0x3C, 0x03, 0xC0, 0x3E,
  0x07, 0xF0, 0xEF, 0xFC, 0xCF, 0x8C, 0x00, 0xC0, 0x0C, 0x00, 0xC0, 0x00,
  0x1E, 0x67, 0xFD, 0xC7, 0xF0, 0x7C, 0x07, 0x80, 0xF0, 0x1E, 0x03, 0xC0,
  0x7C, 0x1D, 0xC7, 0x9F, 0xF1, 0xE6, 0x00, 0xC0, 0x18, 0x03, 0x00, 0x60,
  0xCF, 0x7F, 0x38, 0xC3, 0x0C, 0x30, 0xC3, 0x0C, 0x30, 0xC0, 0x3E, 0x1F,
  0xEE, 0x1B, 0x00, 0xC0, 0x3C, 0x07, 0xF0, 0x3E, 0x01, 0xF0, 0x3E, 0x1D,
  0xFE, 0x3E, 0x00, 0x63, 0x19, 0xFF, 0xB1, 0x8C, 0x63, 0x18, 0xC6, 0x31,
  0xE7, 0xC0, 0xF0, 0x3C, 0x0F, 0x03, 0xC0, 0xF0, 0x3C, 0x0F, 0x03, 0xC0,
  0xF0, 0x7E, 0x3D, 0xFB, 0x3C, 0xC0, 0xE0, 0x66, 0x06, 0x60, 0x67, 0x0C,
  0x30, 0xC3, 0x0C, 0x39, 0x81, 0x98, 0x19, 0x81, 0xF0, 0x0F, 0x00, 0xE0,
  0x0E, 0x00, 0xC1, 0xC1, 0xB0, 0xE1, 0xD8, 0x70, 0xCC, 0x2C, 0x66, 0x36,
  0x31, 0x9B, 0x18, 0xCD, 0x98, 0x64, 0x6C, 0x16, 0x36, 0x0F, 0x1A, 0x07,
  0x8F, 0x03, 0x83, 0x80, 0xC1, 0xC0, 0x60, 0xEE, 0x18, 0xC6, 0x0C, 0xC1,
  0xF0, 0x1C, 0x01, 0x80, 0x78, 0x1B, 0x03, 0x30, 0xC7, 0x30, 0x66, 0x06,
  0xE0, 0x6C, 0x0D, 0x83, 0x38, 0x63, 0x0C, 0x63, 0x0E, 0x60, 0xCC, 0x1B,
  0x03, 0x60, 0x3C, 0x07, 0x00, 0xE0, 0x18, 0x03, 0x00, 0xE0, 0x78, 0x0E,
  0x00, 0xFF, 0xFF, 0xF0, 0x18, 0x0C, 0x07, 0x03, 0x81, 0xC0, 0x60, 0x30,
  0x18, 0x0E, 0x03, 0xFF, 0xFF, 0xC0, 0x19, 0xCC, 0x63, 0x18, 0xC6, 0x31,
  0x99, 0x86, 0x18, 0xC6, 0x31, 0x8C, 0x63, 0x1C, 0x60, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFC, 0xC7, 0x18, 0xC6, 0x31, 0x8C, 0x63, 0x0C, 0x33, 0x31,
  0x8C, 0x63, 0x18, 0xC6, 0x73, 0x00, 0x70, 0x3E, 0x09, 0xE4, 0x1F, 0x03,
  0x80 };

  
#endif // OLED_H