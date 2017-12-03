/*
  LED @ D6 pin, fade effect
*/


#define D0 16
#define D1 5 // I2C Bus SCL (clock)
#define D2 4 // I2C Bus SDA (data)
#define D3 0
#define D4 2 // Same as "LED_BUILTIN", but inverted logic
#define D5 14 // SPI Bus SCK (clock)
#define D6 12 // SPI Bus MISO
#define D7 13 // SPI Bus MOSI
#define D8 15 // SPI Bus SS (CS)
#define D9 3 // RX0 (Serial console)
#define D10 1 // TX0 (Serial console)

int fadeAmount;
int brightness;

void setup() {
  pinMode(D1, OUTPUT);
  fadeAmount = 5;
  brightness = 5;
}

void loop() {
  analogWrite(D1, brightness);
  if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount;
  }
  brightness += fadeAmount;
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
