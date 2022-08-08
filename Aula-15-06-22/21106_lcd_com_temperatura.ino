
//IES: Cotuca/Unicamp
//Curso: 59 - Desenvolvimento em Sistemas Noturno
//Disciplina: DS304 - Automação e Controle de Dispositivos
//Projeto realizado por:
//RA 21106 - Lunara Morena Cunha
//Data: 15-06-2022
//Atividade: Display LCD com sensor de temperatura

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int temperatura = A0;


void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.print("RA 21106");
  delay(2000);
  lcd.clear();
  }



void loop()
{
  
   float leitura = analogRead(A0);
   float temperaturaLida = (((leitura)*5/(1023))/0.01);
    lcd.setCursor(0,1);
  lcd.print("Temp.em C: ");
  lcd.setCursor (10,2);
  lcd.print(temperaturaLida);
  delayMicroseconds(1000);
  Serial.println ("--------------------------------------");
  Serial.print ("RA 21106 ");
  Serial.println ("--------------------------------------");
  Serial.print ("Temperatura : ");
  Serial.print(temperaturaLida);
  Serial.print(" em graus Celsius");
Serial.println ("---------------------------------------");
  
}
 