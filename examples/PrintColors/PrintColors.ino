#include <TT_ColorSensorTCS3200.h>

TT_ColorSensorTCS3200 color_sensor;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  color_sensor.printColor();
}
