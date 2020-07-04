// To find the circular maximun subarray,
// you need to consider the normal subarray (not circular)
// and the circular subarray (end-to-end).
// To find circular maximun subarray, you just simply do
// total_sum - normal minimun subarray sum (not circular)
// Eventually the ansewr is max(normal subarray, circular subarray)

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

    // find maximun sum subarray by kadane's dp method (not circular)
    LL normal_max = kadane(len);

    // find the total array sum
    LL total = 0;
    for(int i = 0; i < len; i++)
      total += a[i];

    // neg the array to invoke kadane's method
    // find the minimun sum subarray (not circular)
    for(int i = 0; i < len; i++)
      a[i] = -a[i];
    LL normal_min = kadane(len);

    // Do total + normal_min, since the normal_min is a positive number;
    LL circular_max = total + normal_min;

    cout << max(circular_max, normal_max) << endl;
  }
  return 0;
}
