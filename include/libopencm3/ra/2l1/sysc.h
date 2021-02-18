
#ifndef LIBOPENCM3_SYSC_H
#define LIBOPENCM3_SYSC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/ra/memorymap.h>

#define SYSC_SBYCR              MMIO16(SYSC_BASE + 0x00C)
#define SYSC_SCKDIVCR          MMIO32(SYSC_BASE + 0x020)
#define SYSC_SCKSCR             MMIO8(SYSC_BASE + 0x026)
#define SYSC_MEMWAIT            MMIO8(SYSC_BASE + 0x031)
#define SYSC_MOSCCR             MMIO8(SYSC_BASE + 0x032)
#define SYSC_HOCOCR             MMIO8(SYSC_BASE + 0x036)
#define SYSC_MOCOCR             MMIO8(SYSC_BASE + 0x038)
#define SYSC_OSCSF              MMIO8(SYSC_BASE + 0x03C)
#define SYSC_CKOCR              MMIO8(SYSC_BASE + 0x03C)
#define SYSC_OSTDCR             MMIO8(SYSC_BASE + 0x040)
#define SYSC_OSTDSR             MMIO8(SYSC_BASE + 0x041)
#define SYSC_MOCOUTCR           MMIO8(SYSC_BASE + 0x061)
#define SYSC_HOCOUTCR           MMIO8(SYSC_BASE + 0x062)
#define SYSC_OPCCR              MMIO8(SYSC_BASE + 0x0A0)
#define SYSC_MOSCWCTR           MMIO8(SYSC_BASE + 0x0A2)
#define SYSC_PRCR               MMIO16(SYSC_BASE + 0x3FE)
#define SYSC_MOMCR              MMIO8(SYSC_BASE + 0x413)
#define SYSC_SOMCR              MMIO8(SYSC_BASE + 0x481)
#define SYSC_SOMRG              MMIO8(SYSC_BASE + 0x482)    
#define SYSC_SOSCCR             MMIO8(SYSC_BASE + 0x480)
#define SYSC_LOCOCR             MMIO8(SYSC_BASE + 0x490)
#define SYSC_LOCOUTCR           MMIO8(SYSC_BASE + 0x492)
#define SYSC_OPCCR              MMIO8(SYSC_BASE + 0x0A0)
#define SYSC_SOPCCR             MMIO8(SYSC_BASE + 0x0AA)




#define REG_MODE(bit, mode)	        	((mode) << bit)
#define REG_MODE_MASK(size, bit)		((((1 << (size)) - 1)) << (bit))



#define SYSC_PRCR_PRC0          (0x1 << 0)
#define SYSC_PRCR_PRC1          (0x1 << 1)
#define SYSC_PRCR_PRC3          (0x1 << 3)
#define SYSC_PRCR_PRKEY         (0xA5 << 8)


#define SYSC_SCKDIVCR_DIV1           0x0
#define SYSC_SCKDIVCR_DIV2           0x1
#define SYSC_SCKDIVCR_DIV4           0x2
#define SYSC_SCKDIVCR_DIV8           0x3
#define SYSC_SCKDIVCR_DIV16          0x4
#define SYSC_SCKDIVCR_DIV32          0x5
#define SYSC_SCKDIVCR_DIV64          0x6

#define SYSC_SCKSCR_CKSEL_HOCO        0x0
#define SYSC_SCKSCR_CKSEL_MOCO        0x1
#define SYSC_SCKSCR_CKSEL_LOCO        0x2
#define SYSC_SCKSCR_CKSEL_MOSC        0x3
#define SYSC_SCKSCR_CKSEL_SOSC        0x4

#define SYSC_MEMWAIT_MEMWAIT         0x1
#define SYSC_MOSCCR_MOSTP            0x1
#define SYSC_SOSCCR_SOSTP            0x1
#define SYSC_LOCOCR_LCSTP            0x1
#define SYSC_HOCOCR_HCSTP            0x1
#define SYSC_MOCOCR_MCSTP            0x1


#define SYSC_OSCSF_HOCOSF            0x1
#define SYSC_OSCSF_MOSCSF            (0x1 << 3)

#define SYSC_OSTDCR_OSTDIE            0x1
#define SYSC_OSTDCR_OSTDE             (0x1 << 7)


#define SYSC_OSTDSR_OSTDF               0x1
#define SYSC_MOSCWTCR_MSTS              0x1

#define SYSC_MOSCWTCR_MSTS_2            0x0
#define SYSC_MOSCWTCR_MSTS_1024         0x1
#define SYSC_MOSCWTCR_MSTS_2048         0x2
#define SYSC_MOSCWTCR_MSTS_4096         0x3
#define SYSC_MOSCWTCR_MSTS_8192         0x4
#define SYSC_MOSCWTCR_MSTS_16384        0x5
#define SYSC_MOSCWTCR_MSTS_32768        0x6
#define SYSC_MOSCWTCR_MSTS_65536        0x7
#define SYSC_MOSCWTCR_MSTS_131072       0x8
#define SYSC_MOSCWTCR_MSTS_262144       0x9


#define SYSC_MOMCR_MODRV1           (0x1 << 3)
#define SYSC_MOMCR_MOSEL            (0x1 << 6)


#define SYSC_SOMCR_SODRV_NM          0x0
#define SYSC_SOMCR_SODRV_LPM1        0x1
#define SYSC_SOMCR_SODRV_LPM2        0x2
#define SYSC_SOMCR_SODRV_LPM3        0x3

#define SYSC_SOMRG_SOSCMRG_NC           0x0
#define SYSC_SOMRG_SOSCMRG_LM           0x1
#define SYSC_SOMRG_SOSCMRG_UM           0x2

#define SYSC_CKOCR_CKOSEL_SHIFT           0
#define SYSC_CKOCR_CKOSEL_HOCO          0x0
#define SYSC_CKOCR_CKOSEL_MOCO          0x1
#define SYSC_CKOCR_CKOSEL_LOCO          0x2
#define SYSC_CKOCR_CKOSEL_MOSC          0x3
#define SYSC_CKOCR_CKOSEL_SOSC          0x4


#define SYSC_CKOCR_CKODIV_SHIFT          4
#define SYSC_CKOCR_CKODIV_DIV1           0x0
#define SYSC_CKOCR_CKODIV_DIV2           0x1
#define SYSC_CKOCR_CKODIV_DIV4           0x2
#define SYSC_CKOCR_CKODIV_DIV8           0x3
#define SYSC_CKOCR_CKODIV_DIV16          0x4
#define SYSC_CKOCR_CKODIV_DIV32          0x5
#define SYSC_CKOCR_CKODIV_DIV64          0x6
#define SYSC_CKOCR_CKODIV_DIV128         0x7

#define SYSC_CKOCR_CKOEN                (0x1 << 7)

#define SYSC_OPCCR_OPCM               (1 << 0)
#define SYSC_OPCCR_OPCMTSF            (1 << 4)

#define SYSC_SOPCCR_SOPCM               (1 << 0)
#define SYSC_SOPCCR_SOPCMTSF            (1 << 4)

//////////////






///////////////


#endif