#include <libopencm3/ra/2l1/iwdg.h>

void iwdg_reset(){

    IWDT_RR = 0x00; 
    IWDT_RR = 0xFF;
}