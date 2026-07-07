const int ledPin = 2;

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Turn the LED on (HIGH is the voltage level)
  digitalWrite(ledPin, HIGH);
  delay(1000); // Wait for 1 second
  
  // Turn the LED off by making the voltage LOW
  digitalWrite(ledPin, LOW);
  delay(1000); // Wait for 1 second
}