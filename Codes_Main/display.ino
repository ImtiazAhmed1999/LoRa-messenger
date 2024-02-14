// void displayText(const String text) {
//   display.setTextSize(2);
//   display.setTextColor(WHITE);
//   display.setCursor(0, 20);
//   display.println(text);
//   display.display();
// }

// void displayLetter(char letter) {
//   display.setTextSize(2);
//   display.setTextColor(WHITE);
//   display.setCursor(display.getCursorX(), display.getCursorY());
//   display.print(letter);
//   display.display();
// }

void clearDisplay() {
  display.clearDisplay();
  display.display();
}

void text(int x, int y, String msg){
  display.setCursor(x, y);
  // display.println("Received Message:");
  display.println(msg);
  display.display();
}
void LoraPrint(){
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  text(0, 10, "   LoRa    ");
  text(0, 26, " Messenger ");
}