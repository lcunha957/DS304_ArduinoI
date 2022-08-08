//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
//Autor: FILIPEFLOP
 
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
#define  buzzer 10

long duration;

int distance;

int safetyDistance;

 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  pinMode(pino_trigger, OUTPUT); // Sets the trigPin as an Output
  pinMode(pino_echo, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}
 
void loop()
{
  //Le as informacoes do sensor, em cm e pol
  
// Clears the trigPin

digitalWrite(pino_trigger, LOW);

delayMicroseconds(15);


// Sets the trigPin on HIGH state for 10 micro seconds

digitalWrite(pino_trigger, HIGH);

delayMicroseconds(30);

digitalWrite(pino_trigger, LOW);


// Reads the echoPin, returns the sound wave travel time in microseconds

duration = pulseIn(pino_echo, HIGH);


// Calculating the distance

distance= duration*0.034/2;


safetyDistance = distance;

if (safetyDistance <= 5){

  digitalWrite(buzzer, HIGH);


}

else{

  digitalWrite(buzzer, LOW);


}


// Prints the distance on the Serial Monitor

Serial.print("Distance: ");

Serial.println(distance);
}
