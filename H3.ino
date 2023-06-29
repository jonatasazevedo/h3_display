#include <Arduino.h>
#include <TM1637Display.h>
#include "DisplayUs.h"
#include "DisplayBuilder.h"
#define CLK 17
#define DIO 16

#define DELAY 1000
#define brightness 0x0f
int state; //saída
uint8_t dado; //saída
int mode,enable,andar,updownstop,reset; //entrada

int startTime,currentTime;

ElevadorUs* eleUs = NULL;
DisplayBuilder* disBuilder = NULL;

void setup() {
  startTime = millis();
  Serial.begin(9600);
  eleUs = new ElevadorUs;
  disBuilder = new DisplayBuilder;
  disBuilder->setEnable(1);
  disBuilder->buildDisplay(CLK,DIO);
  disBuilder->setupDisplay(brightness);
  eleUs->setAndar(2);
  eleUs->setUpDownStop(1);
}

void loop() {
  state = eleUs->getState();
  andar = eleUs->getAndar();
  updownstop = eleUs->getUpdownstop();
  switch(state){
    case 0:
      currentTime = millis();
      disBuilder->setAllDigits(0xff);
      disBuilder->printDataDisplay(1);
      eleUs->doMicroservice();
      if(currentTime-startTime>=DELAY) eleUs->setMode(1);
      break;
    case 1:
      disBuilder->setData(updownstop,andar);
      disBuilder->printDataDisplay();
      eleUs->doMicroservice();
      break;
    default:
      disBuilder->setAllDigits(0x00);
      disBuilder->printDataDisplay();
      eleUs->doMicroservice();
      break;
  }
}
