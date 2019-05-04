/*
 * uart.c
 *
 * Created: 5/3/2019 8:57:08 PM
 * Author : Sahil S. Mahajan
 * Description: Transmits and recieves data to/from PC using Universal Asynchronous Receiver and Transmitter (UART)
 *
 */

#include <REG51F.H>

void initializeUART(void);
void transmitter(unsigned char value);
unsigned char receiver(void);
void delay(unsigned int k);

unsigned char x;        //data transmitted or received


void main()
{
    initializeUART();
    x = 'A';
    while(1)
    {
        transmitter(x);
        delay(10);
        receiver();
        delay(10);
    }
}


/* -----------------
 * Function: initializeUART
 * -----------------
 *
 * Sets timer mode, configures timer to 9600 bps baud rate, and configures Serial Port Control Register
 *    for transmitting and receiving data to/from PC
 *
 */

void initializeUART(void)
{
    TMOD = 0x20;        //Use timer 1 in operating mode 2, 8 bit autoreload for serial communication
    TH1 = 0xFD;         //Calculated for 9600 bps baud rate: Baud rate = (F/12)*2^Smod/(32*(FF-XX+1))
    SCON = 0x52;        //Configure SCON, use mode 1, 8 bit variable baud rate, and set REN and TI in SCON
    TR1 = 1;            //Turn timer 1 on
}
                

/* -----------------
 * Function: transmitter
 * -----------------
 *
 * transmits data from microcontroller to PC
 *
 * value: data to be sent to PC
 *
 */

void transmitter(unsigned char value)
{
    while(TI == 0);         /* Wait for other data to finish transmitting     */
                            /* (TI is set when data is finished transmitting) */
    SBUF = value;           //SBUF sends data at specified baud rate
    TI = 0;                 
}


/* -----------------
 * Function: receiver
 * -----------------
 *
 * receives data from PC to microcontroller
 *
 * returns: data received from PC
 *
 */

unsigned char receiver(void)
{

    while(RI == 0);         /* Wait for other data to finish receiving     */
                            /* (RI is set when data is finished receiving) */
    x = SBUF;               //SBUF sends data to x at specified baud rate
    RI = 0;
    return(x);                  
}


/* -----------------
 * Function: delay
 * -----------------
 *
 * creates delay for a specificed number of milliseconds
 *
 * k: number of milliseconds (approximate)
 *
 */

void delay(unsigned int k)
{
   unsigned int i,j;
    
   for(i=0; i<k;i++)
   {
      for(j=0;j<120;j++); 
   }

}