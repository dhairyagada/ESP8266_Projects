#include <ESP8266WiFi.h>
 
const char* ssid = "linux";               // Enter Wifi Username
const char* password = "012345678";       // Enter Wifi Password
 
int testPin = 14; //GPIO14 -D5            // Test Led

int left_fw = 13; // GPIO13 -D7           // Pins for left motor
int left_bw = 15; // GPIO15 -D8

int right_fw = 0; // GPIO0 -D3            // Pins for right motor
int right_bw = 2; // GPIO2 -D4

WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);                   // Declaring the baud rate for displaying data on serial port
  delay(10);
 
 /*----------------------------------- Initializing Pins as Output -----------------------------------*/
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

  /*----------------------------------- Connecting to WiFi -----------------------------------*/
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  

 if (request.indexOf("/LedTest") != -1)  {
    digitalWrite(testPin, HIGH);
   
  }

  /* ------------- MOVING  FORWARD ---------------------------------------------------------------------------------------------- */
  if (request.indexOf("/fwpin") != -1)  {
    digitalWrite(left_fw, HIGH);
    digitalWrite(right_fw, HIGH);
    digitalWrite(left_bw, LOW);
    digitalWrite(right_bw, LOW);
    
  }

 /* ------------- MOVING  BACKWARD ---------------------------------------------------------------------------------------------- */
  
  if (request.indexOf("/bwpin") != -1)  {
    digitalWrite(left_fw, LOW);
    digitalWrite(right_fw, LOW);
    digitalWrite(left_bw, HIGH);
    digitalWrite(right_bw, HIGH);
    
  }

  /* ------------- MOVING  LEFT ---------------------------------------------------------------------------------------------- */
  
  if (request.indexOf("/leftpin") != -1)  {
    digitalWrite(left_fw, LOW);
    digitalWrite(left_bw, HIGH);
    digitalWrite(right_fw, HIGH);
    digitalWrite(right_bw, LOW);
    
  }

   /* ------------- MOVING HARD  LEFT ---------------------------------------------------------------------------------------------- */
  
  if (request.indexOf("/hleft") != -1)  {
    digitalWrite(left_fw, LOW);
    digitalWrite(left_bw, LOW);
    digitalWrite(right_fw, HIGH);
    digitalWrite(right_bw, LOW);
    
  }

 /* ------------- MOVING  RIGHT ---------------------------------------------------------------------------------------------- */
  
  if (request.indexOf("/rightpin") != -1)  {
    digitalWrite(left_fw, HIGH);
    digitalWrite(left_bw, LOW);
    digitalWrite(right_fw, LOW);
    digitalWrite(right_bw, HIGH);
    
  }

  /* ------------- MOVING  HARD RIGHT ---------------------------------------------------------------------------------------------- */
  
  if (request.indexOf("/hright") != -1)  {
    digitalWrite(left_fw, HIGH);
    digitalWrite(left_bw, LOW);
    digitalWrite(right_fw, LOW);
    digitalWrite(right_bw, LOW);
    
  }

/* -------------STOPPING ---------------------------------------------------------------------------------------------- */
  
  if (request.indexOf("/stop") != -1)  {
    digitalWrite(left_fw, LOW);
    digitalWrite(left_bw, LOW);
    digitalWrite(right_fw, LOW);
    digitalWrite(right_bw, LOW);
    
  }
  

 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Working ");
 
  
  Serial.println("");
 
}
