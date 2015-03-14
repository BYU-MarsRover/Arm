/* ========================================
 *created by Samuel Bury Jan. 31, 2015
*/

#include "main.h"

//this ISR will be used to set our timeFlag according to our timer component
///set to the time of the longest path for our code
//TODO test how long it takes code to run before really implementing this
CY_ISR(timer_isr)
{
    uint32 isr_var = Timer_1_GetInterruptSourceMasked();
    timerFlag = 1;
    Timer_1_ClearInterrupt(isr_var);
}

//Funtion declarations/definitions

//// function to convert int to string
//void reverse(char s[])
// {
//     int i, j;
//     char c;
// 
//     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
//         c = s[i];
//         s[i] = s[j];
//         s[j] = c;
//     }
// }
///* itoa:  convert n to characters in s */
// void itoa(int n, char s[])
// {
//     int i, sign;
// 
//     if ((sign = n) < 0)  /* record sign */
//         n = -n;          /* make n positive */
//     i = 0;
//     do {       /* generate digits in reverse order */
//         s[i++] = n % 10 + '0';   /* get next digit */
//     } while ((n /= 10) > 0);     /* delete it */
//     if (sign < 0)
//         s[i++] = '-';
//     s[i] = '\0';
//     reverse(s);
// }


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

void pos_to_vel(uint8 cur_pos, uint16* array, uint8 ARRAY_SIZE, uint16 command)
{
    if(command >= 1000 && command < 1100)
    {
        if(cur_pos != 0)
        {
            if(array[cur_pos - 1] >= 1020)
            {
                array[cur_pos] = (array[cur_pos - 1] - 20);
            }
            else
            {
                array[cur_pos] = 1000;
            }
            
            if(cur_pos < (ARRAY_SIZE - 1))
            {
                cur_pos++;
            }
            else
            {
                cur_pos = 0;
            }
        }
        else if(cur_pos == 0)
        {
            if(array[ARRAY_SIZE - 1] >= 1020)
            {
                array[cur_pos] = (array[ARRAY_SIZE - 1] - 20);
            }
            else
            {
                array[cur_pos] = 1000;
            }
            
            if(cur_pos < (ARRAY_SIZE - 1))
            {
                cur_pos++;
            }
            else
            {
                cur_pos = 0;
            }
        }
        else
        {
            cur_pos = 0;
        }
    }
    else if(command >= 1100 && command < 1300)
    {
        if(cur_pos != 0)
        {
            array[cur_pos] = (array[cur_pos - 1] - 10);
            
            if(cur_pos < (ARRAY_SIZE - 1))
            {
                cur_pos++;
            }
            else
            {
                cur_pos = 0;
            }
        }
        else if(cur_pos == 0)
        {
            array[cur_pos] = (array[ARRAY_SIZE - 1] - 10);
           
            if(cur_pos < (ARRAY_SIZE - 1))
            {
                cur_pos++;
            }
            else
            {
                cur_pos = 0;
            }
        }
        else
        {
            cur_pos = 0;   
        }    
    }
    else if(command >= 1300 && command < 1490)
    {
        if(cur_pos != 0)
        {
            array[cur_pos] = (array[cur_pos - 1] - 5);
            
            if(cur_pos < (ARRAY_SIZE - 1))
            {
                cur_pos++;
            }
            else
            {
                cur_pos = 0;
            }
        }
        else if(cur_pos == 0)
        {
            array[cur_pos] = (array[ARRAY_SIZE - 1] - 5);
           
            if(cur_pos < (ARRAY_SIZE - 1))
            {
                cur_pos++;
            }
            else
            {
                cur_pos = 0;
            }
        }
        else
        {
            cur_pos = 0;   
        }    
    }
    else if(command > 1510 && command <= 1700)
    {
        if(cur_pos != 0)
        {
            array[cur_pos] = (array[cur_pos - 1] + 5);
            
            if(cur_pos < (ARRAY_SIZE - 1))
            {
                cur_pos++;
            }
            else
            {
                cur_pos = 0;
            }
        }
        else if(cur_pos == 0)
        {
            array[cur_pos] = (array[ARRAY_SIZE - 1] + 5);
           
            if(cur_pos < (ARRAY_SIZE - 1))
            {
                cur_pos++;
            }
            else
            {
                cur_pos = 0;
            }
        }
        else
        {
            cur_pos = 0;   
        }    
    }
    else if(command > 1700 && command <= 1900)
    {
        if(cur_pos != 0)
        {
            array[cur_pos] = (array[cur_pos - 1] + 10);
            
            if(cur_pos < (ARRAY_SIZE - 1))
            {
                cur_pos++;
            }
            else
            {
                cur_pos = 0;
            }
        }
        else if(cur_pos == 0)
        {
            array[cur_pos] = (array[ARRAY_SIZE - 1] + 10);
           
            if(cur_pos < (ARRAY_SIZE - 1))
            {
                cur_pos++;
            }
            else
            {
                cur_pos = 0;
            }
        }
        else
        {
            cur_pos = 0;   
        }
    }
    else if(command > 1900 && command <= 2000)
    {
        if(cur_pos != 0)
        {
            if(array[cur_pos - 1] <= 1980)
            {
                array[cur_pos] = (array[cur_pos - 1] + 20);
            }
            else
            {
                array[cur_pos] = 2000;
            }
            
            if(cur_pos < (ARRAY_SIZE - 1))
            {
                cur_pos++;
            }
            else
            {
                cur_pos = 0;
            }
        }
        else if(cur_pos == 0)
        {
            if(array[ARRAY_SIZE - 1] <= 1980)
            {
                array[cur_pos] = (array[ARRAY_SIZE - 1] + 20);
            }
            else
            {
                array[cur_pos] = 2000;
            }
            
            if(cur_pos < (ARRAY_SIZE - 1))
            {
                cur_pos++;
            }
            else
            {
                cur_pos = 0;
            }
        }
        else
        {
            cur_pos = 0;
        }
    }
    else if(command <= 1510 && command >= 1490)
    {
        if(cur_pos < (ARRAY_SIZE - 1))
        {
            cur_pos++;
        }
        else
        {
            cur_pos = 0;
        }
    }
    else
    {
        //throw error
        if(cur_pos < (ARRAY_SIZE - 1))
        {
            cur_pos++;
        }
        else
        {
            cur_pos = 0;
        }
    }
}

void make_command(uint16* act_array, uint8 act_cspot, int8* info_array, uint8 byte1, uint8 byte2)
{
    int16 command;
    int16 temp1;
    int16 temp2;
    int16 temp3;
    
    temp1 = (info_array[byte1] << 8) & 0xFF00;
    temp2 = 0x00FF & (info_array[byte2]);
    temp3 = temp1 | temp2;
    command = temp3/2 + 1500;
    act_array[act_cspot] = command;
}

uint16 potFeedback(uint32 channel)
{
    //uint16 feedback = ADC_GetResult16(channel);
    uint16 feedback = 500;
    return feedback;
}

void send_feedback()
{
    //compile all of the most recent feedback variables into a packet
    //necessary feedback variables: system state, dynamixel read write errors, PID errors
    //TODO define system state
    //send packet via serial to wiznet
}

//to be used for parsing reading/parsing the data from the wiznet
void fill_data_array()
{
   // wiznetReadUdpFrame(data_array, DATA_ARRAY_SIZE);
    uint8 i = 0;
    for(i = 0; i < TEST_ARRAY_SIZE; i++)
    {
        data_array[i] = test_array[i];
    }
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
    
    UART_1_SpiUartPutArray(array, 0x09);  
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
    
    UART_1_SpiUartPutArray(array, 0x09);
    
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
    
    UART_1_SpiUartPutArray(array, 0x09);
    
}

enum wristTilt_states {tilt_start, tilt_init, tilt_control, tilt_wait, tilt_feedback} wristTilt_state;
//control the tilting motion of the wrist
void wristTilt()
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
    
    switch(wristTilt_state){ //actions
        case tilt_start:
            break;

        case tilt_init:
            for(i = 0; i < WT_ARR_SIZE; i++)
            {
                WT_array[i] = 1500;
            }
            WT_arr_cspot = 0;
            
            break;

        case tilt_control:
            make_command(WT_array, WT_arr_cspot, data_array, WT_BYTE_1, WT_BYTE_2);
            
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
                //UART_1_SpiUartPutArray(avg);
                ServoGoalPosition(0x02, avg);
            }
            else
            {
                //throw error
                //BA_PWM_WriteCompare(1500);
                ServoGoalPosition(0x02, 1500);
            }
            fin_exec++;
            break;
            
        case tilt_wait:
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
            if(new_pack)
            {
                wristTilt_state = tilt_control;
            }
            else
            {
                wristTilt_state = tilt_wait;
            }
            break;
        
        case tilt_wait:
            if(new_pack)
            {
                wristTilt_state = tilt_control;
            }
            else
            {
                wristTilt_state = tilt_wait; 
            }
            break;
    }    
}

enum wristRotate_states {rotate_start, rotate_init, rotate_control, rotate_wait, rotate_feedback} wristRotate_state;
//control the rotating motion of the wrist
void wristRotate()
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
    
    switch(wristRotate_state){ //actions
        case rotate_start:
            break;

        case rotate_init:
            for(i = 0; i < WR_ARR_SIZE; i++)
            {
                WR_array[i] = 1500;
            }
            WR_arr_cspot = 0;
            break;

        case rotate_control:
            make_command(WR_array, WR_arr_cspot, data_array, WR_BYTE_1, WR_BYTE_2);
            
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
                //BA_PWM_WriteCompare(avg);
                //TODO maybe scale avg between 0 and 3000
                ServoGoalPosition(0x01, avg);
            }
            else
            {
                //throw error
                //BA_PWM_WriteCompare(1500);
                //TODO if we scale change the "neutral" value
                ServoGoalPosition(0x01, 1500);
            }
            fin_exec++;
            break;
            
        case rotate_wait:
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
            if(new_pack)
            {
                wristRotate_state = rotate_control;
            }
            else
            {
                wristRotate_state = rotate_wait;
            }
            break;
        
        case rotate_wait:
            if(new_pack)
            {
                wristRotate_state = rotate_control;
            }
            else
            {
                wristRotate_state = rotate_wait;
            }
            break;
    }    
}

//control the elbow
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
enum elbow_states {elbw_start,elbw_init,elbw_execute,elbw_wait} elbow_state;
void elbow()
{ 
    //take instruction from data_array
    //smooth input
    //actuate the elbow using PWM
    //get feedback
    uint8 i;
    uint16 avg;
    
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
            break;

        case elbw_execute:
            make_command(elbow_array, elbw_arr_cspot, data_array, ELBW_BYTE_1, ELBW_BYTE_2);
            
            if(elbw_arr_cspot < (ELBW_ARR_SIZE - 1))
            {
                elbw_arr_cspot++;
            }
            else
            {
                elbw_arr_cspot = 0;
            }
            avg = average(elbow_array, ELBW_ARR_SIZE);
           
            //uint16 feedback = potFeedback(ELBOW_POT); --see above
            //TODO make sure reading from correct pots
//            char buffer[20];
//            
//            itoa(avg, buffer);
//            
//            UART_1_UartPutString(buffer);      
//            UART_1_UartPutString("\r\n");      
            
            if(feedback <= ELBOW_LOWER_BOUND)
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
            else if (feedback >= ELBOW_UPPER_BOUND)
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
                    ELBW_PWM_WriteCompare(1500);
                }
            }
            
            fin_exec++;
            break;
            
        case elbw_wait:
            if(feedback <= ELBOW_LOWER_BOUND || feedback >= ELBOW_UPPER_BOUND)
            {
                ELBW_PWM_WriteCompare(1500);
            }
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
            if(new_pack)
            {
                elbow_state = elbw_execute;
            }
            else
            {
                elbow_state = elbw_wait;
            }
            break;
        
        case elbw_wait:
            if(new_pack)
            {
                elbow_state = elbw_execute;
            }
            else
            {
                elbow_state = elbw_wait; 
            }
            break;
    }    
}

//control the shoulder
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
enum shoulder_states {shldr_start,shldr_init,shldr_execute,shldr_wait} shoulder_state;
void shoulder()
{ 
    //take instruction from data_array
    //smooth input
    //actuate the shoulder using PWM
    //get feedback
    uint8 i;
    uint16 avg;
    int16 command;
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
            break;

        case shldr_execute:
            make_command(shoulder_array, shldr_arr_cspot, data_array, SHLDR_BYTE_1, SHLDR_BYTE_2);
            
            if(shldr_arr_cspot < (SHLDR_ARR_SIZE - 1))
            {
                shldr_arr_cspot++;
            }
            else
            {
                shldr_arr_cspot = 0;
            }
            avg = average(shoulder_array, SHLDR_ARR_SIZE);
           
            //uint16 feedback = potFeedback(SHOULDER_POT); -- see above
            
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
                        //throw error
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
            
            fin_exec++;
            break;
            
        case shldr_wait:
            if(feedback <= SHOULDER_LOWER_BOUND || feedback >= SHOULDER_UPPER_BOUND)
            {
                SHLDR_PWM_WriteCompare(1500);
            }
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
            if(new_pack)
            {
                shoulder_state = shldr_execute;
            }
            else
            {
                shoulder_state = shldr_wait;
            }
            break;
        
        case shldr_wait:
            if(new_pack)
            {
                shoulder_state = shldr_execute;
            }
            else
            {
                shoulder_state = shldr_wait; 
            }
            break;
    }    
}

//control the turret
enum baseAzimuth_states {BA_start,BA_init,BA_execute,BA_wait} baseAzimuth_state;
void baseAzimuth()
{ 
    //take instruction from data_array
    //smooth input
    //actuate the turret using PWM
    uint8 i;
    uint16 avg;
    
    switch(baseAzimuth_state){ //actions
        case BA_start:
            break;

        case BA_init:
            for(i = 0; i < BA_ARR_SIZE; i++)
            {
                baseAz_array[i] = 1500;
            }
            BA_arr_cspot = 0;
            break;

        case BA_execute:
            make_command(baseAz_array, BA_arr_cspot, data_array, BA_BYTE_1, BA_BYTE_2);
            
            if(BA_arr_cspot < (BA_ARR_SIZE - 1))
            {
                BA_arr_cspot++;
            }
            else
            {
                BA_arr_cspot = 0;
            }
            
            //pos_to_vel(BA_arr_cspot, baseAz_array, BA_ARR_SIZE, command);
            
            avg = average(baseAz_array, BA_ARR_SIZE);
            
            if(avg <= 2000 && avg >= 1000)
            {
                BA_PWM_WriteCompare(avg);
            }
            else
            {
                //throw error
                BA_PWM_WriteCompare(1500);
            }
            fin_exec++;
            break;
            
        case BA_wait:
            break;
    }
    
    switch(baseAzimuth_state){ //transitions
        case BA_start:
            baseAzimuth_state = BA_init;
            break;
        
        case BA_init:
            baseAzimuth_state = BA_wait;
            break;
        
        case BA_execute:
            if(new_pack)
            {
                baseAzimuth_state = BA_execute;
            }
            else
            {
                baseAzimuth_state = BA_wait;
            }
            break;
        
        case BA_wait:
            if(new_pack)
            {
                baseAzimuth_state = BA_execute;
            }
            else
            {
                baseAzimuth_state = BA_wait; 
            }
            break;
    }    
}

//Initialization function for the program
void initialize()
{
    //Initialize state variables
    baseAzimuth_state = BA_start;
    wristTilt_state = tilt_start;
    wristRotate_state = rotate_start;
    shoulder_state = shldr_start;
    elbow_state = elbw_start;
    
    //start all of our components
    Clock_pwm_Start();
    Clock_counter_Start();
    UART_1_Start();
    SHLDR_PWM_Start();
    BA_PWM_Start();
    ELBW_PWM_Start();
    
    wiznetInit(ownIpAddr, dstIpAddr, udpPort);
    
    //Initialize the dynamixels
    ServoSpeed(0xFE, 100);
    SetServoTorque(0xFE, 0x03FF);
    
    //Initialize our motor drivers
    ELBW_PWM_WriteCompare(1500); 
    SHLDR_PWM_WriteCompare(1500);
    CyDelay(3000);
   
    ADC_Start();
    ADC_StartConvert();
    
    //helps for generating random arrays
    //srand((unsigned) time(&t));
    
    CyGlobalIntEnable;
    isr_1_StartEx(timer_isr);
    Timer_1_Start();
}

int main()
{  
    //Define variables
    time_t t;
    uint8 counter;
    int direction = 0;
    int16 temp_val= -1000;
    wiznet = 0;
    
    //for testing
    int increasing = 1;
    
    initialize();

    for(;;)
    {
        //check addresses
        //TODO get the address bytes from Steve
        //TODO at what point should we send feedback?
        
        if(wiznet) //!WIZ_INT_Read()
        {
            //wiznetClearInterrupts();
            fill_data_array();
            new_pack = 1;
            fin_exec = 0;
            wiznet = 0;
        }
        
        baseAzimuth();
        shoulder();
        elbow();
        wristTilt();
        wristRotate();

        if(fin_exec == NUM_OF_SM)
        {
            new_pack = 0;
        }
        
        while(!timerFlag){} //this while loop will periodize our code to the time of longest path
        timerFlag = 0;
        
/*``````````````````````````````````````````````````````````````````````````*
 * From here to the end of the main function is purely for testing purposes *
 *``````````````````````````````````````````````````````````````````````````*/
        counter++;
        
        if(counter == 50)
        {
        
            if(increasing)
            {
                temp_val += 100;
                if(temp_val == 1000)
                {
                    increasing = 0;
                }
            }
            else
            {
                temp_val -= 100;
                if(temp_val == -1000)
                {
                    increasing = 1;   
                }
            }
            
            //uint16 feedback1 = ADC_GetResult16(2);
            //int16 forward = 1000;
            //int16 backward = -1000;
            for(int i = 0; i < TEST_ARRAY_SIZE; (i+=2))
            {
                //int16 random_number = rand()%2001 - 1000;
                //test_array[i] = random_number >> 8;
                //test_array[i+1] = random_number & 0x00FF;
                test_array[i] = temp_val >> 8;
                test_array[i+1] = temp_val & 0x00FF;
            }
            counter = 0;
            wiznet = 1;
        }
    }
//                if((second_counter%2) == 0)
//                {
//                    test_array[i] = ;
//                }
            
//                if (feedback1 > 500)
//                {
//                    test_array[i] = forward >> 8;
//                    test_array[i+1] = forward & 0x00FF;
//                }
//                else if (feedback1 < 500)
//                {
//                    test_array[i] = backward >> 8;
//                    test_array[i+1] = backward & 0x00FF;
//                }
//                else
//                {
//                    test_array[i] = 0;
//                    test_array[i+1] = 0;
//                }
//                
//            }
//            counter = 0;
//            wiznet = 1;
//        }
//        
////            //Potential solution to how we will want to send feedback
////            feedback_count++;
////            if(feedback_count == feedback_interval) //sends feeback to base station every 50th
////            {                                        //time through the full set of instructions
////                send_feedback();
////            }
} //<<--- END OF MAIN()!!!

/* [] END OF FILE */
