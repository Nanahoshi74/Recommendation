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


int main(){

    vector<ll> a(3);
    rep(i,3) cin >> a[i];
    sort(all(a));
    if(a[0] == a[1] && a[1] == a[2]){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    ll p = a[2]-a[1];
    ans += p;
    a[1] += p;
    a[0] += p;
    if((a[1]-a[0]) % 2 == 0){
        ans += (a[1]-a[0])/2;
    }
    else{
        a[1]++;
        a[2]++;
        ans++;
        ans += (a[1]-a[0])/2;
    }
    cout << ans << endl;

    return 0;
}