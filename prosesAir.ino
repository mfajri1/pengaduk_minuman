void prosesAir(int pump1, int pump2, int pump3, String dataTampil){
  tampilLcd("Proses Pengisian", dataTampil, 0);
  delay(200);
  servo1.write(55);
  delay(1000);
  servo1.write(10);
  delay(1500);
  digitalWrite(SLIDER_KANAN, ON);
  digitalWrite(SLIDER_KIRI, OFF);
  bacaIr1Awal(pump1,pump2,pump3);
}

void bacaIr1Awal(int pump1, int pump2, int pump3){
  while(1){
    int data1 = analogRead(ir1);
    delay(100);
    if(data1 <= 30){
      digitalWrite(SLIDER_KANAN, OFF);
      digitalWrite(SLIDER_KIRI, OFF);
      delay(500);
      digitalWrite(PUMP_TENGAH, pump2);
      delay(2000);
      digitalWrite(PUMP_TENGAH, LOW);
      digitalWrite(PUMP_KANAN, pump1);
      digitalWrite(PUMP_KIRI, pump3);
      bacaUltra(); 
      return;
    }
  }
}

void bacaUltra(){
  while(1){
    delay(250);
    int US1 = ultrasonic1.ping_cm();
    Serial.println(US1);
    if(US1 == 7){
      Serial.println("air penuh");
      digitalWrite(PUMP_KANAN, OFF);
      digitalWrite(PUMP_TENGAH, OFF);
      digitalWrite(PUMP_KIRI, OFF);
      delay(1000);
      digitalWrite(SLIDER_KANAN, ON);
      digitalWrite(SLIDER_KIRI, OFF);
      bacaLimitAkhir();
      return; 
    }
  }  
}

void bacaLimitAkhir(){
  while(1){
    int statLimit = digitalRead(LIMITH2);
    if(statLimit == 0){
      digitalWrite(SLIDER_KANAN, OFF);
      digitalWrite(SLIDER_KIRI, ON);
      delay(50);
      digitalWrite(SLIDER_KANAN, OFF);
      digitalWrite(SLIDER_KIRI, OFF);
      delay(200);
      servo2.write(0);
      delay(1000);
      digitalWrite(BLENDER_KANAN, OFF);
      digitalWrite(BLENDER_TENGAH, ON);
      delay(5000);
      digitalWrite(BLENDER_KANAN, OFF);
      digitalWrite(BLENDER_TENGAH, OFF);
      delay(200);
      servo2.write(90);
      digitalWrite(BUZZER, ON);
      delay(500);
      digitalWrite(BUZZER, OFF);
      delay(500);
      digitalWrite(BUZZER, ON);
      delay(500);
      digitalWrite(BUZZER, OFF);
      delay(500); 
      delay(2000);
      digitalWrite(SLIDER_KANAN, OFF);
      digitalWrite(SLIDER_KIRI, ON); 
      bacaIr1();
      return;
    }
  }
}

void bacaIrStop(){
  while(1){
    int statIr2 = analogRead(ir2);
    if(statIr2 <= 40){
      tampilLcd("Silahkan Angkat", "", 0);
      digitalWrite(SLIDER_KANAN, OFF);
      digitalWrite(SLIDER_KIRI, OFF);
    }else{
       digitalWrite(SLIDER_KANAN, OFF);
       digitalWrite(SLIDER_KIRI, ON); 
    }
    bacaIr1();
    return;
  }  
}

void bacaIr1(){
  while(1){
    int data1 = analogRead(ir1);
    delay(200);
    if(data1 <= 30){
      digitalWrite(SLIDER_KANAN, OFF);
      digitalWrite(SLIDER_KIRI, ON);  
      bacaLimit1();
      return;
     }
  }
}

void bacaLimit1(){
  while(1){
    int statLimit = digitalRead(LIMITH1);
    if(statLimit == 0){
      Serial.println("Sel");
      digitalWrite(SLIDER_KANAN, ON);
      digitalWrite(SLIDER_KIRI, OFF);
      delay(50);
      digitalWrite(SLIDER_KANAN, OFF);
      digitalWrite(SLIDER_KIRI, OFF);
      return;
    }
  }
}
