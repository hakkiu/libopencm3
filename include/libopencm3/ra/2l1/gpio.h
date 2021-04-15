/*
 * This file is part of the libopencm3 project.
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_GPIO_H
#define LIBOPENCM3_GPIO_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/ra/memorymap.h>

#define GPIO0	PORT0_BASE
#define GPIO1	PORT1_BASE
#define GPIO2	PORT2_BASE
#define GPIO3	PORT3_BASE
#define GPIO4	PORT4_BASE
#define GPIO5	PORT5_BASE
#define GPIO6	PORT6_BASE
#define GPIO7	PORT7_BASE

#define GPIOPIN0			(1 << 0)
#define GPIOPIN1			(1 << 1)
#define GPIOPIN2			(1 << 2)
#define GPIOPIN3			(1 << 3)
#define GPIOPIN4			(1 << 4)
#define GPIOPIN5			(1 << 5)
#define GPIOPIN6			(1 << 6)
#define GPIOPIN7			(1 << 7)
#define GPIOPIN8			(1 << 8)
#define GPIOPIN9			(1 << 9)
#define GPIOPIN10			(1 << 10)
#define GPIOPIN11			(1 << 11)
#define GPIOPIN12			(1 << 12)
#define GPIOPIN13			(1 << 13)
#define GPIOPIN14			(1 << 14)
#define GPIOPIN15			(1 << 15)


/** @defgroup gpio_mode GPIO Pin Direction and Analog/Digital Mode
@ingroup gpio_defines
@{*/
#define GPIO_MODE_INPUT			0x0
#define GPIO_MODE_OUTPUT		0x1
#define GPIO_MODE_AF			0x2
#define GPIO_MODE_ANALOG		0x3

#define GPIO_PUPD_NONE			(0 << 4)
#define GPIO_PUPD_PULLUP		(1 << 4)

#define PORT_PmnPFS_PODR          (1 << 0)
#define PORT_PmnPFS_PIDR          (1 << 1)
#define PORT_PmnPFS_PDR	          (1 << 2)
#define PORT_PmnPFS_NCODR         (1 << 6)
#define PORT_PmnPFS_EOFR          (1 << 12)
#define PORT_PmnPFS_ISEL          (1 << 14)
#define PORT_PmnPFS_ASEL          (1 << 15)
#define PORT_PmnPFS_PMR 	      (1 << 16)
//#define PORT_PmnPFS_PSEL          (1 << 24)

#define PORT_PCNTR1(port)			MMIO32(port + 0x00)
#define PORT_PCNTR2(port)			MMIO32(port + 0x04)
#define PORT_PCNTR3(port)			MMIO32(port + 0x08)
#define PORT_PCNTR4(port)			MMIO32(port + 0x0C)
#define PORT_PMNPFS(port, pin)		MMIO32(PFS_BASE + (0x40 * ((((port) - PORT0_BASE) >> 5) & 0xF )) + (0x04 * (pin)))
#define PORT_PWPR					MMIO8(PFS_BASE + 0x503)
#define PORT_PRWCNTR				MMIO8(PFS_BASE + 0x50F)

/*************************************************************************************************/
#define PORT_PmnPFS_PCR      	(1 << 4)
/*************************************************************************************************/

#define PORT_PWPR_PFSWE				(1 << 6)
#define PORT_PWPR_BOWI				(1 << 7)

/*************************************************************************************************/
#define PORT_PmnPFS_PSEL_POS        	(24)
#define PORT_PmnFS_PSEL_Msk					(0x1F << PORT_PmnPFS_PSEL_POS)
#define PORT_PmnPFS_PSEL(value)      	(((value) << PORT_PmnPFS_PSEL_POS) & PORT_PmnFS_PSEL_Msk )
#define GPIO_AF_IO					(0x00)
#define GPIO_AF_DEBUG				(0x00)
#define GPIO_AF_AGT 				(0x01)
#define GPIO_AF_GPT0 				(0x02)
#define GPIO_AF_GPT1 				(0x03)
#define GPIO_AF_SCI0 				(0x04)
#define GPIO_AF_SCI1 				(0x05)
#define GPIO_AF_SPI 				(0x06)
#define GPIO_AF_IIC 				(0x07)
#define GPIO_AF_KEY	 				(0x08)
#define GPIO_AF_CLKOUT_COMP_RTC		(0x09)
#define GPIO_AF_CAC_AD_DAC 			(0x0A)
#define GPIO_AF_BUS 				(0x0B)
#define	GPIO_AF_CTSU 				(0x0C)
#define GPIO_AF_LCDC 				(0x0D)
#define GPIO_AF_DALI 				(0x0E)
#define GPIO_AF_CAN 				(0x10)

/******************************************************************************************************/

BEGIN_DECLS
void gpio_port_protection_lock(void);
void gpio_port_protection_unlock(void);
void gpio_set(uint32_t gpioport, uint16_t gpios);
void gpio_clear(uint32_t gpioport, uint16_t gpios);
uint16_t gpio_get(uint32_t gpioport, uint16_t gpios);
void gpio_toggle(uint32_t gpioport, uint16_t gpios);

void gpio_mode_setup(uint32_t gpioport, uint8_t mode, uint8_t pull_up_down,
		     uint16_t gpios);
void gpio_set_output_options(uint32_t gpioport, uint8_t otype, uint8_t speed,
			     uint16_t gpios);
void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint16_t gpios);

END_DECLS

#endif
