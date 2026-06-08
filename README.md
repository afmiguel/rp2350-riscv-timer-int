# RP2350 RISC-V Timer Interrupt

Este projeto demonstra o uso de interrupções de hardware (Timer Alarm) no microcontrolador **RP2350** (Raspberry Pi Pico 2) utilizando a arquitetura **RISC-V**.

## Funcionalidades

- **Piscar LED via IRQ**: O LED é alternado dentro de um tratador de interrupção (ISR) a cada 500ms.
- **Arquitetura RISC-V**: Configurado explicitamente para rodar no core Hazard3 (RISC-V) do RP2350.
- **Stdio via USB**: Saída serial configurada para USB para monitoramento via terminal.
- **Loop Principal Livre**: O `while(1)` principal permanece livre para outras tarefas enquanto o timer roda em segundo plano.

## Requisitos

- [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk) v2.2.0 ou superior.
- Toolchain RISC-V (`riscv64-unknown-elf-gcc`).
- VS Code com a extensão [Raspberry Pi Pico](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico).

## Como Compilar

1. Certifique-se de que o SDK está configurado.
2. No VS Code, selecione o kit de compilação RISC-V.
3. Clique em **Build**.

## Estrutura do Código

- `rp2350-riscv-timer-int.c`: Código principal com a lógica da ISR e inicialização do hardware.
- `CMakeLists.txt`: Configurações de compilação, incluindo a ativação do USB e definição da plataforma RISC-V.
