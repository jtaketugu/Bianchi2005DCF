#ifndef _BIANCHI_H
#define _BIANCHI_H

#include "IEEE802_11.h"
#include "define.h"

#if defined IEEE802_11b 
double E_n[R_n+1] = {30*0.5, 63*0.5, 127*0.5, 255*0.5, 511*0.5, 1023*0.5, 1023*0.5, 1023*0.5};

#elif defined IEEE802_11g 
double E_n[R_n+1] = {14*0.5, 31*0.5, 63*0.5, 127*0.5, 255*0.5, 512*0.5, 1023*0.5, 1023*0.5};

#elif defined IEEE802_11a
double E_n[R_n+1] = {14*0.5, 31*0.5, 63*0.5, 127*0.5, 255*0.5, 511*0.5, 1023*0.5, 1023*0.5};

#endif

// E[i] of AP
//double E_ap[R_n+1] = {62*0.5, 31*0.5, 15*0.5, 7*0.5, 3*0.5, 3*0.5, 3*0.5, 3*0.5};
double E_ap[R_n+1] = {30*0.5, 63*0.5, 127*0.5, 255*0.5, 511*0.5, 1023*0.5, 1023*0.5, 1023*0.5};

extern double func_tau_ap(double);

#endif  //#ifndef _BIANCHI_H




