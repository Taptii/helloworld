#include <Servo.h>
Servo myservo; 
int pos = 0;   
const int trigPin = 5;
const int echoPin = 6;
// defining variables
long Distanceincm,duration,Distanceininch;
int distance;
void setup() {
myservo.attach(10); 
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 

Serial.begin(9600); 
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, HIGH);
delay(15);

digitalWrite(trigPin, LOW);
duration=pulseIn(echoPin,HIGH);
Distanceincm=duration/58;
Distanceininch=duration/148;



Serial.print("Distance in cm= ");
Serial.print(Distanceincm);
Serial.print("Distance in inch= ");
Serial.print(Distanceininch);
Serial.println();
delay(500);
if(Distanceininch<40){
  if(Distanceininch>5){
 
 
for (pos = 10; pos <= 360; pos += 2) { 
    myservo.write(pos);             
    delay(1);                       
  } 
  
   delay(100);
    
delay(10);
     
 delay(5000);
for (pos = 360; pos >= 10; pos -= 2) {
    myservo.write(pos);              
    delay(15);                       
  } 
  delay(2000);  
  
        }
}
}