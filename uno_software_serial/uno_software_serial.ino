#include <SoftwareSerial.h>  // Thư viện cho cổng nối tiếp mềm

#define RX_PIN 11     // Chân RX của cổng nối tiếp mềm
#define TX_PIN 12     // Chân TX của cổng nối tiếp mềm
#define BUZZER_PIN 8  // Chân kết nối với led

SoftwareSerial unoSerial(RX_PIN, TX_PIN);  // Tạo một đối tượng cổng nối tiếp mềm

void setup() {
  Serial.begin(9600);     // Khởi tạo cổng nối tiếp cứng với tốc độ baud là 9600
  unoSerial.begin(9600);  // Khởi tạo cổng nối tiếp mềm với tốc độ baud là 9600
  // pinMode(LED_PIN, OUTPUT); // Đặt chân kết nối với led là chân đầu ra
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  tone(BUZZER_PIN, 1000, 2000);
  Serial.println(unoSerial.available());
  if (unoSerial.available()) {                // Nếu có dữ liệu từ cổng nối tiếp mềm
    String data = unoSerial.readString();     // Đọc chuỗi dữ liệu
    Serial.println(data);                     // In ra chuỗi dữ liệu
    String value1 = getValue(data, ';', 0);   // Tách phần tử thứ 0 theo ký tự phân cách ';'
    String value2 = getValue(data, ';', 1);   // Tách phần tử thứ 1 theo ký tự phân cách ';'
    String value3 = getValue(data, ';', 1);   // Tách phần tử thứ 1 theo ký tự phân cách ';'
    String value4 = getValue(data, ';', 1);   // Tách phần tử thứ 1 theo ký tự phân cách ';'
    Serial.println("Date:" + value1);         // In ra phần tử thứ 0
    Serial.println("Time:" + value2);         // In ra phần tử thứ 1
    Serial.println("Temperature:" + value3);  // In ra phần tử thứ 1
    Serial.println("Humidity:" + value4);     // In ra phần tử thứ 1
    unoSerial.println("da nhan dc r nhe");
  }
  delay(1000);
}

// Hàm tách chuỗi dữ liệu theo ký tự phân cách và trả về phần tử thứ index
String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
