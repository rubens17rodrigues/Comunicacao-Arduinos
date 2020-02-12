#include <Wire.h>
#include <TimerOne.h>

const int rele = 8;

int bt,a0,a1,ultestbt;
unsigned long tempo_disparo = 0;
bool flag = false;


void setup() {
  // put your setup code here, to run once:
  Wire.begin();      //Inica a biblioteca wire e define o disposiivo como mestre
  Serial.begin(9600);         //Iniciando a comunicacao Serial
  pinMode(rele, OUTPUT);   // define o led como saida

  Timer1.initialize(3000000);
  Timer1.attachInterrupt(status_sensores); 
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.requestFrom(2,3);    //Requisita 4 bytes do escravo 2
  while (Wire.available()) {  //Leitura dos dados enviados pelo escravo
    bt = Wire.read();
    a0 = Wire.read();
    a1 = Wire.read();
  }
  
  if (bt != ultestbt){
    ultestbt=bt;
    if(bt==0){
      recuo();
    }
  }


  if(a0==0){
    if(flag==false){
      tempo_disp(); 
    }
  }
  
  if (flag){
    if(millis()-tempo_disparo >= 4000){
      avanco();
    }
  }
}
 
