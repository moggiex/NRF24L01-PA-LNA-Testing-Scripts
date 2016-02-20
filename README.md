# NRF24L01P+PA+LNA Testing Scripts

If you've purchased the a pair (or more) of the NRF24L01P+PA+LNA transceivers , there is a lot of **old example code out there that does not work anymore** (as of 2016) and this drove me nuts.

**This code will help you get you up & running *fast* !!!**

![NRF24L01P+PA+LNA board example](http://www.elecfreaks.com/wiki/images/1/1d/N24l01_figure20.jpg)

# You will need:

1. Two Arduino's that use 3.3V (I'm using Pro Mini's)
2. The RF24 library which can be downloaded here https://github.com/tmrh20/RF24/ (add to your libraries, restart etc...)
3. And of course two NRF24L01P+PA+LNA or NRF24L01P boards
4. The Arduino IDE - https://www.arduino.cc/en/Main/Software
5. And I'd **strongly** suggest using a dedicated 3.3V supply as Arduino's don't have anough current capacity to power these devices

**Note: #5 - A Separate 3.3V Power Supply**

LM1117T chips are what I'm using to supply 3.3V to the NRF24L01P boards. They're cheap & simple to wire up with just two capacitors. See here for the diagram http://circuits.datasheetdir.com/40/LM1117-circuits.jpg just make sure you put the GND wire on both the NRF24L01P board  **AND** connect the GND from the 3.3 supply to the Arduino GND too.

# Wiring the Arduino's

See the image below:

![NRF24L01P+PA+LNA pin layout](https://arduino-info.wikispaces.com/file/view/24L01Pinout-800.jpg/243330999/24L01Pinout-800.jpg)

This is the top view of the pins, so make sure you get them the right way around :)

Connect your pins as detailed below, noting this is for Arduino Pro Mini's. If you're using a different board quickly google the board name and "pin out" to make sure you you get the right pins for SCK, MOSI & MSIO (I believe they are different on a MEGA board for example).

```
Pin 1 - Ground to Ground
Pin 2 - VCC to your 3.3V supply
Pin 3 - CE (somtimes called SS) to pin 9
Pin 4 - CSN to pin 10
Pin 5 - SCK to pin 13
Pin 6 - MOSI to pin 11
Pin 7 - MSIO to pin 10
Pin 8 - Unused (it's an interupt)
```

# NRF24L01P Test Script Time!

**Do not skip this step.**  Skipping it will only mean you loose more hair from your head :/

Download the script called "Start_with_this_testing_script.ino" from above as this script **is your biggest friend** when starting with NRF24L01P boards.

1. Copy & paste this script into your Arduino IDE
2. Compile & upload to your board
3. Open the COM window
4. Set the COM window to "9600 baud"
 
If everything goes well, you will know that you have wired the NRF24L01P & Arduino up correct if you see a message like the one below, you'll see values such as "0x3f" and "0x02", **not "0xff"** which are bad.

```c
STATUS		 = 0x0e RX_DR=0 TX_DS=0 MAX_RT=0 RX_P_NO=7 TX_FULL=0
RX_ADDR_P0-1	 = 0x3130303030 0xe8e8f0f0e1
RX_ADDR_P2-5	 = 0xc3 0xc4 0xc5 0xc6
TX_ADDR		 = 0x3130303030
RX_PW_P0-6	 = 0x20 0x20 0x00 0x00 0x00 0x00
EN_AA		 = 0x3f
EN_RXADDR	 = 0x02
RF_CH		 = 0x4c
RF_SETUP	 = 0x21
CONFIG		 = 0x0f
DYNPD/FEATURE	 = 0x00 0x00
Data Rate	 = 250KBPS
Model		 = nRF24L01+
CRC Length	 = 16 bits
PA Power	 = PA_MIN
```

And if the NRF24L01P is wired up **incorrectly**, then you'll see a message like the one below. See the differences!

```c
STATUS		 = 0x00 RX_DR=0 TX_DS=0 MAX_RT=0 RX_P_NO=0 TX_FULL=0
RX_ADDR_P0-1	 = 0xffffffffff 0xffffffffff
RX_ADDR_P2-5	 = 0xff 0xff 0xff 0xff
TX_ADDR		 = 0xffffffffff
RX_PW_P0-6	 = 0xff 0xff 0xff 0xff 0xff 0xff
EN_AA		 = 0xff
EN_RXADDR	 = 0xff
RF_CH		 = 0xff
RF_SETUP	 = 0xff
CONFIG		 = 0xff
DYNPD/FEATURE	 = 0xff 0xff
Data Rate	 = 1MBPS
Model		 = nRF24L01
CRC Length	 = 16 bits
PA Power	 = PA_MAX
```

If you don't see an output like the first example then check your wiring etc... and also the "NRF24L01P not working?" section below.

Don't be tempted to skip this step, confirm the NRF24L01P boards are working first, before continuing.

# NRF24L01P Let's Send Some Data!

**You're ready to rock now!**

Attached are two scripts, one is the sender and one is the receiver. Load the receiver to one of your arduinos and transmitter to the other.

**Note:** The baud rate is 9600, so make sure this is set in your COM window so you see the messages.

These scripts are a simplfied and well document versions of what I've been using to test with. 

The standard RF24 "Getting Started" scripts that comes with the RF24 library is hardly newbie proof, these are much, much easier to use & get started quickly with (ie what I needed originally!).

Power on both devices, check the COM windows and you're away.

# NRF24L01P not working?

Here are some daft things to check.

1. Arduino UNO's normally run on 5V, NRF24L01P **need 3.3V**. So either use a difefrent board (eg Pro mini at 3.3V) or a logic conversion board (they're around £1 each and saves you frying the NRF24L01P with too much voltage) and the standard 3.3V pin on an UNO isn't up to powering a NRF24L01P!!!
2. Solder a 10uF and a 0.1uF capacitor directly to the VCC and GND pins on the NRF24L01P board (gives the board a little extra power when transmitting)
3. Check your wiring 
4. Check your wiring
4. Check your wiring again!! (this was the cause to a lot of my issues to begin with)
5. Use a dedicated 3.3V supply for the NRF24L01P board and make sure the ground pins are joined between the 3.3V supply & the arduino board

# Hope this helps you!
I spent ages faffing around with other test scripts and making silly mistakes. I genuinely hope these simplified examples helps you!

Matt
