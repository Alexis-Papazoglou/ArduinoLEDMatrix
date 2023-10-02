/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           ""
#define BLYNK_TEMPLATE_NAME         ""
#define BLYNK_AUTH_TOKEN            ""

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";

int value0 , value1 , value2;

int slide = 100;
const int LED_PINS[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
const int NUM_LEDS = sizeof(LED_PINS) / sizeof(int);

BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  value0 = param.asInt();

  // Update state
  Blynk.virtualWrite(V0, value0);
}

BLYNK_WRITE(V1)
{
  // Set incoming value from pin V1 to a variable
  value1 = param.asInt();

  // Update state
  Blynk.virtualWrite(V1, value1);
}

BLYNK_WRITE(V2)
{
  // Set incoming value from pin V2 to a variable
  value2 = param.asInt();

  // Update state
  Blynk.virtualWrite(V2, value2);
}

BLYNK_WRITE(V3)
{
  // Set incoming value from pin V2 to a variable
  slide = param.asInt();

      // Update state
  Blynk.virtualWrite(V3, slide);
}


// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}


// routines ----------------------------------------------------------------------------------------- //

void function1(){
  for (int i = 0; i < (NUM_LEDS-1); i++) {
    digitalWrite(LED_PINS[i], HIGH);
    delay(250);
    digitalWrite(LED_PINS[i+1], HIGH);
    delay(250);
    digitalWrite(LED_PINS[i], LOW);
    delay(250);
  }
  digitalWrite(15, LOW);

}
void function2(){
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], HIGH);
    delay(100);
    digitalWrite(LED_PINS[i], LOW);
  }
  for (int i = 15; i > 0; i--) {
    digitalWrite(LED_PINS[i], HIGH);
    delay(100);
    digitalWrite(LED_PINS[i], LOW);
  }
}
void function3(){
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], HIGH);
    delay(slide);
    digitalWrite(LED_PINS[i], LOW);
  }
}


void setup()
{
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

}

void loop()
{
  Blynk.run();
  timer.run();


  //kalw tis sunartiseis gia value 0 , 1 , 2 kai kanei update to state sumfwna me to switch


  if(value0 == 1){
    function1();
  }
  if(value1 == 1){
    function2();
  }
  if(value2 == 1){
    function3();
  }



  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}

