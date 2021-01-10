/**
 *
 * @FILE        	: MTIMER.H
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


#ifndef MTIMER_T
#define MTIMER_T
#include <time.h>
typedef struct{
    struct timespec tstart, tend; 
}mtimer_t;

typedef struct{
    time_t sec;   /*seconds*/ 
    long   msec;  /*milli seconds*/
}mtime_diff_t;

extern void mtimer_start(mtimer_t *timer);
extern mtime_diff_t mtimer_end(mtimer_t *timer);
#endif
