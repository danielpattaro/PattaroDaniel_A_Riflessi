
int led=9;
int bottone = 10;
int buzzer = 11;
int val=LOW;
int numeroRandom=0;
int pas=0;
int controllo=0;
int tempoluc=0;
int tempobuz=0;
#include <LiquidCrystal.h>

void(* Riavvia)(void) = 0;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
void setup() {
  // put your setup code here, to run once:
led=9;
bottone = 10;
buzzer = 11;
val=LOW;
numeroRandom=0;
pas=0;
controllo=0;
tempoluc=0;
tempobuz=0;
pinMode (led, OUTPUT);
pinMode (bottone, INPUT);
pinMode (buzzer, OUTPUT);
lcd.begin(16, 2);
lcd.print("TEST RIFLESSI");
delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:



val=digitalRead(bottone);



 
if (val== HIGH && pas==0)
{
 numeroRandom = random(5000); 
 delay(numeroRandom); 
 digitalWrite(led,HIGH);
  pas=1;
  tempoluc=millis();
  
}
val = digitalRead(bottone);

  if (val== HIGH && pas==1)
{
 tempoluc=millis()-tempoluc;
 digitalWrite(led,LOW);
 
numeroRandom = random(2000,6000); 

 if (controllo==0)
 {
 delay(numeroRandom); 
 tone(buzzer,300);
 controllo=1;
 pas=2;
 tempobuz=millis();
 }

}

val = digitalRead(bottone);

 
if (val== HIGH && pas==2)
{

  
 noTone(buzzer);
 pas=3;
 tempobuz=millis()-tempobuz;
  }
  
val = digitalRead(bottone);



if (val== HIGH && pas==3)
 {
  lcd.clear();
    if (tempoluc!=0 && tempobuz!=0)
   { lcd.print("Luce: "+ String(tempoluc));
    lcd.print(" Buzz: "+ String(tempobuz ));
    }
    else
    {
      lcd.print("TEST NON VALIDO");
      }
    lcd.setCursor(0, 1);
    lcd.print("TIENI PREMUTO IL BOTTONE PER CONTINUARE");
    delay(1000);
    pas=4;
  }


  /*
  
if (pas==4)
{for (int positionCounter = 0; positionCounter < 31; positionCounter++) 
{
    
    lcd.scrollDisplayRight();
    
    delay(500);
  if (val== HIGH )
 {
  break;
  }
}
}
else
{
  for (int positionCounter = 0; positionCounter < 3; positionCounter++) 
{
    
    lcd.scrollDisplayRight();
    
    delay(500);
    if (val== HIGH )
 {
  Riavvia();
  }
}
  for (int positionCounter = 0; positionCounter < 3; positionCounter++) 
{
    
    lcd.scrollDisplayLeft();
    
    delay(500);
    val = digitalRead(bottone);

if (val== HIGH )
 {
  break;
  }
}
  }
*/

  
val = digitalRead(bottone);
while (val==LOW && pas==4)
{

lcd.setCursor(0, 0);
  for (int positionCounter = 0; positionCounter < 31; positionCounter++) 
{
    
    lcd.scrollDisplayRight();
        val = digitalRead(bottone);
      if (val== HIGH )
 {
  Riavvia();
  }
    delay(400);

    }
}

}
