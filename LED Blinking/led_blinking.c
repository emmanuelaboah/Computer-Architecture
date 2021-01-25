/*
 * File:   Led_blinking.c
 * Author: Emmanuel Aboah Boateng
 *
 * Created on November 15, 2018, 9:59 PM
 *
 * Implementation of Interrupt-driven Blinking using PIC24 uC
 * 
 */

// Include the header files of specific PIC microcontroller
#include<p24FJ64GB002.h>

// Configure the Outputs for the LED pins
#define LED1 (_LATB1)
#define LED2 (_LATB4)
void config_LEDsoutput(){
    CONFIG_RB1_AS_DIG_OUTPUT();
    CONFIG_RB4_AS_DIG_OUTPUT();
}


// Configure the Pushbutton Switch
void config_SW1() {
  CONFIG_RB13_AS_DIG_INPUT();
  ENABLE_RB13_PULLUP();
  DELAY_US(1); // Give the pullup some time to take effect.
  
  //Change Notification (CN) Interrupt Configuration
  void config_cn(void) {
  ENABLE_RB13_CN_INTERRUPT();


  // Clear the interrupt flag.
  _CNIF = 0;

  // Choose a priority.
  _CNIP = 2;

  // Enable the Change Notification general interrupt.
  _CNIE = 1;
 
// Define the time, in ms, between Timer2 interrupts.
#define ISR_PERIOD  (15)
void  configTimer2(void) {
  T2CON = T2_OFF | T2_IDLE_CON | T2_GATE_OFF
          | T2_32BIT_MODE_OFF
          | T2_SOURCE_INT
          | T2_PS_1_64;
  PR2 = msToU16Ticks(ISR_PERIOD, getTimerPrescale(T2CONbits)) - 1;
  TMR2  = 0;
  // Enable Timer2 interrupts.
  _T2IF = 0;
  _T2IP = 1;
  _T2IE = 1;
  // Start the timer only after all timer-related configuration is complete.
  T2CONbits.TON = 1;
}


// Interrupt Service Routine (ISR) for Timer2.
void _ISR _T2Interrupt(void) {
  // Toggle the output pin to generate a square wave.
  LED1 = !LED1;
  LED2 =! LED2;
  _T2IF = 0;
}


// Change notification ISR Configuration
void _ISR _CNInterrupt(void) {
  T2CONbits.TON=!T2CONbits.TON;
 _CNIF = 0;

}


int main (void) {
    configTimer2();
    config_LEDsoutput();
    config_SW1();
    Config_cn();

 // The interrupt does work of generating the square wave
  while (1) {
    doHeartbeat();		// Blink the heartbeat LED to show that the PIC is running.
  }

}
