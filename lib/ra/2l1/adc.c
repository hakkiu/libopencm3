#include <libopencm3/ra/2l1/adc.h>

#define ADC_ADCSR_DBLANS            (0x1F)
#define ADC_ADCSR_GBDAIE            (1 << 6)
#define ADC_ADCSR_DBLE              (1 << 7)

#define ADC_ADCSR_EXTRG              (1 << 8)
#define ADC_ADCSR_TRGE               (1 << 9)
#define ADC_ADCSR_ADHSC              (1 << 10)
#define ADC_ADCSR_ADCS               (3 << 13)
#define ADC_ADCSR_ADST               (1 << 15)

#define ADC_ADCER_ACE               (1 << 5)
#define ADC_ADCER_DIAGVAL           (3 << 8)
#define ADC_ADCER_DIAGLD            (1 << 10)
#define ADC_ADCER_DIAGM             (1 << 11)
#define ADC_ADCER_ADRFMT            (1 << 15)

#define ADC_ADEXICR_TSSAD           (1 << 0)
#define ADC_ADEXICR_OCSAD           (1 << 1)
#define ADC_ADEXICR_TSSA            (1 << 8)
#define ADC_ADEXICR_OCSA            (1 << 9)

#define ADC_ADCSR_ADCS_SHIFT            13
#define ADC_ADCSR_SINGLE            (0x0 << ADC_ADCSR_ADCS_SHIFT)
#define ADC_ADCSR_GROUP             (0x1 << ADC_ADCSR_ADCS_SHIFT)
#define ADC_ADCSR_CONT              (0x2 << ADC_ADCSR_ADCS_SHIFT)


void adc_power_on_async(uint32_t adc)
{
    ADC_ADCSR |= ADC_ADCSR_ADST;
}
void adc_power_on(uint32_t adc)
{
    ADC_ADCSR |= ADC_ADCSR_ADST;
}
bool adc_is_power_on(uint32_t adc)
{
    return false;
}
void adc_power_off_async(uint32_t adc)
{
    ADC_ADCSR &= ~ADC_ADCSR_ADST;
}
void adc_power_off(uint32_t adc)
{
    ADC_ADCSR &= ~ADC_ADCSR_ADST;
}
bool adc_is_power_off(uint32_t adc)
{
    return false;
}
void adc_enable_dma(uint32_t adc)
{

}
void adc_disable_dma(uint32_t adc)
{

}
void adc_set_regular_sequence(uint32_t adc, uint8_t length, uint8_t channel[])
{
    uint32_t reg32 = 0;
	uint8_t i = 0;

	if (length == 0) {
		ADC_ADANSA = 0;
		return;
	}

	for (i = 0; i < length; i++) {
		reg32 |= (1 << channel[i]);
	}

	ADC_ADANSA = reg32;
}

void adc_calibrate(uint32_t adc){ /* Kalibrasyon yapılamıyor*/}
void adc_set_right_aligned(uint32_t adc)
{
    ADC_ADCER &= ~ADC_ADCER_ADRFMT;
}
void adc_enable_overrun_interrupt(uint32_t adc) // No enable reg 
{

}
void adc_set_continuous_conversion_mode(uint32_t adc)
{
    uint16_t reg16;

    ADC_ADEXICR &= ~(ADC_ADEXICR_TSSA | ADC_ADEXICR_OCSA); // Disable temperature sensor and reference voltage

    reg16 = ADC_ADCSR;
    ADC_ADCSR = (reg16 & ~ADC_ADCSR_ADCS) | ADC_ADCSR_CONT;
}

void adc_set_single_conversion_mode(uint32_t adc)
{
    uint16_t reg16;
    reg16 = ADC_ADCSR;
    ADC_ADCSR = (reg16 & ~ADC_ADCSR_ADCS) | ADC_ADCSR_SINGLE ;
}
void adc_set_sample_time_on_all_channels(uint32_t adc, uint8_t time)
{
    uint8_t i;
    for (i = 0; i < 14; i++)
    {
        ADC_ADSSTR(i) = time;
    }

    ADC_ADSSTRL = time;
    ADC_ADSSTRT = time;
    ADC_ADSSTRO = time;
}


