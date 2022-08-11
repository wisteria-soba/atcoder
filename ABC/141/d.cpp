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

int main(void)
{
    int n,m;
    cin >> n >> m;
    priority_queue<int> q;
    REP(i,n){
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }

    REP(i,m){
        int max = q.top();
        q.pop();
        q.push(max / 2);
    }

    ll sum = 0;
    REP(i,n){
        sum += q.top();
        q.pop();
    }

    cout << sum << endl;

    return 0;
}