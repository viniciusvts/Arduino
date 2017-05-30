/* Termometro com a barra led
 *  ao passar de 31.5 graus aciona o buzzer
 *  utilizei umas modificações no projeto encontrado
 */
const int LM35 = 0; //sensor de temperatura
float temperatura = 0;
int ADClido = 0;
const int Buzzer = 12;
const int LED[] = {
2,3,4,5,6,7,8,9,10,11};
void setup(){
analogReference(INTERNAL); //No Mega, use INTERNAL1V1, no Leonardo remova essa linha
pinMode(Buzzer, OUTPUT);
for(int x = 0; x < 10; x++){
pinMode(LED[x], OUTPUT);
}
}
void loop(){
ADClido = analogRead(LM35);
temperatura = ADClido * 0.1075268817204301; //no Leonardo use 0.4887585532

for(int i =0; i<10; i++){
  if(temperatura > (25+i)){
  digitalWrite(LED[i], HIGH);
  }
  else{
  digitalWrite(LED[i], LOW);
  }
  if(temperatura > 31){
    tone(Buzzer, 2000);
  }
  else{
    noTone(Buzzer);
   
  }
}
}
