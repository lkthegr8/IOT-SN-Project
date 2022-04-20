/*
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/e878c0fb-f3ab-4292-8e67-65c7c00b0152

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  bool hall_light;
  bool kitchen_light;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);

  // 22 --> hall
  pinMode (22, OUTPUT);

  // 23 --> kitchen
  pinMode (23, OUTPUT);


  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here
}

/*
  Since HallLight is READ_WRITE variable, onHallLightChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onHallLightChange()  {
  // Add your code here to act upon HallLight change
  if (hall_light == 1) {
    digitalWrite (22, LOW);
  } else {
    digitalWrite (22, HIGH);
  }
}

/*
  Since KitchenLight is READ_WRITE variable, onKitchenLightChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onKitchenLightChange()  {
  // Add your code here to act upon KitchenLight change
  if (kitchen_light == 1) {
    digitalWrite (23, HIGH);
  } else {
    digitalWrite (23, LOW);
  }
}




