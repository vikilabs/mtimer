/**
 *
 * @FILE        	: MTIMER.C
 * @DESCRIPTION 	: SIMPLE TIMER LIBRARY
 *
 * @AUTHOR      	: VIKI ( VIGNESH NATARAJAN )
 * @CONTACT         	: VIKILABS.ORG
 *
 */

/*
    Copyright (c) 2016 Viki( Vignesh Natarajan )
    
    Contact @ vikilabs.org

    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the Software
    is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
    OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


#include "mtimer.h"


#include <unistd.h>
#include <stdio.h>
#include <string.h>


void timer_start(mtimer_t *timer)
{
    if(!timer) {
        printf("( error ) timer is NULL ->  ms_timer_start()");
        return;
    }

    memset(&(timer->tstart), 0x0, sizeof(struct timespec)); 
    memset(&(timer->tend)  , 0x0, sizeof(struct timespec)); 
    clock_gettime(CLOCK_MONOTONIC, &(timer->tstart));
}

mtime_diff_t timer_end(mtimer_t *timer)
{
    mtime_diff_t diff;

    diff.sec = 0;
    diff.msec = 0;

    if(!timer) {
        printf("( error ) timer is NULL ->  ms_timer_start()");
        return diff;
    }
    clock_gettime(CLOCK_MONOTONIC, &timer->tend);

    diff.msec = (timer->tend.tv_nsec - timer->tstart.tv_nsec)/1000000;
    diff.sec  = timer->tend.tv_sec - timer->tstart.tv_sec; 
    memset(&(timer->tstart), 0x0, sizeof(struct timespec)); 
    memset(&(timer->tend)  , 0x0, sizeof(struct timespec)); 
    return diff;
}

#if 0 //TEST CODE
int main()
{
    mtimer_t timer;
    mtime_diff_t diff;

    timer_start(&timer);
    usleep(1100 * 1000);
    diff = timer_end(&timer);

    printf("diff_sec  = %d\n", (int)diff.sec);
    printf("diff_msec = %d\n", (int)diff.msec);

}
#endif
