#include <WiFi.h>
#include "TinyUPnP.h"
#include <EasyDDNS.h>

#define LISTEN_PORT 8080
#define LEASE_DURATION 36000
#define MAPPING_NAME "ESP32 UPnP Request"

void setup() {
  Serial.begin(115200);

  ConnectToWifi();

  SendUPnPRequest();
}

void loop() {
}

void ConnectToWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin("OpenWrt", "upnpwpa2key");
  Serial.println("Connecting to WiFi...\n");

  while (WiFi.status() != WL_CONNECTED) {
    delay(2000);
    Serial.print("Still trying to connect...\n");
  }

  delay(500);

  Serial.println("\nConnected!");
  Serial.println(WiFi.localIP());
}

void SendUPnPRequest() {
  TinyUPnP *tinyUPnP = new TinyUPnP(20000);  // -1 for blocking (preferably, use a timeout value in [ms])

  Serial.println("Initial Port Mapping Check\n");
  tinyUPnP->printAllPortMappings();

  tinyUPnP->addPortMappingConfig(WiFi.localIP(), LISTEN_PORT, RULE_PROTOCOL_TCP, LEASE_DURATION, MAPPING_NAME);

  bool portMappingAdded = tinyUPnP->commitPortMappings();

  String added = String(portMappingAdded ? "WAS" : "WAS NOT");

  Serial.println("Port Mapping " + added + " added");

  Serial.println("Final Port Mapping Check\n");
  tinyUPnP->printAllPortMappings();
}
