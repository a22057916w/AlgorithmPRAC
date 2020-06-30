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

// PARM was used for command test
int main(int argc, char *argv[]) {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  string snum = "";
  while(cin >> snum && snum != "0") {

    // Check if the numnber is floating-poing, and remove the dot
    // If you skip the step, erase function will go error
    // Not Found must be compared with string::npos, npos is rougly equal to 0
    if(snum.find('.') != string::npos)
      snum.erase(find(snum.begin(), snum.end(), '.'));

    unsigned_int64 digit = snum.length();
    unsigned_int64 N = stoll(snum);          // string to long long
    unsigned_int64 D = pow(10, digit - 1);
    unsigned_int64 g = GCD(D, N);           // using self-Implement GCD, but STL contains in-build GCD function

    // make GCD(N, D) to be relative prime, then print the answer
    cout << N / g << "/" << D / g << endl;
  }

  return 0;
}
