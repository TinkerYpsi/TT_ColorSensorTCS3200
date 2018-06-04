#include <ColorSensorTCS3200.h>

ColorSensorTCS3200 color_sensor;
int delay_time = 300;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int color = color_sensor.readColor();

  if(color == RED_COLOR)
  {
    Serial.println("RED");
  }
  else if(color == ORANGE_COLOR)
  {
    Serial.println("ORANGE");
  }
  else if(color == GREEN_COLOR)
  {
    Serial.println("GREEN");
  }
  else if(color == YELLOW_COLOR)
  {
    Serial.println("YELLOW");
  }
  else if(color == PURPLE_COLOR)
  {
    Serial.println("PURPLE");
  }
  else if(color == BLUE_COLOR)
  {
    Serial.println("BLUE");
  }
  else if(color == NOT_IDENTIFIED)
  {
    Serial.println("NOT IDENTIFIED");
  }

  delay(delay_time);
}
