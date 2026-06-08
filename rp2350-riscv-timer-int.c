/**
 * Timer com Interrupção — RP2350 / Raspberry Pi Pico 2
 * LED pisca a cada 1 segundo via Alarm IRQ.
 * O loop principal fica livre.
 */
#include "stdio.h"
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/irq.h"

#define LED_PIN      15
#define ALARM_NUM    0
#define INTERVALO_US 500000   // 1 segundo

// Variáveis compartilhadas entre ISR e main (SEMPRE volatile!)
static volatile bool estado_led = false;

void alarm_irq_handler(void) {
    // [TODO] Implementar a lógica da ISR aqui:
    // 1. Limpar a flag de interrupção no hardware para não travar a CPU
    // 2. Inverter a variável lógica do estado e atualizar o pino do LED
    // 3. Reagendar o próximo disparo do alarme (tempo atual + INTERVALO_US)
}

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);                                             // Ativa o controle do pino selecionado
    gpio_set_dir(LED_PIN, GPIO_OUT);                                // Define a direção elétrica do pino como saída

    // Configura e arma o alarme
    // [TODO] Adicionar as instruções para:
    // 1. Autorizar o módulo TIMER a gerar sinal de interrupção
    // 2. Obter o número da IRQ associado ao ALARM_NUM
    // 3. Registrar a função de handler (alarm_irq_handler)
    // 4. Habilitar a interrupção no processador
    // 5. Definir o disparo inicial do alarme

    while (1) {
        printf("Loop principal livre para outras tarefas...\n");
        sleep_ms(2000);                                             // Simula outras tarefas com um delay de 2 segundos
    }
    return 0;                                                       // Encerra a main (em sistemas embarcados, idealmente nunca chega aqui)
}