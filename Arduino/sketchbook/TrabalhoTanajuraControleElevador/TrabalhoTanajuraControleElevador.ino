//Saida de informaçao
const int pinLED [] = {2,3,4,5};
const int pinClock = 6;

//entrada de informacao
//const int pinPot = 0; //retirado
const int pinBotao1 = 8;
const int pinBotao2 = 9;
const int pinSensorPresenca = 10;
//controles
int controlSensorPresenca = HIGH; //Ler Sensor de presença e lanca aqui
int controlAndar = 0; //Controla o andar

int controlTempoTroca = 60; //Lia pot e lancava aqui aqui, agora set um valor
long unsigned int controlUltimoTempoLido = 0; //Ultimo tempo lido no millis

int controlSentido = 1; //controla o sentido dos leds
int controlArrayLeds = 0; //controla a posição no array dos leds

//quando 1 acende led, quando 0 apaga led
int controlLoop = 0;

void setup() {
  Serial.begin(9600);

  for(int x=0; x<4; x++){
    pinMode(pinLED[x], OUTPUT);
  }
  pinMode(pinClock, OUTPUT);
  pinMode(pinBotao1, INPUT);
  pinMode(pinBotao2, INPUT);
  pinMode(pinSensorPresenca, INPUT);
}

void loop() {
  lerHardware();
  Serial.println("leu hard");

  if(isTime() == 1){
    Serial.println("verificou tempo");
    if(controlLoop == 1){
      Serial.println("verificou loop");
      ligaLed();
    }else{
      deslLed();
      controleLed();
    }
    Serial.println("Ssiu loop");
  }
  Serial.println("saiu tempo");
  
  controleLoop();
  Serial.println("controle loop");
}

//Para fazer a leitura do Hardware
void lerHardware(){

  //Ler os botoes de fim da trilha e mudar o controlSentido
  //Alterar a condição para LOW se o botão for intermitente ligado
  if ( digitalRead(pinBotao1) == HIGH ){
    controlSentido = 1;
  }else if( digitalRead(pinBotao2) == HIGH ){
    controlSentido = -1;
  }

  //Ler sensor de presenca e altera andar
  controlSensorPresenca = digitalRead(pinSensorPresenca);

  //Ler Potenciometro para a velocidade de execução da troca
  //controlTempoTroca = analogRead(pinPot);
}

//verifica millis
int isTime(){
  if( ( millis() - controlUltimoTempoLido ) > controlTempoTroca ){
    controlUltimoTempoLido = millis();
    return 1;
  }
  return 0;
}

//me diz em que loop eu estou
void controleLoop(){
  if(controlLoop == 0){
    controlLoop = 1;
  }else{
    controlLoop = 0;
  }
}

//Liga o led
void ligaLed(){
  digitalWrite(pinClock, HIGH);
  digitalWrite(pinLED[controlArrayLeds], HIGH);
}
//Desliga o led
void deslLed(){
  digitalWrite(pinClock, LOW);
  digitalWrite(pinLED[controlArrayLeds], LOW);
}

//Controla o sentido
void controleLed(){
  if(controlSentido == 1){
    controlArrayLeds++;
    if( controlArrayLeds > 3 ){
      controlArrayLeds = 0;
    }
  }else if (controlSentido == -1){
    controlArrayLeds--;
    if( controlArrayLeds < 0 ){
      controlArrayLeds = 3;
    }
  }
}

