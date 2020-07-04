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
  int testcase;

  cin >> testcase;
  while(testcase--) {
    int len;
    cin >> len;

    for(int i = 0; i < len; i++)
      cin >> a[i];

    // find maximun sum subarray by kadane's dp method
    LL normal_max = kadane(len);

    // find the total array sum
    LL total = 0;
    for(int i = 0; i < len; i++)
      total += a[i];

    // find the minimun sum subarray 
    for(int i = 0; i < len; i++)
      a[i] = -a[i];
    LL normal_min = kadane(len);

    LL circular_max = total + normal_min;

    cout << max(circular_max, normal_max) << endl;
  }
  return 0;
}
