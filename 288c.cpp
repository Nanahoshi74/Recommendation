#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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

    ll n,m;
    cin >> n >> m;
    dsu uf(n);
    vector<ll> a(m),b(m);
    vector<vector<ll>> G(n);
    ll ans = 0;
    rep(i,m){
        cin >> a[i] >> b[i];
        a[i]--,b[i]--;
        if(uf.same(a[i],b[i])) ans++;
        else uf.merge(a[i],b[i]);
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
   
    cout << ans << endl;

    return 0;
}