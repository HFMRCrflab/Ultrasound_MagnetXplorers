#define pin_Echo 7 // Echo pin from HC-SR04 through which the back-US signal is received by the Arduino.
#define pin_Trigger 8 // Trigger pin from the HC-SR04 that allows the Arduino to trigger the emission of US signal //
int measurementmax = 300; // Maximal measured distance in cm. //
int measurementmin = 1; // Minimal measured distance in cm. //
float duration;
float Distance;
void setup()
{
pinMode(pin_Trigger, OUTPUT); // Pin mode defined as output //
pinMode(pin_Echo, INPUT); // Pin mode defined as input //
Serial.begin (115200); // Serial communication UART baud rate //
}
void loop() {
digitalWrite(pin_Trigger, LOW); // Trigger pin set on LOW (= 0) for 2 us. //
delayMicroseconds(2);       
digitalWrite(pin_Trigger, HIGH); // Trigger pin set on HIGH (= 1) for 10 us. //
delayMicroseconds(10);
digitalWrite(pin_Trigger, LOW); // Trigger pin set back to LOW (= 0) for 2 us. //
duration = pulseIn(pin_Echo, HIGH); //Duration during which the ECHO pin is high. This gives the time-of-flight. //
Distance = duration*0.034/2; // Uses the half duration and the velocity of sound in the air in order to compute the distance. //

if (Distance >= measurementmax  || Distanz <= measurementmin) {
Serial.println("Error! The distance is outside the 1-300cm boundary") // Error message for wrong measurements. //;
}    
else {

//Serial.print(" ");
Serial.print("Sound travel time: "); 
Serial.print(duration/1000); 
Serial.println(" ms");
}
delay(3000); // 3s delay between each measurement //
}



