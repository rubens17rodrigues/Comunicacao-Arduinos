 #include <XBee.h>
 
const int bt = 2;
const int a1 = 3;
const int a0 = 4;
volatile bool flag = false;
volatile unsigned long tempo_disparo = 0;
int ultestbt;

XBee xbee =XBee();
uint8_t payload[]={0};
XBeeAddress64 add64 =XBeeAddress64(0x0013A200,0x40C1B208);
ZBTxRequest data =ZBTxRequest(add64,payload,sizeof(payload));
ZBTxStatusResponse txStatus = ZBTxStatusResponse();

void setup(){
  Serial.begin(9600);
  xbee.setSerial(Serial);
  
  pinMode(bt, INPUT_PULLUP);
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
