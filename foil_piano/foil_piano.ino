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
  long C_4 =  cs_2_3.capacitiveSensor(30);
  long D_4 =  cs_2_4.capacitiveSensor(30);
  long E_4 =  cs_2_5.capacitiveSensor(30);
  long F_4 =  cs_2_6.capacitiveSensor(30);
  long G_4 =  cs_2_7.capacitiveSensor(30);
  long A_4 =  cs_2_8.capacitiveSensor(30);
  long B_4 =  cs_2_9.capacitiveSensor(30);
  long C_5 =  cs_2_10.capacitiveSensor(30);

  Serial.print(C_4);
  Serial.print("\t");
  Serial.print(D_4);
  Serial.print("\t");
  Serial.print(E_4);
  Serial.print("\t");
  Serial.print(F_4);
  Serial.print("\t");
  Serial.print(G_4);
  Serial.print("\t");
  Serial.print(A_4);
  Serial.print("\t");
  Serial.print(B_4);
  Serial.print("\t");
  Serial.println(C_5);

  if (C_4 > capacity) {tone(speaker,261);}
  if (D_4 > capacity) {tone(speaker,294);}
  if (E_4 > capacity) {tone(speaker,329);}
  if (F_4 > capacity) {tone(speaker,349);}
  if (G_4 > capacity) {tone(speaker,392);}
  if (A_4 > capacity) {tone(speaker,440);}
  if (B_4 > capacity) {tone(speaker,493);}
  if (C_5 > capacity) {tone(speaker,523);}

  if (C_4<=capacity & D_4<=capacity & E_4<=capacity & 
      F_4<=capacity & G_4<=capacity & A_4<=capacity &  
      B_4<=capacity & C_5<=capacity)
  {
    noTone(speaker);
  }
  delay(10);

}
