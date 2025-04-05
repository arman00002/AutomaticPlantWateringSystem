int relayPin = 3;
int green = 7;
const int buzzer = 9;

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  pinMode(green, OUTPUT);
  digitalWrite(relayPin, LOW);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int moisturelevel = analogRead(A0);
  Serial.print("Moisture Level: ");
  Serial.println(moisturelevel);

  if (moisturelevel < 600) {
    digitalWrite(relayPin, LOW);     // Pump OFF
    digitalWrite(green, HIGH);       // LED ON
    tone(buzzer, 2000);              // Buzzer ON
  } else {
    digitalWrite(relayPin, HIGH);    // Pump ON
    digitalWrite(green, LOW);        // LED OFF
    noTone(buzzer);                  // Buzzer OFF
  }
}
