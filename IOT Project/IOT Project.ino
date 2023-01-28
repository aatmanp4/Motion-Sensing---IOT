//Aatman Patel - aatmanp4/Motion-Sensing---IOT
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLHjB9Eh3_"
#define BLYNK_DEVICE_NAME "FINAL"
#define BLYNK_AUTH_TOKEN "XJpBXIvwjPZXNZKSmi4Z8lCOr6uFR8Z8"  
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#include <SimpleTimer.h>
#include<Servo.h>
Servo servo1;



char auth[] = "XJpBXIvwjPZXNZKSmi4Z8lCOr6uFR8Z8";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Aatman";
char pass[] = "1234567890";

SimpleTimer timer;




// This function sends Arduino's up time every second to Virtual Pin (1).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, millis() / 1000);
  
}

int pir_s = D7; // pir sensor
int ir_s = D1;  // infrared sensor
//int pir_supply = D2;
int pin=D5;//servo

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(pir_s, INPUT); 
  pinMode(ir_s, INPUT); 
  servo1.attach(pin);
  //pinMode(pir_supply, OUTPUT);
  timer.setInterval(1000,sensorvalue1); 
  servo1.write(0);

}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer   
}

void sensorvalue1()
{

if(digitalRead(pir_s) == HIGH)
{
  Blynk.virtualWrite(V2,255 ); // turns on the led
  Blynk.virtualWrite(V5,"\n Intruder detected on PIR Sensor!!!" ); 
  Blynk.notify("\n Intruder detected on PIR Sensor!!!"); 
}

if(digitalRead(pir_s) == LOW)
{
  Blynk.virtualWrite(V2,0 ); //turns off the led
  Blynk.virtualWrite(V5,"\n PIR Normal" ); 
}


    if( digitalRead(ir_s) == LOW)
{
  Blynk.virtualWrite(V3,255 ); // turns on the led
  Blynk.virtualWrite(V5,"\n Intruder detected on IR Sensor!!!" );
  servo1.write(90);
  Blynk.notify("Intruder detected on IR Sensor!!!"); 
} 

 if( digitalRead(ir_s) == HIGH)
{
  Blynk.virtualWrite(V3,0 ); // turns off the led
  servo1.write(0);
}


}