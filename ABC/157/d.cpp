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

int main(void)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> friend_tree(n);
    vector<int> block_cnt(n,0);
    vector<int> color(n, 0);
    unordered_map<int, int> ctc;
    int mc = 0;
    REP(i, m)
    {
        int a, b;
        cin >> a >> b;
        friend_tree[a - 1].push_back(b - 1);
        friend_tree[b - 1].push_back(a - 1);
    }

    REP(i,n){
        if(color[i] != 0){
            continue;
        }

        queue<int> s;
        s.push(i);
        color[i] = ++mc;
        ctc[mc] = 0;
        while (!s.empty())
        {
            int v = s.front();
            s.pop();
            REP(j,friend_tree[v].size()){
                if(color[friend_tree[v][j]] == 0){
                    color[friend_tree[v][j]] = color[i];
                    ctc[color[i]]++;
                    s.push(friend_tree[v][j]);
                }
            }
        }
    }

    REP(i,k){
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        if (color[c] == color[d])
        {
            block_cnt[c]++;
            block_cnt[d]++;
        }

    }

    REP(i,n){
        cout << ctc[color[i]] - friend_tree[i].size() - block_cnt[i] << " ";
    }
    cout << endl;

    return 0;
}