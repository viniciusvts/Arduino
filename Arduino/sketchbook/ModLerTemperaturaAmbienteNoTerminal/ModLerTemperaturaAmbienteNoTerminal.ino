const int LM35 = 0;
float temperatura = 0;
int ADClido = 0;
int inicial = 0;
void setup(){
  Serial.begin(9600);
  analogReference(INTERNAL);
  //Se estiver usando Arduino Mega, use INTERNAL1V1
  //se estiver usando Arduino Leonardo, remova esta linha pois o Leonardo não aceita este comando
}
void loop(){
  if(inicial == 0){
    Serial.println("\n\nComo vai Vinicius.");
    Serial.print("A ");
  }
  ADClido = analogRead(LM35);
  temperatura = ADClido * 0.1075268817; //no Leonardo use 0.4887585532
  Serial.println("Temperatura atual: ");
  Serial.print(temperatura);
  Serial.println(" *C");
  inicial++;
  if(inicial == 9){
    inicial = 0;
  }
  delay(1000);
}
