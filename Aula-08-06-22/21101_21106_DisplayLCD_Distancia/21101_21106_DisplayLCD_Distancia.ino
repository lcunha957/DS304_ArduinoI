
/* IES: Cotuca/Unicamp
 *  Disciplina: DS304
 * Data: 08-06-2022
 * RAs: 21101 - Leandro Freitas
 * 21106 - Lunara Cunha
 * Display LCD com sensor de distância
*/
#include <LiquidCrystal.h>
#include <Ultrasonic.h>

LiquidCrystal lcd (2,3,4,5,6,7,8);

//Definição do pinos
#define pino_trigger 11
#define pino_echo 12
char escolhido;
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  Serial.println("Digite p ou c");
  Serial.println("Para ver a distância em metros ou centímetros");
  Serial.println("\n");
  delay(3000);
}
 
void loop(){
 
  //Ler as informações do sensor, em cm e polegada
  double m ,cm, polegadas;
 
  //cria uma variavel para guardar os microsegundos que ele emite uma frequencia, logo apos atribui a essa variavel a uma função que retorna os microsegundos.
  long usec = ultrasonic.timing();
  // variavel para cm onde a ela é atribuida a função que converte microsegundos em centimetros
  cm = ultrasonic.convert(usec, Ultrasonic::CM);
  m  = cm * 1000;
      lcd.print("Dist em metros");
      lcd.print(m);
       lcd.clear();
       
    if (Serial.available()){
      escolhido = Serial.read();
      if (escolhido == 'c')
      lcd.setCursor(0,1);
       lcd.print("Distancia em cm: ");
       Serial.println("Distancia em cm: ");
       lcd.setCursor(0,2);
        lcd.print(cm);
        Serial.print(cm);
    delay(2000);
       lcd.clear();
      }
      // variavel para cm onde a ela é atribuida a função que converte microsegundos em polegadas
  polegadas = ultrasonic.convert(usec, Ultrasonic::IN);
  if (Serial.available()){
      escolhido = Serial.read();
      if (escolhido == 'p')
      lcd.setCursor(0,1);
      lcd.print("Distancia em Polegadas: ");
      Serial.println("Distancia em Polegadas: ");
      lcd.setCursor(0,2);
     lcd.print(polegadas);
     Serial.println(polegadas);
     //tempo para ocorrer a leitura 
  delay(2000);
    lcd.clear();
  }
  
}
