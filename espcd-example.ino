#include <ESPCD.h>
#include "cert.h"

ESPCD espcd;

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();

  espcd.setUrl("https://api.espcd.duckdns.org/");
  espcd.setCert(cert, certLen);
  espcd.setProductId("8ab5ec33-a659-438e-a6ca-3db62b2141f0");
  espcd.setup();

#if defined(ARDUINO_ARCH_ESP32)
  static WebServer& server = espcd.getServer();
#elif defined(ARDUINO_ARCH_ESP8266)
  static ESP8266WebServer& server = espcd.getServer();
#endif
  server.on("/", []() {
    server.send(200, "text/plain", "Hello World");
  });
  Serial.println("HTTP server started");
}

void loop() {
  espcd.loop();
}
