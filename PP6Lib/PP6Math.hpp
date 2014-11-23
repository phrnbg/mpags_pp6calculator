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

// - Vectors
double length(double x, double y, double z);
double length(double t, double x, double y, double z);

// - Physics
double inv_mass(double e1, double px1, double py1, double pz1, double e2, double px2, double py2, double pz2);

// - Utility
double getNumber();
bool determine_size_array(const std::string& path, const std::string& run, const std::string& particle, int& a, int& b);
bool read_file(const std::string& path, const std::string& run, const std::string& particle, int* event_p, double* px_p, double* py_p, double* pz_p, int* event_m, double* px_m, double* py_m, double* pz_m);
int swap(double &a, double &b);
int swap(int &a, int &b);
int basic_sort(double *arr, int size);
int associative_sort(double *arr, int *indices, int size);

#endif
