#ifndef MONITORAMENTO_H //cria a biblioteca 
#define MONITORAMENTO_H

#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define SENSOR_GPIO 25 //Pino do LDR

void monitoramento_init(void);   // chama a função que configura o sensor
const char* monitorar_carro(void); // chama a função que verifica o sensor

#endif
