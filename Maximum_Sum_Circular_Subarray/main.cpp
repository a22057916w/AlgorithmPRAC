#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 100005;

LL greedy(int len, int *a) {
  LL sum = 0, max_sum = 0;
  int start = 0, end = 0, temp_start = 0;

  for(int i = 0; i < len; i++)
    cout << a[i] << " ";
  cout << endl;
  for(int i = 0; i < len; i++) {
    sum += a[i];

    if(sum < 0) {
      sum = 0;
      temp_start = i + 1;
    }

    if(sum > max_sum) {
      max_sum = sum;
      start = temp_start;
      end = i;
    }
  }

  return max_sum;
}

int main(int argc, char *argv[]) {
  int a[MAXN] = {0};
  int length;

  cin >> length;
  for(int i = 0; i < length; i++)
    cin >> a[i];

  LL ans = greedy(length, a);
  cout << ans << endl;
}
