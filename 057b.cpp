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
char itoc(int x){return x + '0';}

int main(){

    ll n,m;
    cin >> n >> m;
    vector<P> a(n),c(m);
    rep(i,n){
        cin >> a[i].first >> a[i].second;
    }
    rep(i,m){
        cin >> c[i].first >> c[i].second;
    }
    rep(i,n){
        ll kyori = LINF;
        ll ind = 0;
        rep(j,m){
            ll man = abs(a[i].first-c[j].first) + abs(a[i].second-c[j].second);
            if(kyori > man){
                kyori = man;
                ind = j;
            }
        }
        cout << ind + 1 << endl;
    }

    return 0;
}