/* Aula Ds304 - Dia 01-06-2022
 *  Atividade sobre Motor Servo
 *  RAs: 
 *  20345 - Guilherme Pavezzi
 *  21101 - Leandro Freitas*  
 *  21106 - Lunara Cunha
 *
*/
// Código no TInkercad: https://www.tinkercad.com/things/3i9RSdozurN?sharecode=nowqoTegAZZlsdFpesSnJhr2yl_DGlqUHlpMAhcwEl0

// Include the Servo library 
 
#include <Servo.h>
Servo servo1;
  #define sPin 3
  #define btn 7
  #define frase "Iniciando"

  

  void setup(){
    Serial.begin(9600);
    Serial.println(frase);
    servo1.attach(sPin);
     pinMode(btn, INPUT);
    }
// Primeiro vai de 0 a 120; depois ao chegar em 120 ele volta para a posição 0;
    void loop(){
    
      if(digitalRead(btn) == HIGH){
      for (int i = 0; i<=120; i+=30){
        servo1.write(i);
        Serial.print("angulo :");
        Serial.println(i);
        delay(100);
        if (i == 120){
        for (int i = 120; i>=0; i-=30){
          servo1.write(i);
        Serial.println(" Estou retornando");
        Serial.print("angulo :");
        Serial.println(i);
        delay(100);
          }
      }
      }
      

      }

    } 
