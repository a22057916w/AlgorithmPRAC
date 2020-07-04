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

  int length;

  cin >> length;
  for(int i = 0; i < length; i++)
    cin >> a[i];

  LL ans = kadane(length);
  cout << ans << endl;

  return 0;
}
