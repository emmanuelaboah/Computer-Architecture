/*

* PROJECT: C Code for Project Execution in MPLAB using the PIC Microcontroller

* File:   traffic_light.c

* Author: Emmanuel Aboah Boateng
*
* Created on October 12, 2018, 9:59 PM

*/

// Include header files of the specific PIC microcontroller (p24FJ64GB002)
#include<p24FJ64GB002.h>

/* The following code is used to initialize the pins */
_CONFIG1(JTAGEN_OFF & GCP_OFF & GWRP_OFF & ICS_PGx1 & FWDTEN_OFF & WINDIS_OFF & FWPSA_PR32 & WDTPS_PS8192)
_CONFIG3(WPFP_WPFP0 & SOSCSEL_IO & WUTSEL_FST & WPDIS_WPDIS & WPCFG_WPCFGDIS & WPEND_WPENDMEM)
_CONFIG2(IESO_OFF & FNOSC_FRCPLL & OSCIOFNC_OFF & POSCMOD_NONE & PLL96MHZ_ON & PLLDIV_DIV2 & FCKSM_CSECME & IOL1WAY_OFF)
_CONFIG4(DSWDTPS_DSWDTPS3 & DSWDTOSC_LPRC & RTCOSC_LPRC & DSBOREN_OFF & DSWDTEN_OFF)


// Define delays of the various intersections
#define M_Delay 65000        // Main road delay on green for normal hours 
#define S_Delay 55000        // Small road delay on green for normal hours 
#define Y_Delay 45000        // Yellow light delay for normal hours 
#define OM_Delay 50000       // Main road delay on green for office hours 
#define OS_Delay 3000        // Small road delay on green for office hours 
#define OY_Delay 25000       // Yellow light delay on green for office hours 
#define State_1 0X208C       // Logic for state 1 
#define Y_State_1 0X2092     // Logic for yellow state 1 
#define State_2 0X20A1       // Logic for state 2 
#define Y_State_2 0X2111     // Logic for yellow state 2 
#define State_3 0X2209       // Logic for state 3 
#define Y_State_3 0X4109     // Logic for yellow state 3 
#define State_4 0X8089       // Logic for state 4 
#define Y_State_4 0X408A     // Logic for yellow state 4 
#include "xc.h"

// Main program
int main(int argc, char**argv)

{

TRISB = 0x000; T1CON = 0X8030; 
while (1) {

for (k = 0; a < 20  k++)       // repeat cycle for 20 sequence  for office period

{

LATB = State_1; TMR1 = 0;

while (TMR1<OM_Delay) {} LATB = OY_State_1;
TMR1 = 0;

while (TMR1<OY_Delay) {}

}

{  LATB = State_2; TMR1 = 0;
while (TMR1<OS_Delay) {} LATB = OY_State_2;
TMR1 = 0;

while (TMR1<OY_Delay) {}

}

{  LATB = State_3; TMR1 = 0;
while (TMR1<OM_Delay) {} LATB = OY_State_3;
TMR1 = 0;

while (TMR1<OY_Delay) {}

}

{ LATB = State_4; TMR1 = 0;
while (TMR1<OS_Delay) {} LATB = OY_State_4;
TMR1 = 0;

while (TMR1<OY_Delay) {}

}  end for

For (k = 0; a < 40 k++)        // repeat cycle for 40 sequences for normal running period
{ LATB = State_1; TMR1 = 0;
while (TMR1<M_Delay) {} LATB = Y_State_1;
TMR1 = 0;

while (TMR1<Y_Delay) {} 
}

{ LATB = State_2; TMR1 = 0;
while (TMR1<S_Delay) {} LATB = Y_State_2;
TMR1 = 0;

while (TMR1<Y_Delay) {}

}

{ LATB = State_3; TMR1 = 0;
while (TMR1<M_Delay) {} LATB = Y_State_3;
TMR1 = 0;

while (TMR1<Y_Delay) {}

}

{

LATB = State_4; TMR1 = 0;
while (TMR1<S_Delay) {} LATB = Y_State_4;
TMR1 = 0;

while (TMR1<Y_Delay) {}

}  end for

}

return 0;

}
