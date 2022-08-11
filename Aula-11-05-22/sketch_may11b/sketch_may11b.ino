// Código tinkercad:https://www.tinkercad.com/things/gQQs8OkwkPq?sharecode=leqy9IO7DQM3PzpAV84Oz6hVT92Q6V4WZn5q_ok4bFs 
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
}
 
void loop()
{
  //Limpa a tela
  
  //Posiciona o cursor na coluna 3, linha 0;
  //Envia o texto entre aspas para o LCD
 
   
  //Rolagem para a esquerda
  /*for (int posicao = 0; posicao < 3; posicao++)
  {
    
    delay(300);
  }*/
   
  //Rolagem para a direita
  for (int posicao = 0; posicao < 6; posicao++)
  {
    
    lcd.print("Teste direita");
    delay(350);
    lcd.clear();
     delay(400);
  }
}
