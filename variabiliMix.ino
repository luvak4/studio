byte MSGindirizzo;
int  MSGvaloreA;
int  MSGvaloreB;
int  MSGvaloreC;
byte MSGvaloreD;
//
byte BYTE[8];
byte CIFR[8]={156,33,183,95,230,63,250,215};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //
  MSGindirizzo=0xAA;
  MSGvaloreA=14567;
  MSGvaloreB=22657;
  MSGvaloreC=-31245;
  MSGvaloreD=0xBB;
  //
  Serial.println("=================="); 
  Serial.println("=================="); 
  Serial.println(MSGindirizzo,HEX); 
  Serial.println(MSGvaloreA); 
  Serial.println(MSGvaloreB); 
  Serial.println(MSGvaloreC); 
  Serial.println(MSGvaloreD); 

  
  setMessaggio();
  for (byte n=0; n<8;n++){ 
    Serial.print(BYTE[n],HEX);    
  }
  Serial.println(); 
  Serial.println("=================="); 
  getMessaggio();
  Serial.println(MSGindirizzo,HEX); 
  Serial.println(MSGvaloreA); 
  Serial.println(MSGvaloreB); 
  Serial.println(MSGvaloreC); 
  Serial.println(MSGvaloreD); 
  Serial.println("=================="); 
  Serial.println("=================="); 
  
}


// ho il messaggio in BYTE -> STRUTT
void getMessaggio(){
  int tempint;
  BYTE[0]=BYTE[0]^CIFR[0];
  MSGindirizzo=BYTE[0];
  //
  BYTE[2]=BYTE[2]^CIFR[2];
  tempint=BYTE[2];
  tempint=tempint << 8;
  BYTE[1]=BYTE[1]^CIFR[1];
  tempint=tempint+BYTE[1];
  MSGvaloreA=tempint;
  //
  BYTE[4]=BYTE[4]^CIFR[4];
  tempint=BYTE[4];
  tempint=tempint << 8;
  BYTE[3]=BYTE[3]^CIFR[3];
  tempint=tempint+BYTE[3];
  MSGvaloreB=tempint;
  //
  BYTE[6]=BYTE[6]^CIFR[6];
  tempint=BYTE[6];
  tempint=tempint << 8;
  BYTE[5]=BYTE[5]^CIFR[5];
  tempint=tempint+BYTE[5];
  MSGvaloreC=tempint;
  //
  BYTE[7]=BYTE[7]^CIFR[7];
  MSGvaloreD=BYTE[7];
}

// ho il messaggio in STRUT -> BYTE
void setMessaggio(){
  int intt;
  unsigned long mask=0x0000FFFF;
  ////////
  BYTE[0]=MSGindirizzo;
  BYTE[0]=BYTE[0]^CIFR[0];
  ////////
  intt=MSGvaloreA;
  BYTE[1]=intt & mask;
  BYTE[1]=BYTE[1]^CIFR[1];
  intt = intt >> 8;
  BYTE[2]=intt & mask;
  BYTE[2]=BYTE[2]^CIFR[2];
  ////////
  intt=MSGvaloreB;
  BYTE[3]=intt & mask;
  BYTE[3]=BYTE[3]^CIFR[3];
  intt = intt >> 8;
  BYTE[4]=intt & mask;
  BYTE[4]=BYTE[4]^CIFR[4];
  ////////
  intt=MSGvaloreC;
  BYTE[5]=intt & mask;
  BYTE[5]=BYTE[5]^CIFR[5];
  intt = intt >> 8;
  BYTE[6]=intt & mask;
  BYTE[6]=BYTE[6]^CIFR[6];
  ////////
  BYTE[7]=MSGvaloreD;  
  BYTE[7]=BYTE[7]^CIFR[7];
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
