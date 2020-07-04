#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;

const int MAXN = 100005;
LL a[MAXN];
LL dp[MAXN];

LL kadane(int len) {
  memset(dp, 0, len);
  dp[0] = a[0];

  LL ans = 0;
  for(int i = 1; i < len; i++) {
    dp[i] = max(dp[i - 1] + a[i], a[i]);
    ans = max(ans, dp[i]);
  }

  return ans;
}

int main(int argc, char *argv[]) {

  int len;

  cin >> len;
  for(int i = 0; i < len; i++)
    cin >> a[i];

  LL normal_max = kadane(len);

  LL total = 0;
  for(int i = 0; i < len; i++)
    total += a[i];

  for(int i = 0; i < len; i++)
    a[i] = -a[i];

  LL normal_min = kadane(len);
  /*LL total = [=]() {
    for(int i = 0; i < len; i++)

  }*/
  LL circular_max = total + normal_min;

  cout << max(circular_max, normal_max) << endl;

  return 0;
}
