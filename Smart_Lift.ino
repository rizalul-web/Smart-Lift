// include the library code:
#include <Servo.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int trigpin=10;    //penginisal kaki trigpin masuk pin 10
int echopin=9;     //penginisal kaki echopin masuk pin 9
float durasi, jarak;
 Servo servo;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Menampilkan di layar LCD
  lcd.print("Dekatkan tangan");
  servo.attach (8);   //penginisal kaki servo masuk pin 8 
pinMode(trigpin,OUTPUT);  //pin trigpin sebagai OUTPUT
pinMode(echopin,INPUT);   //pin echopin sebagai INPUT
}

void loop() {
  digitalWrite(trigpin,LOW); 
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);  
delayMicroseconds(10);
digitalWrite(trigpin,LOW);

int durasi = pulseIn(echopin,HIGH);   //pin echo membaca atau menerima sinyal
int jarak = durasi /58;    //rumus dalam cm
  if (jarak <= 5) //jarak (cm) dapat diatur dan disesuaikan
{
 servo.write(160);
    lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Terima kasih");
}
   else if (jarak <= 7)
{
 servo.write(140);
     lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Terima kasih");
}
   else if(jarak <= 9){
    servo.write(120);
     lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Terima kasih");
  }
  else if(jarak <= 11){
    servo.write(100);
    lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Terima kasih");
  }
  else if(jarak <= 13){
    servo.write(80);
    lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Terima kasih");
  }
  else if(jarak <= 15){
    servo.write(60);
    lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Terima kasih");
  }
   else if(jarak > 15 ){
    servo.write(40);
    lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dekatkan Tangan");
  lcd.setCursor(0, 1);
  lcd.print("Di Tombol :");
  }

delay(1000); 
}
