 #include <XBee.h> // inclui a biblioteca
 XBee xbee =XBee(); // Cria um objeto XBee

 const int rele = 8;

 //Cria um objeto ZBRx na variavel rx
ZBRxResponse rx =ZBRxResponse();

void setup(){
  Serial.begin(9600);
  xbee.setSerial(Serial);
  pinMode (rele, OUTPUT);
}

void loop(){

  uint8_t resposta ;
  xbee.readPacket();

  //Checando se o pacote foi recebido
  if(xbee.getResponse().isAvailable()){
    if(xbee.getResponse().getApiId()==ZB_RX_RESPONSE){
      xbee.getResponse().getZBRxResponse(rx);
      resposta = rx.getData(0);
    }
  }

  if (resposta==1){
    digitalWrite(rele, HIGH);
  }
  if (resposta==0){
    digitalWrite(rele, LOW);
  }
}
