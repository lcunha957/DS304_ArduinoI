// Código TinkerCad: https://www.tinkercad.com/things/dy5RkI8JBYZ?sharecode=-owU_SCIUh6sXApZC4RQS8Vyv7Oe2A3s6f7Pis6F1os
#define PWM1 3
#define PWM2 5

void setup() {
  // put your setup code here, to run once:

pinMode (PWM1, OUTPUT);
pinMode (PWM2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

for (int i = 0; i<=255; i++)
{
  analogWrite(PWM1,i);
  analogWrite(PWM2,i);
  delay(10);
  }
delay(50);
for (int i = 0; i<=255; i--)
{
  analogWrite(PWM1,i);
  analogWrite(PWM2,i);
  delay(10);
  }

} 
