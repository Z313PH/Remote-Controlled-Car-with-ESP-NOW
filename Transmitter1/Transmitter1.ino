
int BTN1 = 25;
int BTN2 = 26;
int BTN3 = 23;
int BTN4 = 19;
#include <esp_now.h>
#include <WiFi.h>

// REPLACE WITH YOUR RECEIVER MAC Address
uint8_t broadcastAddress[] = {0xEC, 0x94, 0xCB, 0x6D, 0xB9, 0xAC};

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
  char a[32];
  bool b;
  bool c;
  bool d;
  bool e;
} struct_message;

// Create a struct_message called myData
struct_message myData;

esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup() {
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(BTN3, INPUT);
  pinMode(BTN4, INPUT);
  digitalWrite(BTN1, LOW);
  digitalWrite(BTN2, LOW);
  digitalWrite(BTN3, LOW);
  digitalWrite(BTN4, LOW);
  // Init Serial Monitor
  Serial.begin(9600);

  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);

  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  // Add peer
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {

  // Set values to send
  strcpy(myData.a, "This car needs to be done by Friday!!!");
  myData.b = false;
  myData.c = false;
  myData.d = false;
  myData.e = false;



  int BTNst = digitalRead(BTN1);
  int BTNst1 = digitalRead(BTN2);
  int BTNst2 = digitalRead(BTN3);
  int BTNst3 = digitalRead(BTN4);


  if (BTNst2) {
    myData.c = true;
    delay(500);
    Serial.println("Button is pressed!");
  }

  if (BTNst3) {
    myData.e = true;
    delay(500);
    Serial.println("Button is pressed!");
  }




  if (BTNst) {
    myData.d = true;
    delay(500);
    Serial.println(BTNst);
    Serial.println("Button is pressed!");
  }

  if (BTNst1) {
    myData.b = true;
    delay(500);
    Serial.println("Button is pressed!");
  }

  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));

  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }

}
