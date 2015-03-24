/* ========================================
 *
 *
 * ========================================
*/
#ifndef MAIN_H
#define MAIN_H

    #include <project.h>
    #include <time.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include "wiznet5500.h"
    #include "spi.h"

    //Initializations of global variables
    #define ownIpAddr 4u
    #define dstIpAddr 1u
    #define udpPort 27015u

    //TODO: We need to make sure the bounds checking doesn't break
    //TODO: re-verify in order to match stop-switch placement
    #define ELBOW_UPPER_BOUND 1000     //was 100  // 16 bit values from ADC
    #define ELBOW_LOWER_BOUND 100       //was 1000
    #define SHOULDER_UPPER_BOUND 800
    #define SHOULDER_LOWER_BOUND 280
    #define SHOULDER_POT 0
    #define ELBOW_POT 1

    //TODO: make sure ourbyte scheme matching the newest version for udp format
    //Array indices of specific bytes transmitted from the wiznet
    #define BA_BYTE_1 2 //change back to 4 and 5
    #define BA_BYTE_2 3
    #define SHLDR_BYTE_1 6
    #define SHLDR_BYTE_2 7
    #define ELBW_BYTE_1 8
    #define ELBW_BYTE_2 9
    #define WT_BYTE_1 10
    #define WT_BYTE_2 11
    #define WR_BYTE_1 12
    #define WR_BYTE_2 13

    //TODO: Make sure that this data_array is the proper size for the newest version of udp format
    #define DATA_ARRAY_SIZE 14
    int8 data_array[DATA_ARRAY_SIZE]; //stores the parsed instructions from the wiznet

    //TODO: might need to implement another ISR setting wiznet as a flag
    uint8 wiznet; //bool indicating wiznet interupt high or low
    uint8 new_pack; //bool indicating a new pack of instructions to carry out

    //TODO: change this logic. 
    #define NUM_OF_SM 5
    uint8 fin_exec; //counts the number of execute states the program goes through

    //TODO: erase this in final product
    #define TEST_ARRAY_SIZE 14
    int8 test_array[TEST_ARRAY_SIZE];

    #define ELBW_ARR_SIZE 20
    uint8 elbw_arr_cspot;
    uint16 elbow_array[ELBW_ARR_SIZE];

    #define SHLDR_ARR_SIZE 20
    uint8 shldr_arr_cspot;
    uint16 shoulder_array[SHLDR_ARR_SIZE];

    #define BA_ARR_SIZE 20
    uint8 BA_arr_cspot;
    uint16 baseAz_array[BA_ARR_SIZE];

    #define WT_ARR_SIZE 20  //for wristTilt
    uint8 WT_arr_cspot;
    uint16 WT_array[WT_ARR_SIZE];

    #define WR_ARR_SIZE 20  //for wristRotate
    uint8 WR_arr_cspot;
    uint16 WR_array[WR_ARR_SIZE];

    //uint16 feedback_count;
    volatile uint8 timerFlag; //used in the timer_isr
    
    //---------------------------------------------------
    //    Function stubs for the header
    //---------------------------------------------------
    //void reverse(char s[]);
    //void itoa(int n, char s[]);
    uint16 average(uint16* array, uint8 num_items);
    void pos_to_vel(uint8 cur_pos, uint16* array, uint8 ARRAY_SIZE, uint16 command);
    uint16 make_command(int8* info_array, uint8 byte1, uint8 byte2);
    uint16 potFeedback();
    void send_feedback();
    void fill_data_array();
    void ServoGoalPosition( uint8 servoID, uint16 position);
    void SetServoTorque( uint8 servoID, uint16 torque);
    void ServoSpeed( uint8 servoID, uint16 speed);
    void wristTilt();
    void wristRotate();
    void elbow();
    void shoulder();
    void baseAzimuth();
    void initialize();
    //--------------------------------------------------- END Function Stubs
#endif
/* [] END OF FILE */
