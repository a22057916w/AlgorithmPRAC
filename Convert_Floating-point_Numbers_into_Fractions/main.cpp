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
  string snum = argv[1];
  //double fnum = stod(snum);
  //string dot = string(".");
  //cout << fnum << endl;
  if(snum.find('.') != string::npos)
    snum.erase(find(snum.begin(), snum.end(), '.'));
  unsigned_int64 digit = snum.length();
  unsigned_int64 N = stod(snum);
  unsigned_int64 D = pow(10, digit - 1);
  unsigned_int64 g = GCD(D, N);

  // make GCD(N, D) to be relative prime, print the answer
  cout << N / g << "/" << D / g << endl;

  //double tmp = fnum;

  // calculate total digits
  // break when last digit is 0. e.g. 3140
  // total digits would be one more than original one.
  /*while(ceil(tmp / 10) != int(tmp / 10) ) {
    tmp *= 10;
    digit++;
  }
  tmp /= 10;

  // make GCD(N, D) to be relative prime
  unsigned_int64 N = tmp;
  unsigned_int64 D = pow(10, digit - 1);
  cout << N << endl;
  cout << D << endl;
  unsigned_int64 g = GCD(D, N);

  // make GCD(N, D) to be relative prime, print the answer
  cout << N / g << "/" << D / g << endl;*/

  return 0;
}
