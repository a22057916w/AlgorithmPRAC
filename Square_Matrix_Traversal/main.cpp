#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long LLU;


int main(int argc, char *argv[]) {

  LLU r, c;
  cin >> r >> c;

  LLU m = max(r, c);

  LLU ans = 1;
  for(LLU i = 0; i < m; i++)
    ans += 2 * i;

  if(c % 1)
    for(LLU i = 0; i < r; i++)
      ans++;
  else
    for(LLU i = 0; i < r; i++)
      ans--;

  cout << ans << endl;

  return 0;
}
