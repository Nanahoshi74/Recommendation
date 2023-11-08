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

    vector<char> a(4);
    vector<ll> num(4);
    rep(i,4){
        cin >> a[i];
        num[i] = a[i] - '0';
    }
    rep(i,1 << 3){
        ll p = num[0];
        deque<char> dq;
        rep(j,3){
            if(i & (1 << j)){
                p += num[j+1];
                dq.pb('+');
            }
            else{
                p -= num[j+1];
                dq.pb('-');
            }
        }
        if(p == 7){
            string s;
            rep(k,4){
                s += a[k];
                //cout << dq.front() << endl;
                if(k != 3) s += dq.front();
                dq.pop_front();
            }
            cout << s << "=7" << endl;
            return 0;
        }
    }

    return 0;
}