/**
 * @file    hal_timer.h
 * @author  Rafael Lopes
 * @date    12 de Fevereiro de 2015
 * @version 0.1.0.0 
 * @brief   Driver Timer para o microcontrolador PIC18f4550.
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 */

#ifndef HAL_TIMER_H
#define	HAL_TIMER_H

/**
 *  Includes
 */
#include "types/types.h"
#include "device/hal_device.h"
#include "vars/vars.h"
#include "interrupt/hal_interrupts.h"

/**
 *  Defines
 */
#define TMR_ON                  1
#define TMR_OFF                 0

#define TMR_BIT_8               1
#define TMR_BIT_16              0

#define TMR_CLOCK_EXT           1
#define TMR_CLOCK_INT           0

#define TMR_HIGH_TO_LOW         1
#define TMR_LOW_TO_HIGH         0

#define TMR_PRESCALE_OFF        1
#define TMR_PRESCALE_ON         0

#define TMR0_PRESCALE_1_2       0x00
#define TMR0_PRESCALE_1_4       0x01
#define TMR0_PRESCALE_1_8       0x02
#define TMR0_PRESCALE_1_16      0x03
#define TMR0_PRESCALE_1_32      0x04
#define TMR0_PRESCALE_1_64      0x05
#define TMR0_PRESCALE_1_128     0x06
#define TMR0_PRESCALE_1_256     0x07

#define TMR1_PRESCALE_1_1       0x00
#define TMR1_PRESCALE_1_2       0x01
#define TMR1_PRESCALE_1_4       0x02
#define TMR1_PRESCALE_1_8       0x03

#define TMR2_PRESCALE_1_1       0x00
#define TMR2_PRESCALE_1_4       0x01
#define TMR2_PRESCALE_1_16      0x02

#define TMR2_POSTSCALE_1_1      0x00
#define TMR2_POSTSCALE_1_2      0x01
#define TMR2_POSTSCALE_1_3      0x02
#define TMR2_POSTSCALE_1_4      0x03
#define TMR2_POSTSCALE_1_5      0x04
#define TMR2_POSTSCALE_1_6      0x05
#define TMR2_POSTSCALE_1_7      0x06
#define TMR2_POSTSCALE_1_8      0x07
#define TMR2_POSTSCALE_1_9      0x08
#define TMR2_POSTSCALE_1_10     0x09
#define TMR2_POSTSCALE_1_11     0x0A
#define TMR2_POSTSCALE_1_12     0x0B
#define TMR2_POSTSCALE_1_13     0x0C
#define TMR2_POSTSCALE_1_14     0x0D
#define TMR2_POSTSCALE_1_15     0x0E
#define TMR2_POSTSCALE_1_16     0x0F

#define TMR3_PRESCALE_1_1       0x00
#define TMR3_PRESCALE_1_2       0x01
#define TMR3_PRESCALE_1_4       0x02
#define TMR3_PRESCALE_1_8       0x03

/**
 * @brief
 * @param module Range: _TMR0 a _TMR3
 * @param value Range: 8 bits - (0 a 255) ou 16 bits - (0 a 65535)
 */
void timer_set_counter(uint8 module, uint16 val);

/**
 * @brief 
 * @param module Range: _TMR0 a _TMR3
 * @return Valor do temporizador
 */
uint16 timer_get_counter(uint8 module);

/**
 * @brief
 * @param module Range: _TMR0 a _TMR3
 * @param value Range: DISABLE - Desabilita interrupcao ENABLE - Habilita interrupcao
 */
void timer_setup_interrupt(uint8 module, uint8 value);

/**
 * @brief
 * @param module Range: _TMR0 a TMR3
 * @param value Range: LOW_PRIORITY - Baixa prioridade HIGH_PRIORITY - Alta prioridade
 */
void timer_priority_interrupt(uint8 module, uint8 value);

/**
 * @brief Inicializa os registradores do Timer0
 */
void timer_init_regs(uint8 module);

/**
 * @brief Funcao para configurar a fonte de clock para o contador do Timer e a transicao de nivel em que deve ser incrementado
 * Ex.: timer_setup_clock(TMR0_INT_CLOCK, 0);
 *      timer_setup_clock(TMR0_EXT_CLOCK, TMR0_HIGH_TO_LOW);
 * @param source Range: TMR0_EXT_CLOCK, TMR0_INT_CLOCK
 * @param transition Range: TMR0_HIGH_TO_LOW, TMR0_LOW_TO_HIGH
 */
void timer_setup_clock(uint8 module, uint8 source, uint8 transition);

/**
 * @brief Funcao para habilitar e configurar o prescale do Timer0
 * Ex.: timer_setup_scale(_TMR0, TMR_PRESCALE_ON, TMR0_PRESCALE_1_8);
 * @param on_off Range: TMR_PRESCALE_OFF, TMR_PRESCALE_ON
 * @param prescale Range: TMR0_PRESCALE_1_x (x->1,2,4,8,16,32,64,128,256)
 */
void timer_setup_scale(uint8 module, uint8 on_off, uint8 prescale, uint8 postscale);

/**
 * @brief Funcao para configurar a quantidade de bits dos contadores dos timers
 * Ex.: timer_setup_bits(TMR_16_BIT);
 * @param bits Range: TMR_8_BIT, TMR_16_BIT
 */
void timer_setup_bits(uint8 module, uint8 bits);

/**
 * @brief
 * @param value Range: TMR_ON - habilita o temporizador TMR_OFF - desabilita o temporizador
 */
void timer_start(uint8 module, uint8 value);

/**
 * @brief
 * @param func
 */
void timer_set_callbak(uint8 module, void (*func)(void));

#endif	/* HAL_TIMER_H */

