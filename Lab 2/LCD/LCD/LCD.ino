#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Postgrado IoT");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("15000104");
}
