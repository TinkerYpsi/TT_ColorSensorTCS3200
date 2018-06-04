#include <Arduino.h>
#include "ColorSensorTCS3200.h"

ColorSensorTCS3200::ColorSensorTCS3200()
  : m_S0_pin(4), m_S1_pin(5), m_S2_pin(6), m_S3_pin(7), m_sensor_out_pin(8)
  {
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(sensorOut, INPUT);

    // Setting frequency-scaling to 20%
    digitalWrite(S0,HIGH);
    digitalWrite(S1,LOW);
  }

ColorSensorTCS3200::ColorSensorTCS3200(uint8_t S0_pin, uint8_t S1_pin,
                                       uint8_t S2_pin, uint8_t S3_pin,
                                       uint8_t sensor_out_pin)
: m_S0_pin(S0_pin), m_S1_pin(S1_pin),
  m_S2_pin(S2_pin), m_S3_pin(S3_pin),
  m_sensor_out_pin(sensor_out_pin)
{
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
}
