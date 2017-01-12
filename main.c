#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "IEEE802_11.h"
#include "define.h"

/**************************************/
/**************************************/
int main(int argc, char *argv[]){

  int node_n;
  double tau_n, p_n;
  extern double bianchi_tau_n(int);

  for( node_n = 1; node_n <= NODE_MAX; node_n++){

    /* tau_n */
    tau_n = bianchi_tau_n(node_n);

    /* tau_n -> p_n */
    p_n = 1 - pow( 1-tau_n, (double)(node_n-1));
    
    print_result(node_n, p_n, tau_n);
  }

  return 0;
}
