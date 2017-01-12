#ifndef _BIANCHI_H
#define _BIANCHI_H

#include "IEEE802_11.h"

#define R_n 6
//#define R_ap 6

#define NO_DIF 1e-9

#if defined IEEE802_11b 
double E_n[R_n+1] = {30*0.5, 63*0.5, 127*0.5, 255*0.5, 511*0.5, 1023*0.5, 1023*0.5};

#elif defined IEEE802_11g 
double E_n[R_n+1] = {14*0.5, 31*0.5, 63*0.5, 127*0.5, 255*0.5, 512*0.5, 1023*0.5};

#elif defined IEEE802_11a
double E_n[R_n+1] = {14*0.5, 31*0.5, 63*0.5, 127*0.5, 255*0.5, 511*0.5, 1023*0.5};

#endif


#endif  //#ifndef _BIANCHI_H
