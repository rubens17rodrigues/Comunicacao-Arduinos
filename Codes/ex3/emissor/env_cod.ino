void msg_recuo(){
  Udp.beginPacket(remoteip, port);
  Udp.write('1');
  Udp.endPacket();   
  tempo_disparo=millis();
}

void msg_avanco(){
  Udp.beginPacket(remoteip, port);
  Udp.write('0');
  Udp.endPacket();
  flag = false;  
}

void tempo_disp (){
  flag=true;
  tempo_disparo = millis();
}
