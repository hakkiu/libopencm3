#ifndef LIBOPENCM3_ADC_H
#define LIBOPENCM3_ADC_H


#include <libopencm3/ra/memorymap.h>
#include <libopencm3/cm3/common.h>


#define ADC_ADDR(adc_ch)           MMIO16(ADC_BASE + 0x20 + ((adc_ch) * 0x2)
#define ADC_ADDBLDR             MMIO16(ADC_BASE + 0x18)
#define ADC_ADDBLDRA            MMIO16(ADC_BASE + 0x84)
#define ADC_ADDBLDRB            MMIO16(ADC_BASE + 0x86)
#define ADC_ADTSDER             MMIO16(ADC_BASE + 0x1A)
#define ADC_ADOCDR              MMIO16(ADC_BASE + 0x1C)
#define ADC_ADCTDR              MMIO16(ADC_BASE + 0x40)
#define ADC_ADRD                MMIO16(ADC_BASE + 0x1E)
#define ADC_ADCSR               MMIO16(ADC_BASE + 0x00)
//#define ADC_ADANSA0             MMIO16(ADC_BASE + 0x04)
#define ADC_ADANSA              MMIO32(ADC_BASE + 0x04)
#define ADC_ADANSB              MMIO32(ADC_BASE + 0x14)
//#define ADC_ADANSB1             MMIO16(ADC_BASE + 0x16)
#define ADC_ADADS0              MMIO16(ADC_BASE + 0x08)
#define ADC_ADADS1              MMIO16(ADC_BASE + 0x0A)
#define ADC_ADADC               MMIO8(ADC_BASE + 0x0C)
#define ADC_ADCER               MMIO16(ADC_BASE + 0x0E)
#define ADC_ADSTRGR             MMIO16(ADC_BASE + 0x10)
#define ADC_ADEXICR             MMIO16(ADC_BASE + 0x12)
#define ADC_ADSSTRO             MMIO8(ADC_BASE + 0xDF)
#define ADC_ADSSTRT             MMIO8(ADC_BASE + 0xDE)
#define ADC_ADSSTRL             MMIO8(ADC_BASE + 0xDD)
#define ADC_ADSSTR(adc_ch)      MMIO8(ADC_BASE + 0xE0 + (0x1 * (adc_ch)))
#define ADC_ADDISCR             MMIO8(ADC_BASE + 0x7A)
#define ADC_ADACSR              MMIO8(ADC_BASE + 0x7E)
#define ADC_ADGSPCR             MMIO16(ADC_BASE + 0x80)
#define ADC_ADCMPCR             MMIO16(ADC_BASE + 0x90)
#define ADC_ADCMPANSR0          MMIO16(ADC_BASE + 0x94)
#define ADC_ADCMPANSR1          MMIO16(ADC_BASE + 0x96)

#define ADC_ADCMPANSER          MMIO8(ADC_BASE + 0x82)
#define ADC_ADCMPLR0            MMIO16(ADC_BASE + 0x98)
#define ADC_ADCMPLR1            MMIO16(ADC_BASE + 0x9A)
#define ADC_ADCMPLER            MMIO8(ADC_BASE + 0x93)
#define ADC_ADCMPDR             MMIO32(ADC_BASE + 0x9C)
#define ADC_ADWINLB             MMIO32(ADC_BASE + 0xA8)
#define ADC_ADCMPSR0            MMIO16(ADC_BASE + 0xA0)
#define ADC_ADCMPSR1            MMIO16(ADC_BASE + 0xA2)
#define ADC_ADCMPSER            MMIO8(ADC_BASE + 0xA4)
#define ADC_ADCMPBNSR           MMIO8(ADC_BASE + 0xA6)
#define ADC_ADCMPBSR            MMIO8(ADC_BASE + 0xAC)
#define ADC_ADWINMON            MMIO8(ADC_BASE + 0x8C)
#define ADC_ADHVREFCNT          MMIO8(ADC_BASE + 0x8A)

BEGIN_DECLS

void adc_power_on_async(uint32_t adc);
void adc_power_on(uint32_t adc);
bool adc_is_power_on(uint32_t adc);
void adc_power_off_async(uint32_t adc);
void adc_power_off(uint32_t adc);
bool adc_is_power_off(uint32_t adc);
void adc_enable_dma(uint32_t adc);
void adc_disable_dma(uint32_t adc);
void adc_set_regular_sequence(uint32_t adc, uint8_t length, uint8_t channel[]);

void adc_calibrate(uint32_t adc);
void adc_set_right_aligned(uint32_t adc);
void adc_enable_overrun_interrupt(uint32_t adc);
void adc_set_continuous_conversion_mode(uint32_t adc);
void adc_set_sample_time_on_all_channels(uint32_t adc, uint8_t time);


/*

void adc_calibrate_async(uint32_t adc);
bool adc_is_calibrating(uint32_t adc);
void adc_set_single_conversion_mode(uint32_t adc);
void adc_enable_temperature_sensor(void);
void adc_disable_temperature_sensor(void);
void adc_enable_vrefint(void);
void adc_disable_vrefint(void);
void adc_set_resolution(uint32_t adc, uint16_t resolution);
void adc_set_left_aligned(uint32_t adc);

bool adc_eoc(uint32_t adc);
bool adc_eos(uint32_t adc);
void adc_enable_eoc_interrupt(uint32_t adc);
void adc_disable_eoc_interrupt(uint32_t adc);
void adc_disable_overrun_interrupt(uint32_t adc);
bool adc_get_overrun_flag(uint32_t adc);
void adc_clear_overrun_flag(uint32_t adc);
uint32_t adc_read_regular(uint32_t adc);
void adc_start_conversion_regular(uint32_t adc);
void adc_enable_dma_circular_mode(uint32_t adc);
void adc_disable_dma_circular_mode(uint32_t adc);
void adc_enable_delayed_conversion_mode(uint32_t adc);
void adc_disable_delayed_conversion_mode(uint32_t adc);*/
END_DECLS

#endif