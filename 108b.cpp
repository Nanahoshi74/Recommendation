#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <math.h>
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

P rotate(P a,double deg){
    P p;
    double PI = acos(-1);
    double rad = deg * (PI/180);
    p.first = a.first * (ll)cos(rad) - a.second * (ll)sin(rad);
    p.second = a.first * (ll)sin(rad) + a.second * (ll)cos(rad);
    
    return p;
}


int main(){

    vector<P> p(4);
    rep(i,2) cin >> p[i].first >> p[i].second;
    P u;
    u.second = p[1].second-p[0].second;
    u.first = p[1].first - p[0].first;
    P v = rotate(u,90);
    // P v;
    // v.first = -u.second;
    // v.second = u.first;
    p[2].first = p[1].first + v.first;
    p[2].second = p[1].second + v.second;
    p[3].first = p[0].first + v.first;
    p[3].second = p[0].second + v.second;

    cout << p[2].first << " " << p[2].second << " " << p[3].first << " " << p[3].second << endl;

    return 0;
}