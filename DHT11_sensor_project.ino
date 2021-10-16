#include <LiquidCrystal_I2C.h>
#include <dht.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
dht DHT;
#define dht_apin A0

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  //lcd.print("Time on:");
}

void loop() {
  DHT.read11(dht_apin);
  lcd.setCursor(0, 0);
  lcd.print("temp=");
  lcd.print(DHT.temperature);
  lcd.print("C");
  
  lcd.setCursor(0, 1);
  lcd.print("humidity=");
  lcd.print(DHT.humidity);
  lcd.print("%");
}
