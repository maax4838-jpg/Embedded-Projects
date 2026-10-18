/******************************************************************************
Max
Last Updated 7/28/2026
for a line follower robot 

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>

void motorUpdate(float out, float bsp)  //  updates motors speeds using output and base speed values
{
    float lmsp = bsp - out;  // if output is negative speeds up left motor
    float rmsp = bsp + out;  // if output is positive speeds up right motor 
    
    // keeps speed values in correct range
    if(lmsp > 255) lmsp = 255;
    if(lmsp < 0) lmsp = 0;
    if(rmsp > 255) rmsp = 255;
    if(rmsp < 0) rmsp = 0;
    //in actual robot will read to motors here 
    printf("\nLeft: %f  Right: %f\n", lmsp, rmsp);
    
}
float sumPID(float prop,float integral,float deriv)
{
    float output = prop + integral + deriv;
 return output;   
}

int main()
{
    float kp = 1, ki = 1, kd =0.002;  //  scale values
    float tVal = 50;  //  target value
    float aVal;  //  actual value
    float error = 0, integral = 0.0, lError = 0.0, prop = 0.0, deriv = 0.0;
    float output = 0;
    int breakVal = 1;  //  only for testing 
    float dt = 0.005;  //  time element for derivative will change when using robot 
    while(breakVal != 0)
    {   
        printf("enter actual value:");
        scanf("%f",&aVal); //  will read line sensor in robot
        printf("Actual Value: %f",aVal);
        error = tVal - aVal;  // calculates the most recent error 
        prop = error * kp; // error value scaled 
        integral += error * dt; // sum of all errors 
        if (integral > 500) integral = 500;
        if (integral < -500) integral = -500;
        printf("\nLast Error: %f", lError);
        deriv = ((error - lError)/dt)*kd; // looks at errors rate of change
        lError = error; //  tracks the last error
        output = sumPID(prop, integral*ki, deriv);
        printf("\nOutput: %f", output);
        printf("\nrecent Error: %f", error);
        motorUpdate(output, 150);
        printf("\n would you like to break the loop type 0 if yes\n");
        scanf("\n%d",&breakVal);
    }
    return 0;
}
/*
Things to add:
 
hardware mapping 
pattern detection(FML)

*/