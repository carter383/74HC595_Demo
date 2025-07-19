// Define control pins for the shift register
const uint8_t DATA_PIN   = 2;   // Data pin (DS)
const uint8_t CLOCK_PIN  = 5;   // Clock pin (SHCP)
const uint8_t LATCH_PIN  = 4;   // Latch pin (STCP)
const uint8_t OUTPUT_ENABLE_PIN = 3; // Output Enable (OE), active LOW

// Control flag to toggle between patterns
bool FLAG = true; 

void setup() {
  // Configure pins as outputs
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(OUTPUT_ENABLE_PIN, OUTPUT);

  // Enable outputs (OE is active LOW)
  digitalWrite(OUTPUT_ENABLE_PIN, LOW);
}

void loop() {
  // Prepare to send data
  digitalWrite(LATCH_PIN, LOW);

  // Choose data pattern based on FLAG and toggle FLAG
  byte data;
  if (FLAG) {
    data = 0b10101010;
    FLAG = false; // Flip flag for next time
  } else {
    data = 0b01010101;
    FLAG = true;
  }

  // Shift the data out to two chained shift registers
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data); 
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data); 

  // Latch the data to the output pins
  digitalWrite(LATCH_PIN, HIGH);

  // Wait for a second
  delay(1000);
}
