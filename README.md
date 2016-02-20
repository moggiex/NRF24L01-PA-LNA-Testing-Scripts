# NRF24L01P+PA+LNA Testing Scripts

If you've purchased the a pair (or more) of the NRF24L01P+PA+LNA transceiver , there is a lot of old examples out there that don't work anymore (as of 2016) and this drove me nuts.

# You will need:

1. Two Arduino's that use 3.3V (I'm using Pro Mini's)
2. The RF24 libray which can be downloaded here https://github.com/tmrh20/RF24/ (add to your libraries etc...)
3. And of course two NRF24L01P+PA+LNA or NRF24L01P boards
4. The Arduino IDE
5. And I'd **strongly** suggest using a dedicated 3.3V supply as Arduino's don't have anough current capacity to power these devices

 **Note: #5 - A Separate Power Supply **
LM1117T chips are what I'm using, they're cheap & simple to wire up with two capacitors. See here for the diagram http://circuits.datasheetdir.com/40/LM1117-circuits.jpg just make sure you put the GND wire on both the NRF24L01P board  **AND ** connect the GND from the 3.3 supply to the Arduino GND too.

# Wiring the Arduino's

See the image below:

![alt tag](https://arduino-info.wikispaces.com/file/view/24L01Pinout-800.jpg/243330999/24L01Pinout-800.jpg)

This is the top view of the pins, so make sure you get them the right way around :)

Connect your pins as detailed below, noting this is for Arduino Pro Mini's. If you're using a different board quickly google the board name and "pin out" to make sure you you get the right pins for CE & CSN.

Pin 1 - Ground to Ground
Pin 2 - VCC to your 3.3V supply
Pin 3 - CE or somtimes called SS to pin 9
Pin 4 - CSN to pin 10
Pin 5 - SCK to pin 13
Pin 6 - MOSI to pin 11
Pin 7 - MSIO to pin 10
Pin 8 - Unused (it's an interupt)

# NRF24L01P Test Script Time!

Attached are two scripts, one is the sender and one is the receiver. Load the receiver to one of your arduinos and transmitter to the other.

**Note:** The baud rate is 9600, so make sure this is set in your COM window so you see the messages.

These scripts are a simplfied and well document versions of what I've been using to test with. The standard "Getting Started" script that comes with the RF24 library is hardly newbie proof, these are getting that way.

Power on both devices and you're away.

# NRF24L01P not working?

Here are some daft things to check.

1. Arduino UNO's normally run on 5V, NRF24L01P **need 3.3V** so either use a difefrent board or a logic conversion board (they're around £1 each and saves you frying the NRF24L01P with too much voltage) and the standard 3.3V pin on an UNO isn't up to powering a NRF24L01P!!!
2. Solder a 10uF and a 0.1uF capacitor directly to the VCC and GND pins on the NRF24L01P board (gives the board a little extra power when transmitting)
3. Check your wiring 
4. Check your wiring again!! (this was the cause to a lot of my issues to begin with)
5. Use a dedicated 3.3V supply for the NRF24L01P board and make sure the ground pins are joined between the 3.3V supply & the arduino board

# Hope this helps you!
I spent ages faffing around with other test scripts and making silly mistakes. I genuinely hope these simplified examples helps you!

