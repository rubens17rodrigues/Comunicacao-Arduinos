void recuo(){
  digitalWrite(rele, HIGH);
  tempo_disparo = millis();
}

void avanco(){
  digitalWrite(rele, LOW);
  flag=false;
}

void tempo_disp (){
  flag=true;
  tempo_disparo = millis();
}
