#ifndef LIBOPENCM3_GPT_H
#define LIBOPENCM3_GPT_H


#include <libopencm3/ra/memorymap.h>
#include <libopencm3/cm3/common.h>

#define GPT_GTWP(gpt_base)              MMIO32((gpt_base) + 0x00)
#define GPT_GTSTR(gpt_base)             MMIO32((gpt_base) + 0x04)
#define GPT_GTSTP(gpt_base)             MMIO32((gpt_base) + 0x08)
#define GPT_GTCLR(gpt_base)             MMIO32((gpt_base) + 0x0C)
#define GPT_GTSSR(gpt_base)             MMIO32((gpt_base) + 0x10)
#define GPT_GTPSR(gpt_base)             MMIO32((gpt_base) + 0x14)
#define GPT_GTCSR(gpt_base)             MMIO32((gpt_base) + 0x18)
#define GPT_GTUPSR(gpt_base)            MMIO32((gpt_base) + 0x1C)
#define GPT_GTDNSR(gpt_base)            MMIO32((gpt_base) + 0x20)
#define GPT_GTICASR(gpt_base)           MMIO32((gpt_base) + 0x24)
#define GPT_GTICBSR(gpt_base)           MMIO32((gpt_base) + 0x28)
#define GPT_GTCR(gpt_base)              MMIO32((gpt_base) + 0x2C)
#define GPT_GTUDDTYC(gpt_base)          MMIO32((gpt_base) + 0x30)
#define GPT_GTIOR(gpt_base)             MMIO32((gpt_base) + 0x34)
#define GPT_GTINTAD(gpt_base)           MMIO32((gpt_base) + 0x38)
#define GPT_GTST(gpt_base)              MMIO32((gpt_base) + 0x3C)
#define GPT_GTBER(gpt_base)             MMIO32((gpt_base) + 0x40)
#define GPT_GTCNT(gpt_base)             MMIO32((gpt_base) + 0x48)
#define GPT_GTPR(gpt_base)              MMIO32((gpt_base) + 0x64)
#define GPT_GTPBR(gpt_base)             MMIO32((gpt_base) + 0x68)
#define GPT_GTDTCR(gpt_base)            MMIO32((gpt_base) + 0x88)
#define GPT_GTDVU(gpt_base)             MMIO32((gpt_base) + 0x8C)
#define GPT_OPSCR                       MMIO32(GPT_OPS_BASE + 0x00)

BEGIN_DECLS


void timer_enable_irq(uint32_t timer_peripheral, uint32_t irq);
void timer_set_period(uint32_t timer_peripheral, uint32_t period);
void timer_enable_counter(uint32_t timer_peripheral);
void timer_disable_counter(uint32_t timer_peripheral);
void timer_set_prescaler(uint32_t timer_peripheral, uint32_t value);
void timer_clear_flag(uint32_t timer_peripheral, uint32_t flag);
void timer_continuous_mode(uint32_t timer_peripheral);
void timer_set_counter(uint32_t timer_peripheral, uint32_t count);
void timer_set_mode(uint32_t timer_peripheral, uint32_t direction);
       
void timer_set_dma_on_update_event(uint32_t timer_peripheral);     
void timer_one_shot_mode(uint32_t timer_peripheral);
void timer_enable_update_event(uint32_t timer_peripheral);
void timer_update_on_overflow(uint32_t timer_peripheral);
void timer_disable_preload(uint32_t timer_peripheral);
END_DECLS


#endif