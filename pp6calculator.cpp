#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;
/*void print( double a){
     std::cout <<"Results: " << a << std::endl;
}*/

int main() {
    int j, k;
    double m, q, intercept;
    double a, b, c, x1, x2;
    double m1, m2, mass;
    double E1, E2, p1x, p1y, p1z, p2x, p2y, p2z;

    //calculate the intercept of a line on the x-axis
    std::cout << "Give the slope" << std::endl;
    std::cin >> m;
    std::cout << "Give the intercept" << std::endl;
    std::cin >> q;
    std::cout << "Straight line equation: y = " << m << "*x + (" << q << ")" << std::endl;
    intercept = -m/q;
    std::cout << "The intercept on the x-axis is: " << intercept << std::endl;

    //solve a quadratic equation
    std::cout << "Give the first coefficient" << std::endl;
    std::cin >> a;
    std::cout << "Give the second coefficient" << std::endl;
    std::cin >> b;
    std::cout << "Give the third coefficient" << std::endl;
    std::cin >> c;
    std::cout << "Quadratic equation:" << a << "*x**2 + (" << b << ")*x + (" << c << ") = 0" << std::endl;
    x1 = (-b - sqrt(pow(b,2)-4*a*c))/(2*a);
    x2 = (-b + sqrt(pow(b,2)-4*a*c))/(2*a);
    printf("x1 = %lf \n", x1);
    printf("x2 = %lf \n", x2);
    std::cout << "The solutions are: x1 = " << x1 << "  x2 = " << x2 << std::endl;

    //calculate the invariant mass of two particles
    std::cout << "Give the two masses" << std::endl;
    std::cin >> m1 >> m2;
    std::cout << "Give the components of p1" << std::endl;
    std::cin >> p1x >> p1y >> p1z;
    std::cout << "Give the components of p2" << std::endl;
    std::cin >> p2x >> p2y >> p2z;
    E1 = sqrt(pow(m1,2) + pow(p1x,2) + pow(p1y,2) + pow(p1z,2));
    E2 = sqrt(pow(m2,2) + pow(p2z,2) + pow(p2y,2) + pow(p2z,2));
    mass = sqrt(pow(m1,2) + pow(m2,2) + 2*(E1*E2 - (p1x*p2x+p1y*p2y+p1z*p2z)));
    std::cout << "The invariant mass is: m = " << mass << std::endl;


    return 0;
}
