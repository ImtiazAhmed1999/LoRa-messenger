void setupF(){
  // while (!Serial);
  Wire.begin(21, 22);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  LoraPrint();

  LoRa.setPins(csPin, resetPin, irqPin);// set CS, reset, IRQ pin
  if (!LoRa.begin(BAND)) {
    display.clearDisplay();
    text(0, 10, "LoRa init failed. Check your connections.");
    Serial.println("LoRa init failed. Check your connections.");
    while (true);                       // if failed, do nothing
  }
  LoRa.setSpreadingFactor(8); //7-12
  display.clearDisplay();
  LoRa.setSignalBandwidth(500); //125 kHz, 250 kHz or 500 kHz.
  // LoRa.setCodingRate4(5);//4/5, 4/6, 4/7 and 4/8
  //The smaller the coding rate is (the smallest is 4/8), the higher the time-on-air is in a transmission, so it takes more time to transmit a packet
  text(0, 10, "LoRa init succeeded.");
  text(0, 42, "Adress:" + String(localAddress));
  Serial.println("LoRa init succeeded.");
  delay(1000);
  display.clearDisplay();
}