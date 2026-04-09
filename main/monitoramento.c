#include "monitoramento.h"
#include <stdio.h>       
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static int carros = 0;           //contador dos carros começa em 0
static char mensagem[64];        //caixa que vai guardar a mensagem do total de carros

void monitoramento_init(void) {
    gpio_set_direction(SENSOR_GPIO, GPIO_MODE_INPUT);  // Pino LDR como entrada
    gpio_set_pull_mode(SENSOR_GPIO, GPIO_PULLDOWN_ONLY); // garante que o pino mantem 0 quando não tem carro
}

const char* monitorar_carro(void) {
    if (gpio_get_level(SENSOR_GPIO) == 1) {     // "se o sensor tiver com baixa resistencia = carro detectado"
        carros++;                               // incrementa o contador de carros em 1
        snprintf(mensagem, sizeof(mensagem),    // coloca o numero de carros no texto
                 "Carro detectado! Total: %d carro(s)", carros);

        while (gpio_get_level(SENSOR_GPIO) == 1) {  // espera o LDR ficar com sinal 0, para não contar o mesmo carro várias vezes
            vTaskDelay(pdMS_TO_TICKS(10));          
        }

        return mensagem;   // retorna a mensagem com o total de carros
    }

    return NULL;   // retorna nada se não teve carro detectado
}
