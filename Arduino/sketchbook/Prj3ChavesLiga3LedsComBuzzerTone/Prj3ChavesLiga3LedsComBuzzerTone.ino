const int ledPin1 = 13;
const int ledPin2 = 12;
const int ledPin3 = 11;
const int Buzzer = 10;
const int Botao1 = 2;
const int Botao2 = 3;
const int Botao3 = 4;
int EstadoBotao1 = 0;
int EstadoBotao2 = 0;
int EstadoBotao3 = 0;
void setup(){
pinMode(ledPin1, OUTPUT);
pinMode(Botao1, INPUT);
pinMode(ledPin2, OUTPUT);
pinMode(Botao2, INPUT);
pinMode(ledPin3, OUTPUT);
pinMode(Botao3, INPUT);
pinMode(Buzzer, OUTPUT);
}

void loop(){
EstadoBotao1 = digitalRead(Botao1);
EstadoBotao2 = digitalRead(Botao2);
EstadoBotao3 = digitalRead(Botao3);
if (EstadoBotao1 == HIGH){
digitalWrite(ledPin1, HIGH);
tone(Buzzer, 523.25); //dó
}
else{
digitalWrite(ledPin1, LOW);
noTone(Buzzer);
}
if (EstadoBotao2 == HIGH){
digitalWrite(ledPin2, HIGH);
tone(Buzzer, 587.33); //ré
}
else{
digitalWrite(ledPin2, LOW);
noTone(Buzzer);
}
if (EstadoBotao3 == HIGH){
digitalWrite(ledPin3, HIGH);
tone(Buzzer, 659.26); //mi
}
else{
digitalWrite(ledPin3, LOW);
noTone(Buzzer);
}
}
