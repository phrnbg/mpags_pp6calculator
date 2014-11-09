#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <cmath>

//using namespace std;
/*void print( double a){
     std::cout <<"Results: " << a << std::endl;
}*/

int main() {
    int j, k;
    double m, q, intercept;
    double a, b, c, x1, x2;
    double m1, m2, mass;
    double E1, E2, p1[3], p2[3], spx, spy, spz, sp2;

    //calculate the intercept of a line on the x-axis
    m = 5.0;
    q = 3.0;
    intercept = -m/q;
    printf("%lf \n", intercept);

    //solve a quadratic equation
    a = 2.0;
    b = -5.0;
    c = 3.0;
    x1 = (-b - sqrt(pow(b,2)-4*a*c))/(2*b);
    x2 = (-b + sqrt(pow(b,2)-4*a*c))/(2*b);
    printf("equation (%lf)*x**2 + (%lf)*x + (%lf) = 0 \n", a, b, c);
    printf("x1 = %lf \n", x1);
    printf("x2 = %lf \n", x2);

    //calculate the invariant mass of two particles
    m1 = 3.0;
    m2 = 5.0;
    p1[0] = 1.;
    p1[1] = 2.;
    p1[2] = 3.;
    p2[0] = 0.5;
    p2[1] = 1.;
    p2[2] = 1.5;

    E1 = sqrt(pow(m1,2) + pow(p1[0],2) + pow(p1[1],2) + pow(p1[2],2));
    E2 = sqrt(pow(m2,2) + pow(p2[0],2) + pow(p2[1],2) + pow(p2[2],2));

    mass = sqrt(pow(m1,2) + pow(m2,2) + 2*(E1*E2 - (p1[0]*p2[0]+p1[1]*p2[1]+p1[2]*p2[2])));
    printf("m = %lf \n", mass);

    return 0;
}
