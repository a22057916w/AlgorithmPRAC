// Coverting floating-point number into fractions
// Implement GCD using Euclidean algorithm
// Included C++11
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

typedef unsigned long long unsigned_int64;

// self-Implement GCD, a must greater than b
unsigned_int64 GCD(unsigned_int64 a, unsigned_int64 b) {
  unsigned_int64 t = 1;

  while(t != 0) {
    t = a % b;
    a = b;
    b = t;
  }

  return a;
}

int main(int argc, char *argv[]) {
  //string snum = argv[1];
  double fnum = 3.14;
  //string dot = string(".");

  unsigned_int64 digit = 0;
  double tmp = fnum;

  while(ceil(tmp / 10) != int(tmp / 10) ) {
    cout << tmp << endl;
    tmp *= 10;
    digit++;
  }

  unsigned_int64 N = digit;
  unsigned_int64 D = digit + 1;
  cout << digit << endl;

  return 0;
}
