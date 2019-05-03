#include<ESP8266WiFi.h>

#include <ESP8266WebServer.h>
// WiFi Definitions
const char* ssid = "SRC";           //set name
const char* password = "12345678"; // set password

int m1 =D1,m2=D2,m3=D3,m4=D4 ; // GPIO

ESP8266WebServer server(80);

void handleL()
{
  Serial.println("L");
    digitalWrite(m1,LOW);
    digitalWrite(m2,LOW);
    
    digitalWrite(m3,HIGH);
    digitalWrite(m4,LOW);
  }
void setup() {
delay(500);
  Serial.begin(115200);
  delay(10);
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

  WiFi.softAP(ssid,password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  Serial.println("");
  

  Serial.begin(115200);
   delay(1);
   pinMode(m1, OUTPUT);
   pinMode(m2, OUTPUT);
   pinMode(m3, OUTPUT);
   pinMode(m4, OUTPUT);


   WiFi.mode(WIFI_AP);
   WiFi.softAP(ssid, password);
  
   server.begin();


  server.begin();
  Serial.println("server started");
  Serial.println(WiFi.localIP());

  server.on("/L",handleL);
}

void loop() {
  
  // Check of client has connected
  WiFiClient client = Server.available();
  if(!client) {
    return;
  }


  /*
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  delay(1);
  //int val;
  // Match the request
  int val;
  if (req.indexOf("/F") != -1)  //server.on("/L",handleL);
   {Serial.println("F");
    digitalWrite(m1,HIGH);
    digitalWrite(m2,LOW);
    
    digitalWrite(m3,HIGH);
    digitalWrite(m4,LOW);
    
    } 
  else if (req.indexOf("/B") != -1)
    {
        Serial.println("B");  
    digitalWrite(m1,LOW);
    digitalWrite(m2,HIGH);
    
    digitalWrite(m3,LOW);
    digitalWrite(m4,HIGH);
      }
  else if (req.indexOf("/R") != -1)
    {
      Serial.println("R");
    digitalWrite(m1,HIGH);
    digitalWrite(m2,LOW);

    
    digitalWrite(m3,LOW);
    digitalWrite(m4,LOW);
      }
  else if (req.indexOf("/L") != -1)
    {Serial.println("L");
    digitalWrite(m1,LOW);
    digitalWrite(m2,LOW);
    
    digitalWrite(m3,HIGH);
    digitalWrite(m4,LOW);
    }
    
  else if (req.indexOf("/W") != -1)
    {Serial.println("W");
    digitalWrite(m1,LOW);
    digitalWrite(m2,LOW);
    
    digitalWrite(m3,LOW);
    digitalWrite(m4,LOW);
    }
    
  else {
    Serial.println("invalid request");
    return;
  }

  // Set GPIO2 according to the request
  //digitalWrite(2, val);



  
  client.flush();

  // Prepare the response
  //String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nGPIO is now ";
  //s += (val)?"high":"low";
  //s += "</html>\n";
String s = "Hello World!!";
  // Send the response to the client
  client.print(s);
  delay(1);
  Serial.println("Client disonnected");

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed


server.handleClient();*/
}
