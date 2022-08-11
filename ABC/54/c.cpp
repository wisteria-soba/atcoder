#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(ll i = n;i >= 0;--i)
#define FOR(i,m,n) for(ll i = m, i##_len=(n);i <i##_len; ++i)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
const int INF = 1e9;
const ll LLINF = 1e16;
 
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int dfscnt(vector<vector<int>> tree,vector<int> color,int v)
{
    color[v] = 1;
    int sum = 0;
    REP(i, tree[v].size())
    {
        if(color[tree[v][i]] == 0){
            sum += dfscnt(tree, color, tree[v][i]);
        }
    }
    bool flag = true;
    REP(i, color.size())
    {
        if(color[i] == 0){
            flag = false;
        }
    }
    if(flag){
        return sum + 1;
    }
    else{
        return sum;
    }
}

int main(void)
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> tree(n);
    REP(i,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    cout << dfscnt(tree, vector<int>(n, 0), 0);

    return 0;
}