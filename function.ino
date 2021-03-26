void bacaLimithAwal(){
  while(1){
    int statLimit = digitalRead(LIMITH1);
    Serial.println(statLimit);
    if(statLimit == 0){
      digitalWrite(SLIDER_KANAN, ON);
      digitalWrite(SLIDER_KIRI, OFF);
      delay(50);
      digitalWrite(SLIDER_KANAN, OFF);
      digitalWrite(SLIDER_KIRI, OFF);
      return 1;
    }else{
      digitalWrite(SLIDER_KANAN, OFF);
      digitalWrite(SLIDER_KIRI, ON); 
    } 
  }  
}

void servoCW(int rot, int del){
  for (pos = 0; pos <= rot; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
}

void servoCCW(int rot, int del){
  for (pos = rot; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
}

void servo2CW(int rot){
  for (pos = 5; pos <= rot; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
}

void servo2CCW(int rot){
  for (pos = rot; pos >= 5; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
}

void bacaLimithStart(){
  while(1){
    int statLimit = digitalRead(LIMITH2);
    if(statLimit == 1){
      digitalWrite(SLIDER_KANAN, ON);
      digitalWrite(SLIDER_KIRI, OFF);
      delay(300);
      digitalWrite(SLIDER_KANAN, OFF);
      digitalWrite(SLIDER_KIRI, OFF);
      delay(50);
      return 1;  
    }
  }  
}


void bacaLimithAkhir(){
  while(1){
    int statLimit = digitalRead(LIMITH2);
    if(statLimit == 1){
      digitalWrite(SLIDER_KANAN, ON);
      digitalWrite(SLIDER_KIRI, OFF);
      delay(300);
      digitalWrite(SLIDER_KANAN, OFF);
      digitalWrite(SLIDER_KIRI, OFF);
      delay(50);
      return;  
    }  
  }
}

void buzzerTekan(){
  digitalWrite(BUZZER, ON);
  delay(100);
  digitalWrite(BUZZER, OFF);
}

void dispMenu(String namaMenu){
  lcd.setCursor(0,1);
  lcd.print(namaMenu);
}

void tampilLcd(String baris1, String baris2, int del){
  if(del == 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(baris1);
    lcd.setCursor(0,1);
    lcd.print(baris2);  
  }else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(baris1);
    lcd.setCursor(0,1);
    lcd.print(baris2);
    delay(del);
  }
  
}
