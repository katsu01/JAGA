/**
 * @file    hal_uart.c
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    26 de Abril de 2015
 * @version 0.1.0.0 

 * @brief   Codigo do Driver UART para o microcontrolador TM4C123GXL.
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

#include "hal_uart.h"

void uart_putc(uint8 UI8_caracter)
{
		// as part of Lab 11, modify this program to use UART0 instead of UART1
		while((UART0_FR_R&UART_FR_TXFF) != 0);
		UART0_DR_R = UI8_caracter;	
}

//__inline uint8 uart_get_data(void)
uint8 uart_get_data(void)
{	
  while((UART0_FR_R&0x0010) != 0);      // wait until RXFE is 0
		return((unsigned char)(UART0_DR_R&0xFF));
}

