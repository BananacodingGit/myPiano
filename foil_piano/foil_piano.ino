/*
Create by BananaCoding
WebSite: bananacoding.ac
CEO: 최은희
engineer: 김정준, 김용진
e-mail: youngjin.kim@bananacoding.ac
gitHub: https://github.com/BananacodingGit
*/

#include <CapacitiveSensor.h>

int speaker = 13;
int capacity = 400;

CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3);
CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4);
CapacitiveSensor   cs_2_5 = CapacitiveSensor(2,5);
CapacitiveSensor   cs_2_6 = CapacitiveSensor(2,6);
CapacitiveSensor   cs_2_7 = CapacitiveSensor(2,7);
CapacitiveSensor   cs_2_8 = CapacitiveSensor(2,8);
CapacitiveSensor   cs_2_9 = CapacitiveSensor(2,9);
CapacitiveSensor   cs_2_10 = CapacitiveSensor(2,10);

void setup() {
  cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF);
  
  Serial.begin(9600);
}

void loop() {
  long total1 =  cs_2_3.capacitiveSensor(30);
  long total2 =  cs_2_4.capacitiveSensor(30);
  long total3 =  cs_2_5.capacitiveSensor(30);
  long total4 =  cs_2_6.capacitiveSensor(30);
  long total5 =  cs_2_7.capacitiveSensor(30);
  long total6 =  cs_2_8.capacitiveSensor(30);
  long total7 =  cs_2_9.capacitiveSensor(30);
  long total8 =  cs_2_10.capacitiveSensor(30);

  long start = millis();

  Serial.print(millis() - start);
  Serial.print("\t");

  Serial.print(total1);
  Serial.print("\t");
  Serial.print(total2);
  Serial.print("\t");
  Serial.print(total3);
  Serial.print("\t");
  Serial.print(total4);
  Serial.print("\t");
  Serial.print(total5);
  Serial.print("\t");
  Serial.print(total6);
  Serial.print("\t");
  Serial.print(total7);
  Serial.print("\t");
  Serial.println(total8);

  if (total1 > capacity) {tone(speaker,261);}
  if (total2 > capacity) {tone(speaker,294);}
  if (total3 > capacity) {tone(speaker,329);}
  if (total4 > capacity) {tone(speaker,349);}
  if (total5 > capacity) {tone(speaker,392);}
  if (total6 > capacity) {tone(speaker,440);}
  if (total7 > capacity) {tone(speaker,493);}
  if (total8 > capacity) {tone(speaker,523);}

  if (total1<=capacity & total2<=capacity & 
      total3<=capacity & total4<=capacity & 
      total5<=capacity & total6<=capacity &  
      total7<=capacity & total8<=capacity)
  {
    noTone(speaker);
  }
  delay(10);

}
