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

vector<ll> divisors(ll n) {
    vector<ll> res;
    for(ll i = 1; i*i <= n; ++i) {
        if(n % i != 0) continue;
        res.push_back(i);
        if(n/i == i) continue;
        res.push_back(n/i);
    }
    return res;
}

bool is_prime(ll n) {
    if(n == 1) return false; // 1 は素数ではない。
    for(ll i = 2; i*i <= n; ++i) { // 2 <= i <= sqrt(n) に約数があれば、
        if(n % i == 0) return false; // n は素数ではない
    }
    return true;
}

int main(void)
{
    ll a,b;
    cin >> a >> b;
    vector<ll> prime_div;
    vector<ll> diva = divisors(a);
    vector<ll> divb = divisors(b);
    vector<ll> divab(diva.size() + divb.size());
    sort(all(diva));
    sort(all(divb));
    vector<ll>::iterator it = set_intersection(all(diva), all(divb), divab.begin());
    ll internum = ll(it - divab.begin());

    REP(i,internum){
        if(is_prime(divab[i])){
            prime_div.push_back(divab[i]);
        }
    }

    cout << prime_div.size() + 1<< endl;

    return 0;
}