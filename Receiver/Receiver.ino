#include <esp_now.h>
#include <WiFi.h>

int Enable1 = 25;
int Enable2 = 26; 

int LED1 = 18;
int LED2 = 19;
int LED3 = 21;
int LED4 = 4;

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
  char a[32];
  bool b;
  bool c;
  bool d;
  bool e;
} struct_message;
// Create a struct_message called myData
struct_message myData;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Char: ");
  Serial.println(myData.a);
  Serial.print("Char: ");
  Serial.println(myData.b);
  Serial.print("bool: ");
  Serial.println(myData.c);
  Serial.print("bool: ");
  Serial.println(myData.d);
  Serial.print("Bool: ");
  Serial.println(myData.e);
  Serial.print("Bool: ");

}

void setup() {
  pinMode(Enable1, OUTPUT);
  pinMode(Enable2, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  // Initialize Serial Monitor
  Serial.begin(115200);

  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {

  // Here we are going to set up the car movements

  //Move Forward
  if (myData.c  == true) {

    digitalWrite(Enable1, HIGH);
    digitalWrite(Enable2, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);

    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);

  }
  else {
    digitalWrite(Enable1, LOW);
    digitalWrite(Enable2, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED4, HIGH);
  }


  //Right
  if (myData.d == true) {
    //DROITE

    digitalWrite(Enable1, HIGH);
    digitalWrite(Enable2, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);

    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);

  }



  //Rear
  if (myData.b == true) {
    digitalWrite(Enable1, HIGH);
    digitalWrite(Enable2, HIGH);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);

    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
  }


  // Left
  if (myData.e == true) {
    digitalWrite(Enable1, HIGH);
    digitalWrite(Enable2, HIGH);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);

    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  }


}
