#define PWM1 3

void setup() {
  // put your setup code here, to run once:

pinMode (PWM1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

for (int i = 0; i<=255; i++)
{
  analogWrite(PWM1,i);
  delay(10);
  }
delay(50);
for (int i = 0; i<=255; i--)
{
  analogWrite(PWM1,i);
  delay(10);
  }

} 
