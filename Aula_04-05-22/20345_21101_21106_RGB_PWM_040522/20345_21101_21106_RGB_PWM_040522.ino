/*IES: Cotuca/Unicamp
Disciplina: Ds304 - Automação e Controle de Dispositivos
Data: 04 Maio 2022
Código realizado por:
RA 20345 - Guilherme Pavezzi
RA 21101 - Leandro Freitas
RA 21106 - Lunara Cunha

Nome: Atividade - Uso do led RGB como se fosse PWM
Uso do Kit Arduíno Uno em ambiente  Arduíno IDE.  
Código no TinkerCad: https://www.tinkercad.com/things/6hOZAi2UVci?sharecode=A5n8EIEOnUcfsgPyWI_uoe38jxFT-IVcMq2BWJngxxc 
*/

void setup() {
  // put your setup code here, to run once:


/*
digitalWrite (LedRGB[0], LOW);
digitalWrite (LedRGB[1], LOW);
digitalWrite (LedRGB[2], HIGH);
*/
}

void loop() {
  // put your main code here, to run repeatedly:

      for (int i=0; i<256; i++){
        analogWrite(3,i);
        delay(50);
        analogWrite(3,0);
        }

        for(int i=0; i>255; i++){
          analogWrite(3,255-i);
          delay(100);
          analogWrite(3,0);
          }

        for (int i=0; i<256; i++){
        analogWrite(5,i);
        delay(150);
        analogWrite(5,0);
        }

        for(int i=0; i>255; i++){
          analogWrite(5,255-i);
          delay(200);
          analogWrite(5,0);
          }          
         for (int i=0; i<256; i++){
        analogWrite(6,i);
        delay(250);
        analogWrite(6,0);
        }

        for(int i=0; i>255; i++){
          analogWrite(6,255-i);
          delay(300);
          analogWrite(6,0);
          }   

/*

  for (int i =0; i<256; i++) {
    analogWrite(3,i);
    delay(50);
    analogWrite(3,0);
     analogWrite(5,i);
    delay(55);
     analogWrite(5,0);
     analogWrite(6,i);
    delay(67);
     analogWrite(6,0);
    }
    for (int i = 255; i>0; i--)
    {
     analogWrite(3,i);
     delay(80);
     analogWrite(3,0);
     analogWrite(5,i);
     delay(87);
     analogWrite(5,i);
    analogWrite(6,i);
     delay(95);
     analogWrite(6,0);
      }

      for (int i=0; i<256; i++){
        analogWrite(3,i);
        delay(50);
        }

        for(int i=0; i>255; i++){
          analogWrite(2,255-i);
          delay(100);
          }
          */
/* Testando intensidades
digitalWrite (LedRGB[0], HIGH);
digitalWrite (LedRGB[1], LOW);
digitalWrite (LedRGB[2], LOW);
delay (500);
digitalWrite (LedRGB[0], LOW);
digitalWrite (LedRGB[1], HIGH);
digitalWrite (LedRGB[2], LOW);
delay (1000);
digitalWrite (LedRGB[0], LOW);
digitalWrite (LedRGB[1], LOW);
digitalWrite (LedRGB[2], HIGH);
delay (1500);
digitalWrite (LedRGB[0], LOW);
digitalWrite (LedRGB[1], LOW);
digitalWrite (LedRGB[2], LOW);
delay (2000);
digitalWrite (LedRGB[0], HIGH);
digitalWrite (LedRGB[1], HIGH);
digitalWrite (LedRGB[2], HIGH);
delay (2000);
*/
}
