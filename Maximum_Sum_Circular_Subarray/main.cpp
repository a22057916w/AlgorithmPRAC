#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <alogrithm>
using namespace std;

typedef unsigned long long LLU;

int MAXN = 100005;

LLU greedy(int len) {
  LLU dp[MAXN] = {0};
  int s, e;

  for(int i = 0; i < len; i++) {
    dp[i] = max(dp[i -1] + a[i], a[i]);
  }

}

int main(int argc, char *argv[]) {
  int length;
  cin >> length;

  for(int i = 0; i < length; i++)
    cin >> a[i];

  LLU = greedy(length);
}
