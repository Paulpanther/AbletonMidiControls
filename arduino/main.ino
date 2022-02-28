#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include <string.h>

const char* ssid = "...";
const char* password = "...";

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void sendDummyMessage() {
  StaticJsonDocument<100> doc;
  doc["type"] = "event";
  doc["event"]["status"] = 0xB0;
  doc["event"]["key"] = 0;
  doc["event"]["value"] = 124;
  doc["event"]["channel"] = 0;
  String out;
  serializeJson(doc, out);
  ws.textAll(out);
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
//   AwsFrameInfo *info = (AwsFrameInfo*)arg;
//   if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
//     data[len] = 0;
//     if (strcmp((char*)data, "toggle") == 0) {
//       notifyClients();
//     }
//   }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      sendDummyMessage();
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      Serial.printf("WebSocket server error");
      break;
  }
}

void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}

void setup(){
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println(WiFi.localIP());

  initWebSocket();

  server.begin();
}

void loop() {
  ws.cleanupClients();
}
