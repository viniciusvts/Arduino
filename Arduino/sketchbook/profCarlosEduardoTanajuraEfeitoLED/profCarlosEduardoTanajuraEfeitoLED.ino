
int pin_LED [] = {2,3,4,5,6,7,8,9,10,11};
int interval_LED;
int sentido = 1;
int selc_LED = 0;

unsigned long tempo;

int pin_Pot = 0;

void setup() {
  // put your setup code here, to run once:
  for(int x=0; x<10; x++){
    pinMode(pin_LED[x], OUTPUT);
  }
  tempo = millis();

}

void loop() {
  // put your main code here, to run repeatedly:
  interval_LED = analogRead(pin_Pot);
  
  if((millis()-tempo)> interval_LED){
    mudar_LED();
    tempo = millis();
  }

}

void mudar_LED(){
  for( int x=0; x<10; x++){
    digitalWrite(pin_LED[x], LOW);
  }
  digitalWrite(pin_LED[selc_LED],HIGH);
  selc_LED += sentido;
  if(selc_LED == 9){sentido =-1;}
  if(selc_LED == 0){sentido = 1;}
}

