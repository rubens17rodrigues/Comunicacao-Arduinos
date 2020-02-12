void msg_recuo(){
  payload[0] = 1;
  xbee.send(data);
  tempo_disparo=millis();
}

void msg_avanco(){
  payload[0] = 0;
  xbee.send(data);  
  flag = false;
}

void tempo_disp (){
  flag=true;
  tempo_disparo = millis();
}
