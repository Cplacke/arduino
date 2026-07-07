#include <Wire.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Declaration for an SSD1306 display connected to I2C (SDA, SCL)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int ledPin = 2;
      int DELAY = 1000; 

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  // Initialize I2C with ESP32 pins (SDA = 21, SCL = 22)
  Wire.begin(21, 22);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
  display.println(F("Hello World!"));
  display.display();
}

void loop() { // Turn the LED on (HIGH is the voltage level)
  digitalWrite(ledPin, HIGH);
  delay(DELAY); // Wait for 1 second
  
  // Turn the LED off by making the voltage LOW
  digitalWrite(ledPin, LOW);
  delay(DELAY); // Wait for 1 second

  DELAY = DELAY - 50;
  if ( DELAY < 0 ) {
    DELAY = 1000;
  }
}