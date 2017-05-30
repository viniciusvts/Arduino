//Projeto dimmer com led

const int PinoPot = A0;
const int Led = 11;
int ValorPot = 0;
int pwm = 0;

void setup() {
pinMode(Led, OUTPUT);
}
void loop() {
ValorPot = analogRead(PinoPot);
pwm = map(ValorPot, 0, 1023, 0, 255);
/*map() mapeia o valor: 
map(valorpot,
  valorpot minimo,
  valorpot maximo,
  novoValorMinimo,
  novoValorMaximo)
*/
analogWrite(Led, pwm);
}
