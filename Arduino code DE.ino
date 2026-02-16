#define pin_Echo 7 // Echo-pin des HC-SR04 zu D7 (Schall wird mit D7 empfangen)
#define pin_Trigger 8 // Trigger-pin des HC-SR04 zu D8 (Schall wird angesteuert/getriggert mit D8) //
// Definition der Variablen
int messungmax = 300; // Maximale zu messende Distanz wird definiert //
int messungmin = 1; // Minimale zu messende Distanz wird definiert //
float dauer;
float Distanz;
void setup()
{
pinMode(pin_Trigger, OUTPUT); // Pin wird als Ausgang festgelegt //
pinMode(pin_Echo, INPUT); // Pin wird als Eingang festgelegt //
Serial.begin (115200);
}
void loop() {
// Es beginnt die Messung dür 10 us //
digitalWrite(pin_Trigger, LOW); // Trigger wird auf LOW (= 0) gesetzt//
delayMicroseconds(2);       
digitalWrite(pin_Trigger, HIGH); // Trigger wird für 10 us auf HIGH (= 1) gesetzt //
delayMicroseconds(10);
digitalWrite(pin_Trigger, LOW); // Trigger wird wieder auf LOW (= 0) gesetzt //
dauer = pulseIn(pin_Echo, HIGH); //Dauer zwischen Puls und Empfang wird gemessen
Distanz = dauer*0.034/2; // Distanz wird berechnet, um spätere Fehler außerhalb des angegebenen Bereichs anzeigen zu können //


if (Distanz >= messungmax  || Distanz <= messungmin) {
Serial.println("Fehler! Messung ist außerhalb des vorgegebenen Bereichs") // Fehlermeldung für fehlerhafte Messung //;
}    
else {
//Serial.print(" ");
Serial.print("Gemessene Zeit: "); 
Serial.print(dauer/1000); 
Serial.println(" ms");
}
delay(3000); // 1 s Verzögerung vor der nächsten Messung //
}



