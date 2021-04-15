#include <libopencm3/ra/2l1/sysc.h>
#include <libopencm3/ra/2l1/flash.h>
void clock_init(void)
{
    /*HOCO osilasyon frekansı flashda belirlenecek */
    SYSC_PRCR = (SYSC_PRCR_PRKEY | SYSC_PRCR_PRC0 | SYSC_PRCR_PRC1); // Unlock  protection
    
    FLASH_PFBER = 0;

    SYSC_SOSCCR = SYSC_SOSCCR_SOSTP;

    while ((SYSC_SOPCCR & SYSC_SOPCCR_SOPCMTSF));
    SYSC_SOPCCR = 0x0; 
    while ((SYSC_SOPCCR != 0));

    if(SYSC_HOCOCR == 0){
        while (!(SYSC_OSCSF & SYSC_OSCSF_HOCOSF));
    }
   
    while ((SYSC_OPCCR & SYSC_OPCCR_OPCMTSF));
    SYSC_OPCCR = 0x0;
    while ((SYSC_OPCCR & SYSC_OPCCR_OPCMTSF));

    SYSC_HOCOCR = ~SYSC_HOCOCR_HCSTP;
    while (!(SYSC_OSCSF & SYSC_OSCSF_HOCOSF));

    SYSC_MEMWAIT = SYSC_MEMWAIT_MEMWAIT;
    MMIO32(FLCN_BASE + 0x3FC4) = 0x1;

    SYSC_SCKSCR = SYSC_SCKSCR_CKSEL_HOCO;
    SYSC_SCKDIVCR = ((SYSC_SCKDIVCR_DIV1 & 0x7) << 0) | ((SYSC_SCKDIVCR_DIV2 & 0x7) << 8) | ((SYSC_SCKDIVCR_DIV1 & 0x7) << 24);

    uint8_t ckocr =  (0x2 << 4);
    SYSC_CKOCR = ckocr;
    ckocr          |= (1 << 7);
    SYSC_CKOCR = ckocr;

    SYSC_PRCR = (SYSC_PRCR_PRKEY & ~(SYSC_PRCR_PRC0 | SYSC_PRCR_PRC1));

    FLASH_PFBER = 1;

}