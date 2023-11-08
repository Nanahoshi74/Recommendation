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

    ll n;
    cin >> n;
    vector<ll> a(n+1),b(n);
    rep(i,n+1){
        cin >> a[i];
    }
    rep(i,n){
        cin >> b[i];
    }
    ll ans = 0;
    rrng(i,n,1){
        ll m_num = min(a[i],b[i-1]);
        ans += m_num;
        b[i-1] -= m_num;
        a[i] -= m_num;
        m_num = min(a[i-1],b[i-1]);
        ans += m_num;
        b[i-1] -= m_num;
        a[i-1] -= m_num;
    }
    cout << ans << endl;

    return 0;
}