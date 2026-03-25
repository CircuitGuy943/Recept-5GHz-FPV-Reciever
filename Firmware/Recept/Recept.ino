#include <Wire.h>

#define TW8819_ADDR 0x45
#define TW_RESET_PIN 2

void twWrite(uint8_t reg, uint8_t val) {
  Wire.beginTransmission(TW8819_ADDR);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
}

void twPage(uint8_t page) {
  twWrite(0xFF, page);
}

void twReset() {
  pinMode(TW_RESET_PIN, OUTPUT);
  digitalWrite(TW_RESET_PIN, LOW);
  delay(10);
  digitalWrite(TW_RESET_PIN, HIGH);
  delay(50);
}

void twInit() {
  twPage(0x00);
  twWrite(0x00, 0x01);
  delay(10);

  twWrite(0x10, 0x80);
  twWrite(0x11, 0x40);
  twWrite(0x12, 0x06);

  twWrite(0x20, 0xE0);
  twWrite(0x21, 0x03);
  twWrite(0x22, 0x00);

  twWrite(0x30, 0x20);
  twWrite(0x31, 0x03);
  twWrite(0x32, 0x20);
  twWrite(0x33, 0x03);

  twWrite(0x34, 0xE0);
  twWrite(0x35, 0x01);
  twWrite(0x36, 0xE0);
  twWrite(0x37, 0x01);

  twWrite(0x50, 0x80);
}

void scanI2C() {
  for (uint8_t addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found: 0x");
      Serial.println(addr, HEX);
    }
  }
}

void setup() {
  Serial.begin(115200);
  Wire.setSDA(4);
  Wire.setSCL(5);
  Wire.begin();

  twReset();
  twInit();

  Serial.println("TW8819 init done");
}

void loop() {
}