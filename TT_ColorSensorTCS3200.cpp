#include <Arduino.h>
#include "TT_ColorSensorTCS3200.h"

TT_ColorSensorTCS3200::TT_ColorSensorTCS3200()
  : m_S0_pin(4), m_S1_pin(5), m_S2_pin(6), m_S3_pin(7), m_sensor_out_pin(8)
  {
    pinMode(m_S0_pin, OUTPUT);
    pinMode(m_S1_pin, OUTPUT);
    pinMode(m_S2_pin, OUTPUT);
    pinMode(m_S3_pin, OUTPUT);
    pinMode(m_sensor_out_pin, INPUT);

    // Setting frequency-scaling to 20%
    digitalWrite(m_S0_pin,HIGH);
    digitalWrite(m_S1_pin,LOW);
  }

TT_ColorSensorTCS3200::TT_ColorSensorTCS3200(uint8_t S0_pin, uint8_t S1_pin,
                                       uint8_t S2_pin, uint8_t S3_pin,
                                       uint8_t sensor_out_pin)
: m_S0_pin(S0_pin), m_S1_pin(S1_pin),
  m_S2_pin(S2_pin), m_S3_pin(S3_pin),
  m_sensor_out_pin(sensor_out_pin)
{
  pinMode(m_S0_pin, OUTPUT);
  pinMode(m_S1_pin, OUTPUT);
  pinMode(m_S2_pin, OUTPUT);
  pinMode(m_S3_pin, OUTPUT);
  pinMode(m_sensor_out_pin, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(m_S0_pin,HIGH);
  digitalWrite(m_S1_pin,LOW);
}

int TT_ColorSensorTCS3200::readColor(bool serial_print_rgb_vals)
{
  // Setting red filtered photodiodes to be read
  digitalWrite(m_S2_pin, LOW);
  digitalWrite(m_S3_pin, LOW);
  // Reading the output frequency
  int frequency = pulseIn(m_sensor_out_pin, LOW);
  int R = frequency;
  // Printing the value on the serial monitor
  if(serial_print_rgb_vals)
  {
    Serial.print("R= ");//printing name
    Serial.print(frequency);//printing RED color frequency
    Serial.print("  ");
  }
  delay(50);

  // Setting Green filtered photodiodes to be read
  digitalWrite(m_S2_pin, HIGH);
  digitalWrite(m_S3_pin, HIGH);
  // Reading the output frequency
  frequency = pulseIn(m_sensor_out_pin, LOW);
  int G = frequency;
  // Printing the value on the serial monitor
  if(serial_print_rgb_vals)
  {
    Serial.print("G= ");//printing name
    Serial.print(frequency);//printing GREEN color frequency
    Serial.print("  ");
  }
  delay(50);

  // Setting Blue filtered photodiodes to be read
  digitalWrite(m_S2_pin, LOW);
  digitalWrite(m_S3_pin, HIGH);
  // Reading the output frequency
  frequency = pulseIn(m_sensor_out_pin, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  if(serial_print_rgb_vals)
  {
    Serial.print("B= ");//printing name
    Serial.print(frequency);//printing BLUE color frequency
    Serial.println("  ");
  }
  delay(50);

  int color = NOT_IDENTIFIED;
  if(R < 32 & R > 15 & G < 130 & G > 80 & B > 15 & B < 30)
  {
    color = RED_COLOR; // Red
  }
  if(R < 40 & R > 15 & G < 80 & G > 50 & B > 8 & B < 18)
  {
    color = ORANGE_COLOR; // Orange
  }
  if(R < 130 & R > 90 & G > 45 & G < 95 & B > 15 & B < 40)
  {
    color = GREEN_COLOR; // Green
  }
  if(R < 38 & R > 20 & G < 44 & G > 25){
    color = YELLOW_COLOR; // Yellow
  }
  if(R < 100 & R > 70 & G < 125 & G > 95 & B > 20 & B < 50)
  {
    color = PURPLE_COLOR; // Brown
  }
  if (R < 100 & R > 75 & B < 22 & B > 10 & B < 22)
  {
    color = BLUE_COLOR; // Blue
  }
  return color;
}

void TT_ColorSensorTCS3200::printColor(int delay_time)
{
  int color = readColor();
  delay(10);

  switch (color) {
    case RED_COLOR:
      Serial.println("RED");
      break;
    case ORANGE_COLOR:
      Serial.println("ORANGE");
      break;
    case GREEN_COLOR:
      Serial.println("GREEN");
      break;
    case YELLOW_COLOR:
      Serial.println("YELLOW");
      break;
    case PURPLE_COLOR:
      Serial.println("PURPLE");
      break;
    case BLUE_COLOR:
      Serial.println("BLUE");
      break;
    case NOT_IDENTIFIED:
      Serial.println("NOT IDENTIFIED");
      break;
  }
  delay(delay_time);
}
