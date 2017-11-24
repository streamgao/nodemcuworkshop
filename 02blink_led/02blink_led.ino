/*
 ESP8266 Blink with a LED on D6
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

void setup() {
  pinMode(D6, OUTPUT);     // Initialize the D6 pin as an output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(D6, LOW);   // Turn the LED on (Note that LOW is the voltage level
                           // but actually the LED is on; this is because 
                           // it is acive low)
  delay(1000);             // Wait for a second
  digitalWrite(D6, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(2000);             // Wait for two seconds (to demonstrate the active low LED)
}



