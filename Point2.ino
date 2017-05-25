#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // initialize interface pins
#include <Ultrasonic.h>
#define TRIGGER_PIN 12
#define ECHO_PIN 13
const byte intPin=2; //interrupt pin
const byte intPin2=13;
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup() 
{
   Serial.begin(9600);
   lcd.begin(16, 2); 
   pinMode(intPin, INPUT_PULLUP); 
   pinMode(intPin2, INPUT_PULLUP); 
   attachInterrupt(0, int0, LOW);
 }
void loop() 
{
  boolean a= digitalRead(7);
  if(a==LOW)
  noInterrupts();
  else
  interrupts();
}
void int0() 
{
   lcd.setCursor(0,0);
   float cmMsec, inMsec;
   long microsec = ultrasonic.timing();
   cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
   inMsec = ultrasonic.convert(microsec, Ultrasonic::IN); 
    lcd.print("MS: ");
    lcd.print(microsec);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(", CM: ");  
    lcd.print(cmMsec);
    lcd.setCursor(0,1);
    lcd.print(", IN: "); 
    lcd.print(inMsec);
    delay(1000); 
    Serial.print(microsec);
}

