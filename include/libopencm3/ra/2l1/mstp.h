
#ifndef LIBOPENCM3_MSTP_H
#define LIBOPENCM3_MSTP_H


#include <libopencm3/cm3/common.h>
#include <libopencm3/ra/memorymap.h>

#define MSTP_MSTPCRB            MMIO32(MSTP_BASE + 0x000)
#define MSTP_MSTPCRC            MMIO32(MSTP_BASE + 0x004)
#define MSTP_MSTPCRD            MMIO32(MSTP_BASE + 0x008)    
#define MSTP_LSMRWDIS           MMIO32(MSTP_BASE + 0x00C)    



#define _REG_BIT(base, bit)		(((base) << 5) + (bit))

enum periph_clken{

    MSTP_DTC    =     _REG_BIT(0x1C, 22),

    MSTP_CAN0   =     _REG_BIT(0x00, 2),
    MSTP_I2C1   =     _REG_BIT(0x00, 8),
    MSTP_I2C0   =     _REG_BIT(0x00, 9),
    MSTP_SPI1   =     _REG_BIT(0x00, 18),
    MSTP_SPI0   =     _REG_BIT(0x00, 19),
    MSTP_SCI9   =     _REG_BIT(0x00, 22),
    MSTP_SCI3   =     _REG_BIT(0x00, 28),
    MSTP_SCI2   =     _REG_BIT(0x00, 29),
    MSTP_SCI1   =     _REG_BIT(0x00, 30),
    MSTP_SCI0   =     _REG_BIT(0x00, 31),

    MSTP_CAC    =     _REG_BIT(0x004, 0),
    MSTP_CRC    =     _REG_BIT(0x004, 1),
    MSTP_CTSU   =     _REG_BIT(0x004, 3),
    MSTP_DOC    =     _REG_BIT(0x004, 13),
    MSTP_ELC    =     _REG_BIT(0x004, 14),
    MSTP_TRNG   =     _REG_BIT(0x004, 28),
    MSTP_ASE    =     _REG_BIT(0x004, 31),

    MSTP_AGT1   =     _REG_BIT(0x008, 2),
    MSTP_AGT0   =     _REG_BIT(0x008, 3),
    MSTP_GPT32  =     _REG_BIT(0x008, 5),
    MSTP_GPT16  =     _REG_BIT(0x008, 6),
    MSTP_POEG   =     _REG_BIT(0x008, 14),
    MSTP_ADC    =     _REG_BIT(0x008, 16),
    MSTP_DAC    =     _REG_BIT(0x008, 20),
    MSTP_ACMPLP =     _REG_BIT(0x008, 29),
};




BEGIN_DECLS

void rcc_periph_clock_enable(enum periph_clken clken);
void rcc_periph_clock_disable(enum periph_clken clken);
//void rcc_periph_reset_pulse(enum rcc_periph_rst rst);

END_DECLS

#endif