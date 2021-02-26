
#ifndef LIBOPENCM3_CRC_H
#define LIBOPENCM3_CRC_H

#include <libopencm3/ra/memorymap.h>
#include <libopencm3/cm3/common.h>

#define CRC_CRCCR0          MMIO8(CRC_BASE + 0x00)
#define CRC_CRCCR1          MMIO8(CRC_BASE + 0x01)
#define CRC_CRCDIR          MMIO32(CRC_BASE + 0x04)
#define CRC_CRCDOR          MMIO32(CRC_BASE + 0x08)
#define CRC_CRCSAR          MMIO32(CRC_BASE + 0x0C)


#define CRC_CRCCR0_GPS                  (7)
#define CRC_CRCCR0_GPS_CRC_8            0x01
#define CRC_CRCCR0_GPS_CRC_16           0x02
#define CRC_CRCCR0_GPS_CRC_CCITT        0x03
#define CRC_CRCCR0_GPS_CRC_32           0x04
#define CRC_CRCCR0_GPS_CRC_32C          0x05

#define CRC_CRCCR0_LMS                  (1 << 6)
#define CRC_CRCCR0_DORCLR               (1 << 7)

///////////
#define CRC_CRCCR1_CRCSWR               (1 << 6)
#define CRC_CRCCR1_CRCSEN               (1 << 7)



BEGIN_DECLS

void crc_reset(void);
uint32_t crc_calculate(uint32_t data);
uint32_t crc_calculate_block(uint32_t *data, uint32_t size);

void crc_set_polynomial(uint32_t polynomial);
void crc_set_initial(uint32_t initial);

END_DECLS


#endif