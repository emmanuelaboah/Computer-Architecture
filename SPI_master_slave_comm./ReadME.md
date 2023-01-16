
## Project Overview 
In this project, two Microstick boards were connected together as master-slave using SPI communication.  
The first PCI board(master) sends a byte to the slave PIC. The slave PCI then changes a sequence of LEDs according to the recieved byte from the master.  
The connection parallel connection between the two Microstick PIC board is shown below:

![alt text](https://github.com/emmanuelaboah/Computer_Architecture/blob/master/SPI_master_slave_comm./spi.jpeg)

### Master PIC Microcontroller Program
Use interrupts to detect if an input is available at port C and write an interrupt service routine, to read the value from the input pins, and send that number to the slave over its SDO1 line, and wait for the acknowledgment that the slave has read the data.

### Slave PIC Microcontroller Program:
Read the values sent by the master on SDI1 pin of the slave. Send a signal of 111 to the master as an acknowledgement (using SDO1 pin of slave). Use one LED connected to the master PIC to show the acknowledgement.

Develop subroutines for (i) a binary up counter, and (ii) a binary down counter. Connect eight LEDs to appropriate available port pins of the slave board to show the sequence of counters. Implement 1 second delay between LED on and LED off during the sequences.
