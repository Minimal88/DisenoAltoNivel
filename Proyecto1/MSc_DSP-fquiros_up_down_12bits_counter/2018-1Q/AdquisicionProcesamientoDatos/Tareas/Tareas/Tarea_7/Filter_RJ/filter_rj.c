/*
 */

#include <std.h>
#include <stdio.h>

#include <log.h>
#include <clk.h>
#include <tsk.h>
#include <gbl.h>

#include "Filter_RJcfg.h"


/*
 *  ======== main ========
 */
Void main()
{
    printf("Filter started...\n");
}

Void taskFxn(Arg value_arg)
{
    Int value = ArgToInt (value_arg); 
    LgUns freq; 

    //LOG_printf(&trace, "Argument is %i \n", value);
	printf("Argument is %i \n", value);

    /* get frequency of platform */
        
    freq = GBL_getFrequency();
    //LOG_printf(&trace, "...awake! GBL Freq is: %lu \n", (LgUns)freq);
	printf("Frequency is %lu \n", freq);
}
