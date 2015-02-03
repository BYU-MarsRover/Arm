/* ========================================
 *created by Samuel Bury Jan. 31, 2015
 *last modified date: Jan. 31, 2015
*/
#include <project.h>

//Initializations of global variables
//TODO should this be global or should we declare it in main and pass a
//////pointer to each function?
uint8 data_array[14]; //stores the parsed instructions from the wiznet
uint16 feedback_count;
uint8 timerFlag;

//this ISR will be used to set our timeFlag according to our timer component
///set to the time of the longest path for our code
//TODO test how long it takes code to run before really implementing this
/*
CY_ISR(timer_isr)
{
    uint32 isr_var = Timer_1_GetInterruptSourceMasked();
    
    timerFlag = 1;
    
    Timer_1_ClearInterrupt(isr_var);
}
*/

//Funtion declarations/definitions
//TODO do we need to make a header for good practice?

//to be used for parsing reading/parsing the data from the wiznet
void fill_data_array() //maybe take param: uint8* array
{
    //read one byte at a time
}

//control the turret
void baseAzimuth()
{
    //take instruction from data_array
    //smooth input
    //actuate the turret using PWM
}

//control the shoulder
void shoulder()
{
    //take instruction from data_array
    //smooth input
    //actuate the shoulder using PWM
    //get feedback
}

//control the elbow
void elbow()
{
    //take instruction from data_array
    //smooth input
    //actuate the elbow using PWM
    //get feedback
}

//control the tilting motion of the wrist
void wristTilt()
{
    //take instruction from data_array
    //smooth input
    //actuate the tilting using UART
    //get feedback
}

//control the rotating motion of the wrist
void wristRotate()
{
    //take instruction from data_array
    //smooth input
    //actuate the turret using UART
    //get feedback
}

void send_feedback()
{
    //compile all of the most recent feedback variables into a packet
    //necessary feedback variables: system state, dynamixel read write errors, PID errors
    //TODO define system state
    //send packet via serial to wiznet
}

int main()
{
    //CyGlobalIntEnable;
    
    //start all of our components
    
    //ISR_StartEx(timer_isr);
    
    for(;;)
    {
        //check addresses
        //TODO get the address bytes from Steve
        
        fill_data_array(); //potentially take input &data_array
        baseAzimuth();
        shoulder();
        elbow();
        wristTilt();
        wristRotate();
        
        /*
        while(!timerFlag) //this while loop will periodize our code to the time of longest path
        {
            //Potential solution to how we will want to send feedback
            feedback_count++;
            if(feedback_count == feedback_interval) //sends feeback to base station every 50th
            {                                        //time through the full set of instructions
                send_feedback();
            }
        }
        timerFlag = 0;
        */
    }
}

/* [] END OF FILE */
