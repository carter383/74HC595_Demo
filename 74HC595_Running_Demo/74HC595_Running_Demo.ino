/*******************************************************
 * FOR THIS DEMO, WE HAVE PLACED A JUMPER BETWEEN CLOCK AND LATCH
 *******************************************************/

// Define control pins for the shift register
const uint8_t DATA_PIN   = 2;   // Data pin (DS) – used to send bits into the shift register
const uint8_t CLOCK_PIN  = 5;   // Clock pin (SHCP) – toggled to shift bits into the register
const uint8_t LATCH_PIN  = 4;   // Latch pin (STCP) – not used directly here due to jumper
const uint8_t OUTPUT_ENABLE_PIN = 3; // Output Enable (OE) – active LOW, enables/disables output

// Number of LEDs (or bits) the shift register is controlling
const uint8_t NUM_LEDS    = 16;

// Time delay between each LED activation (used for visual effect)
const uint16_t STEP_DELAY = 150;

// Function to pulse the CLOCK pin: HIGH then LOW
void pulseClock() {
  digitalWrite(CLOCK_PIN, HIGH);     // Rising edge shifts in the bit on DATA
  delayMicroseconds(5);              // Short delay to ensure the clock is registered
  digitalWrite(CLOCK_PIN, LOW);      // Falling edge prepares for the next bit
  delayMicroseconds(5);              // Short delay before next operation
}

void setup() {
  // Set all control pins as outputs
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(OUTPUT_ENABLE_PIN, OUTPUT);

  // Enable outputs on the 74HCT595 (LOW = enabled)
  digitalWrite(OUTPUT_ENABLE_PIN, LOW);
}

void loop() {
  // Light the first LED by setting the first bit HIGH
  digitalWrite(DATA_PIN, HIGH);  // Send a HIGH bit
  pulseClock();                  // Push the HIGH bit into the shift register
  delay(STEP_DELAY);            // Wait for visual effect

  // Turn DATA LOW for remaining bits (so they are OFF)
  digitalWrite(DATA_PIN, LOW);

  // Shift in remaining LOW bits (all other LEDs OFF)
  for (uint8_t i = 1; i < NUM_LEDS; i++) {
    pulseClock();               // Push LOW into shift register
    delay(STEP_DELAY);         // Delay to maintain the "moving light" effect
  }
}
