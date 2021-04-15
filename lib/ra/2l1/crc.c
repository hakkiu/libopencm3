#include <libopencm3/ra/2l1/crc.h>

uint32_t crc_calculated_value_get(void){
	
	uint32_t calculated_value = 0;

	uint8_t poly = CRC_CRCCR0 & CRC_CRCCR0_GPS;
	switch (poly)
	{
	case CRC_CRCCR0_GPS_CRC_8:
		calculated_value = (CRC_CRCDOR >> 24) & 0xFF;
	break;
	case CRC_CRCCR0_GPS_CRC_16:
	case CRC_CRCCR0_GPS_CRC_CCITT:
		calculated_value = (CRC_CRCDOR >> 16) & 0xFFFF;
	break;
	
	default:	
		calculated_value = CRC_CRCDOR;
	break;
	}

	return calculated_value;
}

void crc_reset(void)
{
	CRC_CRCCR0 |= CRC_CRCCR0_DORCLR;
}

uint32_t crc_calculate(uint32_t data)
{
	uint8_t poly = CRC_CRCCR0 & CRC_CRCCR0_GPS;

	switch (poly)
	{
	case CRC_CRCCR0_GPS_CRC_8:
	case CRC_CRCCR0_GPS_CRC_16:
	case CRC_CRCCR0_GPS_CRC_CCITT:
		CRC_CRCDIR = ((data << 24) & 0xFF000000);
	break;
	
	default:
		CRC_CRCDIR = data;
	}

	return CRC_CRCDOR;
}

uint32_t crc_calculate_block(uint32_t *datap, uint32_t size)
{
	uint32_t i;
	uint8_t poly = CRC_CRCCR0 & CRC_CRCCR0_GPS;
	switch (poly)
	{
	case CRC_CRCCR0_GPS_CRC_8:
	case CRC_CRCCR0_GPS_CRC_16:
	case CRC_CRCCR0_GPS_CRC_CCITT:
		for (i = 0; i < size; i++) {
			CRC_CRCDIR = ((datap[i] << 24) & 0xFF000000);
		}	
	break;
	
	default:
		for (i = 0; i < size; i++) {
			CRC_CRCDIR = datap[i];
		}
		break;
	}



	return CRC_CRCDOR;
}

void crc_set_polynomial(uint8_t polynomial){
	
	uint8_t reg8 = CRC_CRCCR0;
	reg8 = (CRC_CRCCR0 & ~CRC_CRCCR0_GPS) | polynomial;
	CRC_CRCCR0 = reg8;
}