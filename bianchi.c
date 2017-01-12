/************************************************************/
/*--- for calculate propabilities beased on Bianchi 2005 ---*/
/************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "define.h"
#include "bianchi.h"

/**/
double sigma_pE(double p, double *E, int R){

  int i;
  double pi=1.0;
  double sum=0.0;

  for(i=0; i<=R; i++){
    sum += pi * E[i];
    pi *= p;
  }

  return sum;
}

double func_tau_ap(double p_ap){

  double new_p;

  //new_p = p_ap + ALPHA*(1-p_ap);
  //new_p = p_ap / (1-p_ap); //MM1
  //new_p = 1 - pow(1-p_ap, (double)K);
  //new_p = 1 - p_ap;
  new_p = p_ap;

  return  1.0 / (1 + (1 - new_p )/(1 - pow(new_p, R_ap+1.0)) * sigma_pE(new_p,E_ap,R_ap));
}


/**/
double func_tau_n(double tau_n, int n){

  double p_n;
  double p_ap;
  double tau_ap;

  /* tau_n -> p_ap */
  p_ap = 1 - pow(1-tau_n, (double)n);

  /* p_ap -> tau_ap */
  tau_ap = func_tau_ap(p_ap);

  /* tau_ap, tau_n -> p_n */
  p_n = 1 - pow(1-tau_n, (double)(n-1)) * (1-tau_ap);

  /* p_n -> tau_n , return tau_n - tau_n */
  return 1.0 / ( 1 + (1 - p_n)/( 1 - pow(p_n, R_n+1.0)) * sigma_pE(p_n, E_n, R_n)) - tau_n;

}

/********/
/* main */
/********/
double bianchi_tau_n(int n){

  double left_x = 1e-6, right_x = 1.0 - 1e-6, center_x;
  double left_y, right_y, center_y;

  do{
    left_y = func_tau_n(left_x, n);
    right_y = func_tau_n(right_x, n);

    if(left_y * right_y > 0){
      printf("left_x=%e,right_x=%e\n",left_x,right_x);
      printf("left_y=%e,right_y=%e\n",left_y,right_y);
      fprintf(stderr, "left_right error! %s:%d \n",__FILE__,__LINE__);
      exit(1);
    }
    
    center_x = 0.5 * (right_x + left_x);
    center_y = func_tau_n(center_x,n);
    
    if(left_y * center_y > 0){
      left_x = center_x;
      left_y = center_y;
    }
    
    else{
      right_x = center_x;
      right_y = center_y;
    }
    
  }while(right_x - left_x > NO_DIF);
  
  return 0.5 * (right_x + left_x);
}
