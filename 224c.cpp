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

struct V{//************************幾何ライブラリ****************************
    int x,y;
    V(int x = 0, int y = 0): x(x),y(y){}
    V operator+(const V& a) const{//ベクトルの足し算を定義
        return V(x+a.x,y+a.y);
    }
    V operator-(const V& a) const{//ベクトルの引き算を定義
        return V(x-a.x,y-a.y);
    }
    V operator*(const int p) const{//ベクトルの定数倍
        return V(x*p,y*p);
    }
    int cross(const V& a) const{//外積を求める
        return x*a.y - y*a.x;
    }
    int ccw(const V& a) const{
        int area = cross(a);
        if(area > 0) return +1;//ccw(反時計回り)
        if(area < 0) return -1; //cw(時計回り)
        return 0; //collinear(1直線上)
    }
};


int main(){

    ll n;
    cin >> n;
    vector<V> p(n);
    rep(i,n){
        cin >> p[i].x >> p[i].y;
    }
    ll ans = 0;

    rep(i,n){
        rng(j,i+1,n){
            rng(k,j+1,n){
                    V A = p[i];
                    V B = p[j];
                    V C = p[k];
                    V b = B-A,c = C-A;
                    if(b.ccw(c) != 0){
                       ans++;
                    }
            }
        }
    }

    cout << ans << endl;

    return 0;
}