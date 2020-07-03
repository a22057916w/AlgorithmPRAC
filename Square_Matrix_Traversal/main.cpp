// Traveling unusual spiral matrix
// Traveling diagonaly to derive a formula and pattern
// Check whether the row and coulumn is odd or even
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long LLU;


int main(int argc, char *argv[]) {
  int testcase;
  LLU r, c;

  cin >> testcase;
  while(testcase--) {
    cin >> r >> c;

    // find the greater one to travel to M[m][m]
    LLU m = max(r, c);

    LLU ans = 1;
    for(LLU i = 0; i < m; i++)
      ans += 2 * i;   // diagonaly formula

    // first, travel to M[m][m]
    // then, check if the row and column is odd or even and invoke different method
    if(m == c) {
      if(c % 2)
        for(LLU i = 0; i < m - r; i++)
          ans++;
      else
        for(LLU i = 0; i < m - r; i++)
          ans--;
    }
    else {
      if(r % 2)
        for(LLU i = 0; i < m - c; i++)
          ans--;
      else
        for(LLU i = 0; i < m - c; i++)
          ans++;
    }

    cout << ans << endl;
  }

  return 0;
}
