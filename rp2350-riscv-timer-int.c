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
    hw_clear_bits(&timer_hw->intr, 1u << ALARM_NUM);                // Limpa a flag no hardware para não travar a CPU
    estado_led = !estado_led;                                       // Inverte a variável lógica do estado
    gpio_put(LED_PIN, estado_led);                                  // Atualiza o pino físico com o novo estado
    timer_hw->alarm[ALARM_NUM] = timer_hw->timerawl + INTERVALO_US; // Reagenda o próximo disparo somando 1s ao tempo atual
}

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);                                             // Ativa o controle do pino selecionado
    gpio_set_dir(LED_PIN, GPIO_OUT);                                // Define a direção elétrica do pino como saída

    // Configura e arma o alarme
    hw_set_bits(&timer_hw->inte, 1u << ALARM_NUM);                  // Autoriza o módulo TIMER a gerar sinal elétrico de IRQ
    uint alarm_irq = timer_hardware_alarm_get_irq_num(timer_hw, ALARM_NUM);
    irq_set_exclusive_handler(alarm_irq, alarm_irq_handler);        // Registra a nossa função na tabela do processador (NVIC)
    irq_set_enabled(alarm_irq, true);                               // "Abre os ouvidos" do processador para esta linha de IRQ
    timer_hw->alarm[ALARM_NUM] = timer_hw->timerawl + INTERVALO_US; // Disparo inicial: lê o tempo exato agora e soma 1s

    while (1) {
        printf("Loop principal livre para outras tarefas...\n");
        sleep_ms(2000);                                             // Simula outras tarefas com um delay de 2 segundos
    }
    return 0;                                                       // Encerra a main (em sistemas embarcados, idealmente nunca chega aqui)
}