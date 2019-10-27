#include <led_strip.h>

const int RED_PIN = 10;
const int GREEN_PIN = 11;
const int BLUE_PIN = 9;
int pin_numbers[] = {RED_PIN, GREEN_PIN, BLUE_PIN};
int nothing[] = {0,0,0};
const int SPEED = 50; //ms
LED_MODE mode = NONE;
void setup() { // RobotInit
  Wire.begin(4);
  Wire.onReceive(onData);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  setColor(pin_numbers, nothing);
  // put your setup code here, to run once:

} 
void onData(int length) {
  mode = (LED_MODE) Wire.read()
}
void rainbow(int fade_speed) {
  // fade from red to yellow (255, 0, 0) -> (255, 255, 0)
  int r, g, b;
  for (g = 0; g <= 255; g++) { 
    analogWrite(GREEN_PIN, g);
    delay(fade_speed);
  } 
  // yellow to green (255, 255, 0) -> (0, 255, 0)
  for (r = 255; r >= 0;r--) {
    analogWrite(RED_PIN, r)
    delay(fade_speed)
  }
  // green to teal (0, 255, 0) -> (0, 255, 255)
  for (b = 0; b <= 255; b++) { 
    analogWrite(BLUE_PIN, b);
    delay(fade_speed);
  }
  // teal to blue (0, 255, 255) -> (0, 0, 255)
  for (g = 255; g >= 0; g--) { 
    analogWrite(GREEN_PIN, g);
    delay(fade_speed);
  } 
  // blue to purple (0, 0, 255) -> (255, 0, 255)
  for (r = 0; r <= 255; r++) { 
    analogWrite(RED_PIN, r);
    delay(fade_speed);
  }
  // purple to red (255, 0, 255) -> (255, 0, 0)
  for (b = 255; b >= 0; b--) { 
    analogWrite(BLUE_PIN, b);
    delay(fade_speed);
  } 
}

void ratpack() {
  int ratpack_blue[] = {12, 38, 145};
  int ratpack_yellow[] = {229, 255, 0};
  setColor(pin_numbers, ratpack_blue);
  delay(500);
  setColor(pin_numbers, ratpack_yellow);
  delay(500);
}
void red() {
  int red[] = {255, 0, 0};
  setColor(pin_numbers, red);
  delay(500);
}
void loop() { // TeleopPeriodic
  switch mode {
    case FAST_RAINBOW:
      rainbow(1)
      break;
    case SLOW_RAINBOW:
      rainbow(5);
      break;
    case RATPACK:
      ratpack();
      break;
    case NONE:
    default:
      red();
  }
}

// take in a list of pin numbers, and a list of rgb values and set the strip to the desired color
void setColor([]int pins, []int colors) {
  for (int i = 0; i < 3; i++) {
    // analogWrite(pin, val)
    analogWrite(pins[i], colors[i]);
  }
}

