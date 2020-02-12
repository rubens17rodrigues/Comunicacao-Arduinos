#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

byte mac[]={0x90,0xA2,0xDA,0x00,0x64,0x44};
IPAddress ip(192,168,1,200);
unsigned int port =8888;
EthernetUDP Udp;
byte remoteip[]={192,168,1,80};
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];

const int bt = 2;
const int a1 = 3;
const int a0 = 4;
volatile bool flag = false;
volatile unsigned long tempo_disparo = 0;
int ultestbt;

void setup (){
  Ethernet.begin(mac,ip);
  Serial.begin(9600);
  while (!Serial) {
  }

  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield n encontrado. ");
    while (true) {
      delay(1); // n faz nada precisa do shield para iniciar
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Cabo de ethernet n conectado.");
  }
  Udp.begin(port);

  pinMode(bt, INPUT_PULLUP);
  pinMode(a0, INPUT_PULLUP);
  pinMode(a1, INPUT_PULLUP);
}

void loop(){
  // put your main code here, to run repeatedly:
  int btt= digitalRead(bt);
  int a00= digitalRead(a0);
  int a11= digitalRead(a1);

  if (btt != ultestbt){
    ultestbt=btt;
    if(btt==0){
      msg_recuo();
    }
  }
  
    if(a00==0){
    if(flag==false){
      tempo_disp(); 
    }
  }
  
  if (flag){
    if(millis()-tempo_disparo >= 4000){
      msg_avanco();
    }
  }
}
 
