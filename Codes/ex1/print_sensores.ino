void status_sensores(){
  Serial.print("Sensor A0: ");
  Serial.print(digitalRead(a0));
  Serial.print("\t");
  Serial.print("Sensor A1: ");
  Serial.println(digitalRead(a1));
}
