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

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }

    ll tmp = abs(a[0]-0);

    rng(i,1,n){
        tmp += abs(a[i-1]-a[i]);
    }
    tmp += abs(a[n-1]-0);

    rep(i,n){
        ll ans = tmp;
        if(i == 0){
            ans -= abs(0-a[0]);
            ans -= abs(a[0]-a[1]);
            ans += abs(a[1]-0);
        }
        else if(i == n-1){
            ans -= abs(a[i]-a[i-1]);
            ans -= abs(a[i]-0);
            ans += abs(0-a[i-1]);
        }
        else{
            ans -= abs(a[i]-a[i-1]);
            ans -= abs(a[i+1]-a[i]);
            ans += abs(a[i+1]-a[i-1]);
        }

        cout << ans << endl;
    }


    return 0;
}