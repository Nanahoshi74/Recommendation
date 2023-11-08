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

    ll n,k;
    cin >> n >> k;
    vector<ll> a(n),b(n);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        cin >> b[i];
    }
    vector<bool> p(n,false),q(n,false);
    p[0] = true,q[0] = true;
    rng(i,1,n){
        if(p[i-1]){
            if(abs(a[i]-a[i-1]) <= k){
                p[i] = true;
            }
            if(abs(b[i]-a[i-1]) <= k){
                q[i] = true;
            }
        }
        if(q[i-1]){
            if(abs(b[i]-b[i-1]) <= k){
                q[i] = true;
            }
            if(abs(a[i]-b[i-1]) <= k){
                p[i] = true;
            }
        }
    }
    if(p[n-1] || q[n-1]){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;

    return 0;
}