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

    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> r, g, b;
    rep(i,n){
        if(s[i] == 'R'){
            r.push_back(i);
        }
        else if(s[i] == 'G'){
            g.push_back(i);
        }
        else{
            b.push_back(i);
        }
    }
    ll ans = 0;
    rep(i,n){
        rng(j,i+1,n){
            if(s[i] != s[j]){
                unordered_set<char> st = {'R', 'G', 'B'};
                st.erase(s[i]);
                st.erase(s[j]);
                char c = *st.begin();
                ll u, v;
                if(c == 'R'){
                    u = r.end()-upper_bound(all(r), j);
                    v = upper_bound(r.begin(), r.end(), j-i+j) - lower_bound(r.begin(), r.end(), j-i+j);
                }
                else if(c == 'G'){
                    u = g.end()-upper_bound(all(g), j);
                    v = upper_bound(g.begin(), g.end(), j-i+j) - lower_bound(g.begin(), g.end(), j-i+j);
                }
                else{
                    u = b.end()-upper_bound(all(b), j);
                    v = upper_bound(b.begin(), b.end(), j-i+j) - lower_bound(b.begin(), b.end(), j-i+j);
                }
                ans += u - v;
            }
        }
    }

    cout << ans << endl;

    return 0;
}