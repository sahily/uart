# uart
Transmits and recieves data to/from PC using Universal Asynchronous Receiver and Transmitter (UART)

## Getting Started

### Requirements
* Keil IDE
* Flash Magic
* 8051 microcontroller
* PC
* RS232 to USB cable
* RS232 terminal for PC

### Installing
1. Connect PC to the 8051 microcontroller via RS232 to USB cable
1. Open Keil and create new project
   * Choose Philips P89V51RD2 database
1. Add uart.c file to Source Group
1. Build target
1. Use Flash Magic to write the resulting hex file to the 8051 microcontroller

### Example

Microcontroller initially sends the character "A" to the terminal on the PC. When we enter a value on the terminal to send it
to the microcontroller, the microcontroller will send the same value back to the PC.

## Authors

* **Sahil Mahajan**

## License

This project intentionally has no license.
