// code-decode message
byte MSGindirizzo;
int  MSGvaloreA;
int  MSGvaloreB;
int  MSGvaloreC;
byte MSGvaloreD;
byte BYTE[8];
byte CIFR[8]={156,33,183,95,230,63,250,215};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // dati di esempio
  MSGindirizzo=0xAA;
  MSGvaloreA=14567;
  MSGvaloreB=22657;
  MSGvaloreC=-31245;
  MSGvaloreD=0xBB;
  // originale
  Serial.println("=====originale===="); 
  Serial.println(MSGindirizzo,HEX); 
  Serial.println(MSGvaloreA); 
  Serial.println(MSGvaloreB); 
  Serial.println(MSGvaloreC); 
  Serial.println(MSGvaloreD,HEX);
  //  
  encodeMessage();
  // bytizzato
  Serial.println("=====bytizzato====");
  for (byte n=0; n<8;n++){ 
    Serial.print(BYTE[n],HEX);    
  }
  Serial.println(); 
  Serial.println("====recupero======");
  //
  decodeMessage();
  // recupero da bytizzazione
  Serial.println(MSGindirizzo,HEX); 
  Serial.println(MSGvaloreA); 
  Serial.println(MSGvaloreB); 
  Serial.println(MSGvaloreC); 
  Serial.println(MSGvaloreD,HEX);
  Serial.println("=================="); 
}


void decodeMessage(){
  // from byte to struct
  int tempint;
  
  // de-cifratura
  cipher();
  //
  MSGindirizzo=BYTE[0];
  //
  tempint=BYTE[2];
  tempint=tempint << 8;
  tempint=tempint+BYTE[1];
  MSGvaloreA=tempint;
  //
  tempint=BYTE[4];
  tempint=tempint << 8;
  tempint=tempint+BYTE[3];
  MSGvaloreB=tempint;
  //
  tempint=BYTE[6];
  tempint=tempint << 8;
  tempint=tempint+BYTE[5];
  MSGvaloreC=tempint;
  //
  MSGvaloreD=BYTE[7];
}

void encodeMessage(){
  // from struct to byte
  int intt;
  unsigned long mask=0x0000FFFF;
  ////////
  BYTE[0]=MSGindirizzo;
  ////////
  intt=MSGvaloreA;
  BYTE[1]=intt & mask;
  intt = intt >> 8;
  BYTE[2]=intt & mask;
  ////////
  intt=MSGvaloreB;
  BYTE[3]=intt & mask;
  intt = intt >> 8;
  BYTE[4]=intt & mask;
  ////////
  intt=MSGvaloreC;
  BYTE[5]=intt & mask;
  intt = intt >> 8;
  BYTE[6]=intt & mask;
  ////////
  BYTE[7]=MSGvaloreD;  
  // cifratura
  cipher();
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void cipher(){
  for (byte n=0;n<8;n++){
    BYTE[n]=BYTE[n]^CIFR[n];
  }
}
