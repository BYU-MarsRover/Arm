/* ========================================
 *created by Samuel Bury Jan. 31, 2015
 *last modified date: Jan. 31, 2015
*/
#include <project.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

//Initializations of global variables
#define ELBOW_UPPER_BOUND 1000
#define ELBOW_LOWER_BOUND 100
#define SHOULDER_UPPER_BOUND 64000
#define SHOULDER_LOWER_BOUND 0
#define SHOULDER_POT 0
#define ELBOW_POT 1

#define BA_BYTE_1 4
#define BA_BYTE_2 5
#define SHLDR_BYTE_1 6
#define SHLDR_BYTE_2 7
#define ELBW_BYTE_1 8
#define ELBW_BYTE_2 9
#define WT_BYTE_1 10
#define WR_BYTE_2 11

#define DATA_ARRAY_SIZE 14
uint16 data_array[DATA_ARRAY_SIZE]; //stores the parsed instructions from the wiznet

uint8 wiznet; //bool indicating wiznet interupt high or low
uint8 new_pack; //bool indicating a new pack of instructions to carry out

#define NUM_OF_SM 3
uint8 fin_exec; //counts

#define TEST_ARRAY_SIZE 10
int16 test_array[TEST_ARRAY_SIZE];

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
uint8 timerFlag; //used in the timer_isr

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
//TODO do we need to make a header for good practice?

//---------------------------------------------------
//    Function stubs for the header
//---------------------------------------------------
void fill_data_array();
void baseAzimuth();
void shoulder();
void elbow();
void wristTilt();
void wristRotate();
void send_feedback();
uint16 potFeedback();
//--------------------------------------------------- END Function Stubs

// function to convert int to string
void reverse(char s[])
 {
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }
/* itoa:  convert n to characters in s */
 void itoa(int n, char s[])
 {
     int i, sign;
 
     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }



uint16 potFeedback(uint32 channel){
    uint16 feedback = ADC_GetResult16(channel);
    return feedback;
}
//to be used for parsing reading/parsing the data from the wiznet
void fill_data_array()
{
    uint8 i = 0;
    for(i = 0; i < TEST_ARRAY_SIZE; i++)
    {
        data_array[i] = test_array[i];
    }
}



enum wristTilt_states {tilt_init = 0, tilt_start, tilt_control, tilt_feedback} wristTilt_state;
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
    
        // Action
    switch(wristTilt_state)
    {
        case tilt_init:
            wristTilt_state = tilt_start;
            break;
        case tilt_start:
            // Set the torque - this is a one time thing
            // Set the speed - I think this is a one time thing
            break;
        case tilt_control:
            break;
        case tilt_feedback:
            break;
    }
        // Transistion
    switch(wristTilt_state)
    {
        case tilt_init:
            wristTilt_state = tilt_start;
            break;
        case tilt_start:
            wristTilt_state = tilt_control;
            break;
        case tilt_control:
            break;
        case tilt_feedback:
            break;
    }
}

enum wristRotate_states {rotate_init = 0, rotate_start, rotate_control, rotate_feedback} wristRotate_state;
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
    
        // Action
    switch(wristRotate_state)
    {
        case rotate_init:
            wristRotate_state = rotate_start;
            break;
        case rotate_start:
            // Set the torque - this is a one time thing
            // Set the speed - I think this is a one time thing
            break;
        case rotate_control:
            break;
        case rotate_feedback:
            break;
    }
        // Transistion
    switch(wristRotate_state)
    {
        case rotate_init:
            wristRotate_state = rotate_start;
            break;
        case rotate_start:
            wristRotate_state = rotate_control;
            break;
        case rotate_control:
            break;
        case rotate_feedback:
            break;
    }
}

void send_feedback()
{
    //compile all of the most recent feedback variables into a packet
    //necessary feedback variables: system state, dynamixel read write errors, PID errors
    //TODO define system state
    //send packet via serial to wiznet
}


//Average function to be used in smoothing our input
uint16 average(uint16* array, uint8 num_items)
{
    uint8 i;
    uint32 sum = 0;
    uint16 avg = 0;
    
    for(i = 0; i < num_items; i++)
    {
        sum += array[i];
    }
    
    avg = sum/num_items;
    
    return avg;
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
            break;

        case elbw_execute:
            command = (((data_array[ELBW_BYTE_1] << 8) | data_array[ELBW_BYTE_2])/2) + 1500;
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
           
            //uint16 feedback = potFeedback(ELBOW_POT);
            //TODO make sure reading from correct pots
            char buffer[20];
            
            itoa(avg, buffer);
            
            UART_1_UartPutString(buffer);      
            UART_1_UartPutString("\r\n");      
            
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
            break;

        case shldr_execute:
            command = (((data_array[SHLDR_BYTE_1] << 8) | data_array[SHLDR_BYTE_2])/2) + 1500;
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
           
            //uint16 feedback = potFeedback(SHOULDER_POT);
            
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
            break;

        case BA_execute:
            command = (((data_array[BA_BYTE_1] << 8) | data_array[BA_BYTE_2])/2) + 1500;
            baseAz_array[BA_arr_cspot] = command;
            if(BA_arr_cspot < (BA_ARR_SIZE - 1))
            {
                BA_arr_cspot++;
            }
            else
            {
                BA_arr_cspot = 0;
            }
            
//            if(command >= 1000 && command < 1100)
//            {
//                if(BA_arr_cspot != 0)
//                {
//                    if(baseAz_array[BA_arr_cspot - 1] >= 1020)
//                    {
//                        baseAz_array[BA_arr_cspot] = (baseAz_array[BA_arr_cspot - 1] - 20);
//                    }
//                    else
//                    {
//                        baseAz_array[BA_arr_cspot] = 1000;
//                    }
//                    
//                    if(BA_arr_cspot < (BA_ARR_SIZE - 1))
//                    {
//                        BA_arr_cspot++;
//                    }
//                    else
//                    {
//                        BA_arr_cspot = 0;
//                    }
//                }
//                else if(BA_arr_cspot == 0)
//                {
//                    if(baseAz_array[BA_ARR_SIZE - 1] >= 1020)
//                    {
//                        baseAz_array[BA_arr_cspot] = (baseAz_array[BA_ARR_SIZE - 1] - 20);
//                    }
//                    else
//                    {
//                        baseAz_array[BA_arr_cspot] = 1000;
//                    }
//                    
//                    if(BA_arr_cspot < (BA_ARR_SIZE - 1))
//                    {
//                        BA_arr_cspot++;
//                    }
//                    else
//                    {
//                        BA_arr_cspot = 0;
//                    }
//                }
//                else
//                {
//                    BA_arr_cspot = 0;
//                }
//            }
//            else if(command >= 1100 && command < 1300)
//            {
//                if(BA_arr_cspot != 0)
//                {
//                    baseAz_array[BA_arr_cspot] = (baseAz_array[BA_arr_cspot - 1] - 10);
//                    
//                    if(BA_arr_cspot < (BA_ARR_SIZE - 1))
//                    {
//                        BA_arr_cspot++;
//                    }
//                    else
//                    {
//                        BA_arr_cspot = 0;
//                    }
//                }
//                else if(BA_arr_cspot == 0)
//                {
//                    baseAz_array[BA_arr_cspot] = (baseAz_array[BA_ARR_SIZE - 1] - 10);
//                   
//                    if(BA_arr_cspot < (BA_ARR_SIZE - 1))
//                    {
//                        BA_arr_cspot++;
//                    }
//                    else
//                    {
//                        BA_arr_cspot = 0;
//                    }
//                }
//                else
//                {
//                    BA_arr_cspot = 0;   
//                }    
//            }
//            else if(command >= 1300 && command < 1490)
//            {
//                if(BA_arr_cspot != 0)
//                {
//                    baseAz_array[BA_arr_cspot] = (baseAz_array[BA_arr_cspot - 1] - 5);
//                    
//                    if(BA_arr_cspot < (BA_ARR_SIZE - 1))
//                    {
//                        BA_arr_cspot++;
//                    }
//                    else
//                    {
//                        BA_arr_cspot = 0;
//                    }
//                }
//                else if(BA_arr_cspot == 0)
//                {
//                    baseAz_array[BA_arr_cspot] = (baseAz_array[BA_ARR_SIZE - 1] - 5);
//                   
//                    if(BA_arr_cspot < (BA_ARR_SIZE - 1))
//                    {
//                        BA_arr_cspot++;
//                    }
//                    else
//                    {
//                        BA_arr_cspot = 0;
//                    }
//                }
//                else
//                {
//                    BA_arr_cspot = 0;   
//                }    
//            }
//            else if(command > 1510 && command <= 1700)
//            {
//                if(BA_arr_cspot != 0)
//                {
//                    baseAz_array[BA_arr_cspot] = (baseAz_array[BA_arr_cspot - 1] + 5);
//                    
//                    if(BA_arr_cspot < (BA_ARR_SIZE - 1))
//                    {
//                        BA_arr_cspot++;
//                    }
//                    else
//                    {
//                        BA_arr_cspot = 0;
//                    }
//                }
//                else if(BA_arr_cspot == 0)
//                {
//                    baseAz_array[BA_arr_cspot] = (baseAz_array[BA_ARR_SIZE - 1] + 5);
//                   
//                    if(BA_arr_cspot < (BA_ARR_SIZE - 1))
//                    {
//                        BA_arr_cspot++;
//                    }
//                    else
//                    {
//                        BA_arr_cspot = 0;
//                    }
//                }
//                else
//                {
//                    BA_arr_cspot = 0;   
//                }    
//            }
//            else if(command > 1700 && command <= 1900)
//            {
//                if(BA_arr_cspot != 0)
//                {
//                    baseAz_array[BA_arr_cspot] = (baseAz_array[BA_arr_cspot - 1] + 10);
//                    
//                    if(BA_arr_cspot < (BA_ARR_SIZE - 1))
//                    {
//                        BA_arr_cspot++;
//                    }
//                    else
//                    {
//                        BA_arr_cspot = 0;
//                    }
//                }
//                else if(BA_arr_cspot == 0)
//                {
//                    baseAz_array[BA_arr_cspot] = (baseAz_array[BA_ARR_SIZE - 1] + 10);
//                   
//                    if(BA_arr_cspot < (BA_ARR_SIZE - 1))
//                    {
//                        BA_arr_cspot++;
//                    }
//                    else
//                    {
//                        BA_arr_cspot = 0;
//                    }
//                }
//                else
//                {
//                    BA_arr_cspot = 0;   
//                }
//            }
//            else if(command > 1900 && command <= 2000)
//            {
//                if(BA_arr_cspot != 0)
//                {
//                    if(baseAz_array[BA_arr_cspot - 1] <= 1980)
//                    {
//                        baseAz_array[BA_arr_cspot] = (baseAz_array[BA_arr_cspot - 1] + 20);
//                    }
//                    else
//                    {
//                        baseAz_array[BA_arr_cspot] = 2000;
//                    }
//                    
//                    if(BA_arr_cspot < (BA_ARR_SIZE - 1))
//                    {
//                        BA_arr_cspot++;
//                    }
//                    else
//                    {
//                        BA_arr_cspot = 0;
//                    }
//                }
//                else if(BA_arr_cspot == 0)
//                {
//                    if(baseAz_array[BA_ARR_SIZE - 1] <= 1980)
//                    {
//                        baseAz_array[BA_arr_cspot] = (baseAz_array[BA_ARR_SIZE - 1] + 20);
//                    }
//                    else
//                    {
//                        baseAz_array[BA_arr_cspot] = 2000;
//                    }
//                    
//                    if(BA_arr_cspot < (BA_ARR_SIZE - 1))
//                    {
//                        BA_arr_cspot++;
//                    }
//                    else
//                    {
//                        BA_arr_cspot = 0;
//                    }
//                }
//                else
//                {
//                    BA_arr_cspot = 0;
//                }
//            }
//            else if(command <= 1510 && command >= 1490)
//            {
//                if(BA_arr_cspot < (BA_ARR_SIZE - 1))
//                {
//                    BA_arr_cspot++;
//                }
//                else
//                {
//                    BA_arr_cspot = 0;
//                }
//            }
//            else
//            {
//                //throw error
//                if(BA_arr_cspot < (BA_ARR_SIZE - 1))
//                {
//                    BA_arr_cspot++;
//                }
//                else
//                {
//                    BA_arr_cspot = 0;
//                }
//            }
            
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

int main()
{  
    CyGlobalIntEnable;
    
    //Define variables
    time_t t;
    uint8 counter;
    int direction = 0;
    
    //start all of our components
    Clock_pwm_Start();
    Clock_counter_Start();
    
    UART_1_Start();
    
    SHLDR_PWM_Start();
    BA_PWM_Start();
    ELBW_PWM_Start();
    
    ELBW_PWM_WriteCompare(1500); //Initialize our motor drivers
    SHLDR_PWM_WriteCompare(1500);
    CyDelay(10000);
   
    Timer_1_Start();
    
    ADC_Start();
    ADC_StartConvert();
    
    isr_1_StartEx(timer_isr);

    //helps for generating random arrays
    srand((unsigned) time(&t));
    
    for(;;)
    {
        //check addresses
        //TODO get the address bytes from Steve
        
        if(wiznet) //WIZ_INT_Read()
        {
            fill_data_array();
            new_pack = 1;
            fin_exec = 0;
        }
        
        baseAzimuth();
        shoulder();
        elbow();
//        wristTilt();
//        wristRotate();

        if(fin_exec == NUM_OF_SM)
        {
            new_pack = 0;
        }
        
        while(!timerFlag){} //this while loop will periodize our code to the time of longest path
        timerFlag = 0;
        
        counter++;
        
        if(counter == 20)
        {
            uint16 feedback1 = ADC_GetResult16(2);
            int16 forward = 1000;
            int16 backward = -1000;
            for(int i = 0; i < TEST_ARRAY_SIZE; (i+=2))
            {
//                int16 random_number = rand()%2001 - 1000;
//                test_array[i] = random_number >> 8;
//                test_array[i+1] = random_number & 0x00FF;
//                if((second_counter%2) == 0)
//                {
//                    test_array[i] = ;
//                }
                if (feedback1 > 500)
                {
                    test_array[i] = forward >> 8;
                    test_array[i+1] = forward & 0x00FF;
                }
                else if (feedback1 < 500)
                {
                    test_array[i] = backward >> 8;
                    test_array[i+1] = backward & 0x00FF;
                }
                else
                {
                    test_array[i] = 0;
                    test_array[i+1] = 0;
                }
                
            }
            counter = 0;
            wiznet = 1;
        }
        
//            //Potential solution to how we will want to send feedback
//            feedback_count++;
//            if(feedback_count == feedback_interval) //sends feeback to base station every 50th
//            {                                        //time through the full set of instructions
//                send_feedback();
//            }
    }
}

/* [] END OF FILE */
