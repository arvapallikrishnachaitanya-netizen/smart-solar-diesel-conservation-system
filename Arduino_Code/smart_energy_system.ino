#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int ldrPin = A0;
int relayPin = 7;
int solarLED = 8;
int dieselLED = 9;

void setup()
{
  pinMode(relayPin, OUTPUT);
  pinMode(solarLED, OUTPUT);
  pinMode(dieselLED, OUTPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
}

void loop()
{
  int lightValue = analogRead(ldrPin);

  if(lightValue > 500)
  {
    digitalWrite(relayPin, HIGH);

    digitalWrite(solarLED, HIGH);
    digitalWrite(dieselLED, LOW);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SOLAR MODE");

    lcd.setCursor(0,1);
    lcd.print("Diesel Saved");
  }
  else
  {
    digitalWrite(relayPin, LOW);

    digitalWrite(solarLED, LOW);
    digitalWrite(dieselLED, HIGH);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("BACKUP MODE");

    lcd.setCursor(0,1);
    lcd.print("Using Diesel");
  }

  delay(1000);
}