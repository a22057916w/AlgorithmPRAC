#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 100000;
const int logN = ceil(log2(MAXN));

int a[MAXN];
int st[logN][MAXN];

void sparse_table(int n) {

  int logn = floor(log2(n));

  for(int i = 0; i < n; i++)
    st[0][i] = a[i];

  for(int i = 1; i < logn; i++)
    for(int j = 0; j <= n - (1 << i); j++)
      st[i][j] = min(st[i - 1][j], st[i -1][j + (1 << (i - 1))]);
}

int query(int L, int R) {
  int i = floor(log2(R - L + 1));
  return(st[i][L - 1], st[i][(R - 1) - (1 << i) + 1]);
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;

  for(int i = 0; i < n;i++)
    cin >> a[i];

  sparse_table(n);
  int L, R;
  cin >> L >> R;
  cout << query(L, R) << endl;
  return 0;
}
