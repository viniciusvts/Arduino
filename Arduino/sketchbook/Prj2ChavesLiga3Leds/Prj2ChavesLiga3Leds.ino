/* Utilizando botoes no 2 e no 4
e leds no 11, 12 e 13*/
const int ledPin1 = 13;
const int ledPin2 = 12;
const int ledPin3 = 11;
const int Botao1 = 2;
const int Botao3 = 4;
int EstadoBotao1 = 0;
int EstadoBotao3 = 0;

void setup(){
pinMode(ledPin1, OUTPUT);
pinMode(Botao1, INPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(Botao3, INPUT);
}

void loop(){
EstadoBotao1 = digitalRead(Botao1);
EstadoBotao3 = digitalRead(Botao3);
if (EstadoBotao1 == HIGH && EstadoBotao3 == LOW){
digitalWrite(ledPin1, HIGH);
}
else{
digitalWrite(ledPin1, LOW);
}
if (EstadoBotao1 == HIGH && EstadoBotao3 == HIGH){
digitalWrite(ledPin2, HIGH);
}
else{
digitalWrite(ledPin2, LOW);
}
if (EstadoBotao1 == LOW && EstadoBotao3 == HIGH){
digitalWrite(ledPin3, HIGH);
}
else{
digitalWrite(ledPin3, LOW);
}
}
