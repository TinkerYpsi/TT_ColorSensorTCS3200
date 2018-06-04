#ifndef ColorSensorTCS3200_h
#define ColorSensorTCS3200_h

#include <Arduino.h>

#define NOT_IDENTIFIED  0
#define RED_COLOR       1
#define ORANGE_COLOR    2
#define GREEN_COLOR     3
#define YELLOW_COLOR    4
#define PURPLE_COLOR    5
#define BLUE_COLOR      6


class ColorSensorTCS3200
{
public:
  ColorSensorTCS3200();
  ColorSensorTCS3200(uint8_t S0_pin, uint8_t S1_pin, uint8_t S2_pin,
                     uint8_t S3_pin, uint8_t sensor_out_pin);
  int readColor(bool serial_print_rgb_vals = false);
  void printColor(int delay_time = 300);

private:
  uint8_t m_S0_pin;
  uint8_t m_S1_pin;
  uint8_t m_S2_pin;
  uint8_t m_S3_pin;
  uint8_t m_sensor_out_pin;
};

#endif
