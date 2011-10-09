#ifndef MEMMAP_H
#define MEMMAP_H

#define ROMBOT 0x00000000
#define ROMTOP 0x00020000

#define RAMBOT 0x20000000
#define RAMTOP 0x20040000

#define REDLED 0x40001000
#define GRNLED 0x40001004
#define BLULED 0x40001008

#define POLL_UART_STATUS 0x40004100
#define POLL_UART_RSTBIT 0
#define POLL_UART_RXBIT  1
#define POLL_UART_TXBIT  2
#define POLL_UART_RXDATA 0x40004104
#define POLL_UART_TXDATA 0x40004108

#endif // MEMMAP_H