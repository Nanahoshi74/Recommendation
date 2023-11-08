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

    ll a,b,c,d;
    cin >> a >> b >> c >> d;

    ll p = lcm(c,d);

    ll ans = 0;
    ll cnt_c = 0;
    cnt_c = b/c-(a-1)/c;

    ll cnt_d = 0;
    cnt_d = b/d-(a-1)/d;

    ll cnt_p = 0;
    cnt_p = b/p-(a-1)/p;
    // ret(cnt_c);
    // ret(cnt_d);
    // ret(cnt_p);

    ans = (b-a+1)-(cnt_c + cnt_d - cnt_p);

    cout << ans << endl;


    return 0;
}