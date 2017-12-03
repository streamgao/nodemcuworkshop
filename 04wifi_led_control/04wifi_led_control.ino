/*
 *  This sketch demonstrates how to set up a simple HTTP-like server.
 *  The server will set a GPIO pin depending on the request
 *    http://server_ip/YOUR_OFF_URL will set the GPIO low,
 *    http://server_ip/YOUR_ON_URL will set the GPIO high
 *  server_ip is the IP address of the ESP8266 module, will be
 *  printed to Serial when the module is connected.
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
#define D9 3  // RX0 (Serial console)
#define D10 1 // TX0 (Serial console)

#include <ESP8266WiFi.h>

const char* ssid = "CounterPulse Guest";
const char* password = "0084800848";

// please put unique charactors here, otherwise you might turn on other's LED!
const String YOUR_OFF_URL = "/off";
const String YOUR_ON_URL = "/on";

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  delay(10);
  pinMode(D1, OUTPUT);
  digitalWrite(D1, 0);

  // Connect to WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    // keep waiting until connected
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.print("URL is: http://");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  // Match the request
  int val;
  if (req.indexOf(YOUR_OFF_URL) != -1)
    val = LOW;
  else if (req.indexOf(YOUR_ON_URL) != -1)
    val = HIGH;
  else {
    Serial.println("invalid request");
    client.stop();
    return;
  }
  digitalWrite(D1, val);

  // discard any bytes that have been written to the client but not yet read
  // clears the buffer once all outgoing characters have been sent.
  client.flush();

  // Send the response to the client
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nLED is turned ";
  s += val ? "on" : "off";
  s += "</html>\n";
  client.print(s);
  delay(1);
  Serial.println("Client disonnected");

  // The client will actually be disconnected
  // when the function returns and 'client' object is detroyed
}
