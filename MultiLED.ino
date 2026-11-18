// Pin definitions (using uint8_t and const for efficiency and safety)
const uint8_t RED_PIN = 3;
const uint8_t GREEN_PIN = 5;
const uint8_t BLUE_PIN = 6;
 
// Comment this line out if using a Common Cathode LED
#define COMMON_ANODE

// Structure to hold color and timing data cleanly
struct RGBState {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  unsigned int duration;
};

// Sequence table for the loop
const RGBState colorSequence[] = {
  {255,   0,   0, 1000}, // Red
  {  0, 255,   0, 1000}, // Green
  {  0,   0, 255, 1000}, // Blue
  {255, 255,   0, 1000}, // Yellow
  { 80,   0,  80, 1000}, // Purple
  {  0, 255, 255, 1000}  // Aqua
};
 
void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);  
}
 
void loop() {
  // Loop through the color sequence cleanly using a range-based for loop
  for (const auto& item : colorSequence) {
    setColor(item.red, item.green, item.blue);
    delay(item.duration);
  }
}
 
void setColor(int red, int green, int blue) {
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);  
}