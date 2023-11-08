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

long double calc_kitai(long double n){
    long double ans = 0;
    long double ln = (long double)n;
    ans = (long double)(ln*(ln+1.0)/2.0)/(long double)ln;
    return ans;
}

int main(){

    ll n,k;
    cin >> n >> k;
    vector<long double> p(n);
    rep(i,n){
        cin >> p[i];
    }
    long double ans = 0.0;
    rep(i,k){
        ans += calc_kitai(p[i]);
    }
    long double z = ans;
    rep(i,n-k){
        // cout << z << endl;
        z -= calc_kitai(p[i]);
        z += calc_kitai(p[i+k]);
        // cout << calc_kitai(p[i]) << " " << calc_kitai(p[i+k]) << endl;
        ans = max(ans,z);
    }

    cout << fixed << setprecision(12) << ans << endl;


    return 0;
}