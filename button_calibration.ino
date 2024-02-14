#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128, 64, &Wire, -1);
#define c1 32
#define c2 14
#define c3 12
void setup() {
  // put your setup code here, to run once:
  Wire.begin(21, 22);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();
  text(10, 10, "Sensor");
  delay(1000);
  display.clearDisplay();
  pinMode(c1, INPUT);
  pinMode(c2, INPUT);
  pinMode(c3, INPUT);
  // Serial.begin(9600);
}

void loop() {
  int co1 = analogRead(c1);
  int co2 = analogRead(c2);
  int co3 = analogRead(c3);
  // put your main code here, to run repeatedly:
  Serial.print(co1);
  Serial.print(" ");
  Serial.print(co2);
  Serial.print(" ");
  Serial.println(co3);

  text(0, 10, String(co1));
  text(40, 10, String(co2));
  text(70, 10, String(co3));
  delay(200);
  display.clearDisplay();
}
void text(int x, int y, String msg) {
  display.setCursor(x, y);
  // display.println("Received Message:");
  display.println(msg);
  display.display();
}
