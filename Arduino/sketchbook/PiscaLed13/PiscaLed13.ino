// Minha modficação do programa "Blink"
int Led = 13;
void setup() {
  // inicializar o pino digital 13 como saida 
  pinMode(Led, OUTPUT);
}
void loop() {
  digitalWrite(Led, HIGH);   // liga o led
  delay(1000);              // espera 1000 mili segundos
  digitalWrite(Led, LOW);    // desliga o led
  delay(250);              // espera 250 milissegundos
  digitalWrite(Led, HIGH);
  delay(1000);
  digitalWrite(Led, LOW);
  delay(250);
  digitalWrite(Led, HIGH);
  delay(1000);
  digitalWrite(Led, LOW);
  delay(250);
  digitalWrite(Led, HIGH);
  delay(2000);
  digitalWrite(Led, LOW);
  delay(500);

}
