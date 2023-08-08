#include "mcc_generated_files/mcc.h"
#include "FlexLed.h"

#define LED_ON 0xFFU
#define LED_OFF 0x0U

uint8_t LEDCol = 8U, TimerX = 0U, t = 0U;

bool LEDBuffer[24U] = { 0,0,0, //4-R00G01B02;
                        0,0,0, //5-R03G04B05;
                        0,0,0, //2-R06G07B08;
                        0,0,0, //3-R09G10B11;
                        0,0,0, //0-G12R13B14;
                        0,0,0, //1-G15R16B17;
                        0,0,0, //6-G18R19B20;
                        0,0,0  //7-G21R22B23;
};

bool Display_FlexLED[8][36] = { {0,1,1,1,1,0,1,0,0,0,0,1,1,1,1,0,1,0,0,1,0,1,0,0,0,0,1,1,1,1,0,1,1,0,0,0},
                                {0,1,1,1,1,0,1,0,0,0,0,1,1,1,1,0,1,0,0,1,0,1,0,0,0,0,1,1,1,1,0,1,0,1,0,0},
                                {0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0},
                                {0,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0},
                                {0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,0,0,1,1,0,0,1,0,0,0,0,1,1,1,1,0,1,0,0,1,0},
                                {0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0},
                                {0,1,0,0,0,0,1,1,1,1,0,1,1,1,1,0,1,0,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,0,0},
                                {0,1,0,0,0,0,1,1,1,1,0,1,1,1,1,0,1,0,0,1,0,1,1,1,1,0,1,1,1,1,0,1,1,0,0,0}
};

void FlexLedHandler(void){
    TimerX++;
    if(TimerX > 7U){
        TimerX = 0;
        if(t == 0U){
            LEDCol++;    
            if(LEDCol == 28){
                t = !t;
            }       
        }
        else{
            LEDCol--;   
            if(LEDCol == 0){
                t = !t;
            }             
        }
    }
    
    for(uint16_t a = 0U; a < 24U; a++){
        LEDBuffer[a] = 0;
    }
    if(LATCbits.LATC3 == 1U){
        /*Toogle Polarity*/
        LATCbits.LATC3 = 0U;
        LATCbits.LATC4 = 1U;
        for(uint16_t a = 0U; a < 8U; a++){

            LEDBuffer[13] = Display_FlexLED[a][7+LEDCol];
            if(LEDBuffer[13] == 0){
                LEDBuffer[14] = 1;                    
            }
            else{
                LEDBuffer[14] = 0;      
            }
            LEDBuffer[16] = Display_FlexLED[a][6+LEDCol];
            if(LEDBuffer[16] == 0){
                LEDBuffer[17] = 1;                    
            }
            else{
                LEDBuffer[17] = 0;      
            }
            LEDBuffer[6] = Display_FlexLED[a][5+LEDCol];
            if(LEDBuffer[6] == 0){
                LEDBuffer[8] = 1;                    
            }
            else{
                LEDBuffer[8] = 0;      
            }
            LEDBuffer[9] = Display_FlexLED[a][4+LEDCol];
            if(LEDBuffer[9] == 0){
                LEDBuffer[11] = 1;                    
            }
            else{
                LEDBuffer[11] = 0;      
            }
            LEDBuffer[0] = Display_FlexLED[a][3+LEDCol];
            if(LEDBuffer[0] == 0){
                LEDBuffer[2] = 1;                    
            }
            else{
                LEDBuffer[2] = 0;      
            }
            LEDBuffer[3] = Display_FlexLED[a][2+LEDCol];
            if(LEDBuffer[3] == 0){
                LEDBuffer[5] = 1;                    
            }
            else{
                LEDBuffer[5] = 0;      
            }
            LEDBuffer[19] = Display_FlexLED[a][1+LEDCol];
            if(LEDBuffer[19] == 0){
                LEDBuffer[20] = 1;                    
            }
            else{
                LEDBuffer[20] = 0;      
            }
            LEDBuffer[22] = Display_FlexLED[a][0+LEDCol];
            if(LEDBuffer[22] == 0){
                LEDBuffer[23] = 1;                    
            }
            else{
                LEDBuffer[23] = 0;      
            }
            LEDWrite();
        }
    }
    else{
        /*Toogle Polarity*/
        LATCbits.LATC3 = 1U;
        LATCbits.LATC4 = 0U;
        
       for(uint16_t a = 0U; a < 8U; a++){
            /*Red*/
            LEDBuffer[13] = 0;
            LEDBuffer[16] = 0;
            LEDBuffer[6] = 0;
            LEDBuffer[9] = 0;
            LEDBuffer[0] = 0;
            LEDBuffer[3] = 0;
            LEDBuffer[19] = 0;
            LEDBuffer[22] = 0;
            LEDBuffer[14] = 0;
            LEDBuffer[17] = 0;
            LEDBuffer[8] = 0;
            LEDBuffer[11] = 0;
            LEDBuffer[2] = 0;
            LEDBuffer[5] = 0;
            LEDBuffer[20] = 0;
            LEDBuffer[23] = 0;
            LEDWrite();
        }
    }
}

void FlexLedInit(void){
    uint16_t SCKEdgesG = 0U;
    
    LATCbits.LATC3 = 0U; /*Coast H-bridge*/
    LATCbits.LATC4 = 0U; /*Coast H-bridge*/
            
    /*Config Grayscale*/
    LATCbits.LATC5 = 0U; /*SCK pin*/
    LATAbits.LATA5 = 0U; /*GCLK pin*/
    LATAbits.LATA4 = 0U; /*LATCH pin*/
    LATAbits.LATA2 = 0U; /*BLANK pin*/
    LATCbits.LATC2 = 1U; /*SDI pin*/
    while(SCKEdgesG < SDIBufferSize){
        LATCbits.LATC5 = 1U; /*SCK pin*/
        __delay_us(1U);
        LATCbits.LATC5 = 0U; /*SCK pin*/
        __delay_us(1U);
        SCKEdgesG++;
    }
    LATAbits.LATA4 = 1U; /*LATCH pin*/ 
    __delay_us(2U);
    LATAbits.LATA4 = 0U; /*LATCH pin*/ 
    __delay_us(1U);
    LATAbits.LATA2 = 1U; /*BLANK pin*/ 
    __delay_us(1U);
    LATAbits.LATA5 = 1U; /*GCLK pin*/     
}

void LEDWrite(void){
    uint16_t SCKEdges = 0U;   
    uint8_t LEDCounter = 0U, CurrentCounter = 0U;
    bool LEDState = 0;
    
    __delay_us(2600U);
    LATAbits.LATA4 = 1U; /*LATCH pin*/
    while(SCKEdges < SDIBufferSize){
        LATCbits.LATC5 = 0U; /*SCK pin*/ 
        if(SCKEdges < 97U){
            LATCbits.LATC2 = 0U; /*SDI pin*/
        }
        else if(SCKEdges < 120U){
            LATCbits.LATC2 = 1U; /*SDI pin*/
        }
        else{
            CurrentCounter++;
            if(CurrentCounter >= 7U){
                CurrentCounter = 0U;
                LEDCounter++;
            }
            else{
                /*Skip*/
            }
            LATCbits.LATC2 = LEDBuffer[LEDCounter];
        }  
        
        __delay_us(1U);
        LATCbits.LATC5 = 1U; /*SCK pin*/
        __delay_us(1U);
        SCKEdges++;
    }
    LATCbits.LATC5 = 0U; /*SCK pin*/
    __delay_us(1U);
    LATAbits.LATA4 = 0U; /*LATCH pin*/
    __delay_us(1U);
}
