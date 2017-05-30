//Saida de informaçao
const int pinLED [] = {2,3,4,5};
const int pinClock = 6;
//entrada de informacao
const int pinPot = 0;
const int pinBotao1 = 8;
const int pinBotao2 = 9;
//controles
int tempoTrocaLeds;
int sentido = 1;
int control = 0;

unsigned long tempo;

void setup() {
  // put your setup code here, to run once:
  for(int x=0; x<4; x++){
    pinMode(pinLED[x], OUTPUT);
  }
  pinMode(pinClock, OUTPUT);
  pinMode(pinBotao1, INPUT);
  pinMode(pinBotao2, INPUT);
}

void loop() {
  lerBotao();
  piscaLed();
  controleLed();
}

void lerBotao(){
  if (digitalRead(pinBotao1) ){
    sentido = 1;
  }else if( digitalRead(pinBotao2) ){
    sentido = -1;
  }
}
void piscaLed(){
  digitalWrite(pinClock, HIGH);
  digitalWrite(pinLED[control], HIGH);
  delay( analogRead(pinPot) );
  digitalWrite(pinClock, LOW);
  digitalWrite(pinLED[control], LOW);
}
void controleLed(){
  if(sentido == 1){
    control++;
    if( control > 3 ){
      control = 0;
    }
  }
  if (sentido == -1){
    control--;
    if( control < 0 ){
      control = 3;
    }
  }
}

