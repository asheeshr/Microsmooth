#include "autotune.h"

int ams_init()
{

    return 0;
}


void ams_tuning()
{
    int option=0, exectime;

    /* Generate menu and input options */
    Serial.println("This is the tuning module for the Microsmooth library.");
    Serial.println("Please select a tuning function to use:");
    Serial.println("(S)MA (E)MA (C)MA S(G)A (K)ZA (R)DP");
    if (Serial.available() > 0) 
    {
	option = Serial.read();
    }
	
    Serial.println("Enter the time within which the smoothing function may run:");
    if (Serial.available() > 0) 
    {
	exectime = Serial.parseInt();
	/* TBD: Check for lower bound */
    }
    
	
    switch(option)
    {
    case 'S':ams_sma(exectime);
	break;

    case 'E':ams_ema(exectime);
	break;    
	
    case 'C':;
	break;
	
    case 'G':;
	break;
    
    case 'K':;
	break;    

    case 'R':;
	break;

    default:
	    Serial.println("Invalid option.");
    }
    

}


int ams_sma(int maxtime)
{
    return 0;
}

int ams_ema(int maxtime)
{
    return 0;
}
