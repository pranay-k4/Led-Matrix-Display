#include <RTClib.h>
#include <Wire.h>
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include <ESP32-HUB75-VirtualMatrixPanel_T.hpp>
#include <ESP32-VirtualMatrixPanel-I2S-DMA.h>

// HUB75 PIN CONFIG

#define R1_PIN 25
#define G1_PIN 26
#define B1_PIN 27

#define R2_PIN 14
#define G2_PIN 12
#define B2_PIN 13

#define A_PIN 23
#define B_PIN 19
#define C_PIN 5
#define D_PIN 17

#define CLK_PIN 16
#define LAT_PIN 4
#define OE_PIN 15

// BUTTONS

#define BTN_MODE 32
#define BTN_BRIGHT 33

// RTC

RTC_DS3231 rtc;

// MATRIX CONFIG

HUB75_I2S_CFG mxconfig(64, 32, 1);
MatrixPanel_I2S_DMA *dma_display = nullptr;

int currentMode = 0;
int brightnessLevels[] = {20, 50, 80}; 
int brightnessIndex = 2;

String customQuote = "PRANAY 4K";

int scrollX = 64;


void setup() {


  Serial.begin(115200);

  pinMode(BTN_MODE, INPUT_PULLUP);
  pinMode(BTN_BRIGHT, INPUT_PULLUP);

  Wire.begin(21, 22);

  if (!rtc.begin()) {
    Serial.println("RTC NOT FOUND");
  }

  mxconfig.gpio.r1 = R1_PIN;
  mxconfig.gpio.g1 = G1_PIN;
  mxconfig.gpio.b1 = B1_PIN;

  mxconfig.gpio.r2 = R2_PIN;
  mxconfig.gpio.g2 = G2_PIN;
  mxconfig.gpio.b2 = B2_PIN;

  mxconfig.gpio.a = A_PIN;
  mxconfig.gpio.b = B_PIN;
  mxconfig.gpio.c = C_PIN;
  mxconfig.gpio.d = D_PIN;

  mxconfig.gpio.clk = CLK_PIN;
  mxconfig.gpio.lat = LAT_PIN;
  mxconfig.gpio.oe = OE_PIN;

  dma_display = new MatrixPanel_I2S_DMA(mxconfig):
  dma_display->begin();

  dma_display->setBrightness8(
    brightnessLevels[brightnessIndex]
  );

  dma_display->clearScreen();


}

void drawClock() {
  DateTime now = rtc.now();

  char timeBuffer[10];

  sprintf(
    timeBuffer,
    "%02d:%02d:%02d",
    now.hour(),
    now.minute(),
    now.second()
  );

  dma_display->clearScreen();
  dma_display->setTextSize(1);
  dma_display->setCursor(2, 10);

  dma_display->setTextColor(
    dma_display->color565(0, 255, 0)
  );

  dma_display->print(timeBuffer);
  dma_display->setCursor(8, 22);

  dma_display->setTextColor(
    dma_display->color565(0, 0, 255)
  );

}

void loop() {
  // put your main code here, to run repeatedly:

}
