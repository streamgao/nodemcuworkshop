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

## Sample 1: Blink with NodeMCU
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

## Sample 2: Blink plus a LED with NodeMCU
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


## Sample 3: Fade a LED with NodeMCU
analogWrite


## Sample 4: Control a LED From Web Browser
### What is DHCP (Dynamic Host Configuration Protocol)
A standardized network protocol used on Internet Protocol (IP) networks. The DHCP is controlled by a DHCP server that dynamically distributes network configuration parameters, such as IP addresses, for interfaces and services. A router or a residential gateway can be enabled to act as a DHCP server. A DHCP server enables computers to request IP addresses and networking parameters automatically, reducing the need for a network administrator or a user to configure these settings manually. In the absence of a DHCP server, each computer or other device on the network needs to be manually assigned to an IP address.
TCP/IP defines how devices on one network communicate with devices on another network. A DHCP server can manage TCP/IP settings for devices on a network, by automatically or dynamically assigning Internet Protocol (IP) addresses to the devices.

### Your home wifi
IP address 192.168.0.1 is the address of some home-use broadband router, it’s mainly the default value of a variety of D-Link and Netgear model routers. And you can change it using the network router management console at any time. 192.168.0.1 is a private IPv4 network address. When DHCP assigning IPs, they normally are something like 192.168.0.x.

### Steps
- Switch your laptop wifi to `kineviz_test`
- Connect the Esp8266 to the Wi-Fi router using SSID(the name of network wifi) and password of network Wifi, where the esp8266 connect to our wifi and create a webserver. The server can be accessed by looking through the serial Monitor of the Arduino window or you can also log into your Wifi router and check for the list of clients connected to your Wi-Fi router.
- Setup function:
Boilerplate code. Set up wifi; Connect to wifi and print IP address that been assigned to the NodeMCU to the serial monitor.
- Loop function:
Boilerplate code for looking for connection.
Parse URL, and depends on the request to turn the LED on / off.


## Sample 5: Adding interface over the browser
🤓
Let's write some html markup and make it more interactive.
2 buttons to turn the led on / off.

## Sample 6: Automate your LED control through a server
### What is Node.js ?
- Node.js is an open source server framework
- Node.js is free
- Node.js runs on various platforms (Windows, Linux, Unix, Mac OS X, etc.)
- Node.js uses JavaScript on the server
- Node.js can generate dynamic page content
- Node.js can create, open, read, write, delete, and close files on the server
- Node.js can collect form data
- Node.js can add, delete, modify data in your database

### Steps:
1. Go to: https://nodejs.org/en/download/ and download nodejs. This would install nodejs and npm onto your laptop automatically, which we will use to build the server.
2. Write your own node controller:
- Open terminal, type `cd ` + a directory
- Terminal: `npm init`, then fill the rest of the information
- Terminal: `npm install express; npm install axios`
- Terminal: `cat > index.js` (or you can manualy create a js file called `index.js`)
- Write your code inside!
- Do remember to change the IP address and customize the on / off routes to be your own NodeMCUs!
- Start server by typing `node index.js` in terminal
- Now you can see your LEDs get automated by your server


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
