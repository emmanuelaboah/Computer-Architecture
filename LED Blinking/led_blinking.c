/*
 * File:   Led_blinking.c
 * Author: Emmanuel Aboah Boateng
 *
 * Created on November 15, 2018, 9:59 PM
 *
 * Implementation of Interrupt-driven Blinking using PIC24 uC
 * 
 */

#include <p24FJ64GB002.h>

#define LED1 (_LATB1)
#define LED2 (_LATB4)

#define ISR_PERIOD (15)

void config_LEDsoutput() {
    CONFIG_RB1_AS_DIG_OUTPUT();
    CONFIG_RB4_AS_DIG_OUTPUT();
}

void config_SW1() {
    CONFIG_RB13_AS_DIG_INPUT();
    ENABLE_RB13_PULLUP();
    DELAY_US(1);
}

void config_cn() {
    ENABLE_RB13_CN_INTERRUPT();

    _CNIF = 0;
    _CNIP = 2;
    _CNIE = 1;
}

void configTimer2() {
    T2CON = T2_OFF | T2_IDLE_CON | T2_GATE_OFF
          | T2_32BIT_MODE_OFF
          | T2_SOURCE_INT
          | T2_PS_1_64;
    PR2 = msToU16Ticks(ISR_PERIOD, getTimerPrescale(T2CONbits)) - 1;
    TMR2  = 0;

    _T2IF = 0;
    _T2IP = 1;
    _T2IE = 1;

    T2CONbits.TON = 1;
}

void _ISR _T2Interrupt() {
    LED1 = !LED1;
    LED2 = !LED2;
    _T2IF = 0;
}

void _ISR _CNInterrupt() {
    T2CONbits.TON = !T2CONbits.TON;
    _CNIF = 0;
}

int main() {
    configTimer2();
    config_LEDsoutput();
    config_SW1();
    config_cn();

    while (1) {
        doHeartbeat(); // Blink the heartbeat LED to show that the PIC is running.
    }

    return 0;
}
