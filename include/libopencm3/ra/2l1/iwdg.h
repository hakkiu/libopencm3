#ifndef LIBOPENCM3_IWDT_H
#define LIBOPENCM3_IWDT_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/ra/memorymap.h>


#define IWDT_RR         MMIO8(IWDT_BASE)
#define IWDT_SR         MMIO16(IWDT_BASE + 0x04)

#define IWDT_SR_CNTVAL         (0x3FFF)
#define IWDT_SR_UNDFF          (1 << 14) 
#define IWDT_SR_REFEF          (1 << 15)

BEGIN_DECLS
void iwdg_reset(void);
END_DECLS


#endif