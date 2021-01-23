## Project Overview
This is a project report on the implementation of the blinking of two LEDs with a switch and connected to a PIC24 microcontroller. 
A scenario for the description of the project was such that, the two LEDs namely; LED1 and LED2 were designed to be initially blinking, and whenever the switch (SW1) is pressed and released, the two LEDS are supposed to alternate between terminating the blinking and resuming the blinking [1]. 

There are two major approaches to the solution of the problem elaborated above, which are as follows;
```
1. The use of Polled I/O instructions for switching within a while (1) loop with two states for each press and release action.
2. The use of Periodic Interrupt and change notification interrupt for sampling the switch input (SW1).

```

The periodic interrupt approach was adopted in this project because 
it provides a more efficient way for solving the problem by making use of interrupts to reduce the CPU cycles and also 
conserve power by avoiding the polling of I/Os.

The hardware components connection to the PIC24 uC is depicted in the figure below:

![alt text](https://github.com/emmanuelaboah/Computer_Architecture/blob/master/LED%20Blinking/images/hardware_design.png)


The software implementation of the project is summarized in the flowchart below:

![alt text](https://github.com/emmanuelaboah/Computer_Architecture/blob/master/LED%20Blinking/images/flowchart.png)


