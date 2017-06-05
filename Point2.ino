#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // initialize interface pins
#include <Ultrasonic.h>
#define TRIGGER_PIN 12
#define ECHO_PIN 13
const byte intPin=2; //interrupt pin
const byte intPin2=5;
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup() 
{
  Serial.begin(9600);
  //pinMode(2,INPUT_PULLUP);
  attachInterrupt(0,int0,LOW);
  pinMode(2,INPUT_PULLUP);
}
void loop() 
{   
  int0();
}
void int0()
{
  if (digitalRead(2) == HIGH)
  {
    float cmMsec, inMsec;
    long microsec = ultrasonic.timing();
    cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // 計算距離，單位: 公分
    inMsec = ultrasonic.convert(microsec, Ultrasonic::IN); // 計算距離，單位: 英吋
    Serial.print("MS: "); Serial.print(microsec);
    Serial.print(", CM: "); Serial.print(cmMsec);
    Serial.print(", IN: "); Serial.println(inMsec);
    lcd.begin(20, 2);
    lcd.print("MS: "); lcd.print(microsec);
    lcd.setCursor(0,1);
    lcd.print("CM: "); lcd.print(cmMsec);
    lcd.print(" IN: "); lcd.print(inMsec);
    delay(100);
  }
}

