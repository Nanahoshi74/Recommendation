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
ll ceilLL(ll x , ll y){return (x+y-1)/y;}

int main(){

    string s;
    cin >> s;
    ll k;
    cin >> k;

    ll n = si(s);

    vector<ll> p(n+1), q(n+1);
    rep(i,n){
        p[i+1] = p[i];
        q[i+1] = q[i];
        if(s[i] == 'X'){
            p[i+1]++;
        }
        else if(s[i] == '.'){
            q[i+1]++;
        }
    }


    auto check = [&](ll li, ll m) -> bool{
        if(li + m -1 >= n+1){
            return false;
        }
        if(m - (p[li+m-1] - p[li-1]) <= k){
            return true;
        }
        return false;
    };

    ll ans = -1;
    if(n == 1){
        if(s[0] == '.' && k >= 1){
            cout << 1 << endl;
            return 0;
        }
        else if(s[0] == '.' && k == 0){
            cout << 0 << endl;
            return 0;
        }
        else if(s[0] == 'X'){
            cout << 1 << endl;
            return 0;
        }
    }

    rep(i,n){
        ll ok = 0, ng = 1e10;
        while(abs(ok - ng) > 1){
            ll m = (ok + ng) / 2;
            if(check(i, m)){
                ok = m;
            }
            else{
                ng = m;
            }
            // cout << ok << " " << ng << endl;
        }
        chmax(ans, ok);
    }

    cout << ans << endl;

    return 0;
}