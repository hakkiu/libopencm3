#include <libopencm3/ra/2l1/flash.h>


#define FLASH_FSTATR1_DRRDY         (1 << 1)
#define FLASH_FSTATR1_FRDY          (1 << 6)
#define FLASH_FSTATR1_EXRDY         (1 << 7)

#define FLASH_FPR_UNLOCK            0xA5 

#define FLASH_FENTRYR_DATAFLASH_PE_MODE            (0xAA80U)
#define FLASH_FENTRYR_CODEFLASH_PE_MODE            (0xAA01U)
#define FLASH_FENTRYR_READ_MODE                    (0xAA00U)

#define FLASH_FPMCR_DATAFLASH_PE_MODE                    (0x10)
#define FLASH_FPMCR_READ_MODE                            (0x08)
#define FLASH_FPMCR_DISCHARGE_1                          (0x12)
#define FLASH_FPMCR_CODEFLASH_PE_MODE                    (0x02)

#define FLASH_CF_BLOCK_SIZE         (0x800) 
#define FLASH_DF_BLOCK_SIZE         (0x400)

#define FLASH_FSTATR2_ERERR             (1 << 0)
#define FLASH_FSTATR2_PRGERR            (1 << 1)
#define FLASH_FSTATR2_PRGERR01          (1 << 2)
#define FLASH_FSTATR2_BCERR             (1 << 3)
#define FLASH_FSTATR2_ILGLERR           (1 << 4)
#define FLASH_FSTATR2_EILGLERR          (1 << 5)

#define FLASH_FCR_WRITE                            (0x1)
#define FLASH_FCR_ERASE                            (0x4)
#define FLASH_FCR_CF_BLANKCHECK                    (0x3)
#define FLASH_FCR_CLEAR                            (0x0)

#define FLASH_FCR_OPST              (1 << 7)

void flash_wait_for_last_operation(void)
{
    while ((FLASH_FSTATR1 & FLASH_FSTATR1_FRDY) != FLASH_FSTATR1_FRDY);
}
void flash_lock(void)   // Code flash mode to read mode
{
    FLASH_FPR = FLASH_FPR_UNLOCK;

    FLASH_FPMCR = FLASH_FPMCR_READ_MODE
    FLASH_FPMCR = (uint8_t) ~FLASH_FPMCR_READ_MODE
    FLASH_FPMCR = FLASH_FPMCR_READ_MODE

    FLASH_FENTRYR = FLASH_FENTRYR_READ_MODE;

    while (FLASH_FENTRYR != 0);
    
}
void flash_unlock(void)     // Read mode to code flash 
{
    FLASH_FPR = FLASH_FPR_UNLOCK;

    FLASH_FENTRYR = FLASH_FENTRYR_CODEFLASH_PE_MODE;

    FLASH_FPMCR = FLASH_FPMCR_CODEFLASH_PE_MODE
    FLASH_FPMCR = (uint8_t) ~FLASH_FPMCR_CODEFLASH_PE_MODE
    FLASH_FPMCR = FLASH_FPMCR_CODEFLASH_PE_MODE

    /*should wait tDIS*/
}

void flash_program_word(uint32_t address, uint32_t data)
{
    FLASH_FSARH = (uint16_t)(address>>16);
    FLASH_FSARL = (uint16_t)(address);

    FLASH_FWBH0 = (uint16_t)(data>>16);
    FLASH_FWBL0 = (uint16_t)(data);

    FLASH_FCR = FLASH_FCR_WRITE | FLASH_FCR_OPST;

    flash_wait_for_last_operation();
    FLASH_FCR = FLASH_FCR_WRITE;
    FLASH_FCR = 0x0;
    while ((FLASH_FSTATR1 & FLASH_FSTATR1_FRDY) != ~FLASH_FSTATR1_FRDY);
}

void flash_erase_page(uint32_t page_address)
{

    uint32_t end_addr_idx = page_address + (FLASH_CF_BLOCK_SIZE - 1U);

    FLASH_FSARH = (uint16_t) ((start_addr >> 16));
    FLASH_FSARL = (uint16_t) (start_addr);

    FLASH_FEARH = ((end_addr_idx >> 16));
    FLASH_FEARL = (uint16_t) (end_addr_idx);
   
    FLASH_FCR = FLASH_FCR_ERASE | FLASH_FCR_OPST;

    flash_wait_for_last_operation();
    FLASH_FCR = FLASH_FCR_ERASE;
    FLASH_FCR = 0x0;

    while ((FLASH_FSTATR1 & FLASH_FSTATR1_FRDY) != ~FLASH_FSTATR1_FRDY);
}
void flash_set_clock_frequency(uint8_t freq_in_mhz)
{
    FLASH_FISR = (freq - 1) & 0x1F;
}
uint16_t flash_get_error_status()
{
    return (FLASH_FSTATR2 & 0x3F);
}
/*
uint32_t flash_get_status_flags(void){} // Kullanılmadı
void flash_program_half_word(uint32_t address, uint16_t data){}
void flash_unlock_option_bytes(void){}
void flash_erase_option_bytes(void){}
void flash_program_option_bytes(uint32_t address, uint16_t data){}
*/
