//Iluminaço Auto LDR

const int LDR = A0;
const int Led = 11;
int ValorLDR = 0;
int pwm = 0;

void setup() {
pinMode(Led, OUTPUT);
Serial.begin(9600); //para calibrar
}
void loop() {
ValorLDR = analogRead(LDR);
if (ValorLDR<20){
  analogWrite(Led, pwm);
  pwm++;
  delay(100);
}else{
  digitalWrite(Led, LOW);
  pwm=0;
}
if(pwm>255){
  pwm=255;
}
//Serial.print("\nValor lido LDR"); //Para calibrar
//Serial.print(ValorLDR);
//delay(500);            //comentar essas tres linhas
}
