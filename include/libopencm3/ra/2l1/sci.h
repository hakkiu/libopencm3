
#ifndef LIBOPENCM3_SCI_H
#define LIBOPENCM3_SCI_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/ra/memorymap.h>



#define SCI_RDR(sci_base)           MMIO8((sci_base) + 0x05)
#define SCI_RDRHL(sci_base)         MMIO16((sci_base) + 0x10)
#define SCI_FRDRHL                  MMIO16(SCI0_BASE + 0x10)
#define SCI_TDR(sci_base)           MMIO8((sci_base) + 0x03)
#define SCI_TDRHL(sci_base)         MMIO16((sci_base) + 0x0E)
#define SCI_FTDRHL                  MMIO16(SCI0_BASE + 0x1E)
#define SCI_SMR(sci_base)           MMIO8((sci_base) + 0x00)
#define SCI_BRR(sci_base)           MMIO8((sci_base) + 0x01)
#define SCI_SCR(sci_base)           MMIO8((sci_base) + 0x02)
#define SCI_SSR(sci_base)           MMIO8((sci_base) + 0x04)
#define SCI_SCMR(sci_base)          MMIO8((sci_base) + 0x06)
#define SCI_MDDR(sci_base)          MMIO8((sci_base) + 0x12)
#define SCI_SEMR(sci_base)          MMIO8((sci_base) + 0x07)
#define SCI_CDR(sci_base)           MMIO16((sci_base) + 0x1A)
#define SCI_DCCR(sci_base)          MMIO16((sci_base) + 0x13)
#define SCI_SPTR(sci_base)          MMIO8((sci_base) + 0x1C)

/*********SEMR*******/

#define SCI_SEMR_BRME               (1 << 2)
#define SCI_SEMR_ABCSE              (1 << 3)
#define SCI_SEMR_ABCS               (1 << 4)
#define SCI_SEMR_BDGM               (1 << 5)
#define SCI_SEMR_RXDESEL            (1 << 6)
#define SCI_SEMR_NFEN               (1 << 7)

#define SCI_SMR_CKS         (3 << 0)

#define SCI_SMR_MP           (1 << 2)
#define SCI_SMR_STOP         (1 << 3)
#define SCI_SMR_PM           (1 << 4)
#define SCI_SMR_PE           (1 << 5)
#define SCI_SMR_CHR          (1 << 6)
#define SCI_SMR_CM           (1 << 7)

#define SCI_SCR_CKE          (3 << 0)
#define SCI_SCR_TEIE         (1 << 2)
#define SCI_SCR_MPIE         (1 << 3)
#define SCI_SCR_RE           (1 << 4)
#define SCI_SCR_TE           (1 << 5)
#define SCI_SCR_RIE          (1 << 6)
#define SCI_SCR_TIE          (1 << 7)

#define SCI_SSR_MPBT         (1 << 0)
#define SCI_SSR_MPB          (1 << 1)
#define SCI_SSR_TEND         (1 << 2)
#define SCI_SSR_PER          (1 << 3)
#define SCI_SSR_FER          (1 << 4)
#define SCI_SSR_ORER         (1 << 5)
#define SCI_SSR_RDRF         (1 << 6)
#define SCI_SSR_TDRE         (1 << 7)



#define USART_PARITY_NONE		0x00
#define USART_PARITY_EVEN		SCI_SMR_PE
#define USART_PARITY_ODD		(SCI_SMR_PM | SCI_SMR_PE)
/**@}*/
#define SCI_PARITY_MASK		(SCI_SMR_PM | SCI_SMR_PE)

#define USART_MODE_RX               SCI_SCR_RE
#define USART_MODE_TX		        SCI_SCR_TE
#define USART_MODE_TX_RX		(SCI_SCR_TE | SCI_SCR_RE)
/**@}*/
#define SCI_MODE_MASK		        (SCI_SCR_TE | SCI_SCR_RE)

BEGIN_DECLS

void usart_set_baudrate(uint32_t usart, uint32_t baud);
void usart_set_databits(uint32_t usart, uint32_t bits);
void usart_set_stopbits(uint32_t usart, uint8_t stopbits);
void usart_set_parity(uint32_t usart, uint8_t parity);
void usart_set_mode(uint32_t usart, uint8_t mode);
void usart_set_flow_control(uint32_t usart, uint32_t flowcontrol);
void usart_enable(uint32_t usart);
void usart_disable(uint32_t usart);
void usart_send(uint32_t usart, uint16_t data);
uint16_t usart_recv(uint32_t usart);
void usart_wait_send_ready(uint32_t usart);
void usart_wait_recv_ready(uint32_t usart);
void usart_send_blocking(uint32_t usart, uint16_t data);
uint16_t usart_recv_blocking(uint32_t usart);
void usart_enable_rx_dma(uint32_t usart);
void usart_disable_rx_dma(uint32_t usart);
void usart_enable_tx_dma(uint32_t usart);
void usart_disable_tx_dma(uint32_t usart);
void usart_enable_rx_interrupt(uint32_t usart);
void usart_disable_rx_interrupt(uint32_t usart);
void usart_enable_tx_interrupt(uint32_t usart);
void usart_disable_tx_interrupt(uint32_t usart);
void usart_enable_error_interrupt(uint32_t usart);
void usart_disable_error_interrupt(uint32_t usart);
bool usart_get_flag(uint32_t usart, uint32_t flag);


END_DECLS

#endif