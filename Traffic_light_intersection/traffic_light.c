/*
 * PROJECT: C Code for Project Execution in MPLAB using the PIC Microcontroller
 * File:   traffic_light.c
 * Author: Emmanuel Aboah Boateng
 * Created on October 12, 2018, 9:59 PM
 */

#include <p24FJ64GB002.h>

_CONFIG1(JTAGEN_OFF & GCP_OFF & GWRP_OFF & ICS_PGx1 & FWDTEN_OFF & WINDIS_OFF & FWPSA_PR32 & WDTPS_PS8192)
_CONFIG3(WPFP_WPFP0 & SOSCSEL_IO & WUTSEL_FST & WPDIS_WPDIS & WPCFG_WPCFGDIS & WPEND_WPENDMEM)
_CONFIG2(IESO_OFF & FNOSC_FRCPLL & OSCIOFNC_OFF & POSCMOD_NONE & PLL96MHZ_ON & PLLDIV_DIV2 & FCKSM_CSECME & IOL1WAY_OFF)
_CONFIG4(DSWDTPS_DSWDTPS3 & DSWDTOSC_LPRC & RTCOSC_LPRC & DSBOREN_OFF & DSWDTEN_OFF)

#define M_Delay 65000
#define S_Delay 55000
#define Y_Delay 45000
#define OM_Delay 50000
#define OS_Delay 3000
#define OY_Delay 25000
#define State_1 0x208C
#define Y_State_1 0x2092
#define State_2 0x20A1
#define Y_State_2 0x2111
#define State_3 0x2209
#define Y_State_3 0x4109
#define State_4 0x8089
#define Y_State_4 0x408A

#include "xc.h"

int main(int argc, char** argv) {
    TRISB = 0x000;
    T1CON = 0x8030;

    while (1) {
        for (int k = 0; k < 20; k++) {
            LATB = State_1;
            TMR1 = 0;
            while (TMR1 < OM_Delay) {}
            LATB = Y_State_1;
            TMR1 = 0;
            while (TMR1 < OY_Delay) {}

            LATB = State_2;
            TMR1 = 0;
            while (TMR1 < OS_Delay) {}
            LATB = Y_State_2;
            TMR1 = 0;
            while (TMR1 < OY_Delay) {}

            LATB = State_3;
            TMR1 = 0;
            while (TMR1 < OM_Delay) {}
            LATB = Y_State_3;
            TMR1 = 0;
            while (TMR1 < OY_Delay) {}

            LATB = State_4;
            TMR1 = 0;
            while (TMR1 < OS_Delay) {}
            LATB = Y_State_4;
            TMR1 = 0;
            while (TMR1 < OY_Delay) {}
        }

        for (int k = 0; k < 40; k++) {
            LATB = State_1;
            TMR1 = 0;
            while (TMR1 < M_Delay) {}
            LATB = Y_State_1;
            TMR1 = 0;
            while (TMR1 < Y_Delay) {}

            LATB = State_2;
            TMR1 = 0;
            while (TMR1 < S_Delay) {}
            LATB = Y_State_2;
            TMR1 = 0
              while (TMR1 < Y_Delay) {}

        LATB = State_3;
        TMR1 = 0;
        while (TMR1 < M_Delay) {}
        LATB = Y_State_3;
        TMR1 = 0;
        while (TMR1 < Y_Delay) {}

        LATB = State_4;
        TMR1 = 0;
        while (TMR1 < S_Delay) {}
        LATB = Y_State_4;
        TMR1 = 0;
        while (TMR1 < Y_Delay) {}
    }
}

return 0;
