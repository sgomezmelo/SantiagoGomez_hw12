#include <iostream>
using std::cout;
using std::endl;

double u_tnext(double u_tx, double dt, double dx, double c, double u_xant){
  double u = u_tx - c*(dt/dx)*(u_tx - u_xant);
  return u;
}

int main(){
  double  dx = 0.001;
  double dt = 0.001;
  double L = 4;
  double c = 1;
  int n_snaps = 700/5;

  
  int n_x = L/dx +1;
  int n_t = 700;
  
  double *u = new double[n_x];
  double *u_ant = new double[n_x];
  double *x = new double[n_x];
  
  x[0] = -L/2;

  /*Inicializacion de constantes y condicion inicial */
  for(int i = 1; i < n_x; i++){
    x[i] = x[i-1] + dx;
    double x_i = x[i];
    if((x_i < 0.5) && (x_i > -0.5)){
       u_ant[i] = 0.5;
     }
     else{
       u_ant[i] = 0;
     }
    cout << x_i << " " << u_ant[i] << endl;
  }

 /*Evolucion temporal */

   for(int j = 0; j < n_t;j++){
     for(int i = 0; i < n_x; i++){
       
       if((i == 0) || (i == n_x-1)){
	 u[i] = u_ant[i];
       }
       else{
	 u[i] = u_tnext(u_ant[i],dt,dx,c,u_ant[i-1]);
       }
     }

     int iter = j+1;
 /*Impresion de los snaps */
     if((iter%n_snaps == 0)){
       for(int i = 0; i < n_x; i++){
	 cout << x[i] << " " << u[i] << endl;
       }
     }
 /*Actualizacion de la funcion del punto anterior */
     for(int i = 0; i < n_x; i++){
       u_ant[i] = u[i];
     }
   }
 
   return 0;
  
}
