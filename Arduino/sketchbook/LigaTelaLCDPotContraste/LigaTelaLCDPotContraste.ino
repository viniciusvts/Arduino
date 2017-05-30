//Liga a tela lacd e utiliza pot como contraste

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
lcd.begin(16, 2);
lcd.setCursor(0,0); //primeira linha
lcd.print("Ola, meu nome e:");
lcd.setCursor(0,1); //segunda linha
lcd.print("Samuel");
}
void loop() {
}

