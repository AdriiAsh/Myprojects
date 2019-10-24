///////////////////////////////////////////////////////////////////
//Student ID No.:81600115
//Date:13/10/2019
///////////////////////////////////////////////////////////////////
#include <p18cxxx.h>
#include    "FreeRTOS.h"
#include 	"task.h"
#include    <timers.h>
#include <delays.h>
#include    <xlcd.h>
#include    <p18f452.h>

//#include "includes.h"


/*  Write the appropriate code to set configuration bits:
* - set HS oscillator
* - disable watchdog timer
* - disable low voltage programming
*/
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

/* Write LCD delay functions */
int a = 0 ; 
void DelayFor18TCY( void )
{
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop(); 
 Nop(); 
 Nop();
 Nop();
 Nop(); 
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
}

void DelayPORXLCD (void)
{
      Delay1KTCYx(5) ;
      return ; 
  /* Create a delay of 15 ms  */
}

void DelayXLCD (void)
{
    Delay1KTCYx(15) ;
    return ; 
  /* Create a delay of 5 ms  */  
}


void ICDconfig() 
{

    OpenXLCD (FOUR_BIT & LINE_5X7 ) ; 
 //   while BusyXLCD()) ;     
}

/* Write the appropriate code to do the following:
* Configure PORTB pin 1 as an output
* TaskA will loop until the global variable stopped is set.
* Within the loop -- print string "Task 1 rocks! \n" to LCD top row
*                 -- toggle PORTB pin 1
*                 -- delay for 1 second using vTaskDelay()
* TaskA will delete itself if the loop is exited.
*/


void TaskA(void *pdata)
{
    TRISBbits.RB1 = 0 ;
    PORTBbits.RB1 = 0  ;
    PORTBbits.RB1 = 1  ; 
  
     while(BusyXLCD())  ;
    SetDDRamAddr(0x23) ; 
     while(BusyXLCD())  ;
      WriteCmdXLCD(SHIFT_DISP_RIGHT) ;
  //  while(BusyXLCD())  ; 
    //   SetDDRamAddr(0x23) ;
    while(BusyXLCD()) ; 
    putrsXLCD("AAAAAAAAAAAAAAAAHHHHH") ; 
    vTaskDelay(1000)  ;  //vTaskDelay( pdMS_TO_TICKS( 20 )) MY EDIT!!!
    if (a != 0)  ;
    {
        vTaskDelete(NULL) ; 
    }
}

/* Write the appropriate code to do the following:
* Configuee PORTB pin 2 as an output
* TaskB will loop until the global variable stopped is set.
* Within the loop -- print string "Task 2 rules?\n" to LCD bottom row
*                 -- toggle PORTB pin 2
*                 -- delay of 200 ms using vTaskDelay(), specifying the time in ms instead of ticks
* TaskB will delete itself if the loop is exited.
*/
void TaskB(void *pdata)
{
    TRISBbits.RB2 = 0 ;
    PORTBbits.RB2 = 0  ;
    PORTBbits.RB2 = 1  ; 
    
     while(BusyXLCD())  ;
     SetDDRamAddr(0x01) ; 
     while(BusyXLCD())  ;
     WriteCmdXLCD(SHIFT_DISP_RIGHT) ;
 
    while(BusyXLCD())
    putrsXLCD("BBBBBBBBBBBBBBBBBB") ; 
    vTaskDelay(200) ; //vTaskDelay( pdMS_TO_TICKS( 20 )) MY EDIT!!!  
    //a=2 ;
    if (a != 0)  ;
    {
        vTaskDelete(NULL) ; 
    }
}

void vSerialTxISR (void)
{
    
}

void main (void)
{
     INTCONbits.GIE = 0;  // Write the appropriate code to disable all interrupts 
	
   xTaskCreate(TaskA,"TaskA", configMINIMAL_STACK_SIZE,NULL,1,NULL) ; 
   xTaskCreate(TaskB,"TaskB",configMINIMAL_STACK_SIZE,NULL,1,NULL) ; 
     // Write code to create tasks A and B


  /* Write the appropriate code to define the priorities for taskA
  *   and taskB in "FreeRTOSConfig.h". Use these defines to assign priorities 
  *   when creating taskA and taskB with xTaskCreate()
  */

  // Initialise the LCD display
     ICDconfig() ;
   
  // Write the appropriate code to start FreeRTOS kernel
	vTaskStartScheduler();
  
   while(1) ;
}
