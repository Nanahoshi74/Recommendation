#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
//using mint = modint998244353;
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

ll f(ll n){
    ll ans = 1;
    rng(i,1,n+1){
        ans *= i;
    }
    return ans;
}


int main(){

    ll n;
    cin >> n;
    vector<ll> x(n),y(n);
    rep(i,n){
        cin >> x[i] >> y[i];
    }
    vector<ll> a(n);
    rep(i,n){
        a[i] = i;
    }
    double ans = 0;
    do{
        rep(i,n-1){
            ans += sqrt((x[a[i+1]]-x[a[i]]) * (x[a[i+1]]-x[a[i]]) + (y[a[i+1]]-y[a[i]]) * (y[a[i+1]]-y[a[i]]));
        }
    }while(next_permutation(all(a)));

    printf("%.10f\n",(double)(ans/f(n)));

    return 0;
}