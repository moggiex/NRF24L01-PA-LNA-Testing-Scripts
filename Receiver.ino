// Load up the libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// define the pins
#define CE_PIN   9
#define CSN_PIN 10

// Create a Radio
RF24 radio(CE_PIN, CSN_PIN); 

// The tx/rx address
const byte rxAddr[6] = "00001";

void setup()
{

  // Start the serial
  Serial.begin(9600);
  while(!Serial);
  Serial.println("NRF24L01P Receiver Starting...");
  
  // Start the radio, again set to min & slow as I'm guessing while testing theire really close to each other
  radio.begin();
  radio.setPALevel(RF24_PA_MIN);   // RF24_PA_MIN ,RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  radio.setDataRate( RF24_250KBPS ); // RF24_250KBPS, RF24_1MBPS, RF24_2MBPS
  
  // Set the reading pipe and start listening
  radio.openReadingPipe(0, rxAddr);
  radio.startListening();
  
}

void loop()
{
  if (radio.available())
  {
    // the buffer to store the received message in
    char text[100] = {0};
    
    // Now read the message, old examples have done = radio.read(), that doesn't work anymore!!!
    radio.read(&text, sizeof(text));
    
    // Print the message out to the COM window
    Serial.println("Received Message: ");
    Serial.print(text);
    Serial.println("");
  } 
}
