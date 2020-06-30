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

int main(int argc, char *argv[]) {
  string snum = argv[1];
  double fnum = stod(snum);
  string dot = string(".");

  while(cin >> fnum && fnum != 0) {

      unsigned_int64 digit;
      double tmp = fnum;
      while(ceil(tmp / 10) == int(tmp / 10) ) {
        tmp *= 10;
        digit++;
      }
      cout << digit << endl;
  }
  return 0;
}
