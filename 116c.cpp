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
    vector<ll> h(n);
    rep(i,n){
        cin >> h[i];
    }

    ll ans = 0;

    ll li = 0;
    unordered_set<ll> st;
    while(si(st) != n){
        bool ok = false;
        rng(i,0,n){
            if(h[i] != 0){
                ok = true;
                h[i]--;
                if(i == n-1) ans++;
            }
            else if(ok && h[i] == 0){
                ans++;
                st.insert(i);
                ok = false;
            }
            else if(!ok && h[i] == 0){
                st.insert(i);
                continue;
            }
        }
    }

    cout << ans << endl;

    return 0;
}