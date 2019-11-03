#include "include/led_strip.h"
#include <Wire.h>

// Initialize pins and modes
const int RED_PIN = 10;
const int GREEN_PIN = 11;
const int BLUE_PIN = 9;
int pin_numbers[] = {RED_PIN, GREEN_PIN, BLUE_PIN};
int nothing[] = {0,0,0};
LED_MODE mode = NONE;
void setup() { // RobotInit
  
  Serial.begin(9600);
  Wire.begin(4);
  Wire.onReceive(onData);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  setColor(pin_numbers, nothing);

} 
void onData(int length) {
  mode = (LED_MODE) Wire.read();
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
    analogWrite(RED_PIN, r);
    delay(fade_speed);
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
void Alliance (bool color)
{
    //true = red
    //false = blue
    if (color == true)//the color is red not blue
    {
      //wipe to red
      analogWrite(RED_PIN, 255);
      analogWrite(BLUE_PIN, 1);
      analogWrite(GREEN_PIN, 0);
      delay(1000);
      
      //fade to yellow
      for (int g = 0; g == 255; g++) { 
        analogWrite(GREEN_PIN, (int)(g*(217/255));
        delay(2));//ms
      }

      delay(1000);

      //fade to red
      for (g = 255; g == 0; g--)
      {
        analogWrite(GREEN_PIN, (int)(g*(217/255));
        delay(2);//ms
      }
    }
    else if (color == false)//THE COLOR IS BLUE, NOT RED  
    {
      //wipe to blue
      analogWrite(RED_PIN, 0);
      analogWrite(BLUE_PIN, 255);
      analogWrite(GREEN_PIN, 0);
      delay(1000);
      
      //fade to yellow
      for (int g = 0; g == 255; g++) { 
        analogWrite(GREEN_PIN, (int)(g*(217/255));
        analogWrite(RED_PIN, (int)(g*(217/255));
        analogWrite(BLUE_PIN, 255-G);
        delay(2));//ms
      }

      delay(1000);

      //fade to red
      for (g = 255; g == 0; g--)
      {
        analogWrite(GREEN_PIN, (int)(g*(217/255));
        analogWrite(RED_PIN, (int)(g*(217/255));
        analogWrite(BLUE_PIN, 255-G);
        delay(2));//ms
      }
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
void setRed() {
  int red[] = {255, 0, 0};
  setColor(pin_numbers, red);
  delay(500);
}

void loop() { // TeleopPeriodic
  switch (mode) {
    case FAST_RAINBOW:
      rainbow(1);
      break;
    case SLOW_RAINBOW:
      rainbow(5);
      break;
    case RATPACK:
      ratpack();
      break;
    case RED_ALLIANCE
      Alliance(true);
    case BLUE_ALLIANCE
      Alliance(false);
    case NONE:
    default:
      setRed();
  }
}

// take in a list of pin numbers, and a list of rgb values and set the strip to the desired color
void setColor(int pins[], int colors[]) {
  for (int i = 0; i < 3; i++) {
    // analogWrite(pin, val)
    analogWrite(pins[i], colors[i]);
  }
}