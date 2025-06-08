#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>

#include "web_handler.h"

const char *ap_ssid = "Free Wi-Fi - TEST";
const char *ap_password = "";

const byte DNS_PORT = 53;
DNSServer dns_server;
WebServer http_server(80);

void setup() {

    Serial.begin(115200);  
  
    WiFi.softAP(ap_ssid, ap_password);    // create Access Point
    dns_server.start(DNS_PORT, "*", WiFi.softAPIP());   // start DNS server 
    setup_web_handler();    // setup http server
    http_server.begin();        // start http server

    Serial.println("[OK] Captive Portal Started");
    Serial.println("[INFO] IP Address: ");
    Serial.print(WiFi.softAPIP()); 

  }

  void loop() {

    dns_server.processNextRequest();
    http_server.handleClient();

  }
  
