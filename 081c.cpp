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
    vector<ll> a(n);
    map<ll,ll> mp;
    rep(i,n){
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<P> pa;
    for(auto p : mp){
        pa.emplace_back(p.second,p.first);
    }
    sort(rall(pa));
    ll now = 1;
    ll sum = 0;
    for(auto v : pa){
        sum += v.first;
        if(now == k){
            cout << n-sum << endl;
            return 0; 
        }
        now++;
    }

    cout << 0 << endl;


    return 0;
}