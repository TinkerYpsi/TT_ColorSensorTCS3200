#include <ColorSensorTCS3200.h>

void setup()
{
  Serial.begin(9600);
  ColorSensorTCS3200 color_sensor;
}

void loop()
{
  color_sensor.printColor();
}
