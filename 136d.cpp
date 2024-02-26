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

    ll n = si(s);

    vector<pair<char,ll>> pa;
    pa.emplace_back(s[0], 1);
    rng(i,1,n){
        if(pa.back().first == s[i]){
            pa.back().second++;
        }
        else{
            pa.emplace_back(s[i], 1);
        }
    }

    vector<P> rl;
    ll cnt = 0;
    for(int i = 0; i < si(pa)-1; i += 2){
        ll rc = cnt + pa[i].second;
        ll lc = rc + pa[i+1].second;
        rl.emplace_back(rc-1, lc-1);
        cnt += pa[i].second + pa[i+1].second;
    }

    // rep(i,si(rl)){
    //     cout << rl[i].first << " " << rl[i].second << endl;
    // }
    // cout << "/////////////" << endl;

    vector<ll> ans(n);
    ll start = 0, end = 0;

    for(auto p : rl){
        ll even = p.first;
        ll odd = even + 1;
        if(even % 2 == 1){
            swap(even, odd);
        }
        if(rl[0] == p){
            start = 0;
        }
        else{
            start = end + 1;
        }
        end = p.second;
        // cout << start << " " << end << endl;
        for(int i = start; i <= end; i++){
            if(i % 2 == 0){
                ans[even]++;
            }
            else{
                ans[odd]++;
            }
        }
    }

    print(ans);
    

    return 0;
}