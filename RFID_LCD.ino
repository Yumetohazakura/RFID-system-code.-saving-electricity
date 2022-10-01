#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
#include <LiquidCrystal.h>
LiquidCrystal lcd(3, 2, A1, A2, A3, A4);
#define Contrast 75
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
String UID1 = "85 C3 10 E3";  //Ishan Saraswat
String UID2 = "5E 85 70 8B";  //Ushika Sinha
String UID3 = "A2 FF D2 59";  //Atharva Naman

void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("HOLY PUT UR FRICKING CARD IN THE READER!");
  Serial.println();
  pinMode(7,OUTPUT);
  pinMode(5,OUTPUT);
  analogWrite(6, Contrast);
  lcd.begin(16, 2);
  lcd.clear();

}
void loop() 
{
    lcd.setCursor(0,0);
  lcd.print("AMAN");
  lcd.setCursor(0,1);
  lcd.print("SIR");
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == UID1 || content.substring(1) == UID2 || content.substring(1) == UID3)//change here the UID of the card/cards that you want to give access
  
    Serial.println("KK UR AUTHORIZED NOW GO OFF");
    Serial.println();
    delay(500);
  }

 else   {
    Serial.println("U FRICKING THEIF GET THE HELL OUTTA HERE");
  }

  if (content.substring(1) == UID1 || content.substring(1) == UID2 || content.substring(1) == UID3 || content.substring(1) == UID4){
  digitalWrite(7 , HIGH);
  delay(2000);
  digitalWrite(7,LOW);
  delay(2000);
  digitalWrite(5, LOW);
  } else  {
  digitalWrite(5,HIGH);
  delay(2000);
  digitalWrite(5,LOW);
  delay(2000);
  digitalWrite(7,LOW);
  }

} 
