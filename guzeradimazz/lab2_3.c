//
//  main.c
//  2.2.6requorsion
//
//  Created by Дима Гузерчук on 23.03.21.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n = 0;
float x, epsylon;

double sinus_requorsion(double number){
    if (fabs(number)<epsylon)return number;
    else{
        n++;
        double temp =(-number * (x*x)/(2*number)/(2*number+1));
        return number+sinus_requorsion(temp);
    }
}
int main(int argc, const char * argv[]) {
    printf("Enter x: ");
    scanf("%f",&x);
    printf("Enter epsylon: ");
    scanf("%f",&epsylon);
    printf("Sinus = %f\n\n",sin(x));
    printf("Reruorsion = %f\n\n",sinus_requorsion(x));
    printf("Number of stacks = %d\n\n",n);
    return 0;
}
