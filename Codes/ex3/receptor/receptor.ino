#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

const int rele = 8;


byte mac[]={0x90,0xA2,0xDA,0x00,0x64,0x50};
IPAddress ip(192,168,1,80);
unsigned int port = 8888;
EthernetUDP Udp;
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];

void setup(){
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
  
  pinMode(rele, OUTPUT);
}

void loop(){
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
    
    if(packetBuffer[0]=='1'){
      recuo();
    }
    if(packetBuffer[0]=='0'){
      avanco();
    }
  }
}
    
