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
    string s;
    cin >> s;
    ll ans = -1;
    rep(i,n-1){
        string p,q;
        ll prev = 0;
        p = s.substr(0,i+1);
        q = s.substr(i+1);
        if(si(p) == 0 || si(q) == 0) continue;
        unordered_set<char> st;
        rep(j,si(p)){
            st.insert(p[j]);
        }
        rep(k,si(q)){
            if(st.count(q[k])){
                prev++;
                st.erase(q[k]);
            }
        }
        ans = max(ans,prev);
    }

    cout << ans << endl;

    return 0;
}