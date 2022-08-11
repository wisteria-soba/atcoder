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
ll modinv(ll a, ll m) {ll b = m, u = 1, v = 0;while (b) {ll t = a / b;a -= t * b; swap(a, b);u -= t * v; swap(u, v);}u %= m;if (u < 0) u += m;return u;}
const int INF = 1e9;
const ll LLINF = 1e16;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<vector<int>> graph(n);
    vector<int> kcnt(n, 0);
    REP(i, n - 1)
    {
        graph[i].push_back(i + 1);
        graph[i + 1].push_back(i);
    }
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    graph[x].push_back(y);
    graph[y].push_back(x);

    REP(i,n){
        queue<int> s;
        vector<int> color(n, 0);
        vector<int> dist(n);
        dist[i] = 0;
        color[i] = 1;
        s.push(i);
        while(!s.empty()){
            int v = s.front();
            s.pop();
            REP(j,graph[v].size()){
                if(color[graph[v][j]] == 0){
                    s.push(graph[v][j]);
                    color[graph[v][j]] = 1;
                    dist[graph[v][j]] = dist[v] + 1;
                    if (i < graph[v][j])
                    {
                        kcnt[dist[graph[v][j]]]++;
                    }
                }
            }
        }
    }
    FOR(k,1,n){
        cout << kcnt[k] << endl;
    }
    return 0;
}