/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
 *
 *  .. based on file from F4.
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

#ifndef LIBOPENCM3_MEMORYMAP_H
#define LIBOPENCM3_MEMORYMAP_H

#include <libopencm3/cm3/memorymap.h>

/* --- Renesas specific peripheral definitions ------------------------------- */

/* Memory map for all buses */
#define FLASH_BASE          (0x00000000U)
#define MPU_BASE            (0x40000000U)


#define SRAM_BASE           (0x40002000U)
#define BUS_BASE            (0x40004000U)
#define DTC_BASE            (0x40006000U)
#define DBG_BASE            (0x4001B000U)
#define SYSC_BASE           (0x4001E000U)

#define PORT0_BASE          (0x40040000U)
#define PORT1_BASE          (0x40040020U)
#define PORT2_BASE          (0x40040040U)
#define PORT3_BASE          (0x40040060U)
#define PORT4_BASE          (0x40040080U)
#define PORT5_BASE          (0x400400A0U)
#define PORT6_BASE          (0x400400C0U)
#define PORT7_BASE          (0x400400E0U)
#define PORT8_BASE          (0x40040100U)

#define PFS_BASE            (0x40040800U)
#define ELC_BASE            (0x40041000U)
#define POEG_BASE           (0x40042000U)
#define RTC_BASE            (0x40044000U)
#define WDT_BASE            (0x40044200U)
#define IWDT_BASE           (0x40044400U)
#define CAC_BASE            (0x40044600U)
#define MSTP_BASE           (0x40047000U)

#define CAN0_BASE           (0x40050000U)
#define I2C0_BASE           (0x40053000U)
#define I2C0WU_BASE         (0x40053014U)
#define I2C1_BASE           (0x40053100U)
#define DOC_BASE            (0x40054100U)
#define ADC_BASE            (0x4005C000U)
#define DAC_BASE            (0x4005E000U)

#define SCI0_BASE           (0x40070000U)
#define SCI1_BASE           (0x40070020U)
#define SCI2_BASE           (0x40070040U)
#define SCI3_BASE           (0x40070060U)
#define SCI9_BASE           (0x40070120U)

#define SPI0_BASE           (0x40072000U)
#define SPI1_BASE           (0x40072100U)

#define CRC_BASE            (0x40074000U)

#define GPT0_BASE           (0x40078000U)
#define GPT1_BASE           (0x40078100U)
#define GPT2_BASE           (0x40078200U)
#define GPT3_BASE           (0x40078300U)
#define GPT4_BASE           (0x40078400U)
#define GPT5_BASE           (0x40078500U)
#define GPT6_BASE           (0x40078600U)
#define GPT7_BASE           (0x40078700U)
#define GPT8_BASE           (0x40078800U)
#define GPT9_BASE           (0x40078900U)
#define GPT_OPS_BASE        (0x40078FF0U)

#define KINT_BASE           (0x40080000U)
#define CTSU_BASE           (0x40082000U)
#define AGT0_BASE           (0x40084000U)
#define AGT1_BASE           (0x40084100U)
#define ACMPLP_BASE         (0x40085E00U)
#define FLCN_BASE           (0x407EC000U)

#endif
