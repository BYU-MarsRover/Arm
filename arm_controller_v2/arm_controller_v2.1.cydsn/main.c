/* ========================================
 *created by Samuel Bury Jan. 31, 2015
*/

#include "main.h"

//this ISR will be used to set our timeFlag according to our timer component
///set to the time of the longest path for our code
//TODO: test how long it takes code to run
CY_ISR(timer_isr)
{
    uint32 isr_var = Timer_1_GetInterruptSourceMasked();
    timerFlag = 1;
    Timer_1_ClearInterrupt(isr_var);
}

//Funtion declarations/definitions
uint16 CalibrationElbow(uint16 velocity)
{
    uint8 	CYCLES = 3;
	uint8 	i;
	uint16 	bound;
	uint16 	average;
    uint32  channel;
    int16   difference;
 
	for(i = 0, average = 0; i < CYCLES; i++)
	{
        // Test stop switch
        LED_Write(0);
        
        // Move till stop switch presses down
        if(velocity < 1500)
        {
            while(stop_elb_dn_Read())
            {
                ELBW_PWM_WriteCompare(velocity);
            }
        }
        else if(velocity > 1500)
        {
            while(stop_elb_up_Read())
            {
                ELBW_PWM_WriteCompare(velocity);
            }
        }
        else
        {
            ELBW_PWM_WriteCompare(velocity);
        }
        ELBW_PWM_WriteCompare(NEUTRAL);
        LED_Write(1);
        CyDelay(1000);
        
        channel = ELBOW_POT;
        
        // Add the value to average
        average+=potFeedback(channel);
 
		// Move away for 2 seconds
			// Use negative of velocity * 2, so that it moves away quick enough
        difference = 1500-velocity;
        ELBW_PWM_WriteCompare((uint16)(1500 + difference));
        LED_Write(0); 
        CyDelay(1000);
 
		// Stop moving
        ELBW_PWM_WriteCompare(NEUTRAL);
        LED_Write(1); 
        CyDelay(1000);
	}
    
    if(velocity > 1500)
	    bound = ((average / CYCLES) - BOUND_OFFSET);
    else if(velocity < 1500)
        bound = ((average / CYCLES) + BOUND_OFFSET);
    else // velocity == 1500
        LED_Write(1); 
 
	return bound;
}

uint16 CalibrationShoulder(uint16 velocity)
{
	uint8 	CYCLES = 3;
	uint8 	i;
	uint16 	bound;
	uint16 	average;
    uint32  channel;
    int16 difference;
 
	for(i = 0, average = 0; i < CYCLES; i++)
	{
        LED_Write(0);
		// Move till stop switch presses down
        if(velocity < 1500)
        {
            while(stop_shdr_dn_Read())
            {
                SHLDR_PWM_WriteCompare(velocity);
            }
        }
        else if(velocity > 1500)
        {
            while(stop_shdr_up_Read())
            {
                SHLDR_PWM_WriteCompare(velocity);
            }
        }
        else
        {
            SHLDR_PWM_WriteCompare(velocity);
        }
        SHLDR_PWM_WriteCompare(NEUTRAL);
        LED_Write(1); 
        CyDelay(1000);
        
        channel = SHOULDER_POT;
 
		// Add the value to average
        average+=potFeedback(channel);
 
		// Move away for 2 seconds
			// Use negative of velocity * 2, so that it moves away quick enough
        difference = 1500-velocity;
        SHLDR_PWM_WriteCompare((uint16)(1500 + difference));
        LED_Write(0); 
        CyDelay(1000);
 
		// Stop moving
        SHLDR_PWM_WriteCompare(NEUTRAL);
        LED_Write(1); 
        CyDelay(1000);
	}
 
	if(velocity > 1500)
	    bound = ((average / CYCLES) - BOUND_OFFSET);
    else if(velocity < 1500)
        bound = ((average / CYCLES) + BOUND_OFFSET);
    else // velocity == 1500
        LED_Write(1); 
 
	return bound;
}

//Average function to be used in smoothing our input
uint16 average(uint16* av_array, uint8 num_items)
{
    uint8 i;
    uint32 sum = 0;
    uint16 avg = 0;
    
    for(i = 0; i < num_items; i++)
    {
        sum += av_array[i];
    }
    
    avg = sum/num_items;
    
    return avg;
}

uint8 maintain_array(uint8 cpos, uint8 SIZE)
{
    if(cpos < (SIZE - 1))
    {
        cpos++;
    }
    else
    {
        cpos = 0;
    }
    return cpos;
}

uint8 check_update(uint16* array, uint8 arr_pos, uint8 size, int change)
{
    uint8 index;
    if(arr_pos != 0)
    {
        index = arr_pos - 1;
    }
    else
    {
        index = size - 1;
    }
    
    if(change < 0)
    {
        if(array[index] >= (1000 - change))
        {
            array[arr_pos] = (array[index] + change);
        }
        else
        {
            array[arr_pos] = 1000;
        }
    }
    else
    {
        if(array[index] <= (2000 - change))
        {
            array[arr_pos] = (array[index] + change);
        }
        else
        {
            array[arr_pos] = 2000;
        }
    }
    
    return maintain_array(arr_pos, size);
}

uint8 pos_to_vel(uint8 cur_pos, uint16* array, uint8 ARRAY_SIZE, uint16 command)
{
    if(command >= 1000 && command < 1125)
    {
         cur_pos = check_update(array, cur_pos, ARRAY_SIZE, -100);
    }
    else if(command >= 1125 && command < 1250)
    {
        cur_pos = check_update(array, cur_pos, ARRAY_SIZE, -50);  
    }
    else if(command >= 1250 && command < 1375)
    {
        cur_pos = check_update(array, cur_pos, ARRAY_SIZE, -10);
    }
    else if(command >= 1375 && command < 1490)
    {
        cur_pos = check_update(array, cur_pos, ARRAY_SIZE, -5);
    }
    else if(command <= 1510 && command >= 1490)
    {
        cur_pos = maintain_array(cur_pos, ARRAY_SIZE);
    }
    else if(command > 1510 && command <= 1625)
    {
        cur_pos = check_update(array, cur_pos, ARRAY_SIZE, 5);
    }
    else if(command > 1625 && command <= 1750)
    {
        cur_pos = check_update(array, cur_pos, ARRAY_SIZE, 10);
    }
    else if(command > 1750 && command <= 1875)
    {
        cur_pos = check_update(array, cur_pos, ARRAY_SIZE, 50);
    }
    else if(command > 1875 && command <= 2000)
    {
         cur_pos = check_update(array, cur_pos, ARRAY_SIZE, +100);
    }
    else
    {
        //increment error variable
        cur_pos = maintain_array(cur_pos, ARRAY_SIZE);
    }
    return cur_pos;
}

uint16 make_command(int8* info_array, uint8 byte1, uint8 byte2)
{
    uint16 command;
    int16 temp1;
    int16 temp2;
    int16 temp3;
    
    temp1 = (info_array[byte1] << 8) & 0xFF00;
    temp2 = 0x00FF & (info_array[byte2]);
    temp3 = temp1 | temp2;
    command = (temp3/2) + 1500;
    return command;
}

uint16 potFeedback(uint32 channel)
{
    uint16 feedback = ADC_GetResult16(channel);
    return feedback;
}

void send_packet(uint8 heart_beat)
{
    //compile all of the most recent feedback variables into a packet
    //necessary feedback variables: system state, dynamixel read write errors, PID errors
    //TODO define system state
    //send packet via serial to wiznet
    if(heart_beat){
        feedback_array[0] = 7;
        feedback_array[1] = 7;
        feedback_array[2] = 7;
        feedback_array[3] = 7;
        feedback_array[4] = 7;
        feedback_array[5] = 7;
        feedback_array[6] = 7;
        feedback_array[7] = 7;
        feedback_array[8] = 7;
        feedback_array[9] = 7;
        feedback_array[10] = 7;
        feedback_array[11] = 7;
        feedback_array[12] = 7;
        feedback_array[13] = 0xee;
        wiznetWriteUdpFrame(feedback_array, FEEDBACK_ARRAY_SIZE);
    }
    else{
        feedback_array[0] = 7;      // ph value
        feedback_array[1] = 7;      // humidity
        feedback_array[2] = 7;      // wrist rotate temperature
        feedback_array[3] = 7;      // wrist rotate position
        feedback_array[4] = 7;      // wrist rotate error status
        feedback_array[5] = 7;      // wrist tilt temperature
        feedback_array[6] = 7;      // wrist tilt position
        feedback_array[7] = 7;      // wrist tilt error statue
        feedback_array[8] = 7;      // elbow stop switch count
        feedback_array[9] = 7;      // elbow pot value
        feedback_array[10] = 7;      // shoulder stop swtich count
        feedback_array[11] = 7;      // shoulder pot value
        feedback_array[12] = 7;      // turret error status
        feedback_array[13] = 0xff;       
        wiznetWriteUdpFrame(feedback_array, FEEDBACK_ARRAY_SIZE);
        LED_Write(1);
    }
    wiznetSend();
    while(WIZ_INT_Read() == 1);
    wiznetClearInterrupts();
    LED_Write(0);    
}

//to be used for parsing reading/parsing the data from the wiznet
void fill_data_array()
{
    wiznetReadUdpFrame(data_array, DATA_ARRAY_SIZE);
}

void ServoGoalPosition( uint8 servoID, uint16 position)
{
    uint8 array[9];
    
    array[0] = 0xFF;
    array[1] = 0xFF;
    array[2] = servoID; //this is a broadcast ID.  Change for daisychained servos.
    array[3] = 0x05;
    array[4] = 0x03; //write instruction
    array[5] = 0x1E;
    array[6] = position;
    array[7] = position >> 8;
    array[8] = ~(servoID + 0x05 + 0x1E + array[6] + array[7] + 0x03);
    
    Wrist_UART_SpiUartPutArray(array, 0x09);  
}

void SetServoTorque( uint8 servoID, uint16 torque)
{
    uint8 array[9];
    
    array[0] = 0xFF;
    array[1] = 0xFF;
    array[2] = servoID; 
    array[3] = 0x05;
    array[4] = 0x03; //write instruction
    array[5] = 0x0E;
    array[6] = torque;
    array[7] = torque >> 8;
    array[8] = ~(servoID + 0x05 + 0x0E + array[6] + array[7] + 0x03);
    
    Wrist_UART_SpiUartPutArray(array, 0x09);
    
}    

void ServoSpeed( uint8 servoID, uint16 speed)
{
    uint8 array[9];
    
    array[0] = 0xFF;
    array[1] = 0xFF;
    array[2] = servoID; //this is a broadcast ID.  Change for daisychained servos.
    array[3] = 0x05;
    array[4] = 0x03; //write instruction
    array[5] = 0x20;
    array[6] = speed;
    array[7] = speed >> 8;
    array[8] = ~(servoID + 0x05 + 0x20 + array[6] + array[7] + 0x03);
    
    Wrist_UART_SpiUartPutArray(array, 0x09);
    
}

enum wristTilt_states {tilt_start, tilt_init, tilt_control, tilt_wait} wristTilt_state;
//control the tilting motion of the wrist
uint8 wristTilt(uint8 WT_arr_cspot, uint16* WT_array)
{
    // Overview
    //take instruction from data_array
    //smooth input
    //actuate the tilting using UART
    //get feedback

    //-------------------------- 
    // Dynamixel Servo specific
    // TODO: Set the torque - Requires building an array with bit representation
    // TODO: Set the desired position

    //--------------------------
    // State machine
    
    uint8 i;
    uint16 avg;
    uint16 command;
    
    switch(wristTilt_state){ //actions
        case tilt_start:
            break;

        case tilt_init:
            for(i = 0; i < WT_ARR_SIZE; i++)
            {
                WT_array[i] = 1500; //TODO: make sure this is the neutral value
            }
            WT_arr_cspot = 0;
            
            ServoGoalPosition(0x02, 1500);
            break;

        case tilt_control:
            command = make_command(data_array, WT_BYTE_1, WT_BYTE_2);
            
            WT_array[WT_arr_cspot] = command;
            
            if(WT_arr_cspot < (WT_ARR_SIZE - 1))
            {
                WT_arr_cspot++;
            }
            else
            {
                WT_arr_cspot = 0;
            }
            
            //pos_to_vel(WT_arr_cspot, WT_array, WT_ARR_SIZE, command);
            
            avg = average(WT_array, WT_ARR_SIZE);
            
            if(avg <= 2000 && avg >= 1000)
            {
                ServoGoalPosition(0x02, avg);
            }
            else
            {
                //increment error variable
                ServoGoalPosition(0x02, 1500); //TODO: write a neutral value
            }
            WT_FLAG = 0;
            break;
            
        case tilt_wait:
            break;
                        
        default:
            wristTilt_state = tilt_start;
            break;
    }
    
    switch(wristTilt_state){ //transitions
        case tilt_start:
            wristTilt_state = tilt_init;
            break;
        
        case tilt_init:
            wristTilt_state = tilt_wait;
            break;
        
        case tilt_control:
            if(WT_FLAG)
            {
                wristTilt_state = tilt_control;
            }
            else
            {
                wristTilt_state = tilt_wait;
            }
            break;
        
        case tilt_wait:
            if(WT_FLAG)
            {
                wristTilt_state = tilt_control;
            }
            else
            {
                wristTilt_state = tilt_wait; 
            }
            break;
            
        default:
            wristTilt_state = tilt_start;
            break;
    }  
    return WT_arr_cspot;
}

enum wristRotate_states {rotate_start, rotate_init, rotate_control, rotate_wait} wristRotate_state;
//control the rotating motion of the wrist
uint8 wristRotate(uint8 WR_arr_cspot, uint16* WR_array)
{
    //Overview
    //take instruction from data_array
    //smooth input
    //actuate the tilting using UART
    //get feedback

    //-------------------------- 
    // Dynamixel Servo specific
    // TODO: Set the torque - Requires building an array with bit representation
    // TODO: Set the desired position

    //--------------------------
    // State machine
    
    uint8 i;
    uint16 avg;
    uint16 command;
    
    switch(wristRotate_state){ //actions
        case rotate_start:
            break;

        case rotate_init:
            for(i = 0; i < WR_ARR_SIZE; i++)
            {
                WR_array[i] = 1500; //TODO: Make sure this is the neutral value
            }
            WR_arr_cspot = 0;
            
            ServoGoalPosition(0x01, 1500); //TODO: Make sure this is the neutral value
            break;

        case rotate_control:
            command = make_command(data_array, WR_BYTE_1, WR_BYTE_2);
            
            WR_array[WR_arr_cspot] = command;
            
            if(WR_arr_cspot < (WR_ARR_SIZE - 1))
            {
                WR_arr_cspot++;
            }
            else
            {
                WR_arr_cspot = 0;
            }
            
            //pos_to_vel(WR_arr_cspot, WR_array, WR_ARR_SIZE, command);
            
            avg = average(WR_array, WR_ARR_SIZE);
            
            if(avg <= 2000 && avg >= 1000)
            {
                //TODO: maybe scale avg between 0 and 3000
                ServoGoalPosition(0x01, avg);
            }
            else
            {
                //increment error variable
                //TODO: if we scale, change the "neutral" value
                ServoGoalPosition(0x01, 1500);
            }
            WR_FLAG = 0;
            break;
            
        case rotate_wait:
            break;
                        
        default:
            wristRotate_state = rotate_start;
            break;
    }
    
    switch(wristRotate_state){ //transitions
        case rotate_start:
            wristRotate_state = rotate_init;
            break;
        
        case rotate_init:
            wristRotate_state = rotate_wait;
            break;
        
        case rotate_control:
            if(WR_FLAG)
            {
                wristRotate_state = rotate_control;
            }
            else
            {
                wristRotate_state = rotate_wait;
            }
            break;
        
        case rotate_wait:
            if(WR_FLAG)
            {
                wristRotate_state = rotate_control;
            }
            else
            {
                wristRotate_state = rotate_wait;
            }
            break;
            
        default:
            wristRotate_state = rotate_start;
            break;
    }  
    return WR_arr_cspot;
}

//control the elbow
enum elbow_states {elbw_start,elbw_init,elbw_execute,elbw_wait} elbow_state;
uint8 elbow(uint8 elbw_arr_cspot, uint16* elbow_array)
{ 
    //take instruction from data_array
    //smooth input
    //actuate the elbow using PWM
    //get feedback
    uint8 i;
    uint16 avg;
    uint16 command;
    
    uint16 feedback = potFeedback(ELBOW_POT); //check the feedback in every tick
    
    switch(elbow_state){ //actions
        case elbw_start:
            break;

        case elbw_init:
            for(i = 0; i < ELBW_ARR_SIZE; i++)
            {
                elbow_array[i] = 1500;
            }
            elbw_arr_cspot = 0;
            
            ELBW_PWM_WriteCompare(1500);
            break;

        case elbw_execute:
            command = make_command(data_array, ELBW_BYTE_1, ELBW_BYTE_2);
            
            elbow_array[elbw_arr_cspot] = command;
            
            if(elbw_arr_cspot < (ELBW_ARR_SIZE - 1))
            {
                elbw_arr_cspot++;
            }
            else
            {
                elbw_arr_cspot = 0;
            }
            avg = average(elbow_array, ELBW_ARR_SIZE);   
            
            if(!stop_elb_dn_Read() || !stop_elb_up_Read())
            {
                if(feedback <= ELBOW_LOWER_BOUND )  // lower bound checking, only move away is allowed
                {
                    if (avg < 1500)
                    {
                        ELBW_PWM_WriteCompare(1500);
                    }
                    else
                    {
                        if(avg <= 2000 && avg >= 1000)
                        {
                            ELBW_PWM_WriteCompare(avg);
                        }
                        else
                        {
                            ELBW_PWM_WriteCompare(1500);
                        }
                    }
                }
                else if (feedback >= ELBOW_UPPER_BOUND) // upper bound checking, only move away is allowed
                {
                    if(avg > 1500)
                    {
                        ELBW_PWM_WriteCompare(1500);
                    }
                    else
                    {
                        if(avg <= 2000 && avg >= 1000)
                        {
                            ELBW_PWM_WriteCompare(avg);
                        }
                        else
                        {
                            ELBW_PWM_WriteCompare(1500);
                        }
                    }
                }
                else
                {
                    if(avg <= 2000 && avg >= 1000)
                    {
                        ELBW_PWM_WriteCompare(avg);
                    }
                    else
                    {
                        ELBW_PWM_WriteCompare(NEUTRAL);
                    }
                }
            }
            else // One of the stop switches was presses, shouldn't happen but just in case
            {
                if(!stop_elb_dn_Read()){
                    ELBOW_LOWER_BOUND = potFeedback(ELBOW_POT) + BOUND_OFFSET;
                    if (avg < 1500)
                    {
                        ELBW_PWM_WriteCompare(1500);
                    }
                    else
                    {
                        if(avg <= 2000 && avg >= 1000)
                        {
                            ELBW_PWM_WriteCompare(avg);
                        }
                        else
                        {
                            ELBW_PWM_WriteCompare(1500);
                        }
                    }
                }
                else if(!stop_elb_up_Read()){
                    ELBOW_UPPER_BOUND = potFeedback(ELBOW_POT) - BOUND_OFFSET;
                    if(avg > 1500)
                    {
                        ELBW_PWM_WriteCompare(1500);
                    }
                    else
                    {
                        if(avg <= 2000 && avg >= 1000)
                        {
                            ELBW_PWM_WriteCompare(avg);
                        }
                        else
                        {
                            //increment error variable
                            ELBW_PWM_WriteCompare(1500);
                        }
                    }
                }
                else{
                    LED_Write(1);
                }
            }
            ELBOW_FLAG = 0;
            break;
            
        case elbw_wait:
            if(feedback <= ELBOW_LOWER_BOUND || feedback >= ELBOW_UPPER_BOUND)
            {
                ELBW_PWM_WriteCompare(1500);
            }
            break;
                        
        default:
            elbow_state = elbw_start;
            break;
    }
    
    switch(elbow_state){ //transitions
        case elbw_start:
            elbow_state = elbw_init;
            break;
        
        case elbw_init:
            elbow_state = elbw_wait;
            break;
        
        case elbw_execute:
            if(ELBOW_FLAG)
            {
                elbow_state = elbw_execute;
            }
            else
            {
                elbow_state = elbw_wait;
            }
            break;
        
        case elbw_wait:
            if(ELBOW_FLAG)
            {
                elbow_state = elbw_execute;
            }
            else
            {
                elbow_state = elbw_wait; 
            }
            break;
            
        default:
            elbow_state = elbw_start;
            break;
    }  
    return elbw_arr_cspot;
}

//control the shoulder
enum shoulder_states {shldr_start,shldr_init,shldr_execute,shldr_wait} shoulder_state;
uint8 shoulder(uint8 shldr_arr_cspot, uint16* shoulder_array)
{ 
    //take instruction from data_array
    //smooth input
    //actuate the shoulder using PWM
    //get feedback
    uint8 i;
    uint16 avg;
    uint16 command;
    
    uint16 feedback = potFeedback(SHOULDER_POT);
    
    switch(shoulder_state){ //actions
        case shldr_start:
            break;

        case shldr_init:
            for(i = 0; i < SHLDR_ARR_SIZE; i++)
            {
                shoulder_array[i] = 1500;
            }
            shldr_arr_cspot = 0;
                        
            SHLDR_PWM_WriteCompare(1500);
            break;

        case shldr_execute:
            command = make_command(data_array, SHLDR_BYTE_1, SHLDR_BYTE_2);
            shoulder_array[shldr_arr_cspot] = command;    
        
            if(shldr_arr_cspot < (SHLDR_ARR_SIZE - 1))
            {
                shldr_arr_cspot++;
            }
            else
            {
                shldr_arr_cspot = 0;
            }
            avg = average(shoulder_array, SHLDR_ARR_SIZE);
            
            if(!stop_shdr_dn_Read() || !stop_shdr_up_Read())
            {
                if(feedback <= SHOULDER_LOWER_BOUND)
                {
                    if (avg < 1500)
                    {
                        SHLDR_PWM_WriteCompare(1500);
                    }
                    else
                    {
                        if(avg <= 2000 && avg >= 1000)
                        {
                            SHLDR_PWM_WriteCompare(avg);
                        }
                        else
                        {
                            //increment error variable
                            SHLDR_PWM_WriteCompare(1500);
                        }
                    }
                }
                else if (feedback >= SHOULDER_UPPER_BOUND)
                {
                    if(avg > 1500)
                    {
                        SHLDR_PWM_WriteCompare(1500);
                    }
                    else
                    {
                        if(avg <= 2000 && avg >= 1000)
                        {
                            SHLDR_PWM_WriteCompare(avg);
                        }
                        else
                        {
                            //throw error
                            SHLDR_PWM_WriteCompare(1500);
                        }
                    }
                }
                else
                {
                    if(avg <= 2000 && avg >= 1000)
                    {
                        SHLDR_PWM_WriteCompare(avg);
                    }
                    else
                    {
                        //throw error
                        SHLDR_PWM_WriteCompare(1500);
                    }
                }
            }
            else // One of the stop switches was presses, shouldn't happen but just in case
            {
                if(!stop_elb_dn_Read()){
                    SHOULDER_LOWER_BOUND = potFeedback(SHOULDER_POT) + BOUND_OFFSET;
                    if (avg < 1500)
                    {
                        SHLDR_PWM_WriteCompare(1500);
                    }
                    else
                    {
                        if(avg <= 2000 && avg >= 1000)
                        {
                            SHLDR_PWM_WriteCompare(avg);
                        }
                        else
                        {
                            SHLDR_PWM_WriteCompare(1500);
                        }
                    }
                }
                else if(!stop_elb_up_Read()){
                    SHOULDER_UPPER_BOUND = potFeedback(SHOULDER_POT) - BOUND_OFFSET;
                    if(avg > 1500)
                    {
                        SHLDR_PWM_WriteCompare(1500);
                    }
                    else
                    {
                        if(avg <= 2000 && avg >= 1000)
                        {
                            SHLDR_PWM_WriteCompare(avg);
                        }
                        else
                        {
                            SHLDR_PWM_WriteCompare(1500);
                        }
                    }
                }
                else{
                    LED_Write(1);
                }
            }
            SHOULDER_FLAG = 0;
            break;
            
        case shldr_wait:
            if(feedback <= SHOULDER_LOWER_BOUND || feedback >= SHOULDER_UPPER_BOUND)
            {
                SHLDR_PWM_WriteCompare(1500);
            }
            break;
                        
        default:
            shoulder_state = shldr_start;
            break;
    }
    
    switch(shoulder_state){ //transitions
        case shldr_start:
            shoulder_state = shldr_init;
            break;
        
        case shldr_init:
            shoulder_state = shldr_wait;
            break;
        
        case shldr_execute:
            if(SHOULDER_FLAG)
            {
                shoulder_state = shldr_execute;
            }
            else
            {
                shoulder_state = shldr_wait;
            }
            break;
        
        case shldr_wait:
            if(SHOULDER_FLAG)
            {
                shoulder_state = shldr_execute;
            }
            else
            {
                shoulder_state = shldr_wait; 
            }
            break;
            
        default:
            shoulder_state = shldr_start;
            break;
    }  
    return shldr_arr_cspot;
}

//control the turret
enum baseAzimuth_states {BA_start,BA_init,BA_execute,BA_wait} baseAzimuth_state;
uint8 baseAzimuth(uint8 BA_arr_cspot, uint16* baseAz_array)
{ 
    //take instruction from data_array
    //smooth input
    //actuate the turret using PWM
    uint8 i;
    uint16 avg;
    uint16 command;
    
    switch(baseAzimuth_state){ //actions
        case BA_start:
            break;

        case BA_init:
            for(i = 0; i < BA_ARR_SIZE; i++)
            {
                baseAz_array[i] = 1500;
            }
            BA_arr_cspot = 0;
            
            BA_PWM_WriteCompare(1500);
            break;

        case BA_execute:
            command = make_command(data_array, BA_BYTE_1, BA_BYTE_2);

            BA_arr_cspot = pos_to_vel(BA_arr_cspot, baseAz_array, BA_ARR_SIZE, command);
            
            avg = average(baseAz_array, BA_ARR_SIZE);

            if(avg <= 2000 && avg >= 1000)
            {
                BA_PWM_WriteCompare(avg);
            }
            else
            {
                LED_Write(1);

                //increment error variable
                BA_PWM_WriteCompare(1500);
            }
            BA_FLAG = 0;
            break;
            
        case BA_wait:
            break;
            
        default:
            baseAzimuth_state = BA_start;
            break;
    }
    
    switch(baseAzimuth_state)
    { //transitions
        case BA_start:
            baseAzimuth_state = BA_init;
            break;
        
        case BA_init:
            baseAzimuth_state = BA_wait;
            break;
        
        case BA_execute:
            if(BA_FLAG)
            {
                baseAzimuth_state = BA_execute;
            }
            else
            {
                baseAzimuth_state = BA_wait;
            }
            break;
        
        case BA_wait:
            if(BA_FLAG)
            {
                baseAzimuth_state = BA_execute;
            }
            else
            {
                baseAzimuth_state = BA_wait; 
            }
            break;
            
        default:
            baseAzimuth_state = BA_start;
            break;
    }  
    return BA_arr_cspot;
}

enum effector_states {eff_start, eff_init, eff_execute, eff_wait} effector_state;
void effector()
{
    uint16 command;

    switch(effector_state){ //actions
        case shldr_start:
            break;

        case eff_init:           
           EFFECTOR_PWM_WriteCompare(1500);
           break;

        case eff_execute:
            command = make_command(data_array, EFF_BYTE_1, EFF_BYTE_2);    

            if(command <= 2000 && command >= 1000)
            {
                EFFECTOR_PWM_WriteCompare(command);
            }
            else
            {
                //increment error variable
                SHLDR_PWM_WriteCompare(1500);
            }
            
            EFFECTOR_FLAG = 0;
            break;
            
        case eff_wait:
            break;
        
        default:
            effector_state = eff_start;
            break;
    }
    
    switch(effector_state){ //transitions
        case eff_start:
            effector_state = eff_init;
            break;
        
        case eff_init:
            effector_state = eff_wait;
            break;
        
        case eff_execute:
            if(EFFECTOR_FLAG)
            {
                effector_state = eff_execute;
            }
            else
            {
                effector_state = eff_wait;
            }
            break;
        
        case eff_wait:
            if(EFFECTOR_FLAG)
            {
                effector_state = eff_execute;
            }
            else
            {
                effector_state = eff_wait; 
            }
            break;
        
        default:
            effector_state = eff_start;
            break;
    }    
}

enum arduino_states {ard_start, ard_init, ard_wait, ard_read, ard_write} arduino_state;
void arduino()
{
    //uint8 video_mux = data_array[ARD_BYTE_1];
    //uint8 laser = data_array[ARD_BYTE_2];
    
    switch(arduino_state) //state actions
    {
        case ard_start:
            break;
        
        case ard_init:
            //write initial video
            //write the laser enable
            break;
        
        case ard_wait:
            break;
        
        case ard_read:
            //for(int i = 0; i < ARD_ARRAY_SIZE; i++)
            //{
            //  feedback_array[i] = Arduino_UART_UARTGetChar();
            //{
            break;
        
        case ard_write:
            //write laser
            //write video
            ARD_FLAG = 0;
            break;
        
        default:
            arduino_state = ard_start;
            break;
    }
    switch(arduino_state) //state transitions
    {
        case ard_start:
            arduino_state = ard_init;
            break;
        
        case ard_init:
            arduino_state = ard_wait;
            break;
        
        case ard_wait:
            arduino_state = ard_read;
            break;
        
        case ard_read:
            if(ARD_FLAG)
            {
                arduino_state = ard_write;
            }
            else
            {
                arduino_state = ard_wait;
            }
            break;
            
        case ard_write:
            if(ARD_FLAG)
            {
                arduino_state = ard_write;
            }
            else
            {
                arduino_state = ard_wait;
            }
            break;
            
        default:
            arduino_state = ard_start;
            break;
    }   
}

//Initialization function for the program
void initialize()
{
    //initialize the wiznet
    WIZ_RST_Write(0);
    CyDelay(10);
    WIZ_RST_Write(1);
    WIZ_SS_Write(1);
    for(uint8 j=0; j<100; j++)
    {
        if(WIZ_RDY_Read())
        {
            break;
        }
        else
        {
            CyDelay(4);
        }
    }
    
    //Initialize state variables
    baseAzimuth_state = BA_start;
    wristTilt_state = tilt_start;
    wristRotate_state = rotate_start;
    shoulder_state = shldr_start;
    elbow_state = elbw_start;
    effector_state = eff_start;
    arduino_state = ard_start;
    
    //start all of our components
    SPIM_1_Start();
    Clock_pwm_Start();
    Clock_counter_Start();
    Wrist_UART_Start();
    SHLDR_PWM_Start();
    BA_PWM_Start();
    ELBW_PWM_Start();
    EFFECTOR_PWM_Start();
    ADC_Start();
    ADC_StartConvert();
    //start arduino
    
    wiznetInit(ownIpAddr, dstIpAddr, udpPort);
    
    //Initialize the dynamixels
    ServoSpeed(0xFE, 100);
    SetServoTorque(0xFE, 0x03FF);
    
    //Initialize our motor drivers
    ELBW_PWM_WriteCompare(1500); 
    SHLDR_PWM_WriteCompare(1500);
    CyDelay(3000);
    
    //initial calibration funtions for elbow and shoulder pots
    SHOULDER_UPPER_BOUND = CalibrationShoulder(1700);
    SHOULDER_LOWER_BOUND = CalibrationShoulder(1300);
    uint16 starting_shldr_pos = SHOULDER_UPPER_BOUND;
    uint16 feedback = potFeedback(SHOULDER_POT);
    while(feedback < SHOULDER_UPPER_BOUND)
    {
        SHLDR_PWM_WriteCompare(1900);
        feedback = potFeedback(SHOULDER_POT);
    }
    ELBOW_UPPER_BOUND = CalibrationElbow(1700);
    ELBOW_LOWER_BOUND = CalibrationElbow(1300);
    ELBW_PWM_WriteCompare(1700);
    CyDelay(2000);
    ELBW_PWM_WriteCompare(1500);
    
    //ISR stuff
    CyGlobalIntEnable;
    isr_1_StartEx(timer_isr);
    Timer_1_Start();    
}
int main()
{  
    //Define variables
    //wiznet = 0; //for testing -- see header move from here when establish ISR for wiznet
    uint8 BA_cspot;
    uint16 BA_array[BA_ARR_SIZE];
    uint8 shldr_cspot;
    uint16 shldr_array[SHLDR_ARR_SIZE];
    uint8 elbw_cspot;
    uint16 elbw_array[ELBW_ARR_SIZE];
    uint8 WT_cspot;
    uint16 WT_array[WT_ARR_SIZE];
    uint8 WR_cspot;
    uint16 WR_array[WR_ARR_SIZE];
    
    uint8 fs_count = 0; //fail safe counter to check the interval between receiving packets
    int16 temp_val = 1500; //do we need this still?
    
    initialize();

    for(;;)
    {   
        if(WIZ_INT_Read()==0) //!WIZ_INT_Read()--put wiznet in as condition if use ISR
        {
            wiznetClearInterrupts();
            fill_data_array();
            //TODO check addresses? -- set up error checking/reporting logic
            BA_FLAG = 1;
            WR_FLAG = 1;
            WT_FLAG = 1;
            SHOULDER_FLAG = 1;
            ELBOW_FLAG = 1;
            EFFECTOR_FLAG = 1;
            ARD_FLAG = 1;
            fs_count = 0;
            send_packet(1); //send heartbeat
            //wiznet = 0; //for testing
        }
        else
        {
            fs_count += 1;
        }
        
        if(fs_count >= 50)
        {
            temp_val = 1500;
            for(int i = 0; i < TEST_ARRAY_SIZE; (i+=2))
            {
                data_array[i] = temp_val >> 8;
                data_array[i+1] = temp_val & 0x00FF;
            }
        }
        else
        {
        
        //if(wiznet gives a complete packet)
            BA_cspot = baseAzimuth(BA_cspot, BA_array);
            shldr_cspot = shoulder(shldr_cspot, shldr_array);
            elbw_cspot = elbow(elbw_cspot, elbw_array);
            WT_cspot = wristTilt(WT_cspot, WT_array);
            WR_cspot = wristRotate(WR_cspot, WR_array);
            effector();
            //add arduino
            feedback_array[1] = (feedback_array[1] + 1);
            send_packet(0); //send feedback once every tick
            
        //else{dropped_packets++}
        }
        
        while(!timerFlag){} //this while loop will periodize our code to the time of longest path
        timerFlag = 0;
    } 
} 

/* [] END OF FILE */
