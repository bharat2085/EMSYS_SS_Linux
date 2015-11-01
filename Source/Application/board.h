/*****************************************************************************
*
*  board.h -
*
*Last Modified : 13/09/2014
*****************************************************************************/

#ifndef BOARD_H
#define	BOARD_H

#include "basic.h"

typedef unsigned char   uint8;

#define SYSLED0 2	//Used for fatal error.
#define SYSLED1 1	//system running.
#define SYSLED2 3	//Cmd recvd.




//SPI CS P1.3								// must be same as used in spi.c ,in macro ASSERT_CS()
#define SPI_CS_PORT_OUT    P1OUT
#define SPI_CS_PORT_DIR    P1DIR
#define SPI_CS_PORT_SEL    P1SEL0
#define SPI_CS_PORT_SEL2   P1SEL1
#define SPI_CS_PIN         BIT3


//SPI IRQ P2.3								//must be same as in spi.h, used in pause_spi() in spi.c
#define SPI_IRQ_PORT_DIR   P2DIR
#define SPI_IRQ_PORT_SEL   P2SEL0
#define SPI_IRQ_PORT_SEL2  P2SEL1
#define SPI_IRQ_PIN        BIT3



#ifdef INIT_SPI_NOT_DONE_IN_SPI_C

// SPI  MISO_MOSI  P1.6 P1.7 					//must be same as in spi.h ,used in  init_spi() in spi.c
#define MOSI_MISO_PORT_SEL    P1SEL1
#define MOSI_MISO_PORT_SEL2   P1SEL0
#define SPI_MISO_PIN         BIT6
#define SPI_MOSI_PIN         BIT7

//SPI CLK  P2.2									//must be same as in  spi.h,  used in init_spi() in spi.c
#define SPI_CLK_PORT_SEL    P2SEL1
#define SPI_CLK_PORT_SEL2   P2SEL0
#define SPI_CLK_PIN         BIT2

#endif


//WLAN ENA/DIS LINE  P4.1
#define WLAN_EN_PORT_OUT   P4OUT
#define WLAN_EN_PORT_DIR   P4DIR
#define WLAN_EN_PORT_SEL   P4SEL0
#define WLAN_EN_PORT_SEL2  P4SEL1
#define WLAN_EN_PIN        BIT1


//UART
/*
#define UART1_PORT   P2SEL0
#define UART1_PIN    BIT0
#define UART2_PORT   P2SEL1
#define UART2_PIN    BIT1
*/


typedef enum
{
    NO_LED,
    LED1,
    LED2,
    LED3,
    LED4,
    LED5,
    LED6,
    LED7,
    LED8
} ledEnum;

typedef enum
{ //TODO : Need to be changed as per the our app.
    NO_LED_IND = NO_LED,
    CC3000_ON_IND = LED1,
    CC3000_ASSOCIATED_IND = LED2,
    CC3000_IP_ALLOC_IND = LED3,
    CC3000_SERVER_INIT_IND = LED4,
    CC3000_CLIENT_CONNECTED_IND = LED5,
    CC3000_SENDING_DATA_IND = LED6,
    CC3000_UNUSED1_IND = LED7,
    CC3000_FTC_IND = LED8,
} ledNames;



extern void gpio_init();

extern  uint8 wifi_SPI_gpio_init_Done;
extern void misc_init_r();
extern   void misc_init_s();


void initLEDs();

long ReadWlanInterruptPin(void);
void WlanInterruptEnable();
void WlanInterruptDisable();
void WriteWlanPin( unsigned char val );


void turnLedOn(char ledNum);
void turnLedOff(char ledNum);
void toggleLed(char ledNum);

void restartMSP430();
extern void fatal();

/*
long IsFTCflagSet();
void SetFTCflag();
void ClearFTCflag();
void RestoreSwitch();
long switchIsPressed();
*/
//void unsolicicted_events_timer_init(void);
//void unsolicicted_events_timer_disable(void);

//void DissableSwitch();
//void StartDebounceTimer();
//void StopDebounceTimer();

#endif
