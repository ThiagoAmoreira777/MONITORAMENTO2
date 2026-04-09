#include "monitoramento.h"       
#include <stdio.h>               
#include "driver/gpio.h"        
#include "freertos/FreeRTOS.h"   
#include "freertos/task.h"       

#define LED_GPIO 2               // define o pino do LED da placa do ESP32

void app_main(void) {
    monitoramento_init();        // inicializa o sensor antes de começar o loop

    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);  // configura o pino do LED para enviar sinal (saída)

    while (1) {                                      
        const char* msg = monitorar_carro();// chama a função e guarda o resultado (mensagem ou valor NULL)

        if (msg != NULL) {                           // se o carro for detectado, manda a mensagem
            printf("%s\n", msg);

            gpio_set_level(LED_GPIO, 1);
            vTaskDelay(pdMS_TO_TICKS(300));
            gpio_set_level(LED_GPIO, 0);
        }

        vTaskDelay(pdMS_TO_TICKS(10));// tempo para não sobrecargar o processador
    }
}
