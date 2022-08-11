#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i = n;i >= 0;--i)
#define FOR(i,m,n) for(int i = m, i##_len=(n);i <i##_len; ++i)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int INF = 1e9;
const ll LLINF = 1e16;

// 入力
int n = 6, A;
int a[6] =  {100,101,102,103,104,105};

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
  int n = 6, m = 1001;
  int a[6] = {100,101,102,103,104,105};
  int c[100];
  int dp[100001];
  int cnt;
  // ifstream cin( "test.txt" );
  while (1) {
    // 入力
    cin >> n >> m;
    if (!(n | m)) return 0;

    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> c[i];

    // 計算
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= m; j++) {
        if (dp[j] >= 0) {
          dp[j] = c[i];
        } else if ( j - a[i] >= 0 && dp[j-a[i]] > 0) {
          dp[j] = dp[j - a[i]] - 1;
        } else {
          dp[j] = -1;
        }
      }
    }
    cnt = 0;
    for (int j = 1; j <= m; j++) {
      if (dp[j] >= 0) cnt++;
    }
    // 出力
    cout << cnt << endl;
  }
}