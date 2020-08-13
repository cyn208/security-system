/*
 * Author : Newton Kelvin
 * Burglar alert Security System Utilizing SIM800L from SimCom 
 */


#include "SIM900.h"
#include <SoftwareSerial.h>
//If not used, is better to exclude the HTTP library,
//for RAM saving.
//If your sketch reboots itself proprably you have finished,
//your memory available.
//#include "inetGSM.h"

//If you want to use the Arduino functions to manage SMS, uncomment the lines below.
#include "sms.h"
SMSGSM sms;

int alarm = 8;                // choose the pin for the LED
int inputPin = 4;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status.
int inputPin1 = 5;
int inputPin2 = A2;
int inputPin3 = A3;
int inputPin4 = A4;
int inputPin5 = A6;
int inputPin6 = A7;


int numdata;
boolean started=false;
char smsbuffer[160];
char n[20];

void setup() 
{
  digitalWrite(inputPin, LOW);
  digitalWrite(inputPin1, LOW);
  digitalWrite(inputPin2, LOW);
  digitalWrite(inputPin3, LOW);
  digitalWrite(inputPin4, LOW);
  digitalWrite(inputPin5, LOW);
  digitalWrite(inputPin6, LOW);
  pinMode(alarm, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
    //Serial connection.
  Serial.begin(9600);
  Serial.println("GSM Shield testing.");
  if (gsm.begin(2400)){
    Serial.println("\nstatus=READY");
    started=true;  
  }
  else Serial.println("\nstatus=IDLE");
  
  if(started){
    //Enable this two lines if you want to send an SMS.
    if (sms.SendSMS("+254794094271", "SOMEONE IN CHURCH   ")){
      Serial.println("\nSMS sent OK");
  }
   if (sms.SendSMS("+254723868407", "SOMEONE IN CHURCH")){
      Serial.println("\nSMS sent OK");
   }
  }
}

void loop() {
  pir1();
  pir2();
  pir3();
  pir4();
  pir5();
  pir6();
  pir7();
  if(started){
    //Read if there are messages on SIM card and print them.
    if(gsm.readSMS(smsbuffer, 160, n, 20))
    {
      Serial.println(n);
      Serial.println(smsbuffer);
    }
    delay(1000);
  }
}

void Send_Sms(){

  //Start configuration of shield with baudrate.
  //For http uses is raccomanded to use 4800 or slower.
    if (gsm.begin(2400)){
    Serial.println("\nstatus=READY");
    started=true;  
  }
  else Serial.println("\nstatus=IDLE");
  
  if(started){
    //Enable this two lines if you want to send an SMS.
    if (sms.SendSMS("+254723868407", "SOMEONE IN AT DELIVERANCE CHURCH - NAROMORU")){
      Serial.println("\nSMS sent OK");
  }
   if (sms.SendSMS("+254702526264", "SOMEONE IN AT DELIVERANCE CHURCH - NAROMORU")){
      Serial.println("\nSMS sent OK");
  }
  }
  delay(1000);
}
void pir1(){
   if (digitalRead(inputPin) == HIGH) {
    digitalWrite(alarm, HIGH); // The Relay Input works Inversly
    Send_Sms();
    delay(100000);
    digitalWrite(alarm, LOW); // The Relay Input works Inversly
    Serial.println("Motion Detected");
    delay(1000);
  }
}
void pir2(){
   if (digitalRead(inputPin1) == HIGH) {
    digitalWrite(alarm, HIGH); // The Relay Input works Inversly
    Send_Sms();
    delay(100000);
    digitalWrite(alarm, LOW); // The Relay Input works Inversly
    Serial.println("Motion Detected");
    delay(1000);
  }
}
void pir3(){
   if (digitalRead(inputPin2) == HIGH) {
    digitalWrite(alarm, HIGH); // The Relay Input works Inversly
    Send_Sms();
    delay(100000);
    digitalWrite(alarm, LOW); // The Relay Input works Inversly
    Serial.println("Motion Detected");
    delay(1000);
  }
}
void pir4(){
   if (digitalRead(inputPin3) == HIGH) {
    digitalWrite(alarm, HIGH); // The Relay Input works Inversly
    Send_Sms();
    delay(100000);
    digitalWrite(alarm, LOW); // The Relay Input works Inversly
    Serial.println("Motion Detected");
    delay(1000);
  }
}
void pir5(){
   if (digitalRead(inputPin4) == HIGH) {
    digitalWrite(alarm, HIGH); // The Relay Input works Inversly
    Send_Sms();
    delay(100000);
    digitalWrite(alarm, LOW); // The Relay Input works Inversly
    Serial.println("Motion Detected");
    delay(1000);
  }
}
void pir6(){
   if (digitalRead(inputPin6) == HIGH) {
    digitalWrite(alarm, HIGH); // The Relay Input works Inversly
    Send_Sms();
    delay(100000);
    digitalWrite(alarm, LOW); // The Relay Input works Inversly
    Serial.println("Motion Detected");
    delay(1000);
  }
}
void pir7(){
   if (digitalRead(inputPin5) == HIGH) {
    digitalWrite(alarm, HIGH); // The Relay Input works Inversly
    Send_Sms();
    delay(100000);
    digitalWrite(alarm, LOW); // The Relay Input works Inversly
    Serial.println("Motion Detected");
    delay(1000);
  }
}
