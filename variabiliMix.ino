// code-decode message

int  INTERIlocali[4]={7228,-32675,4435,1120};
byte BYTEradio[8];
byte CIFR[8]={156,33,183,95,230,63,250,215};
const unsigned long mask=0x0000FFFF;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("=====originale===="); 
  for (int n=0; n <4; n++){
    Serial.println(INTERIlocali[n]); 
  }
  //  
  encodeMessage();
  //
  Serial.println("=====bytizzato====");
  for (byte n=0; n<8;n++){ 
    Serial.print(BYTEradio[n]);    
  }
  Serial.println(); 
  Serial.println("====recupero======");
  //
  decodeMessage();
  //
  for (int n=0; n <4; n++){
    Serial.println(INTERIlocali[n]); 
  }
}


void decodeMessage(){
  // de-cifratura
  byte m=0;
  cipher();
  for (int n=0; n<4;n++){
    INTERIlocali[n]=BYTEradio[m+1];
    INTERIlocali[n]=INTERIlocali[n] << 8;
    INTERIlocali[n]=INTERIlocali[n]+BYTEradio[m];
    m+=2;
  }
}

void encodeMessage(){
  // from struct to byte
  byte m=0;
  for (int n=0; n<4;n++){
    BYTEradio[m]=INTERIlocali[n] & mask;
    INTERIlocali[n]=INTERIlocali[n] >> 8;
    BYTEradio[m+1]=INTERIlocali[n] & mask;
    m+=2;
  }
  cipher();
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void cipher(){
  for (byte n=0;n<8;n++){
    BYTEradio[n]=BYTEradio[n]^CIFR[n];
  }
}
