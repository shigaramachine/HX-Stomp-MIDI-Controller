/**
 * @file      WLAN.ino
 * @brief     WLAN setting
 * @note      
 * @author    shigara
 * @copyright 
 */

#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

//wifi AP
static const char *ssid = "hx stomp";
static const char *pwd = "11922960";

//server
IPAddress ip( 192, 168, 128, 21); 
IPAddress subnet( 255, 255, 255, 0 );

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

String processor(const String& var){

}
 
void SetupWLAN(void){
  // Initialize SPIFFS  
  if(!SPIFFS.begin()){
    //Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
  
  WiFi.mode(WIFI_AP); 
  WiFi.softAPConfig(ip, ip, subnet); 
  WiFi.softAP(ssid, pwd); 

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });
  
  // Route to load style.css file
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css", "text/css");
  });

  //buttons request
  server.on("/tuner", HTTP_GET, [](AsyncWebServerRequest *request){
    SendCommandControl(e_control_tuner);
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  server.on("/SW1", HTTP_GET, [](AsyncWebServerRequest *request){
    SendCommandControl(e_control_sw1);  
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  server.on("/SW2", HTTP_GET, [](AsyncWebServerRequest *request){
    SendCommandControl(e_control_sw2);  
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  server.on("/SW3", HTTP_GET, [](AsyncWebServerRequest *request){
    SendCommandControl(e_control_sw3);  
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  server.on("/SW4", HTTP_GET, [](AsyncWebServerRequest *request){
    SendCommandControl(e_control_sw4);  
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  server.on("/SW5", HTTP_GET, [](AsyncWebServerRequest *request){
    SendCommandControl(e_control_sw5);  
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });
  
  server.on("/control_mode", HTTP_GET, [](AsyncWebServerRequest *request){
    ToggleControlMode();
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  // Start server
  server.begin();
}
