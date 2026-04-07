#ifndef MONITORAMENTO_H
#define MONITORAMENTO_H
 
#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
 
#define SENSOR_GPIO 36
 

void monitoramento_init(void);
 
const char* monitorar_carro(void);
 
#endif 
 