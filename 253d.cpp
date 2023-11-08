#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
//using mint = modint998244353;
// using mint;  /*このときmint::set_mod(mod)のようにしてmodを底にする*/
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = a; i <= (int)(b); i++)
#define rng(i,a,b) for(int i = a; i < (int)(b); i++)
#define rrng(i,a,b) for(int i = a; i >= (int)(b); i--)
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define si(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ret(x) { cout<<(x)<<endl;}
typedef long long ll;
using namespace std;
using P = pair<ll,ll>;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
ll mul(ll a, ll b) { if (a == 0) return 0; if (LINF / a < b) return LINF; return min(LINF, a * b); }
ll mod(ll x, ll y){return (x % y + y) % y;}
char itoc(int x){return x + '0';}
int ctoi(char c){return c - '0';}

int main(){

    ll n,a,b;
    cin >> n >> a >> b;

    ll cnt_a = n/a;
    ll cnt_b = n/b;

    ll lcm_ab = lcm(a,b);
    ll cnt_ab = n/lcm_ab;

    ll sum_a = cnt_a*(2*a + (cnt_a-1)*a)/2;
    ll sum_b = cnt_b*(2*b + (cnt_b-1)*b)/2;
    ll sum_ab = cnt_ab*(2*lcm_ab + (cnt_ab-1)*lcm_ab)/2;


    ll sum = (n*(n+1))/2;

    cout << sum-(sum_a+sum_b-sum_ab) << endl;


    return 0;
}