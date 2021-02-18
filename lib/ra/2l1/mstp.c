#include <libopencm3/ra/2l1/mstp.h>

            
#define _RCC_REG(i)		MMIO32((i >= 0x1C ? SYSC_BASE : MSTP_BASE) + ((i) >> 5))
#define _RCC_BIT(i)		(1 << ((i) & 0x1f))

void rcc_periph_clock_enable(enum periph_clken clken){
    _RCC_REG(clken) &= ~_RCC_BIT(clken);
}
void rcc_periph_clock_disable(enum periph_clken clken){
     _RCC_REG(clken) |= _RCC_BIT(clken);
}
/*void rcc_periph_reset_pulse(enum rcc_periph_rst rst){
  
}*/
