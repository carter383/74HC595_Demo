/*******************************************************
 * FOR THIS DEMO, WE HAVE REMOVED THE JUMPER BETWEEN CLOCK AND LATCH
 *******************************************************/

// Shift register control pins
const uint8_t DATA_PIN   = 2;
const uint8_t CLOCK_PIN  = 5;
const uint8_t LATCH_PIN  = 4;
const uint8_t OUTPUT_ENABLE_PIN = 3;

// Configuration variables
const uint8_t NUM_LEDS = 16;        // Total number of LEDs 
const uint8_t LEDS_ILLUMINATED = 3; // Number of adjacent LEDs to illuminate

int ledPos = 0;       // Starting position
int direction = 1;    // 1 = right, -1 = left

void setup() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(OUTPUT_ENABLE_PIN, OUTPUT);

  digitalWrite(OUTPUT_ENABLE_PIN, LOW); // Enable output (active LOW)
}

void loop() {
  uint16_t pattern = 0;

  // Generate pattern with LEDS_ILLUMINATED bits set starting at ledPos
  for (int i = 0; i < LEDS_ILLUMINATED; i++) {
    int pos = ledPos + i;
    if (pos < NUM_LEDS) {
      pattern |= (1 << pos);
    }
  }

  // Extract bytes to send to the shift registers
  byte highByte = (pattern >> 8) & 0xFF;
  byte lowByte = pattern & 0xFF;

  // Send to shift registers
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, highByte);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, lowByte);
  digitalWrite(LATCH_PIN, HIGH);

  // Update LED position
  ledPos += direction;

  // Reverse direction if we reach the ends
  if (ledPos <= 0 || ledPos >= (NUM_LEDS - LEDS_ILLUMINATED)) {
    direction = -direction;
  }

  delay(100); // Delay between frames
}
