
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
 

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
void setup() {
  // put your setup code here, to run once:

pinMode (led, OUTPUT);
pinMode (bottone, INPUT);
pinMode (buzzer, OUTPUT);
lcd.begin(16, 2);
lcd.print("TEST RIFLESSI");
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
  pas=0;
  controllo=0;
  lcd.clear();
    lcd.print("Luce "+ String(tempoluc));
    lcd.setCursor(0, 1);
    lcd.print("Buzz "+ String(tempobuz ));
    val=LOW;
    tempobuz=0;
    tempoluc=0;
    delay(15000);
    setup();
   
  }

}
