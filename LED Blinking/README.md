## Project Overview
This is a project report on the implementation of the blinking of two LEDs with a switch and connected to a PIC24 microcontroller. 
A scenario for the description of the project was such that, the two LEDs namely; LED1 and LED2 were designed to be initially blinking, and whenever the switch (SW1) is pressed and released, the two LEDS are supposed to alternate between terminating the blinking and resuming the blinking [1]. 

There are two major approaches to the solution of the problem elaborated above, which are as follows;
```
1.	The use of Polled I/O instructions for switching within a while (1) loop with two states for each press and release action.
2.	The use of Periodic Interrupt and change notification interrupt for sampling the switch input (SW1).

```


