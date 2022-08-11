// Aula realizada em 18-05-2022 pelos RAs:
// 21101 - Leandro Freitas
// 21106 - Lunara Cunha
// Disciplina: DS303, curso 59 noturno
// Projeto com montagem no TinkerCad: https://www.tinkercad.com/things/2X8NSYFL0e7-2110121106tresledsnobrowser/editel 

int led1 = 2;
int led2 = 4;
int led3 = 7;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode (led3, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
   if(Serial.available() > 0) // Read from serial port
    {
      char ReaderFromNode; // Store current character
      ReaderFromNode = (char) Serial.read();
      convertToState(ReaderFromNode); // Convert character to state
    }
  delay(1000);
}
void convertToState(char chr) {
  if(chr=='w'){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(100);
  }
  if(chr=='b'){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(150);
  }
    if(chr=='x'){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(200);
  }
    if(chr=='d'){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(130);
  }
    if(chr=='r'){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(170);
  }
  if(chr=='t'){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(180);
}
}
