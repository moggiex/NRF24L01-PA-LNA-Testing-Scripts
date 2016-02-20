// Load up the libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <printf.h>

// Set the pins up
#define CE_PIN   9
#define CSN_PIN 10

// A pipe is needed
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe

// Create a Radio
RF24 radio(CE_PIN, CSN_PIN); 

void setup() 
{
  // Start Serial
  Serial.begin(9600);
  while(!Serial);
  
  // Saying hello to you
  Serial.println("NRF24L01P test Script starting...");
  Serial.println("If you do not see a long message after this line, something is not right!");
  
  // This is needed so that radio.printDetails(); actually works!!!!
  printf_begin();
  
  // Start the radio
  radio.begin();
  
  // Start the radio, again set ti min & slow as I'm guessing while testing theire really close to each oth
  radio.setPALevel(RF24_PA_MIN);   // RF24_PA_MIN ,RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  radio.setDataRate( RF24_250KBPS ); // RF24_250KBPS, RF24_1MBPS, RF24_2MBPS
  
  // Set the pipe
  radio.openReadingPipe(1,pipe);
  
  // Start listening
  radio.startListening();
  
  // And cruically print the details
  radio.printDetails();
}
void loop()
{
  // nothing here on purpose :)
}

/*

======
You should be seeing something like this, if you are, have a beer, throw a party my friend, she's working :)
======

STATUS		 = 0x0e RX_DR=0 TX_DS=0 MAX_RT=0 RX_P_NO=7 TX_FULL=0
RX_ADDR_P0-1	 = 0x3130303030 0xe8e8f0f0e1
RX_ADDR_P2-5	 = 0xc3 0xc4 0xc5 0xc6
TX_ADDR		 = 0x3130303030
RX_PW_P0-6	 = 0x20 0x20 0x00 0x00 0x00 0x00
EN_AA		 = 0x3f
EN_RXADDR	 = 0x02
RF_CH		 = 0x4c
RF_SETUP	 = 0x01
CONFIG		 = 0x0f
DYNPD/FEATURE	 = 0x00 0x00
Data Rate	 = 1MBPS
Model		 = nRF24L01+
CRC Length	 = 16 bits
PA Power	 = PA_MIN

======
And it's NOT working if you see the below. Check the pins again (and again!)
======

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


*/
