#include <L298N.h>
#include <Wire.h>
#include <NewPing.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Key.h>

#define ON 1
#define OFF 0

#define trigPin1 42 //Set Trigger HCSR04 di Pin digital 6
#define echoPin1 44 //Set Echo HCSR04 di Pin digital 5
#define SLIDER_KANAN 27
#define SLIDER_KIRI 28
#define BLENDER_TENGAH 22
#define BLENDER_KANAN 24
#define BUZZER 36
#define LIMITH1 14
#define LIMITH2 15

int ir1 = A0;
int ir2 = A1;
int PUMP_KIRI = 30;
int PUMP_TENGAH = 32;
int PUMP_KANAN = 40;

#define MAX_DISTANCE 200 //Set jarak maksimal

char inChar;
String namMenu="";
String inString = "";
int angka = 0;
int menu = 0;
int pos;
int first = 0;
bool dar = true;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'} };
byte rowPins[ROWS] = {10, 9, 8, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 5, 4, 3}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

NewPing ultrasonic1(trigPin1, echoPin1, MAX_DISTANCE);

Servo servo1;
Servo servo2;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT); //Set pin Trigger sebagai output
  pinMode(echoPin1, INPUT); //Set pin Echo sebagai input
  pinMode(SLIDER_KANAN, OUTPUT);
  pinMode(SLIDER_KIRI, OUTPUT);
  pinMode(BLENDER_TENGAH, OUTPUT);
  pinMode(BLENDER_KANAN, OUTPUT);
  pinMode(PUMP_KIRI, OUTPUT);
  pinMode(PUMP_TENGAH, OUTPUT);
  pinMode(PUMP_KANAN, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(LIMITH1, INPUT);
  pinMode(LIMITH2, INPUT);  
  
  servo1.attach(11);
  servo2.attach(12);
  
  lcd.begin();
  lcd.backlight();
  
  servo1.write(10);
  servo2.write(90);

  tampilLcd("Selamat Datang", "Toko Kami", 2000);
  digitalWrite(SLIDER_KANAN, OFF);
  digitalWrite(SLIDER_KIRI, ON);

  bacaLimithAwal();  
}

void loop() { 
  inChar = keypad.getKey();
  lcd.setCursor(0,0);
  lcd.print("Masukkan Menu = ");
  if (inChar == 'A'){
    buzzerTekan();
    menu = 1;
    dispMenu("Sprite Susu");
    return menu;
  }else if (inChar == 'B'){
    buzzerTekan();
    menu = 2;
    dispMenu("Fanta Susu");
    return menu;
  }else if (inChar == 'C'){
    buzzerTekan();
    menu = 3;
    dispMenu("Blend");
    return menu;
  }else if (inChar == 'D'){
    buzzerTekan();
    lcd.clear();
    menu = 0;
  }

  if (inChar == '*'){
    buzzerTekan();
    tampilLcd("Tunggu...", " ", 1000);
    cekJumlah(menu);
  }
}

void cekJumlah(int menu){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Masukkan Jumlah: ");
  while(1){
    inChar = keypad.getKey();
    if (inChar >= '0' && inChar <= '9'){
      buzzerTekan();
      first = first * 10 + (inChar - '0');
      Serial.println(first);
      lcd.setCursor(0,1);
      lcd.print(first);
    }
    if(inChar == '*'){
      buzzerTekan();
      for(int i=1; i<=first; i++){
        Serial.println(i);
        if(menu == 1){
          prosesAir(ON, ON, OFF, "Sprite Susu");  
        }
        if(menu == 2){
          prosesAir(OFF, ON, ON, "Fanta susu"); 
        }
        if(menu == 3){
          prosesAir(ON, ON, ON, "Blend");
        }
      }
      menu = 0;
        first = 0;
        lcd.clear();
        return; 
    }  
  } 
}
