/// Declaration for PP6Math Functions
#ifndef PP6CALCULATOR_PP6MATH_HH
#define PP6CALCULATOR_PP6MATH_HH

// - Arithmetic
double add(double a, double b, double& answer);
double subtract(double a, double b, double& answer);
double multiply(double a, double b, double& answer);
double divide(double a, double b, double& answer);

// - Solvers
double intercept(double m, double q);
double quadratic(double a, double b, double c, bool answer);
double length(double x, double y, double z);
double length(double t, double x, double y, double z);
double inv_mass(double e1, double px1, double py1, double pz1, double e2, double px2, double py2, double pz2);
double getNumber();
int determine_size_array(int a, int b);
double read_file(int* event_p, double* px_p, double* py_p, double* pz_p, int* event_m, double* px_m, double* py_m, double* pz_m);

#endif // PP6CALCULATOR_PP6MATH_HH
