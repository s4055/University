#include <DHT.h>
#define DHTPIN 7
#define DHTTYPE DHT11
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);//RS,E,D4,D5,D6,D7
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(6,INPUT);//화염
  pinMode(5,OUTPUT);//피에조
  pinMode(4,OUTPUT);//LED
  lcd.begin(16,2);
  dht.begin();
}

void loop() {
  int reading=digitalRead(6);
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if(reading==HIGH){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Hu: ");
    lcd.print(h);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("Temper: ");
    lcd.print(t);
    lcd.print(" 'c");
    delay(100);
  }
  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("EMERGENCY!!!");
    tone(5,342,500);
    digitalWrite(4,HIGH);
    delay(100);
    digitalWrite(4,LOW);
    delay(100);
  }
}
