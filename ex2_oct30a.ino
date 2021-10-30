//Juan Pablo Acero Herrejon
#include <LiquidCrystal.h>

float fuerza = 0.0;
float voltaje = 0.0;
float v2 = 0.0;
double resist = 0.0;
double peso = 0.0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  pinMode(A0, INPUT);
  lcd.begin (16,2);
  Serial.begin (9600);
}

void loop ()
{
  voltaje=(analogRead(A0));
  v2 = (voltaje*5)/1023;
  resist =1000*((5/v2)-1);
  if(v2<0.5){
    fuerza=pow((resist/4184.9),(1/-1.213));
  }else{
    fuerza = pow((resist/6006.8),(1/-0.701));
  }
  
  peso = ((fuerza/9.81)*1000);

  lcd.setCursor(0,0);
  lcd.print("Fuerza: ");
  lcd.print(fuerza);
  lcd.setCursor(12,0);
  lcd.print("  N");
  lcd.setCursor(0,1);
  lcd.print("Peso: ");
  lcd.print(peso);
  lcd.setCursor(12,1);
  lcd.print("  g");
}
