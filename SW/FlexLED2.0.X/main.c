/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F15324
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "FlexLed.h"

bool TMRFlag = 0;
uint8_t BlankTimer = 0U;

void main(void)
{
    SYSTEM_Initialize();
    __delay_us(100U);
    FlexLedInit();
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while (1){
        CLRWDT();        
        if(TMRFlag == 1){
            TMRFlag = 0; /*Clear timer flag*/
            FlexLedHandler();
        }
        else{
            /*Skip*/
        }
    }
}


//void LedHandler(void){    
////    __delay_us(100U);
////    LEDBuffer[(0*21U)+1U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////    LEDBuffer[(1*21U)+1U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////    LEDBuffer[(2*21U)+1U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////    LEDBuffer[(3*21U)+1U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////    LEDBuffer[(4*21U)+1U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////    LEDBuffer[(5*21U)+1U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////    LEDBuffer[(6*21U)+1U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////    LEDBuffer[(7*21U)+1U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////    LEDWrite();
//      
////    while(LEDRow <= 6){
////        LEDRow++;
////        for(uint8_t cc = 1U; cc < 8U; cc++){
////            LEDBuffer[(cc*21U)+15U] = 1;//HappyChristmasBuffer[LEDCol][LEDRow];
////        }
////            LEDWrite();
//////             __delay_ms(1U);
////        LEDRow++;
////        for(uint8_t cc = 1U; cc < 8U; cc++){
////            LEDBuffer[(cc*21U)+15U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////        }
////        LEDWrite();
////        LEDRow++;
////        for(uint8_t cc = 2U; cc < 6U; cc++){
////            LEDBuffer[(cc*21U)+14U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDBuffer[(cc*21U)+15U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDBuffer[(cc*21U)+16U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDBuffer[(cc*21U)+17U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDWrite();
////        }
////        LEDRow++;
////        for(uint8_t cc = 2U; cc < 6U; cc++){
////            LEDBuffer[(cc*21U)+14U] = 1;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDBuffer[(cc*21U)+15U] = 1;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDBuffer[(cc*21U)+16U] = 1;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDBuffer[(cc*21U)+17U] = 1;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDWrite();
////        }
////        LEDRow++;
////        for(uint8_t cc = 2U; cc < 6U; cc++){
////            LEDBuffer[(cc*21U)+14U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDBuffer[(cc*21U)+15U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDBuffer[(cc*21U)+16U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDBuffer[(cc*21U)+17U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDWrite();
////        }
////        LEDRow++;
////        for(uint8_t cc = 2U; cc < 6U; cc++){
////            LEDBuffer[(cc*21U)+14U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDBuffer[(cc*21U)+15U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDBuffer[(cc*21U)+16U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDBuffer[(cc*21U)+17U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDWrite();
////        }
////        LEDRow++;
////        for(uint8_t cc = 2U; cc < 6U; cc++){
////            LEDBuffer[(cc*21U)+14U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDBuffer[(cc*21U)+15U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDBuffer[(cc*21U)+16U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDBuffer[(cc*21U)+17U] = 0;//HappyChristmasBuffer[LEDCol][LEDRow];
////            LEDWrite();
////        }
////    } 
//}
/**
 End of File
*/