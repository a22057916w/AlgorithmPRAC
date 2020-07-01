#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef unsigned long long unsigned_int64;

unsigned_int64 m[3][3] = { {1, 2, 0}, {4, 3, 0}, {0, 0, 0} };

unsigned_int64 order(unsigned_int64 r, unsigned_int64 c) {
    if(r <= 2 && c <= 2)
      return m[r][c];


}

unsigned_int64 travel() {
  int sum = 5;
  int tr, tc;

  // row starts with 3, column starts with 1 (M[3][1])

  if(tr % 2 == 1) {
    // Traveling odd rows
    for(unsigned_int64 i = 1; i <= tr; i++) {
      // tring to make break point
      if(tr == r && tc == c)
        return sum;
      sum++;
    }
    // Traveling odd columns
    for(unsigned_int64 j = tc; j >= 1; j--) {
      // tring to make break point
      if(tr == r && tc == c)
        return sum;
      sum++;
    }
  }
  else {
    // Traveling even columns
    for(unsigned_int64 j = 1; j <= tc; j++) {
      // tring to make break point
      if(tr == r && tc == c)
        return sum;
      sum++;
    }
    // Traveling even rows
    for(unsigned_int64 i = tr; i >= 1; i--) {
      // tring to make break point
      if(tr == r && tc == c)
        return sum;
      sum++;
    }
  }
}

int main(int argc, char *argv[]) {

  unsigned_int64 i, j;
  cin >> i >> j;

  cout << order(i, j) << endl;

  return 0;
}
