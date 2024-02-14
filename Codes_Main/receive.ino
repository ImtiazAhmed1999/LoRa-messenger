void onReceive(int packetSize) {
  if (packetSize == 0) return;          // if there's no packet, return

  // read packet header bytes:
  byte receiver = LoRa.read();          // recipient address
  byte sender = LoRa.read();            // sender address
  byte incomingMsgId = LoRa.read();     // incoming msg ID
  byte incomingLength = LoRa.read();    // incoming msg length

  while (LoRa.available()) {
    incomingMsg += (char)LoRa.read();
  }

  // if the recipient isn't this device or broadcast,
  if (receiver != localAddress && sender != destination) {
    Serial.println("This message is not for me.");
    return;                             // skip rest of function
  }

  // if message is for this device, or broadcast, print details:
  Serial.println("Received from: 0x" + String(sender));
  Serial.println("Sent to: 0x" + String(receiver));
  Serial.println("Message ID: " + String(incomingMsgId));
  Serial.println("Message length: " + String(incomingLength));
  Serial.println("Message: " + incomingMsg);
  Serial.println("RSSI: " + String(LoRa.packetRssi()));
  Serial.println("Snr: " + String(LoRa.packetSnr()));
  Serial.println();
  // display.clearDisplay();
  // display.setTextSize(1);
  // text(10,10,"Received Msg:");
  // display.setTextSize(2);
  // text(10,20,incomingMsg);
}