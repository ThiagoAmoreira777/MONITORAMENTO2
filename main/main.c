#include "monitoramento.h"
 
void app_main(void) {
    monitoramento_init();  
 
    while (1) {
        const char* msg = monitorar_carro();
 
        if (msg != NULL) {
            printf("%s\n", msg);  
        }
 
        vTaskDelay(10 / portTICK_PERIOD_MS);  
    }
}