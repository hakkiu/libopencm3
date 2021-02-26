#include <libopencm3/ra/2l1/gpt.h>


#define GPT_GTCR_CST                (1 << 0)

#define GPT_GTCR_MD                 (0x7 << 16)
#define GPT_GTCR_SWPWM              (0x0 << 16)
#define GPT_GTCR_SWONE              (0x1 << 16)
#define GPT_GTCR_TWPWM1             (0x4 << 16)
#define GPT_GTCR_TWPWM2             (0x5 << 16)
#define GPT_GTCR_TWPWM3             (0x6 << 16)

#define GPT_GTCR_TPCS               (0x7 << 24)
#define GPT_GTCR_CLKDIV1            (0x0 << 24)
#define GPT_GTCR_CLKDIV4            (0x1 << 24)
#define GPT_GTCR_CLKDIV16           (0x2 << 24)
#define GPT_GTCR_CLKDIV64           (0x3 << 24)
#define GPT_GTCR_CLKDIV256          (0x4 << 24)
#define GPT_GTCR_CLKDIV1024         (0x5 << 24)

#define GPT_GTUDDTYC_UD_DOWN          (0 << 0)
#define GPT_GTUDDTYC_UD_UP            (1 << 1)

void timer_write_protect_disable(uint32_t timer_peripheral)
{
    GPT_GTWP(timer_peripheral) = 0xA501;
}
void timer_write_protect_enable(uint32_t timer_peripheral)
{
    GPT_GTWP(timer_peripheral) = 0xA500;
}

void timer_set_period(uint32_t timer_peripheral, uint32_t period)
{
    GPT_GTPSR(timer_peripheral) = period;
}
void timer_enable_counter(uint32_t timer_peripheral)
{
    GPT_GTCR(timer_peripheral) |= GPT_GTCR_CST;
}
void timer_disable_counter(uint32_t timer_peripheral)
{
    GPT_GTCR(timer_peripheral) &= ~GPT_GTCR_CST;
}
void timer_clear_flag(uint32_t timer_peripheral, uint32_t flag)
{
    GPT_GTST(timer_peripheral) &= ~flag;
}
void timer_continuous_mode(uint32_t timer_peripheral)
{
    uint32_t reg32;
	reg32 = GPT_GTCR(timer_peripheral);
	GPT_GTCR(timer_peripheral) = (reg32 & ~GPT_GTCR_MD) | GPT_GTCR_SWPWM;
}
void timer_one_shot_mode(uint32_t timer_peripheral)
{
    uint32_t reg32;
	reg32 = GPT_GTCR(timer_peripheral);
	GPT_GTCR(timer_peripheral) = (reg32 & ~GPT_GTCR_MD) | GPT_GTCR_SWONE;
}
void timer_set_counter(uint32_t timer_peripheral, uint32_t count)
{
    GPT_GTCNT(timer_peripheral) = count;
}
void timer_set_mode(uint32_t timer_peripheral, uint32_t direction)
{
    uint32_t reg32;
    reg32 = GPT_GTUDDTYC(timer_peripheral);
    GPT_GTUDDTYC(timer_peripheral) = (reg32 & ~GPT_GTUDDTYC_UD_UP) | direction;

}

void timer_set_prescaler(uint32_t timer_peripheral, uint32_t value)
{
    uint32_t reg32;
    reg32 = GPT_GTCR(timer_peripheral);
    GPT_GTCR(timer_peripheral) = (reg32 & ~GPT_GTCR_TPCS) | value;
}
       
void timer_enable_update_event(uint32_t timer_peripheral)
{
    GPT_GTBER(timer_peripheral) |= (0x1 << 20); 
} 

void timer_set_buffer_value(uint32_t timer_peripheral, uint32_t value)
{
    GPT_GTPBR(timer_peripheral) = value;
}

void timer_enable_irq(uint32_t timer_peripheral, uint32_t irq) // enable etme gibi bir olay yok
{
    
}
void timer_update_on_overflow(uint32_t timer_peripheral); // Overflow veya underflow durumda update yapıyor
void timer_disable_preload(uint32_t timer_peripheral);
void timer_set_dma_on_update_event(uint32_t timer_peripheral);  // dma olaylarına topluca bakılacak   
