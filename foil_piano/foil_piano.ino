
// Import the CapacitiveSensor Library.
#include <CapacitiveSensor.h>


// Name the pin as led. 
#define speaker 13


// Set the Send Pin & Receive Pin.
CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_2_5 = CapacitiveSensor(2,5);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_2_6 = CapacitiveSensor(2,6);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_2_7 = CapacitiveSensor(2,7);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_2_8 = CapacitiveSensor(2,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_2_9 = CapacitiveSensor(2,9);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_2_10 = CapacitiveSensor(2,10);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil


void setup()                    
{
  cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  
  // Arduino start communicate with computer.
  Serial.begin(9600);
}

void loop()                    
{
  
  
  // Set the sensitivity of the sensors.
  long total1 =  cs_2_3.capacitiveSensor(30);
  long total2 =  cs_2_4.capacitiveSensor(30);
  long total3 =  cs_2_5.capacitiveSensor(30);
  long total4 =  cs_2_6.capacitiveSensor(30);
  long total5 =  cs_2_7.capacitiveSensor(30);
  long total6 =  cs_2_8.capacitiveSensor(30);
  long total7 =  cs_2_9.capacitiveSensor(30);
  long total8 =  cs_2_10.capacitiveSensor(30);
  
// Set a timer.
  long start = millis();

  Serial.print(millis() - start);        // check on performance in milliseconds
  Serial.print("\t");                    // tab character for debug windown spacing

  Serial.print(total1);                  // print sensor output 1
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total2);                  // print sensor output 2
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total3);                  // print sensor output 3
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total4);                  // print sensor output 4
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total5);                  // print sensor output 5
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total6);                  // print sensor output 6
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total7);                // print sensor output 7
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.println(total8);                // print sensor output 7
                                         // "println" - "ln" represent as "line", system will jump to next line after print the output.
  
  
  
  
  // When hand is touched the sensor, the speaker will produce a tone.
  // I set a threshold for it, so that the sensor won't be too sensitive.
  if (total1 > 150) tone(speaker,261);
  if (total2 > 150) tone(speaker,294);
  if (total3 > 150) tone(speaker,329);
  if (total4 > 150) tone(speaker,349);
  if (total5 > 150) tone(speaker,392);
  if (total6 > 150) tone(speaker,440);
  if (total7 > 150) tone(speaker,493);
  if (total8 > 150) tone(speaker,523);
  
  // When hand didn't touch on it, no tone is produced.
  if (total1<=150  &  total2<=150  &  total3<=150 & total4<=150  &  total5<=150  &  total6<=150 &  total7 & total8<=150)
    noTone(speaker);

  delay(10);                             // arbitrary delay to limit data to serial port 
}
