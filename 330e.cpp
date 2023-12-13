#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
//using mint = modint1000000007;
// using mint = modint;  /*このときmint::set_mod(mod)のようにしてmodを底にする*/
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(ll i = a; i <= (ll)(b); i++)
#define rng(i,a,b) for(ll i = a; i < (ll)(b); i++)
#define rrng(i,a,b) for(ll i = a; i >= (ll)(b); i--)
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define si(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ret(x) { cout<<(x)<<endl;}
using namespace std;
using P = pair<ll,ll>;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
ll mul(ll a, ll b) { if (a == 0) return 0; if (LINF / a < b) return LINF; return min(LINF, a * b); }
ll mod(ll x, ll y){return (x % y + y) % y;}
char itoc(int x){return x + '0';}
int ctoi(char c){return c - '0';}
void chmin(ll& x,ll y){x = min(x,y);}
void chmax(ll& x,ll y){x = max(x,y);}
ll getnum(ll x, ll y, ll H, ll W) { (void) H; return (x * W + y);}
template<typename T>
void print(vector<T> &p){rep(i,si(p)) cout << p[i] << " "; cout << endl;}
ll ceil(ll x , ll y){return (x+y-1)/y;}

int main(){

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }

    set<ll> st;
    map<ll,ll> mp;
    rep(i,n+1){
        st.insert(i);
    }
    auto add = [&](ll x){
        if(x > n) return;
        if(mp[x] == 0) st.erase(x);
        mp[x]++;
    };

    auto del = [&](ll x){
        if(x > n) return;
        mp[x]--;
        if(mp[x] == 0) st.insert(x);
    };

    rep(i,n){
        add(a[i]);
    }
    rep(i,q){
        ll li, x;
        cin >> li >> x;
        li--;
        del(a[li]);
        a[li] = x;
        add(a[li]);
        cout << *st.begin() << "\n";
    }

    return 0;
}