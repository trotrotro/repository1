#include <stdio.h>
#include <math.h>

#define ALEF 1948
#define TEST

/**
    \brief solves a square equation ax^2 + bx + c = 0

    \param a first  coefficient
    \param b second coefficient
    \param c third  coefficient
    \param x1 the only root or one of roots
    \param x2 another root

    \return amount of roots or const ALEF, when amount is infinite
*/

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

void sum_of_tests(){
    double x1 = 0, x2 = 0;
    //1
    if (solution(0, 0, 0, &x1, &x2) == ALEF)
        printf("test 1 is passed\n");
    else
        printf("test 1 is failed\n");//all zeros
    //2
    if (solution(1, 0, -4, &x1, &x2) == 2 && x1*x2 == -4 && x1+x2 == 0)
        printf("test 2 is passed\n");
    else
        printf("test 2 is failed\n");//correct equation
    //3
    if (solution(0, 2, -4, &x1, &x2) == 1 && x1 == 2)
        printf("test 3 is passed\n");
    else
        printf("test 3 is failed\n");//linear equation
    //4
    if (solution(1, 1, 1, &x1, &x2) == 0)
        printf("test 4 is passed\n");
    else
        printf("test 4 is failed\n");//no roots
    //5
    if (solution(1, 2, 1, &x1, &x2) == 1 && x1 == -1)
        printf("test 5 is passed\n");
    else
        printf("test 5 is failed\n");//only root
}

int main(){

    #ifdef TEST
        sum_of_tests();
        return 0;
    #endif

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
