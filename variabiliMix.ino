void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  unsigned long uno;
  uno=0;
  uno=scorriotto(uno,0xAA);
  uno=scorrisedici(uno,1234);
  uno=scorriotto(uno,5);
  Serial.println(uno,HEX);
  Serial.println(leggiprimiotto(uno));
    Serial.println(leggiint(uno));
}

unsigned long scorriotto(unsigned long valore, byte aggiungi){
  valore=valore << 8;
  valore+=aggiungi;
  return valore;
}

unsigned long scorrisedici(unsigned long valore, unsigned int aggiungi){
  valore=valore << 16;
  valore+=aggiungi;
  return valore;
}

byte leggiprimiotto(unsigned long valore){
  unsigned long mask=0x000000FF;
  return valore & mask;
}

unsigned int leggiint(unsigned long valore){
  valore=valore>>8;
  unsigned long mask=0x0000FFFF;
  return valore & mask;
}
void loop() {
  // put your main code here, to run repeatedly:

}
