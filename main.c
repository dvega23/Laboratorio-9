#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "uart.h"
#include "sensortemp.h"
//#include <avr/io.h>
//#include <util/delay.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd1(0x27, 16, 2);
int modo = 0;
int verde = 8;
int azul = 9;
int rojo = 10;
int amarillo = 11;
int cian = 12;

/*void INT()
{
  modo = ~modo;
}*/
void setup()
{
  lcd1.init();
  lcd1.backlight();
  lcd1.setCursor(1, 0);
  lcd1.print("hola mundo");
  _delay_ms(1500);
  // start serial port
  // Serial.begin(9600);
  serial_begin();
  // Start up the library
  sensors.begin();
}

void loop()
{

  if (modo == 0)
  {
    DDRB |= 1 << cian;
    serial_print_str("Requesting temperatures...");
    sensors.requestTemperatures();
    DDRB |= 1 << cian;
    if (sensors.getTempCByIndex(0) < 28)
    {
      DDRB |= 1 << rojo;
    }
    if (sensors.getTempCByIndex(0) > 34)
    {
      DDRB |= 1 << azul;
    }
     if (sensors.getTempCByIndex(0) < 34 | sensors.getTempCByIndex(0) > 28)
    {
      DDRB |= 1 << verde;
    }

  }
  else
  {
    DDRB |= 1 << amarillo;
    char ch;
    printf("Introduzca una accion: ");
    ch = getchar();
    switch (ch)
    {
    case 'cal':
      puts(DDRB |= 1 << rojo;);
      break;
    case 'enf':
      puts(DDRB |= 1 << azul;);
      break;
    case 'reg':
      puts( DDRB |= 1 << verde;);
      break;
    default:
      puts("Error");
    }
  }

  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  // Send the command to get temperatures
  serial_println_str("DONE");

  serial_println_str(sensors.getTempCByIndex(0));
  lcd1.setCursor(0, 0);
  lcd1.print("Distancia en cm:");
  lcd1.setCursor(5, 1);
  _delay_ms(1500);
  lcd1.clear();
}
