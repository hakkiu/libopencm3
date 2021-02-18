#include <libopencm3/ra/2l1/sci.h>

void usart_set_baudrate(uint32_t usart, uint32_t baud){
    uint32_t clock = 48000000; /// That will be extern
    uint8_t coeff = 64;
    uint8_t mode =  SCI_SMR(usart); 

    if(mode & SCI_SEMR_ABCSE){
         coeff = 12;
    }else if (mode & SCI_SEMR_BDGM || mode & SCI_SEMR_ABCS){
        coeff = 32;
    }else if (mode & (SCI_SEMR_BDGM || SCI_SEMR_ABCS)){
        coeff = 16;
    }

    SCI_BRR(usart) = ((clock * 1000000) / (coeff * (1 << (2 * (SCI_SMR(usart) & SCI_SMR_CKS) - 1 ))  * baud )) - 1;

}

void usart_set_databits(uint32_t usart, uint32_t bits){
   
    if (bits == 8) {
        SCI_SCMR(usart) |= SCI_SMR_CHR;
        SCI_SMR(usart) &= ~SCI_SMR_CHR;
    } else if(bits == 9) {
        SCI_SCMR(usart) &= ~SCI_SMR_CHR;
    } else {
        SCI_SCMR(usart) |= SCI_SMR_CHR;
        SCI_SMR(usart) |= SCI_SMR_CHR;
    }
}
void usart_set_stopbits(uint32_t usart, uint8_t stopbits){
    uint8_t reg8;

    reg8 = SCI_SMR(usart);
	reg8 = (reg8 & ~SCI_SMR_STOP) | stopbits;
	SCI_SMR(usart) = reg8;
}
void usart_set_parity(uint32_t usart, uint8_t parity){
    uint8_t reg8;

	reg8 = SCI_SMR(usart);
	reg8 = (reg8 & ~SCI_PARITY_MASK) | parity;
	SCI_SMR(usart) = reg8;
}

void usart_set_mode(uint32_t usart, uint8_t mode){
    uint8_t reg8;

	reg8 = SCI_SCR(usart);
	reg8 = (reg8 & ~SCI_MODE_MASK) | mode;
	SCI_SCR(usart) = reg8;
}
void usart_set_flow_control(uint32_t usart, uint32_t flowcontrol){
/*****Gerek yok******/
}
/*Module stop veya TE ve RE üzerinden yapılacak*/
void usart_enable(uint32_t usart){
    SCI_SCR(usart) |= (SCI_SCR_TE | SCI_SCR_RE);
}
void usart_disable(uint32_t usart){
    SCI_SCR(usart) &= ~(SCI_SCR_TE | SCI_SCR_RE);
} 
void usart_send(uint32_t usart, uint16_t data){
    
    if(!(SCI_SCMR(usart) & SCI_SMR_CHR)){   // 7 or 8 bits data
        SCI_TDR(usart) = (data & 0xFF);
    } else  {                               // 9 bits data
       SCI_TDRHL(usart) = (data & 0x1FF);
    }
    
}
void usart_wait_send_ready(uint32_t usart){
 	/* Wait until the data has been transferred into the shift register. */
	while ((SCI_SSR(usart) & SCI_SSR_TDRE) == 0);
}

void usart_send_blocking(uint32_t usart, uint16_t data){
    
    usart_wait_send_ready(usart);
    usart_send(usart, data);
}
/*void usart_enable_rx_dma(uint32_t usart); // DTC işlemlerinden sonra bak
void usart_disable_rx_dma(uint32_t usart);
void usart_enable_tx_dma(uint32_t usart);
void usart_disable_tx_dma(uint32_t usart);*/
void usart_enable_rx_interrupt(uint32_t usart){
    SCI_SCR(usart) |= SCI_SCR_RIE;
}
void usart_disable_rx_interrupt(uint32_t usart){
    SCI_SCR(usart) &= ~SCI_SCR_RIE;
}
void usart_enable_tx_interrupt(uint32_t usart){
    SCI_SCR(usart)  |= SCI_SCR_TIE;
}
void usart_disable_tx_interrupt(uint32_t usart){
    SCI_SCR(usart) &= ~SCI_SCR_TIE;
}