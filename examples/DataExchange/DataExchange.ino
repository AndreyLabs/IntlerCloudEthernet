#include <IntlerCloudEthernet.h>

void printValue(double val) {
  Serial.println("Print value " + String(val));
}

int luminosity, temperature;

Cloud cloud("usr", "pass", "myArduino");

void setup() {
  Serial.begin(9600);
  
  cloud.connect();
  cloud.setInterval(8000);
  
  cloud.addCommand("temperature", printValue);
}

void loop()
{
  cloud.run();
  
  luminosity = 1;
  temperature = 2;
  
  cloud.sendValue("temperature", temperature);
  cloud.sendValue("light", luminosity);
}
