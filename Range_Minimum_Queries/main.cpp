#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN = 100000;
const int logN = ceil(log2(MAXN));

int a[MAXN];
int st[logN][MAXN];

void sparse_table(int n) {

  for(int i = 0; i < n; i++)
    st[0][i] = a[i];
}

int main(int argc. char *argv[]) {
  /*int n;
  cin >> n;

  for(int i = 0; i < n;i++)
    cin >> a[i];

  sparse_table(n);*/
  for(int i = 0; i < 2; i++)
    printf("%d", i);
  for(int i = 0; i < 2; ++i)
    printf("%d", i);
  return 0;
}
