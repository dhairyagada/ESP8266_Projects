#include <ESP8266WiFi.h>
 
/*---------------------------- Initializations ----------------------------*/
int testPin = 14; //GPIO14 -D5

int left_fw = 13; // GPIO13 -D7
int left_bw = 15; // GPIO15 -D8

int right_fw = 0; // GPIO0 -D3
int right_bw = 2; // GPIO2 -D4

int sen_right = 16; //GPIO6 -D0
int sen_center= 5;  //GPIO5 -D1
int sen_left = 4; //GPIO6 -D0

void setup() {
  Serial.begin(115200);
  delay(10);
 /*---------------------------- Defining Pin Modes ----------------------------*/
  pinMode(left_fw, OUTPUT);
  digitalWrite(left_fw, LOW);
  pinMode(left_bw, OUTPUT);
  digitalWrite(left_bw, LOW);
  pinMode(right_fw, OUTPUT);
  digitalWrite(right_fw, LOW);
  pinMode(right_bw, OUTPUT);
  digitalWrite(right_bw, LOW);
  pinMode(testPin, OUTPUT);
  digitalWrite(testPin, LOW);


  pinMode(sen_right, INPUT);
  pinMode(sen_center, INPUT);
  pinMode(sen_left, INPUT);
  
  
 
 
}
 
void loop() {
  
  if(digitalRead(sen_center)==0 && digitalRead(sen_left)==1 && digitalRead(sen_right)==1)
  {
   // Forward
       digitalWrite(left_fw, HIGH);
    digitalWrite(right_fw, HIGH);
    digitalWrite(left_bw, LOW);
    digitalWrite(right_bw, LOW);
  }

  else if(digitalRead(sen_center)==1 && digitalRead(sen_left)==1 && digitalRead(sen_right)==1)
  {
   // Backward
   digitalWrite(left_fw, LOW);
    digitalWrite(right_fw, LOW);
    digitalWrite(left_bw, HIGH);
    digitalWrite(right_bw, HIGH);  
  } 
  else if(digitalRead(sen_center)==1 && digitalRead(sen_left)==1 && digitalRead(sen_right)==0)
  {
   // Right
    digitalWrite(left_fw, HIGH);
    digitalWrite(left_bw, LOW);
    digitalWrite(right_fw, LOW);
    digitalWrite(right_bw, HIGH); 
  }
  else if(digitalRead(sen_center)==0 && digitalRead(sen_left)==1 && digitalRead(sen_right)==0)
  {
   // Hard Right
   digitalWrite(left_fw, HIGH);
    digitalWrite(left_bw, LOW);
    digitalWrite(right_fw, LOW);
    digitalWrite(right_bw, LOW);   
  }
 else if(digitalRead(sen_center)==1 && digitalRead(sen_left)==0 && digitalRead(sen_right)==1)
  {
   // Left
   digitalWrite(left_fw, LOW);
    digitalWrite(left_bw, HIGH);
    digitalWrite(right_fw, HIGH);
    digitalWrite(right_bw, LOW);
  }
 else if(digitalRead(sen_center)==0 && digitalRead(sen_left)==0 && digitalRead(sen_right)==1)
  {
   // Hard Left
   digitalWrite(left_fw, LOW);
    digitalWrite(left_bw, LOW);
    digitalWrite(right_fw, HIGH);
    digitalWrite(right_bw, LOW);    
  }
  else 
  {
    digitalWrite(left_fw, LOW);
    digitalWrite(left_bw, LOW);
    digitalWrite(right_fw, LOW);
    digitalWrite(right_bw, LOW);
  }
}
 
