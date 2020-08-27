#include <stdio.h>
#include <math.h>

#define ALEF 1948

int solution(double a, double b,
     double c, double *x1, double *x2){

    if (a == 0){
        if(b == 0){
            if (c == 0)
                return ALEF;
            return 0;
        }
        *x1 = -c/b;
        return 1;
    }

    int d = b*b - 4*a*c;

    if (d < 0)
        return 0;

    if (d == 0){
        *x1 = -b/(2*a);
        return 1;
    }

    *x1 = (-b + sqrt(d))/(2*a);
    *x2 = (-b - sqrt(d))/(2*a);
    return 2;
}

int main(){
    printf("enter a, b, c:\n");
    double a = 0, b = 0, c = 0;

    if (scanf("%lg %lg %lg", &a, &b, &c) != 3){
        printf("error");
        return 0;
    };

    double x1 = 0, x2 = 0;
    int amount = solution(a, b, c, &x1, &x2);

    if (amount == 0)
        printf("no roots\n");

    if (amount == 1)
        printf("the only root: %lg\n", x1);

    if (amount == 2)
        printf("two roots: %lg and %lg\n", x1, x2);

    if (amount == ALEF)
        printf("any real number is a root\n");

    return 0;
}
