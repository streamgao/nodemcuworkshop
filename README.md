# nodemcuworkshop


## Setting up the environment
- Reference can be found [here](http://esp8266.github.io/Arduino/versions/2.3.0/doc/installing.html)
1. Download Arduino IDE(Integrated Development Environment) from here:  https://www.arduino.cc/en/Main/Software
2. Go to files and click on the preference in the Arduino IDE, copy the below code in the Additional boards Manager: 
`http://arduino.esp8266.com/stable/package_esp8266com_index.json`.   click OK to close the preference Tab.
3. After completing the above steps , go to Tools and board, and then select board Manager. Search for esp8266 and install the software(`esp8266 by esp8266 community`) for Arduino.
4. On the Tools menu, configure your board according to the model you are using. The most common options are:
```
Board: NodeMCU, according to its model
CPU Frequency: 80 MHz
Upload Speed: 115200 
```

Once all the above process been completed we are read to program our esp8266 with Arduino IDE !!! 

## Blink with NodeMCU
- Open File -> examples -> ESP8266 -> Blink
- From the example code: 
```
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
```

## Blink plus a LED with NodeMCU
- NodeMCU PIN MAPPING.   
Put the following snippet ahead of all the code. 
```
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
```
- Define a pin instead of the `LED_BUILTIN`
- On the breadboard: Connect `GND` with the LED short led, and the pin you defined with the long leg 


## Control an LED From Web Browser
### What is UDP ?
User Datagram Protocol (UDP) is one of the core members of the Internet protocol suite.
When an app uses UDP, packets are just sent to the recipient. The sender doesn’t wait to make sure the recipient received the packet—it just continues sending the next packets. If the recipient misses a few UDP packets here and there, they are just lost—the sender won’t resend them. Losing all this overhead means the devices can communicate more quickly.
UDP is used when speed is desirable and error correction isn’t necessary. For example, UDP is frequently used for live broadcasts and online games.
For example, let’s say you’re watching a live video stream, which are often broadcast using UDP instead of TCP. The server just sends a constant stream of UDP packets to computers watching. If you lose your connection for a few seconds, the video may freeze or get jumpy for a moment and then skip to the current bit of the broadcast. If you experience minor packet-loss, the video or audio may be distorted for a moment as the video continues to play without the missing data.

### Steps
- Connect the Esp8266 to the Wi-Fi router using SSID and password of Home network Wifi, where the esp8266 connect to our wifi and create a webserver. The server can be accessed by looking through the serial Monitor of the Arduino window or you can also log into your Wifi router and check for the list of clients connected to your Wi-Fi router.



## Common problems
1. Error during loading code
```error: cannot access /dev/cu.SLAB_USBtoUART
error: espcomm_open failed
the selected serial port 
 does not exist or your board is not connected
error: espcomm_upload_mem failed
```
- Upload speed can be tricky, try changing it.
- Try resetting the board.
- Try changing a usb cable. 
... 