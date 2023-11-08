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
    vector<string> s(n);
    map<string,ll> plus;
    unordered_set<string> u;
    rep(i,n){
        cin >> s[i];
        plus[s[i]]++;
        u.insert(s[i]);
    }
    ll m;
    cin >> m;
    vector<string> t(m);
    map<string,ll> minus;
    rep(i,m){
        cin >> t[i];
        minus[t[i]]--;
        u.insert(t[i]);
    }
    set<ll> st;
    for(auto p : u){
        st.insert(plus[p] + minus[p]);
    }
    if(*st.rbegin() < 0){
        cout << 0 << endl;
    }
    else{
        cout << *st.rbegin() << endl;
    }
    

    return 0;
}