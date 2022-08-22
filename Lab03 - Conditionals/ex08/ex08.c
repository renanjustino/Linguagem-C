#include <stdio.h>
#include <stdlib.h>

int main()
{
float a, b, c, x1, x2;
float delta;
printf("Digite a: ");
scanf("%f", &a);
printf("Digite b: ");
scanf("%f", &b);
printf("Digite c: ");
scanf("%f", &c);
delta = (b*b) - (4*a*c);
if(delta>0){
x1 = (-b + (sqrt(delta))) / (2*a);
x2 = (-b - (sqrt(delta))) / (2*a);
printf("X1 = %.2f\n", x1);
printf("X2 = %.2f\n", x2);
}
else if(delta=0){
x1 = -b/(2*a);
printf("X = %.2f\n",x1);
}
else
printf("Delta Negativo!");
}



