/**
 * Wheel Header
 *
 * Processor:       PIC18F46K80
 * Compiler:        Microchip C18
 * Author:          George Schwieters
 * Created:         2013-2014
 */

#ifndef WHEEL_H
#define WHEEL_H

#include "GenericTypeDefs.h"
#include "adc.h"

/*
 * Code Control
 */

//#define INTERNAL
//#define DEBUGGING
//#define PADDLES

/*
 * Magic Numbers
 */

#define LEFT 0
#define RIGHT 1
#define BOTH 3
#define NUM_CHAN 7

// reading and modifying the rotary voltages
#define POS_0 0
#define POS_1 555
#define POS_2 1111
#define POS_3 1666
#define POS_4 2222
#define POS_5 2777
#define POS_6 3333
#define POS_7 3888
#define POS_8 4444
#define POS_9 5000
#define RANGE_LOW 0
#define RANGE_0 409
#define RANGE_1 819
#define RANGE_2 1228
#define RANGE_3 1638
#define RANGE_4 2048
#define RANGE_5 2457
#define RANGE_6 2867
#define RANGE_7 3276
#define RANGE_8 3686
#define RANGE_HIGH 4096

#define CAN_ERR         0
#define DATA_ERR        1
#define RANGE_ERR       2

#define IN_RANGE        0
#define OUT_OF_RANGE    1
#define HI              2
#define LOW             3

// timing
#define HOLD_TIME       2000
#define BLINK_TIME      200
#define REFRESH_TIME    150
#define BOUNCE_TIME     100
#define CAN_PER         200
#define CAN_RECIEVE_MAX  1000

//data reading limits
//TODO
#define RPM_MAX         150
#define RPM_MIN         0
#define OIL_P_MAX       1000
#define OIL_P_MIN       0
#define OIL_T_MAX       300
#define OIL_T_HI        180
#define OIL_T_MIN       0
#define ENGINE_T_MAX    200
#define ENGINE_T_HI     115
#define ENGINE_T_MIN    0
#define VOLTAGE_MAX     200
#define VOLTAGE_HI      150
#define VOLTAGE_LO      115
#define VOLTAGE_MIN     0
#define SPEED_MAX       1500
#define SPEED_MIN       0

// data channel indicies
#define OIL_T       0
#define ENGINE_T    1
#define VOLTAGE     2
#define OIL_P       3
#define SPEED       4
#define RPM         5
#define LOGGING     6
#define CANERR1     7
#define CANERR2     8
#define NODATA1     9
#define NODATA2     10

// addresses for display driver
#define NO_OP       0x00
#define DIG0        0x01
#define DIG1        0x02
#define DIG2        0x03
#define DIG3        0x04
#define DIG4        0x05
#define DIG5        0x06
#define DIG6        0x07
#define DIG7        0x08
#define DECODE      0x09
#define INTENSITY   0x0A
#define SCAN        0x0B
#define SHUTDOWN    0x0C
#define DISP_MODE   0x0F

// data bytes

// config
#define SHUTDOWN_ON     0b00000001
#define SHUTDOWN_OFF    0b00000001
#define NO_DECODE       0x00
#define FULL_SCAN       0b00000111

// numbers
#define NUM_DP          0b10000000
#define NUM_0           0b01111110
#define NUM_1           0b00110000
#define NUM_2           0b01101101
#define NUM_3           0b01111001
#define NUM_4           0b00110011
#define NUM_5           0b01011011
#define NUM_6           0b01011111
#define NUM_7           0b01110000
#define NUM_8           0b01111111
#define NUM_9           0b01110011
#define BLANK           0b00000000

// characters
#define CHAR_A          0b01110111
#define CHAR_b          0b00011111
#define CHAR_t          0b00001111
#define CHAR_O          0b01111110
#define CHAR_E          0b01001111
#define CHAR_P          0b01100111
#define CHAR_S          0b01011011
#define CHAR_d          0b00111101
#define CHAR_c          0b00001101
#define CHAR_C          0b01001110
#define CHAR_N          0b01110110
#define CHAR_r          0b00000101
#define CHAR_H          0b00110111
#define CHAR_I          0b00000110
#define CHAR_L          0b00001110
#define CHAR_u          0b00011100
#define CHAR_G          0b01011111
#define CHAR_o          0b00011101

// display mode
#define TEST            0x01
#define NORMAL          0x00

/*
 * Pin Definitions
 */

// chip select
#define CS LATDbits.LATD3

// setup switch inputs
#define CYCLE_L PORTEbits.RE1
#define CYCLE_R PORTEbits.RE2
#define WATER_OVER PORTDbits.RD6
#define FAN_OVER PORTDbits.RD5
#define RADIO PORTBbits.RB4
#define ACK PORTBbits.RB5

// set analog inputs
#define LAUNCH_ROT ADC_CH5
#define TRAC_ROT ADC_CH1
#define DRS_ROT ADC_CH2

#define TERM_LAT LATCbits.LATC6

void init_unused_pins(void);
void updateText(unsigned char side, unsigned char *state);
void updateDisp(unsigned char side);
void write_num(int data, unsigned char d_place, unsigned char side);
void blank_display(unsigned char side);
void write_gear(unsigned char gear);
void driver_write(unsigned char addr, unsigned char data);
void write_CAN_data_error(void);
void write_CAN_error(void);
void checkRangeError(void);
void high_isr(void);
void bufferData(void);
void ADLsample(unsigned char *data, const unsigned char ADLoffset,
        const unsigned char ch);
void modifyRotary(unsigned int * sample);

#endif
