void warna(int persentaseMerah, int persentaseHijau, int persentaseBiru){
    if((persentaseMerah > 58) && (persentaseMerah < 80) && (persentaseHijau <= 46) && (persentaseBiru<=37)){
      Serial.print(persentaseMerah);
      Serial.print(", ");
      Serial.print(persentaseHijau);
      Serial.print(", ");
      Serial.print(persentaseBiru);
      Serial.println(" - MERAH detected!");
  }
  else if((persentaseMerah <= 37) && (persentaseHijau < 64) && (persentaseHijau > 37) && (persentaseBiru <= 33)){
      Serial.print(persentaseMerah);
      Serial.print(", ");
      Serial.print(persentaseHijau);
      Serial.print(", ");
      Serial.print(persentaseBiru);
      Serial.println(" - HIJAU detected!");
  }
  else if((persentaseMerah <= 33) && (persentaseHijau <=45) && (persentaseBiru < 76) && (persentaseBiru > 38)){
      Serial.print(persentaseMerah);
      Serial.print(", ");
      Serial.print(persentaseHijau);
      Serial.print(", ");
      Serial.print(persentaseBiru);
      Serial.println(" - BIRU detected!");
  }
  else if((persentaseMerah > 36) && (persentaseMerah < 66) && (persentaseHijau > 29) && (persentaseHijau < 47) && (persentaseBiru <= 23)){
      Serial.print(persentaseMerah);
      Serial.print(", ");
      Serial.print(persentaseHijau);
      Serial.print(", ");
      Serial.print(persentaseBiru);
      Serial.println(" - KUNING detected!");
  }
  else if((persentaseMerah > 1) && (persentaseMerah < 72) && (persentaseHijau <= 32) && (persentaseBiru > 31) && (persentaseBiru < 66)){
      Serial.print(persentaseMerah);
      Serial.print(", ");
      Serial.print(persentaseHijau);
      Serial.print(", ");
      Serial.print(persentaseBiru);
      Serial.println(" - UNGU detected!");
  }
  else
  {
      Serial.print(persentaseMerah);
      Serial.print(", ");
      Serial.print(persentaseHijau);
      Serial.print(", ");
      Serial.print(persentaseBiru);
      Serial.println(" - detected!");
      
  }
  
}
