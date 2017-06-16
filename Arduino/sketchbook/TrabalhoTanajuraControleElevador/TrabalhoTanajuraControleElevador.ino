//Saida de informaçao
const int pinLED [] = {2,3,4,5};
const int pinClock = 6;

//entrada de informacao
//const int pinPot = 0; //retirado
const int pinBotao1 = 8;
const int pinBotao2 = 9;
const int pinSensorPresenca = 10;

//para os botões que pedem andares:
const int andar1 = A0; //A0
const int andar2 = A1; //A1
const int andar3 = A2; //A2
const int andar4 = A3; //A3
const int andar5 = A4; //A4
const int andar6 = A5; //A5

const int VALORMEDIO = 1010;

int andarvar1 = 0; //A0
int andarvar2 = 0; //A1
int andarvar3 = 0; //A2
int andarvar4 = 0; //A3
int andarvar5 = 0; //A4
int andarvar6 = 0; //A5

//controles
int controlSensorPresenca = 0; //controla o loop do sensor de presença
int controlVerificaAndar = 0; //Controla o andar
int controlBotoesEscolhaAndar = 0; //controla o loop dos botoes de andar
int controlAndarPedido = 0; //controla se estiver no andar pedido
int controlTempoTroca = 200; //Lia pot e lancava aqui aqui, agora set um valor
long unsigned int controlUltimoTempoLido = 0; //Ultimo tempo lido no millis

int controlSentido = 1; //controla o sentido dos leds
int controlArrayLeds = 0; //controla a posição no array dos leds

//quando 1 acende led, quando 0 apaga led
int controlLoop = 0;

void setup()
{
  //Inicializo a porta serial
  Serial.begin(9600);

  //inicializo os pinos
  for(int x=0; x<4; x++)
  {
    pinMode(pinLED[x], OUTPUT);
  }
  pinMode(pinClock, OUTPUT);
  pinMode(pinBotao1, INPUT);
  pinMode(pinBotao2, INPUT);
  pinMode(pinSensorPresenca, INPUT);
}

void loop()
{
  Serial.println( controlVerificaAndar );
  Serial.println( controlBotoesEscolhaAndar );
  Serial.println( analogRead(andar1) );
  Serial.println( analogRead(andar2) );
  Serial.println( analogRead(andar3) );
  lerHardware();

  if( isTimeMotor() == 1 )
  {
    if( controlLoop == 1 )
    {
      ligaLed();
    }else if(  controlLoop == 0 )
    {
      deslLed();
      controleLed();
    }else
    {
      iteraAndarPedido();
    }
  }
  contarAndar();
  selecionaAndar();
  controleLoop();
}

//Para fazer a leitura do Hardware
void lerHardware()
{

  //Ler os botoes de fim de trilha para mudar o controlSentido
  //Alterar a condição para LOW se o botão for intermitente ligado
  if ( digitalRead(pinBotao1) == HIGH )
  {
    controlSentido = 1;
  }else if( digitalRead(pinBotao2) == HIGH )
  {
    controlSentido = -1;
  }
  //-------------------------------------------------------------------------------
  //Ler Potenciometro para a velocidade de execução da troca
  //controlTempoTroca = analogRead(pinPot);
  //-------------------------------------------------------------------------------
  //Ler se algum botao de andar esta pressionado
  andarvar1 = analogRead( andar1 );
  andarvar2 = analogRead( andar2 );
  andarvar3 = analogRead( andar3 );
  andarvar4 = analogRead( andar4 );
  andarvar5 = analogRead( andar5 );
  andarvar6 = analogRead( andar6 );
}

//verifica millis
int isTimeMotor()
{
  if( ( millis() - controlUltimoTempoLido ) > controlTempoTroca )
  {
    controlUltimoTempoLido = millis();
    return 1;
  }
  return 0;
}

//me diz em que loop eu estou
void controleLoop()
{
  if(controlLoop == 0)
  {
    controlLoop = 1;
  }else
  {
    controlLoop = 0;
  }
}

//Liga o led
void ligaLed()
{
  digitalWrite(pinClock, HIGH);
  digitalWrite(pinLED[controlArrayLeds], HIGH);
}
//Desliga o led
void deslLed()
{
  digitalWrite(pinClock, LOW);
  digitalWrite(pinLED[controlArrayLeds], LOW);
}

//Controla o sentido
void controleLed()
{
  if(controlSentido == 1)
  {
    controlArrayLeds++;
    if( controlArrayLeds > 3 )
    {
      controlArrayLeds = 0;
    }
  }else if (controlSentido == -1)
  {
    controlArrayLeds--;
    if( controlArrayLeds < 0 )
    {
      controlArrayLeds = 3;
    }
  }
}

//verifica o andar e o atualiza na var controlSensorPresenca
void contarAndar()
{
  if( (digitalRead(pinSensorPresenca) == LOW ) && ( controlSensorPresenca == 0 ) )
  {
    controlSensorPresenca = 1; //controle para não contar mais de um andar por vez
    
    if(controlSentido == 1)
    {
      controlVerificaAndar++;
    }else if (controlSentido == -1)
    {
      controlVerificaAndar--;
    }
  }

  if( (digitalRead(pinSensorPresenca) == HIGH ) && ( controlSensorPresenca == 1 ) )
  {
    controlSensorPresenca = 0; //controle para não contar mais de um andar por vez
  }
}

//verifica se esta no andar que pediu
int estaNoAndar()
{
  if(controlVerificaAndar == controlBotoesEscolhaAndar )
  {
    return 1;
  }
}

void selecionaAndar()
{
  //->->prepare-se para meio mundo de if
  if( andarvar1 > VALORMEDIO )
  {
    controlBotoesEscolhaAndar = 1;
  }
  if( andarvar2 > VALORMEDIO )
  {
    controlBotoesEscolhaAndar = 2;
  }
  if( andarvar3 > VALORMEDIO )
  {
    controlBotoesEscolhaAndar = 3;
  }
  if( andarvar4 >VALORMEDIO )
  {
    controlBotoesEscolhaAndar = 4;
  }
  if( andarvar5 > VALORMEDIO )
  {
    controlBotoesEscolhaAndar = 5;
  }
  if( andarvar6 > VALORMEDIO )
  {
    controlBotoesEscolhaAndar = 6;
  }
}

void iteraAndarPedido()
{
  controlAndarPedido++;
  if(controlAndarPedido > 8)
  {
    controlAndarPedido = 0;
  }
}

