#include <DHT.h>
#include <LiquidCrystal.h>
#include <DHT.h>
//#include "DHT.h"
#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT11   // we are using the DHT11 sensor

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  for (int DigitalPin = 7; DigitalPin <= 9; DigitalPin++) 
 {
  pinMode(DigitalPin, OUTPUT);
 }
  lcd.begin(16,2);  //16 by 2 character display
  dht.begin();
}
 void loop()
{
  delay(500);
  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity();
  
  float t = dht.readTemperature();  // Read temperature as Celsius (the default)

  
   if (isnan(h) || isnan(t)) 
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp : ");
    lcd.print("ERROR");  //printing temperarture to the LCD display
    //lcd.print(" C");
  
    lcd.setCursor(0,1);
    lcd.print("Humid: ");
    lcd.print("ERROR");  //printing humidity to the LCD display
    //lcd.print(" %");
    return;
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp : ");
    lcd.print(t);  //printing temperarture to the LCD display
    lcd.print(" C");
  
    lcd.setCursor(0,1);
    lcd.print("Humid: ");
    lcd.print(h);  //printing humidity to the LCD display
    lcd.print(" %");
  }
 
}
