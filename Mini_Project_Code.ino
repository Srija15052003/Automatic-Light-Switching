#include<LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);


#define in 14

#define out 19

#define relay 2


int count=0;

void setup()

{

  lcd.begin(16,2);

  lcd.print("Visitor Counter");

  delay(2000);

  pinMode(in, INPUT);

  pinMode(out, INPUT);

  pinMode(relay, OUTPUT);

  lcd.clear();

  lcd.print("Person In Room:");

}


void loop()

{  

  if(digitalRead(in)==LOW)
  {
    count++;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);

  }
  else if(digitalRead(out)==LOW)
  {
    count--;
    if(count<=0)
    {
      count=0;
    }
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
  }
  else if(count<=0)
  {
    lcd.clear();
    digitalWrite(relay,LOW);
    lcd.clear();
    lcd.print("NOBODY IN ROOM");
    lcd.setCursor(0,1);
    lcd.print("Light is off");
    delay(500);
  }
  else
  digitalWrite(relay,HIGH);
}