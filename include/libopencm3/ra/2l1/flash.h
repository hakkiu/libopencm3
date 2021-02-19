
#ifndef LIBOPENCM3_FLASH_H
#define LIBOPENCM3_FLASH_H


#include <libopencm3/ra/memorymap.h>
#include <libopencm3/cm3/common.h>

#define FLASH_DFLCTL            MMIO8(FLCN_BASE + 0x0090)
#define FLASH_PFBER             MMIO8(FLCN_BASE + 0x3FC8)
#define FLASH_FENTRYR           MMIO16(FLCN_BASE + 0x3FB0)
#define FLASH_FPR               MMIO8(FLCN_BASE + 0x0180)
#define FLASH_FPSR              MMIO8(FLCN_BASE + 0x0184)
#define FLASH_FPMCR             MMIO8(FLCN_BASE + 0x0100)
#define FLASH_FISR              MMIO8(FLCN_BASE + 0x01D8)
#define FLASH_FRESETR           MMIO8(FLCN_BASE + 0x0124)
#define FLASH_FASR              MMIO8(FLCN_BASE + 0x0104)
#define FLASH_FCR               MMIO8(FLCN_BASE + 0x0114)
#define FLASH_FEXCR             MMIO8(FLCN_BASE + 0x01DC)
#define FLASH_FSARH             MMIO16(FLCN_BASE + 0x0110)
#define FLASH_FSARL             MMIO16(FLCN_BASE + 0x0108)
#define FLASH_FEARH             MMIO16(FLCN_BASE + 0x0120)
#define FLASH_FEARL             MMIO16(FLCN_BASE + 0x0118)
#define FLASH_FWBL0             MMIO16(FLCN_BASE + 0x0130)
#define FLASH_FWBH0             MMIO16(FLCN_BASE + 0x0138)
#define FLASH_FRBH0             MMIO16(FLCN_BASE + 0x0190)
#define FLASH_FSTATR00          MMIO16(FLCN_BASE + 0x0128)
#define FLASH_FSTATR2           MMIO16(FLCN_BASE + 0x01F0)
#define FLASH_FSTATR1           MMIO16(FLCN_BASE + 0x013C)
#define FLASH_FEAMH             MMIO16(FLCN_BASE + 0x01E8)
#define FLASH_FEAML             MMIO16(FLCN_BASE + 0x01E0)
#define FLASH_FSCMR             MMIO16(FLCN_BASE + 0x01C0)
#define FLASH_FAWSMR            MMIO16(FLCN_BASE + 0x01C8)
#define FLASH_FAWEMR            MMIO16(FLCN_BASE + 0x01D0)

BEGIN_DECLS

void flash_wait_for_last_operation(void);
void flash_lock(void);
void flash_unlock(void);
void flash_unlock_option_bytes(void);
uint32_t flash_get_status_flags(void);
void flash_program_word(uint32_t address, uint32_t data);
void flash_program_half_word(uint32_t address, uint16_t data);
void flash_erase_page(uint32_t page_address);
void flash_erase_all_pages(void);
void flash_erase_option_bytes(void);
void flash_program_option_bytes(uint32_t address, uint16_t data);


END_DECLS

#endif