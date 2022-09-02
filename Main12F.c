/*
 * File:   Main12F.c
 * Author: mario
 *
 * Created on 1 de septiembre de 2022, 09:12 PM
 */


#include <xc.h>
#define _XTAL_FREQ 4000000

// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // GP3/MCLR pin function select (GP3/MCLR pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)


// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// Pines del DHT
#define DATA_DIR TRISIO5
#define DATA_IN GP5             
#define DATA_OUT GPIO5

#define LED_CPU GPIO2



void __interrupt () ISR (void); //Interrupción 

void main(void) {
    
    ANSEL = 0x00; //Habilitar todos los pines Analogos como digitales
    
    TRISIO1 = 0;
    TRISIO2 = 0;
    TRISIO4 = 0;
    GPIO0 = 0;
    GPIO1 = 0;
    GPIO2 = 0;
    GPIO4 = 0;
    GPIO4=1;
    
    
    WPU=0;
    /*Configuración del Timer*/
    OPTION_REG=0xC7;
    T0IF=0;
    TMR0=0;
    /*Configuración de la interrupción*/
    
    T0IE=1;
    //PEIE=1;
    GIE=1;
    DATA_DIR=1;
    __delay_ms(1000);
    GPIO4=0;
    while(1){
        
        //GPIO4=0;
        //__delay_ms(21);//18ms Reales
        //GPIO4=1;
        //__delay_ms(21);
//        GPIO4=0;
//        __delay_ms(46); // 40ms Reales
//        GPIO4=1;
//        __delay_ms(46);
        
        //GPIO4=0;
        //__delay_ms(92);//80ms Reales
        //GPIO4=1;
        //__delay_ms(92);
        
//        GPIO4=0;
//        __delay_us(12);//13us Reales
//        GPIO4=1;
//        __delay_us(12);
        
//        GPIO4=0;
//            __delay_us(22);//22us Reales
//            GPIO4=1;
//            __delay_us(22);
        if(DATA_IN==1){
            GPIO4=1;
        }
        else{
            GPIO4=0;
        }
        
        
    }
}

void __interrupt () ISR (void){ //Interrupción 
    if(T0IF==1){
            T0IF=0;
            LED_CPU=LED_CPU^ 1; // Conmutar PinC13 LED CPU
        }
}
