#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define f(x,y) (sqrt(x+y))
int main()
{
    printf("Welcome to Runge-Kutta\n");
    float yInitial, xInitial, xFinal,h,k1, k2, k3,k4, k, y;
    printf("Enter the initial value of x\n");
    scanf("%f", &xInitial);
    printf("Enter the initial value of y\n");
    scanf("%f", &yInitial);
    printf("Enter the value of h\n");
    scanf("%f", &h);
    printf("Enter the final value of x\n");
    scanf("%f", &xFinal);

    int iteration = (xFinal - xInitial)/h;
    printf("No of Iterations is %d\n", iteration);
     FILE * Runge;
  Runge = fopen("Question 4.txt", "w");
  fprintf(Runge, "%0.1f\t%0.4f\n",xInitial,yInitial);
    int i;
 for(i=0; i < iteration; i++)
 {
  k1 = h * (f(xInitial, yInitial));
  k2 = h * (f((xInitial+h/2), (yInitial+k1/2)));
  k3 = h * (f((xInitial+h/2), (yInitial+k2/2)));
  k4 = h * (f((xInitial+h), (yInitial+k3)));
  k = (k1+2*k2+2*k3+k4)/6;

  y = yInitial + k;
  printf("%0.1f\t%0.4f\n",xInitial,y);
  xInitial = xInitial+h;
  yInitial = y;
  fprintf(Runge,"%0.1f\t%0.4f\n",xInitial, y);

 }
 fclose(Runge);
}
