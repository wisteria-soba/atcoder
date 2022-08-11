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

int listnum(vector<int> list)
{
    int num = 0;
    int digit = 1;
    REPR(i,list.size()-1){
        num += digit * list[i];
        digit *= 10;
    }
    return num;
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    vector<int> jun(n);
    vector<int> junnum;

    iota(all(jun), 1);
    do{
        int digit = 1;
        junnum.push_back(0);
        for (int i = n - 1; i >= 0; i--)
        {
            junnum[junnum.size() - 1] += digit * jun[i];
            digit *= 10;
        }
    } while (next_permutation(all(jun)));

    REP(i,n){
        cin >> p[i];
    }
    REP(i,n){
        cin >> q[i];
    }

    int pnum = listnum(p);
    int qnum = listnum(q);

    sort(all(junnum));

    int a = 0;
    int b = 0;
    REP(i, junnum.size())
    {
        if(junnum[i] == pnum){
            a = i;
        }
        if(junnum[i] == qnum){
            b = i;
        }
    }

    cout << abs(a - b) << endl;

    return 0;
}