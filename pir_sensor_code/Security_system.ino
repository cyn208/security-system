/*
 * PIR sensor tester
 */
#include <SoftwareSerial.h>

SoftwareSerial sim800l(2, 3); // RX,TX for Arduino and for the module it's TXD RXD, they should be inverted
 
int alarm = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
 
void setup() {
  pinMode(alarm, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  sim800l.begin(9600);   //Module baud rate, this is on max, it depends on the version
  Serial.begin(9600);   
  delay(1000);
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(alarm, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(alarm, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
void SendSMS()
{
  Serial.println("MOTION AT CHURCH");               //Show this message on serial monitor
  sim800l.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  sim800l.print("AT+CMGS=\"+254702526264\"\r");  //Your phone number don't forget to include your country code, example +212123456789"
  delay(500);
  sim800l.print("MOTION AT CHURCH");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  sim800l.print((char)26);// (required according to the datasheet)
  delay(500);
  sim800l.println();
  Serial.println("Text Sent.");
  delay(500);

}




