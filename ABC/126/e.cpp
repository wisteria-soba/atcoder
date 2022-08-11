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

class UnionFind
{
public:
    vector<int> parent;
    vector<int> size;

    UnionFind(int n) : parent(n), size(n, 1)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int root(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = root(parent[x]);
    }

    void unite(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
            return;
        if (size[rx] < size[ry])
        {
            swap(rx, ry);
        }
        size[rx] += size[ry];
        parent[ry] = rx;
    }

    bool same(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int get_size(int x) { return size[root(x)]; }
};

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    UnionFind friends(n);
    vector<ll> x(m);
    vector<ll> y(m);
    vector<ll> z(m);
    REP(i,m){
        cin >> x[i] >> y[i] >> z[i];
        x[i]--;
        y[i]--;
    }
    vector<pair<ll, ll>> enemy_r;
    REP(i, m)
    {
        friends.unite(x[i], y[i]);   
    }

    set<ll> roots;
    REP(i, n)
    {
        roots.insert(friends.root(i));
    }
    cout << roots.size() << endl;
    return 0;
}