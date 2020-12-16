#include <Arduino.h>

#define PIN_IN_BRAKE 34

int32_t analogValue = 0;
uint16_t analogValueRaw = 0;
uint16_t analogValueMinCalibRaw = 0;

void setup()
{
  Serial.begin(115200);

  pinMode(PIN_IN_BRAKE, INPUT);
  analogValueMinCalibRaw = analogRead(PIN_IN_BRAKE);

  Serial.println("set cntrl_mode 3");
}

void loop()
{

  char print_buffer[500];

  analogValueRaw = analogRead(PIN_IN_BRAKE);

  analogValue = analogValueRaw - analogValueMinCalibRaw - 20;

  //analogValue = analogValue / 1.8;

  if (analogValue > 1000)
    analogValue = 1000;
  if (analogValue < 0)
    analogValue = 0;

  Serial.println("analogValueRaw = " + (String)analogValueRaw + " / analogValueMinCalibRaw = " + analogValueMinCalibRaw);

  sprintf(print_buffer, "set speed %d",
          analogValue);
  Serial.println(print_buffer);

  delay(10);
}