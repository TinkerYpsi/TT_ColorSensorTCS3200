#include <ColorSensorTCS3200.h>

ColorSensorTCS3200 color_sensor;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  color_sensor.printColor();
}
