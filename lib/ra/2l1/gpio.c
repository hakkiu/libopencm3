#include <libopencm3/ra/gpio.h>

void gpio_set(uint32_t gpioport, uint16_t gpios){
    PORT_PCNTR3(gpioport) = gpios;
}
void gpio_clear(uint32_t gpioport, uint16_t gpios){
    PORT_PCNTR3(gpioport) = ( gpios << 16);
}
uint16_t gpio_get(uint32_t gpioport, uint16_t gpios){
    return (uint16_t)PORT_PCNTR2(gpioport) & gpios;
}

void gpio_mode_setup(uint32_t gpioport, uint8_t mode, uint8_t pull_up_down, uint16_t gpios){
    
    uint16_t i;
    uint32_t pmnfs;

    PORT_PWPR = (uint8_t) (~PORT_PWPR_BOWI | PORT_PWPR_PFSWE);
 /*   uint32_t moder, pupd;
	moder = GPIO_MODER(gpioport);
	pupd = GPIO_PUPDR(gpioport);

	for (i = 0; i < 16; i++) {
		if (!((1 << i) & gpios)) {
			continue;
		}

		moder &= ~GPIO_MODE_MASK(i);
		moder |= GPIO_MODE(i, mode);
		pupd &= ~GPIO_PUPD_MASK(i);
		pupd |= GPIO_PUPD(i, pull_up_down);
	}

	GPIO_MODER(gpioport) = moder;
	GPIO_PUPDR(gpioport) = pupd;
    */
    
    for (i = 0; i < 16; i++) {
        if (!((1 << i) & gpios)) {
            continue;
	    }
      //  pmnfs = PORT_PMNPFS(gpioport, i);
        switch (mode)
        {
        case GPIO_MODE_INPUT:
            pmnfs = PORT_PmnPFS_PDR | PORT_PmnPFS_PCR(0);
            break;
        case GPIO_MODE_OUTPUT:
            pmnfs = ~PORT_PmnPFS_PDR;
            break;
        case GPIO_MODE_ANALOG:
            pmnfs = (~PORT_PmnPFS_PMR | ~ PORT_PmnPFS_PCR(0) | ~PORT_PmnPFS_PDR | PORT_PmnPFS_ASEL );
            break;
        case GPIO_MODE_AF:
            pmnfs = ~PORT_PmnPFS_PMR;
            break;
        }

	    PORT_PMNPFS(gpioport, i) = pmnfs;

    }
}
void gpio_set_output_options(uint32_t gpioport, uint8_t otype, uint8_t speed, uint16_t gpios){

    uint8_t i;
    uint32_t pmnfs;

    for (i = 0; i < 16; i++) {
        if (!((1 << i) & gpios)) {
            continue;
	    }
        pmnfs = PORT_PMNPFS(gpioport, i);
        if(otype == 0x01){
            pmnfs |= PORT_PmnPFS_NCODR;
        }else{   
            pmnfs &= ~PORT_PmnPFS_NCODR;
        }
        PORT_PMNPFS(gpioport, i) = pmnfs;

    }


}
void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint16_t gpios){
    
    uint8_t i;
    uint32_t pmnfs;
    for (i = 0; i < 16; i++) {
        if (!((1 << i) & gpios)) {
            continue;
	    }
        pmnfs = PORT_PMNPFS(gpioport, i);
        pmnfs &= ~PORT_PmnFS_PSEL_Msk;
        pmnfs |= PORT_PmnPFS_PSEL(alt_func_num);
        PORT_PMNPFS(gpioport, i) = pmnfs;
        PORT_PMNPFS(gpioport, i) |= PORT_PmnPFS_PMR;
    }

}
