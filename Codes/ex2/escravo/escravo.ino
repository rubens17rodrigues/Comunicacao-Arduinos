#include<Wire.h>

const int bt = 2;
const int a1 = 4;
const int a0 = 3;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(2);     
  Wire.onRequest(envia);
  
  pinMode(bt, INPUT_PULLUP);
  pinMode(a0, INPUT_PULLUP);
  pinMode(a1, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void envia(){    //funcao a ser chamada
  char buf[3];  
  buf[0] = digitalRead(bt);         // le o botao
  buf[1] = digitalRead(a0);         // le o sensor A0
  buf[2] = digitalRead(a1);         // le o sensor A1
  Wire.write (buf, 3);             // Envia o estados dos sensores e do botao para o mestre
}
