#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long LLU;

const int MAXN = 100005;

LLU greedy(int len) {
  LLU sum = 0, max_sum = 0;
  int start = 0, end = 0, temp_start = 0;

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

  LLU ans = greedy(length);
  cout << ans << endl;
}
