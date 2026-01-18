#include <WiFi.h>
#include <SPI.h>
#include <SD.h>
#include <SPIFFS.h>

const char* ssid = "The Bomb";
const char* password = "verysafepassword";

WiFiServer server(80);

#define SD_CS 5

IPAddress local_ip(192,168,69,69);
IPAddress gateway(192,168,10,1);
IPAddress subnet(255,255,255,0);

void setup() {
  Serial.begin(115200);

  SPIFFS.begin(true);

  SPI.begin(18, 19, 23, SD_CS);
  delay(300);
  SD.begin(SD_CS, SPI, 4000000);

  WiFi.softAPConfig(local_ip, gateway, subnet);
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  String request = "";
  while (client.connected()) {
    if (!client.available()) continue;
    char c = client.read();
    request += c;
    if (c == '\n' && request.endsWith("\r\n\r\n")) break;
  }

  if (request.indexOf("GET /video.mp4") >= 0) {
    File video = SD.open("/video.mp4", FILE_READ);
    if (video) {
      size_t size = video.size();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: video/mp4");
      client.print("Content-Length: ");
      client.println(size);
      client.println("Connection: close");
      client.println();

      uint8_t buf[1024];
      while (video.available() && client.connected()) {
        int len = video.read(buf, sizeof(buf));
        if (len <= 0) break;
        client.write(buf, len);
        delay(1);
      }
      video.close();
    }
  } else {
    File file = SPIFFS.open("/index.html", "r");
    if (file) {
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("Connection: close");
      client.println();
      while (file.available()) {
        client.write(file.read());
      }
      file.close();
    }
  }

  client.stop();
}
