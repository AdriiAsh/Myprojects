///////////////////////////////////////////////////////////////////
//Student ID No.:81600115
//Date:13/10/2019
///////////////////////////////////////////////////////////////////
//#include <p18cxxx.h>
#include    "FreeRTOS.h"
#include 	"task.h"
#include    <timers.h>
#include    <xlcd.h>
//#include    <p18f452.h>
//#include "includes.h"


/*  Write the appropriate code to set configuration bits:
* - set HS oscillator
* - disable watchdog timer
* - disable low voltage programming
*/

/* Write LCD delay functions */
void DelayFor18TCY( void )
{
  /* Create a delay of 18 cycles  */
}

void DelayPORXLCD (void)
{
  /* Create a delay of 15 ms  */  
}

void DelayXLCD (void)
{
  /* Create a delay of 5 ms  */  
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
//  ... 
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
// ...
}

void vSerialTxISR (void)
{
    
}

void main (void)
{
  // Write the appropriate code to disable all interrupts 
	
  // Write code to create tasks A and B
	
  /* Write the appropriate code to define the priorities for taskA
  *   and taskB in "FreeRTOSConfig.h". Use these defines to assign priorities 
  *   when creating taskA and taskB with xTaskCreate()
  */

  // Initialise the LCD display
  // Write the appropriate code to start FreeRTOS kernel
}
