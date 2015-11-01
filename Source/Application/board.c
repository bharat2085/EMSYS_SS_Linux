/*****************************************************************************
*
*  board.c
*
*
*  Date : 19/06/2014
*  First Modified : 19/06/2014
*  Last Modified: 13/09/2014
*
* TODO: will be set later as required.
*****************************************************************************/

#include <msp430.h>
#include "wlan.h" 
#include "evnt_handler.h"    // callback function declaration
#include "nvmem.h"
//#include "socket.h"

#include "netapp.h"
#include "board.h"
#include "basic.h"

/*#define FRAM_FORCED_RES_ADDRESS       0x1840
//unsigned char * msp430_forced_restart_ptr = (unsigned char *)FRAM_FORCED_RES_ADDRESS;
 */

uint8 configurePins_4_Wlan();
uint8 wifi_SPI_gpio_init_Done;

//*****************************************************************************
//		CONFIGURE GPIOs.
//
//
//ONLY  Outputs need to be defined explicitly ,
//all other are  Inputs(by default).
 //
//
//****************************************************************************/
void gpio_init()
{
	uint8 ret;

	ret=configurePins_4_Wlan();
	if(ret==0)
		 wifi_SPI_gpio_init_Done=1;


	initLEDs();


	__delay_cycles(12000000);

	//
	//CONFIGURATION FOR  MSB(MAIN SWITCH BOARD)
	//
	//PORT P1 USED AS MSB LOGIC INPUTS
	//PORT P2 USED AS MSB LOGIC OUTPUTS.

	// DEFINE ALL MSB LOGIC OUTPUTS .
	//P2DIR |= BIT0 |BIT5 |BIT6 |BIT1|BIT2;				//SET AS OUTPUT
	//P2OUT &= ~BIT0& ~BIT5 & ~BIT6 & ~BIT1 & ~BIT2;			// RESET AS DEFAULT



}


void misc_init_r()
{
	// TODO : add appropriate implementation.


	/*
	////CLEAR All SPURIOUS INTERRUPT
	//while(P3IFG) P3IFG=0;

	//CONFIGURATION FOR ZCD INTERRUPT INPUT.
	////P1REN |= BIT4;					//ENABLE INTERNAL PULLUP/PULLDOWN
	///P1OUT |= BIT4;					//PULLUP TO VCC

	// ENABLE INTERRUPT ON  MSB LOGIC INPUTS  (Port P1).
	//P1IE  |=BIT0+BIT1+BIT2+BIT3+BIT4+BIT5;  //ENABLE INTERRUPT FROM P1.0 TO P1.5

	P2REN |=BIT0;//
	P2OUT |=BIT0;
	//P3OUT |=BIT2;//
	P3REN |=BIT2;//
	P3OUT |=BIT2;//
	P3IE  |=BIT2;

	//CONFIGURE P1.5 AS ZCD INPUT INTERRUPT.
	//P3IES |=BIT0;					// Edge selection: 1 for setting high to low.

	//CLEAR ANY SPURIOUS INTERRUPT ON PORT1
	//P1IFG &= ~BIT5;
	while(P3IFG) P3IFG=0;

	//Enable_Interrupts();

	 */
}


void
misc_init_s()
{
	// TODO : add appropriate implementation.

	// Enable global Interrupt.
	    //__bis_SR_register(GIE);

}


/*****************************************************************************
//		initWlan()
 *
 * 1. Configure one spi port as communication bus for wlan.
 * 2. Configure a pin for wlan_chipset enable.
 *
 *
 *Note: PORT2_Vector has been assigned interrupt handler in spi.c . So we are not going to
 *Note: assign any interrupt on this port.
*********************************************************************************/
uint8
configurePins_4_Wlan()
{

//
	//
	// SPI for communication with wifi chip.
	//
	//PORT USED : ( SPI B0)



// Configure SPI IRQ line. (INPUT)					//Interrupt Vector PORT2_Vector has been be assigned handler in spi.c
	SPI_IRQ_PORT_DIR  &= (~SPI_IRQ_PIN);			//cleared , to be input .
	SPI_IRQ_PORT_SEL2 &= ~SPI_IRQ_PIN;				// cleared , so as no special function, just work as  io.
	SPI_IRQ_PORT_SEL &= ~SPI_IRQ_PIN;

	//as cc3000 has an interrupt request line , so we have configured a pin on microcontroller
	//even though nothing like spi irq exists in real.
	//MSP430  provides 3/4 pins for spi. mosi/miso(data) , clk ,  and STE( slave enable) which is defined as CS here.



// Configure the SPI CS /uc_STE. (OUTPUT)
   	SPI_CS_PORT_OUT |= SPI_CS_PIN;
	SPI_CS_PORT_DIR |= SPI_CS_PIN;
	SPI_CS_PORT_SEL2 &= ~SPI_CS_PIN;
	SPI_CS_PORT_SEL &= ~SPI_CS_PIN;

	//SPI CS	pin has been used in ASSERT_CS macro in spi.c


#ifdef INIT_SPI_NOT_DONE_IN_SPI_C

	//The data/clock pins has been already configured in init_spi() in Spi.c.
	//hence no need to be configured again here. however CS and Irq pins used directly there.
	// therefore configured here.

// Select the SPI MISO/MOSI functionality.( using PORT_Select register).
	MOSI_MISO_PORT_SEL |= (SPI_MISO_PIN + SPI_MOSI_PIN);
	MOSI_MISO_PORT_SEL2 &= (~(SPI_MISO_PIN + SPI_MOSI_PIN));

//Select SPI CLK functionality. using PORT_Select register.
	SPI_CLK_PORT_SEL |= (SPI_CLK_PIN);
	SPI_CLK_PORT_SEL2 &= ~SPI_CLK_PIN;

#endif

//
// CONFIGURE A  PIN FOR  WLAN ENA/DISABLE LINE.
//
	//CONFIGURE WLAN ENA PIN ( OUTPUT, LOW, GPIO)

		WLAN_EN_PORT_OUT &= ~WLAN_EN_PIN;
		WLAN_EN_PORT_DIR |= WLAN_EN_PIN;
		WLAN_EN_PORT_SEL2 &= ~WLAN_EN_PIN;
		WLAN_EN_PORT_SEL &= ~WLAN_EN_PIN;


		return 0;

	 }


//*****************************************************************************
//
//! WriteWlanPin
//!
//! \param  new val
//!
//! \return none
//
//				callback function for	wlan_en_pin  on/off.
//!
//! \brief    Enable/Disable wlan chip. by asserting the wlan_ena line.
//
//*****************************************************************************

void WriteWlanPin( unsigned char val )
{
    if (val)
    {
        P4OUT |= BIT1;			//Enable Wlan chip.
    }
    else
    {
        P4OUT &= ~BIT1;			//Disable wlan chip by removing wlan_ena signal.
    }
}



//*****************************************************************************
//
//! Enable wlan IRQ pin
//!
//! \param  none
//!
//! \return none
//!
//! \brief  callback  function to enable interrupt on cc3000 spi IRQ line. (P2.3 pin of uc)
//
//*****************************************************************************


void WlanInterruptEnable()
{
    __bis_SR_register(GIE);
    P2IES |= BIT3;
    P2IE |= BIT3;
}

//*****************************************************************************
//
//! Disable wlan IRQ pin
//!
//! \param  none
//!
//! \return none
//!
//! \brief  None
//
//*****************************************************************************


void WlanInterruptDisable()
{
    P2IE &= ~BIT3;
}


//*****************************************************************************
//
//! ReadWlanInterruptPin
//!
//! \param  none
//!
//! \return none
//!
//! \brief  return value on cc3000  wlan interrupt pin (p2.3)
//
//*****************************************************************************

long ReadWlanInterruptPin(void)
{
    return (P2IN & BIT3);
}


//*****************************************************************************
//
//! Initialize LEDs
//!
//! \param  none
//!
//! \return none
//!
//! \brief  Initializes LED Ports and Pins
//
//*****************************************************************************
void initLEDs()
{
    PJOUT &= ~(BIT0 + BIT1 + BIT2 + BIT3);
    P3OUT &= ~(BIT4 + BIT5 + BIT6 + BIT7);
    
    PJDIR |= (BIT0 + BIT1 + BIT2 + BIT3);
    P3DIR |= (BIT4 + BIT5 + BIT6 + BIT7);
}

//*****************************************************************************
//
//! Turn LED On
//!
//! \param  ledNum is the LED Number
//!
//! \return none
//!
//! \brief  Turns a specific LED Off
//
//*****************************************************************************
void turnLedOn(char ledNum)
{
    switch(ledNum)
    {
      case LED1:
        PJOUT |= (BIT0); 
        break;
      case LED2:
        PJOUT |= (BIT1); 
        break;
      case LED3:
        PJOUT |= (BIT2); 
        break;
      case LED4:
        PJOUT |= (BIT3);
        break;
      case LED5:
        P3OUT |= (BIT4);
        break;
      case LED6:
        P3OUT |= (BIT5);
        break;
      case LED7:
        P3OUT |= (BIT6);
        break;
      case LED8:
        P3OUT |= (BIT7);
        break;
    }
}

//*****************************************************************************
//
//! Turn LED Off
//!
//! \param  ledNum is the LED Number
//!
//! \return none
//!
//! \brief  Turns a specific LED Off
//
//*****************************************************************************    
void turnLedOff(char ledNum)
{                     
    switch(ledNum)
    {
      case LED1:
        PJOUT &= ~(BIT0); 
        break;
      case LED2:
        PJOUT &= ~(BIT1); 
        break;
      case LED3:
        PJOUT &= ~(BIT2); 
        break;
      case LED4:
        PJOUT &= ~(BIT3);
        break;
      case LED5:
        P3OUT &= ~(BIT4);
        break;
      case LED6:
        P3OUT &= ~(BIT5);
        break;
      case LED7:
        P3OUT &= ~(BIT6);
        break;
      case LED8:
        P3OUT &= ~(BIT7);
        break;
    }
}

//*****************************************************************************
//
//! toggleLed
//!
//! \param  ledNum is the LED Number
//!
//! \return none
//!
//! \brief  Toggles a board LED
//
//*****************************************************************************    

void toggleLed(char ledNum)
{
    switch(ledNum)
    {
      case LED1:
        PJOUT ^= (BIT0); 
        break;
      case LED2:
        PJOUT ^= (BIT1); 
        break;
      case LED3:
        PJOUT ^= (BIT2); 
        break;
      case LED4:
        PJOUT ^= (BIT3);
        break;
      case LED5:
        P3OUT ^= (BIT4);
        break;
      case LED6:
        P3OUT ^= (BIT5);
        break;
      case LED7:
        P3OUT ^= (BIT6);
        break;
      case LED8:
        P3OUT ^= (BIT7);
        break;
    }
}

//
//	Catch interrupt vectors that are not initialized.
//
//PORT2_Vector has already been used in spi.c. for cc3000 interrupt request line.
//Timer _Vector has already been used.

#pragma	 vector = WDT_VECTOR,TIMER1_A1_VECTOR,TIMER0_A0_VECTOR, ADC10_VECTOR, UNMI_VECTOR,COMP_D_VECTOR,DMA_VECTOR, PORT1_VECTOR, RTC_VECTOR, TIMER0_B0_VECTOR, TIMER1_B0_VECTOR, TIMER0_B1_VECTOR, TIMER1_B1_VECTOR, TIMER2_B0_VECTOR, TIMER2_B1_VECTOR,SYSNMI_VECTOR, USCI_A1_VECTOR, USCI_B0_VECTOR
__interrupt void Trap_ISR(void)
{
  while(1)
	  __no_operation();

}









//*****************************************************************************
//
//! unsolicicted_events_timer_init
//!
//!  \param  None
//!
//!  \return none
//!
//!  \brief  The function initializes the unsolicited events timer handler
//
//*****************************************************************************
void unsolicicted_events_timer_init(void)
{
    TA1CCTL0 &= ~CCIE;
    TA1CTL |= MC_0;

    // Configure teh timer for each 500 milli to handle un-solicited events
    TA1CCR0 = 0x4000;

    // run the timer from ACLCK, and enable interrupt of Timer A
    TA1CTL |= (TASSEL_1 + MC_1 + TACLR);

    TA1CCTL0 |= CCIE;
}


//*****************************************************************************
//
//! unsolicicted_events_timer_init
//!
//!  \param  None
//!
//!  \return none
//!
//!  \brief  The function initializes a CC3000 device and triggers it to start operation
//
//*****************************************************************************
void unsolicicted_events_timer_disable(void)
{
	TA1CCTL0 &= ~CCIE;
	TA1CTL |= MC_0;
}


// Timer A0 interrupt service routine
#pragma vector=TIMER1_A0_VECTOR
__interrupt void TIMER1_A0_ISR(void)
{
	__no_operation();

/*
 * //hci_unsolicited_event_handler();
	 * no need to call this handler for newer service packs(fw)of cc3000.
	 */

}



#ifdef BLACK_HOLE

//*****************************************************************************
//
//! \brief  Starts timer that handles switch debouncing
//!
//! \param  none
//!
//! \return none
//!
//
//*****************************************************************************
void StartDebounceTimer()
{
    // default delay = 0
    // Debounce time = 1500* 1/8000 = ~200ms
    TB0CCTL0 = CCIE;                          // TACCR0 interrupt enabled
    TB0CCR0 = 3000;
    TB0CTL = TBSSEL_1 + MC_1;                 // SMCLK, continuous mode
}

//*****************************************************************************
//
//! \brief  Stops timer that handles switch debouncing
//!
//! \param  none
//!
//! \return none
//!
//
//*****************************************************************************
void StopDebounceTimer()
{
    TB0CCTL0 &= ~CCIE;                          // TACCR0 interrupt enabled
}






//*****************************************************************************
//
//! \brief  check if FTC flag was set
//!
//! \param  none
//!
//! \return indication if flag is set
//!
//
//*****************************************************************************
long IsFTCflagSet()
{  

  return (P4OUT&BIT0) ;                                //  check if FTC flag is configure

}

//*****************************************************************************
//
//! \brief  set FTC flag when S2 was pressed
//!
//! \param  none
//!
//! \return none
//!
//
//*****************************************************************************
void SetFTCflag()
{  
   *ptrFtcAtStartup = FIRST_TIME_CONFIG_SET;                              //  set FTC flag  
}

//*****************************************************************************
//
//! \brief  clear FTC flag when S2 was pressed
//!
//! \param  none
//!
//! \return none
//!
//
//*****************************************************************************
void ClearFTCflag()
{  
  *ptrFtcAtStartup = 0xFF;                             //  clear FTC flag  
}

  
//*****************************************************************************
//
//! \brief  Dissable S2 switch interrupt
//!
//! \param  none
//!
//! \return none
//!
//
//*****************************************************************************
void DissableSwitch()
{  
            // disable switch interrupt
            
            
            P4IFG &= ~BIT0;                // Clear P4.0 IFG
            P4IE &= ~(BIT0);               // P4.0 interrupt disabled
            P4IFG &= ~BIT0;                // Clear P4.0 IFG

            
                P4IFG = 0;
}

//*****************************************************************************
//
//! \brief  Restore S2 switch interrupt
//!
//! \param  none
//!
//! \return none
//!
//
//*****************************************************************************
void RestoreSwitch()
{  
          
            
    // Restore Switch Interrupt
    P4IFG &= ~BIT0;                 // Clear P4.0 IFG
    P4IE |= BIT0;                   // P4.0 interrupt enabled
    P4IFG &= ~BIT0;                 // Clear P4.0 IFG

}

 //*****************************************************************************
//
//! \brief  Indication if the switch is still pressed
//!
//! \param  none
//!
//! \return none
//!
//
//*****************************************************************************
long switchIsPressed()
{  
          
if(!(P1IN & BIT3))
  return 1;
 
return 0;

}


#endif


void fatal()
{
/*#ifdef DEBUG_PRINT
  prints("\r FATAL ERROR  :\n");
#endif*/

  turnLedOn(SYSLED0);

//restart system,
  while(1)
__no_operation();
}


