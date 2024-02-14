#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <LoRa.h>
#define BAND 433E6         // LoRa frequency band 433 MHz

#define csPin 5     // LoRa radio chip select
#define resetPin 2  // LoRa radio reset
#define irqPin 15   // change for your board; must be a hardware interrupt pin

Adafruit_SSD1306 display(128, 64, &Wire, -1);


String outgoing;          // outgoing message
byte msgCount = 0;        // count of outgoing messages
byte localAddress = 121;  // address of this device
byte destination = 124;   // destination to send to

uint32_t lastSendTime = 0;  // last send time
bool messageDelivered = false;
byte column[3] = { 32, 14, 12 };
const char letters[3][9] = { //button interfacing for alphabets
  { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' },  // 0
  { 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R' },  // 1
  { 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '.' },  // 2
};

String inputText = "";
String incomingMsg = ""; // incoming message

void setup() {
  // Serial.begin(9600);
  setupF();
}

void loop() {
  int columns[3] = { analogRead(column[0]), analogRead(column[1]), analogRead(column[2]) };
  int thresholds[4] = {750, 1100, 1720, 3950 };//1
  // int thresholds[4] = {850, 1200, 1850, 3950 };//2
  for (byte i = 0; i < 3; i++) {
    for (byte j = 1; j <= 3; j++) {
      if (columns[i] > thresholds[j]) {
        byte btn = button(column[i], thresholds[j]);
        if (btn > 0) {
          if (btn > 3) btn -= 3;
          char letter = letters[j - 1][btn - 1 + i * 3];
          inputText += letter;  // Append the letter to the inputText
          // clearDisplay();
          Serial.println(inputText);
          // display.setTextSize(1);
          // text(0, 0, "Type MSG");
          // display.setTextSize(2);
          // text(0,10,inputText);
        }
      }
    }
  }

  if (columns[2] > thresholds[0]) {
    byte btn = button(column[2], thresholds[0]);
    if (btn > 0) {
      // clearDisplay();                            // Clear the OLED display
      display.fillRect(0, 0, 200, 30, SSD1306_BLACK);
      if (inputText.length() > 0) {
        inputText.remove(inputText.length() - 1);  // Remove the last character
        // display.setTextSize(1);
        // text(0, 0, "Type MSG");
        // display.setTextSize(2);
        // text(0,10,inputText);                    // Update the OLED display with the modified input text
      }
    }
  }

  if (columns[0] > thresholds[0]) {
    byte btn = button(column[0], thresholds[0]);
    if (btn > 0) {
      // clearDisplay();  // Clear the OLED display
      display.fillRect(0, 0, 200, 30, SSD1306_BLACK);
      // Button associated with columns[0] > thresholds[0] is clicked
      Serial.println("Input Text: " + inputText);
      if (millis() - lastSendTime > 1000)  //send delay 1000ms
      {
        if (inputText.length()) {
          sendMessage(inputText);
          Serial.println("Sending " + inputText);
        }
        lastSendTime = millis();  // timestamp the message
      }
      inputText = "";  // Clear the inputText after sending to Serial monitor
    }
  }
  // parse for a packet, and call onReceive with the result:
  onReceive(LoRa.parsePacket());
  // clearDisplay();
  display.setTextSize(1);
  text(0, 0, "Enter MSG");
  text(0, 30, "Received MSG");
  
  // Display the typed message in the first row
  if(inputText){
    display.setTextSize(2);
    text(0,10, inputText);
  }
  // Display the received message in the second row
  if(!incomingMsg.isEmpty()){
    clearDisplay();
    display.setTextSize(2);
    text(0,40,incomingMsg);
    incomingMsg="";
  }
}
