#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "IEEE802_11.h"
#include "define.h"

/**************************************/
/**************************************/
int main(int argc, char *argv[]){

  int node_n;
  double tau_n, p_n, tau_ap, p_ap;
  extern double bianchi_tau_n(int);
  extern double func_tau_ap(double);
  extern void print_result(int, double, double, double, double);

  for( node_n = 1; node_n <= NODE_MAX; node_n++){

    /* tau_n */
    tau_n = bianchi_tau_n(node_n);

    /* tau_n -> p_ap */
    p_ap = 1 - pow(1-tau_n, (double)node_n);

    /* p_ap -> tau_ap */
    tau_ap = func_tau_ap(p_ap);

    /* tau_ap, tau_n -> p_n */
    p_n = 1 - pow( 1-tau_n, (double)(node_n-1)) * (1-tau_ap);

    print_result(node_n, p_ap, tau_ap, p_n, tau_n);
  }

  return 0;
}
