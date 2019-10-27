const int RED_PIN = 10;
const int GREEN_PIN = 11;
const int BLUE_PIN = 9;
int pin_numbers[] = {RED_PIN, GREEN_PIN, BLUE_PIN};
int red[] = {255,0,0};
const int SPEED = 50; //ms
void setup() { // RobotInit

  // pinMode(pin, output|input)
   setColor(pin_numbers, red)
  // put your setup code here, to run once:

} 

void loop() { // TeleopPeriodic
  // put your main code here, to run repeatedly:
  // 0-255
  int r, g, b;
  // fade from red to yellow (255, 0, 0) -> (255, 255, 0)
  for (g = 0; g <= 255; g++) { 
    analogWrite(GREEN_PIN, g);
    delay(SPEED);
  } 
  // yellow to green (255, 255, 0) -> (0, 255, 0)
  for (r = 255; r >= 0;r--) {
    analogWrite(RED_PIN, r)
    delay(SPEED)
  }
  // green to teal (0, 255, 0) -> (0, 255, 255)
  for (b = 0; b <= 255; b++) { 
    analogWrite(BLUE_PIN, b);
    delay(SPEED);
  }
  // teal to blue (0, 255, 255) -> (0, 0, 255)
  for (g = 255; g >= 0; g--) { 
    analogWrite(GREEN_PIN, g);
    delay(SPEED);
  } 
  // blue to purple (0, 0, 255) -> (255, 0, 255)
  for (r = 0; r <= 255; r++) { 
    analogWrite(RED_PIN, r);
    delay(SPEED);
  }
  // purple to red (255, 0, 255) -> (255, 0, 0)
  for (b = 255; b >= 0; b--) { 
    analogWrite(BLUE_PIN, b);
    delay(SPEED);
  } 
  
}

//int add(int num1, int num2) {
//  return num1 + num2;
//}
// [100, 200, 50]
// take in a list of pin numbers, and a list of rgb values and set the strip to the desired color
void setColor([]int pins, []int colors) {
  for (int i = 0; i < 3; i++) {
    // analogWrite(pin, val)
    analogWrite(pins[i], colors[i]);
  }
}

