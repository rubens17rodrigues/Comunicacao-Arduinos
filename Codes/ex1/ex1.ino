#include <TimerOne.h>

const int bt = 2;
const int a1 = 4;
const int a0 = 3;
const int rele = 8;
volatile bool flag = false;
volatile unsigned long tempo_disparo = 0;
int ultestbt;

void setup() {
  // put your setup code here, to run once:
  pinMode(bt, INPUT_PULLUP);
  pinMode(a0, INPUT_PULLUP);
  pinMode(a1, INPUT_PULLUP);
  pinMode(rele, OUTPUT); 
  Serial.begin(9600);
  
 Timer1.initialize(3000000);
 Timer1.attachInterrupt(status_sensores); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int btt= digitalRead(bt);
  int a00= digitalRead(a0);
  int a11= digitalRead(a1);

  if (btt != ultestbt){
    ultestbt=btt;
    if(btt==0){
      recuo();
    }
  }
  
    if(a00==0){
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
 
