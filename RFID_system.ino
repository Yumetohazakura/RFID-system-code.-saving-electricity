#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
const int rs = 5 , en = 3, d4 = 2, d5 = 1, d6 = 0, d7 = 6;
String UID1 = "85 C3 10 E3";  //Ishan Saraswat
String UID2 = "5E 85 70 8B";  //Ushika Sinha
String UID3 = "A2 FF D2 59";  //Atharva Naman
String UID4 = "A3 DB A0 59";  //Harshita khanna
 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Put your card to the reader...");
  Serial.println();
  pinMode(7,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(0,OUTPUT);
}
void loop() 
{
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
  if (content.substring(1) == UID1 || content.substring(1) == UID2 || content.substring(1) == UID3 || content.substring(1) == UID4) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    delay(500);
  }
 
 else   {
    Serial.println(" Access denied");
  }

  if (content.substring(1) == UID1 || content.substring(1) == UID2 || content.substring(1) == UID3 || content.substring(1) == UID4){;
  digitalWrite(7 , HIGH);
  delay(2000);
  digitalWrite(7,LOW);
  delay(2000);
  digitalWrite(5, LOW);
  } else  {
  digitalWrite(5,HIGH);
  delay(2000);
  digitalWrite(5,LOW);
  }

  
  
} 
