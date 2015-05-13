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
    #include <cypins.h>
    #include "dynamixel.h"

    //Initializations of global variables
    #define ownIpAddr 4u
    #define dstIpAddr 130u//147u //<-- This is the only number we need to change when we change the ip config. unless we change our subnet
    #define udpPort 27015u
   
    //Bounds variables for elbow and shoulder
    uint32  ELBOW_UPPER_BOUND = 1000;
    uint32  ELBOW_LOWER_BOUND = 100;
    uint32  SHOULDER_UPPER_BOUND = 800;
    uint32  SHOULDER_LOWER_BOUND = 280;
    #define BOUND_OFFSET 20
    
    #define SHOULDER_POT 0
    #define ELBOW_POT 1

    //TODO: make sure ourbyte scheme matching the newest version for udp format
    //Array indices of specific bytes transmitted from the wiznet
    #define BA_BYTE_1 10 
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
    //#define ARD_BYTE_1 22
    //#define ARD_BYTE_2 23

    uint16 NEUTRAL = 1500;

    //TODO: Make sure that this data_array is the proper size for the newest version of udp format
    #define DATA_ARRAY_SIZE 22
    int8 data_array[DATA_ARRAY_SIZE]; //stores the parsed instructions from the wiznet

    #define SEND_ARRAY_SIZE 14
    uint8_t feedback_array[SEND_ARRAY_SIZE];
    uint8_t heartbeat_array[SEND_ARRAY_SIZE];
    uint8 HEARTBEAT_FLAG;
    
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
    uint8 WT_feedback_flag = 0;
    uint8 WR_feedback_flag = 0;
    uint16 WR_feedback = 0;//this is variable for storing feedback
    uint8 WT_FLAG = 0;
    uint8 WR_FLAG = 0;
    uint8 ELBOW_FLAG = 0;
    uint8 SHOULDER_FLAG = 0;
    uint8 BA_FLAG = 0;
    uint8 EFFECTOR_FLAG = 0;
    uint8 ARD_FLAG = 0;
    //these are for feedback path
    uint8 Time_Out_flag = 0;
    uint8 Time_count = 0;
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
    
    enum equipment {SHOULDER = 0, ELBOW, WRIST, TURRET, EFFECTOR};
    
    //---------------------------------------------------
    //    Function stubs for the header
    //---------------------------------------------------
    uint16 CalibrationElbow(uint16 velocity);
    uint16 CalibrationShoulder(uint16 velocity);
    uint16 average(uint16* array, uint8 num_items);
    void maintain_array(uint8* cpos, uint8 SIZE);
    void check_update(uint16* array, uint8* arr_pos, uint8 size, int change);
    void pos_to_vel(uint8* cur_pos, uint16* array, uint8 ARRAY_SIZE, uint16 command);
    
    uint16 simple_pos_to_vel(uint16 new_command, uint16 recent_command);
    uint16 latest_command;
    
    uint16 WR_pos_to_vel(uint16 new_command, uint16 recent_command);
    uint16 WT_pos_to_vel(uint16 new_command, uint16 recent_command);
    uint16 latest_WR_command;
    uint16 latest_WT_command;
    
    uint16 make_command(int8* info_array, uint8 byte1, uint8 byte2);
    uint16 make_wristRotate_command(int8* info_array, uint8 byte1, uint8 byte2);
    uint16 make_wristTilt_command(int8* info_array, uint8 byte1, uint8 byte2);
    
    uint16 potFeedback(uint32 channel);
    void send_packet();
    void fill_data_array();
//    uint8 wristTilt(uint8 WT_arr_cspot, uint16* WT_array);
//    uint8 wristRotate(uint8 WR_arr_cspot, uint16* WR_array);
//    void elbow(uint8* elbw_arr_cspot, uint16* elbow_array);
//    void shoulder(uint8* shldr_arr_cspot, uint16* shoulder_array);
//    void baseAzimuth(uint8* BA_arr_cspot, uint16* BA_array);
    
    void wristTilt();
    void wristRotate();
    void elbow();
    void shoulder();
    void baseAzimuth();
    
    void effector();
    void arduino();
    void initialize();
    //--------------------------------------------------- END Function Stubs
#endif
/* [] END OF FILE */
