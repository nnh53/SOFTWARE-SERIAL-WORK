#include "SoftwareSerial.h"
//#include <String.h>

#define RX_PIN 4 //D2
#define TX_PIN 5 //D1

SoftwareSerial espSerial(RX_PIN, TX_PIN);

void setup() {
  Serial.begin(9600);
  espSerial.begin(9600);

  // In ra thông báo khởi động
  Serial.println("ESP8266 UART Communication Example");
}

void loop() {
  delay(2000); // Đợi 2 giây
  Serial.println("ESP8266 UART Communication Example");

  String str = "Hello ahihihi;ahihi2";

  espSerial.println(str); //Gửi giá trị nhiệt độ và độ ẩm qua Software serial
  Serial.println(str); //In ra Serial Monitor chuỗi gửi đi
  
}


//int spliceStr(char str[], int pos, int amount) { //cat đc return 1 ko 0
//  int size = strlen(str);
//  if (pos < 0 || pos >= size) return 0;
//  int i;
//  for (i = pos; i <= size - 1; i++) {
//    str[i] = str[i + amount];
//  }
//  str[size - amount] = '\0';
//  return 1;
//}
//
////void rightTrim(char str[]) {
////  strrev(str);
////  int i, j;
////  for (i = 0; i <= strlen(str) - 1; i++) {
////    if (str[i] == ' ') {
////      for (j = i; j <= strlen(str) - 1; j++) {
////        str[j] = str[j + 1];
////      }
////      str[strlen(str)] = '\0';
////      i--;
////    } else break;
////  }
////  strrev(str);
////}
//
//void leftTrim(char str[]) {
//  int i, j;
//  for (i = 0; i <= strlen(str) - 1; i++) {
//    if (str[i] == ' ') {
//      for (j = i; j <= strlen(str) - 1; j++) {
//        str[j] = str[j + 1];
//      }
//      str[strlen(str)] = '\0';
//      i--;
//    } else break;
//  }
//}
//
//void trim(char str[]) {
//  int size = strlen(str);
//  int i;
//  for (i = 0; i <= strlen(str) - 1; i++) {
//    if (str[i] == ' ' && str[i + 1] == ' ') {
//      spliceStr(str, i, 1);
//      i--;
//    }
//  }
//  if (str[0] == ' ') spliceStr(str, 0, 1);
//  if (str[strlen(str) - 1] == ' ') spliceStr(str, strlen(str) - 1, 1);
//}
//
