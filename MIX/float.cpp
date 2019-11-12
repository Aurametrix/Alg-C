#include <iostream>
#include <math.h>
#include <quadmath.h>

using namespace std;

template <typename T> T e(T x) {
  return x == 0. ? 1. : (exp(x) - 1.)/x;
}

template <typename T> T q(T x) {
  return fabs(x - sqrt(x*x + 1.)) - 1./(x + sqrt(x*x + 1.));
}

template <typename T> T h(T x) {
  return e( q(x)*q(x) );
}

int main() {

  int x[] = {15, 16, 17, 9999};

  for (int i = 0; i < 4; i++) {
      cout << h(     float(x[i]) ) << endl;
      cout << h(    double(x[i]) ) << endl;
      cout << h(__float128(x[i]) ) << endl;
  }
}
