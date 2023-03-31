#include <Adafruit_NeoPixel.h>
#include <Bounce2.h>


#define LED_PIN1    9
#define LED_COUNT1  30

#define LED_PIN2    10
#define LED_COUNT2  30

#define ANIM1_LED 11  // Don't forget to start at 0
#define ANIM1_SIZE 5

#define ANIM2_LED 18
#define ANIM2_SIZE 3


int flashSpeed1 = 100;
int flashSpeed2 = 100;
int brightness = 50;

Adafruit_NeoPixel strip1(LED_COUNT1, LED_PIN1, NEO_GRB + NEO_KHZ400);
Adafruit_NeoPixel strip2(LED_COUNT2, LED_PIN2, NEO_GRB + NEO_KHZ400);


unsigned long lastChange1, lastChange2;

int anim1, anim2 = 0;

uint32_t colour = strip1.Color(255,255,255);
uint32_t blank = strip1.Color(0,0,0);
uint32_t anim1_colour = strip1.Color(255,0,0);
uint32_t anim2_colour = strip1.Color(0,255,0);

void setup() {

  Serial.begin(115200);
  
  strip1.begin();
  strip2.begin();

  strip1.setBrightness(20);
  strip2.setBrightness(20);
  for(int i=0; i<strip1.numPixels(); i++)
  {
    strip1.setPixelColor(i, colour);
  }

  for(int i=0; i<strip2.numPixels(); i++)
  {
    strip2.setPixelColor(i, colour);
  }

  strip1.show();
  strip2.show();

}

void loop() {


  brightness = map(analogRead(A1), 0, 1024, 1, 200);
  flashSpeed1 = map(analogRead(A2), 0, 890, 0, 3000);
  flashSpeed2 = map(analogRead(A3), 0, 890, 0, 3000);

  strip1.setBrightness(brightness);
  strip2.setBrightness(brightness);


  if (millis() > lastChange1 + flashSpeed1) {

    for(int i=0; i<ANIM1_SIZE; i++)
    {
      Serial.println(anim1);
      if (i < anim1) {
        strip1.setPixelColor(ANIM1_LED - i, blank);
      } else {
        strip1.setPixelColor(ANIM1_LED - i, anim1_colour);
      }
    }
    anim1++;
    if (anim1 > ANIM1_SIZE) 
      anim1 = 0;
    
    lastChange1 = millis();
  }


  if (millis() > lastChange2 + flashSpeed2) {

    for(int i=0; i<ANIM2_SIZE; i++)
    {
      Serial.println(anim2);
      if (i < anim2) {
        strip1.setPixelColor(ANIM2_LED + i, blank);
        strip1.setPixelColor(ANIM2_LED +ANIM2_SIZE + i, blank);
      } else {
        strip1.setPixelColor(ANIM2_LED + i, anim2_colour);
        strip1.setPixelColor(ANIM2_LED + ANIM2_SIZE + i, anim2_colour);
      }
    }
    anim2++;
    if (anim2 > ANIM2_SIZE) 
      anim2 = 0;

     
    lastChange2 = millis();
  }
  
  strip1.show();
  strip2.show();
}
