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
    #define BA_BYTE_1 10 //change back to 4 and 5
    #define BA_BYTE_2 11
    #define SHLDR_BYTE_1 12
    #define SHLDR_BYTE_2 13
    #define ELBW_BYTE_1 14
    #define ELBW_BYTE_2 15
    #define WT_BYTE_1 16
    #define WT_BYTE_2 17
    #define WR_BYTE_1 18
    #define WR_BYTE_2 19
    #define EFF_BYTE_1 20
    #define EFF_BYTE_2 21

    #define NEUTRAL 1500

    //TODO: Make sure that this data_array is the proper size for the newest version of udp format
    #define DATA_ARRAY_SIZE 22
    int8 data_array[DATA_ARRAY_SIZE]; //stores the parsed instructions from the wiznet

    //TODO: might need to implement another ISR setting wiznet as a flag
    uint8 wiznet; //bool indicating wiznet interupt high or low

    //TODO: erase this in final product
    #define TEST_ARRAY_SIZE 22
    int8 test_array[TEST_ARRAY_SIZE];

    #define ELBW_ARR_SIZE 20
    #define SHLDR_ARR_SIZE 20
    #define BA_ARR_SIZE 20
    #define WT_ARR_SIZE 20  //for wristTilt
    #define WR_ARR_SIZE 20  //for wristRotate
    
    // execute flags
    uint8 WT_FLAG = 0;
    uint8 WR_FLAG = 0;
    uint8 ELBOW_FLAG = 0;
    uint8 SHOULDER_FLAG = 0;
    uint8 BA_FLAG = 0;
    uint8 EFFECTOR_FLAG = 0;
    
    //error variables to send back to base station
    uint16 dropped_packets = 0;
    uint16 fail_safe_errors = 0;
    uint16 shldr_errors = 0;
    uint16 elbw_errors = 0;
    uint16 BA_errors = 0;
    uint16 WT_errors = 0;
    uint16 WR_errors = 0;
    uint16 eff_errors = 0;

    volatile uint8 timerFlag; //used in the timer_isr
    
    //---------------------------------------------------
    //    Function stubs for the header
    //---------------------------------------------------
    //void reverse(char s[]);
    //void itoa(int n, char s[]);
    uint16 average(uint16* array, uint8 num_items);
    uint8 maintain_array(uint8 cpos, uint8 SIZE);
    uint8 check_update(uint16* array, uint8 arr_pos, uint8 size, int change);
    uint8 pos_to_vel(uint8 cur_pos, uint16* array, uint8 ARRAY_SIZE, uint16 command);
    uint16 make_command(int8* info_array, uint8 byte1, uint8 byte2);
    uint16 potFeedback();
    void send_feedback();
    void fill_data_array();
    void ServoGoalPosition( uint8 servoID, uint16 position);
    void SetServoTorque( uint8 servoID, uint16 torque);
    void ServoSpeed( uint8 servoID, uint16 speed);
    uint8 wristTilt(uint8 WT_arr_cspot, uint16* WT_array);
    uint8 wristRotate(uint8 WR_arr_cspot, uint16* WR_array);
    uint8 elbow(uint8 elbw_arr_cspot, uint16* elbow_array);
    uint8 shoulder(uint8 shldr_arr_cspot, uint16* shoulder_array);
    uint8 baseAzimuth(uint8 BA_arr_cspot, uint16* baseAz_array);
    void effector();
    void initialize();
    //--------------------------------------------------- END Function Stubs
#endif
/* [] END OF FILE */
