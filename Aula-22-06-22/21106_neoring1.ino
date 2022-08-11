#include <Adafruit_NeoPixel.h>
/* IES: Cotuca/Unicamp
* Curso: 59 - Desenvolvimento de Sistemas Noturno
* Disciplina: DS304 - Automação e Controle
* Aluna: Lunara Morena Cunha, ra: 21106
* Data: 22 Junho 2022
* Usando o Neo Ring
*/

// Link no TinkerCad: https://www.tinkercad.com/things/h48sq07915i?sharecode=C7FJJnnnCxFXT4tZlz6SXVAjO8ZOHP9Dchyl4ZjScqA

#define LED_PIN 6
#define LED_COUNT 24
//ANEL RGB COM VELOCIDADE
Adafruit_NeoPixel ring (LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

int cnt; // contador atual
int cnt_old; // contador antigo
void setup()
{
  ring.begin();
  
  ring.clear();
  ring.fill(ring.Color(128,50,200),0,23);
  delay(500);
  ring.show();
  ring.clear();

}

void loop()
{
  // cor roxo-magenta nos pares
  for (cnt=0; cnt<24; cnt++){
    if (cnt%2 == 0){
      ring.setPixelColor(cnt,128,20,100);
      delay(500);
      ring.show();
                        
    }
    // cor verde-ciano nos ímpares
    else 
    {
      ring.setPixelColor(cnt,50,79,159);
      delay(500);
      ring.show();
    }
      
     }
    
    // Apagando as cores na volta de um por um
   for (cnt=24; cnt>0; cnt--){
     ring.setPixelColor(cnt,0,0,0);
      delay(500);
      ring.show();
                 
           
  }
  
}
  
   
   
  
  
