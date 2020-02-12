void serialEvent() {
  while (Serial.available()) {
    char ls = (char)Serial.read();
    Serial.print("Recebido: ");
    Serial.print(ls); 
    Serial.print("\t");

    switch (ls) {
      case '1':
        recuo();
        Serial.println("Comando recuo cilindro");
        break;
      case '0':
        avanco();
        Serial.println("Comando avanco cilindro");
        break;
      default:
        Serial.println("Comando invalido");
        break;
    }
  }
}
