#include <stdio.h>
#include <math.h>

#include "define.h"
#include "IEEE802_11.h"


void print_result(int n, double p_n, double tau_n){

  double th_n1;
  double Pi,Ps_n1,Pc;

  double Bo_n;
  double mod_S_TIME_n, mod_C_TIME, total_TIME;

  /* for throughput */
  Pi = pow(1-tau_n, (double)n);
  Ps_n1 = tau_n * pow(1-tau_n, (double)(n-1));
  Pc = 1 - Ps_n1 * n;

  Bo_n = 1.0/(CWmin+1);
  mod_S_TIME_n = S_TIME/(1-Bo_n) + I_TIME;
  mod_C_TIME = C_TIME + I_TIME;

  total_TIME = I_TIME*Pi + mod_S_TIME_n * Ps_n1 * n + mod_C_TIME * Pc;

  th_n1 = (Ps_n1 * DATA_SIZE/RATE)/total_TIME;

  printf("%d\t%f\n",n, p_n);

  return;
}
