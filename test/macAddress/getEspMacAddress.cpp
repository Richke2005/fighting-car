#include <PS4Controller.h>
#include <esp_bt_main.h>
#include <esp_bt_device.h>
void printDeviceAddress();

void setup() {
  Serial.begin(115200);
  PS4.begin();
  Serial.print("This device MAC is: ");
  printDeviceAddress();
  Serial.println("");
}

void loop() {
  // Below has all accessible outputs from the controller
  delay(200);
}

void printDeviceAddress() {
  const uint8_t* point = esp_bt_dev_get_address();
  for (int i = 0; i < 6; i++) {
    char str[3];
    sprintf(str, "%02x", (int)point[i]);
    Serial.print(str);
    if (i < 5) {
      Serial.print(":");
    }
  }
}