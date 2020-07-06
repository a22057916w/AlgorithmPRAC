// Implement Sparse-Table to resolve the Range-Minimun-Queries.
// The concept of Sparse-Table is quite, for any number could be
// represent as the additon of binary. e.g. 18 = 8 + 4 + 2 + 1
// So does the interval.
// The index serach is quite tricking, suggetion to draw a
// concept diagram to understand.

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 100000;
const int logN = ceil(log2(MAXN)); // we only need log2(N) rows

int a[MAXN];
int st[logN][MAXN]; // st[0][x] for range 1, st[1][x] -> 2, st[2][x] -> 4 ...

void sparse_table(int n) {

  int logn = ceil(log2(n));   // compute the rows of testcase

  // consutructing the sparse table
  // initiate the range-1-row
  for(int i = 0; i < n; i++)
    st[0][i] = a[i];

  // consutructing the table for the remaining rows
  for(int i = 1; i < logn; i++)
    for(int j = 0; j <= n - (1 << i); j++)
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

// The concept is to search the interval [L, L + Range-N] and [R - Range-N, R]
// e.g. query(1, 3) -> cmp([1, 2], [2, 3])
// However, the index serach is quite tricking, suggetion to draw a
// concept diagram to understand.
int query(int L, int R) {
  int i = floor(log2(R - L + 1));
  return min(st[i][L - 1], st[i][(R - 1) - (1 << i) + 1]);
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;

  for(int i = 0; i < n;i++)
    cin >> a[i];

  sparse_table(n);

  int L, R;
  while(n--) {
    cin >> L >> R;
    cout << query(L, R) << endl;
  }
  return 0;
}
