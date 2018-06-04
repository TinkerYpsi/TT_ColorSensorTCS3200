#include <ColorSensorTCS3200.h>

int delay_time = 300;

void setup()
{
  Serial.begin(9600);
  ColorSensorTCS3200 color_sensor;
}

void loop()
{
  int color = color_sensor.readColor();

  if(color == RED_COLOR)
  {
    Serial.println("RED");
    break;
  }
  else if(color == ORANGE_COLOR)
  {
    Serial.println("ORANGE");
    break;
  }
  else if(color == GREEN_COLOR)
  {
    Serial.println("GREEN");
    break;
  }
  else if(color == YELLOW_COLOR)
  {
    Serial.println("YELLOW");
    break;
  }
  else if(color == PURPLE_COLOR)
  {
    Serial.println("PURPLE");
    break;
  }
  else if(color == BLUE_COLOR)
  {
    Serial.println("BLUE");
    break;
  }
  else if(color == NOT_IDENTIFIED)
  {
    Serial.println("NOT IDENTIFIED");
    break;
  }

  delay(delay_time);
}
