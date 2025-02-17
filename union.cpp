/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

#define     lg(x) __lg(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll long long
#define     fi first
#define     se second
#define     Mask(i) (1ll<<(i))
#define     c_bit(i) __builtin_popcountll(i)
#define     fr(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define     frd(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define     REP(i, a, b) for(int i = (a), _b = (b); i < _b; i++)

const ll MN = 1e9+7;
const long long inf = 1e18+7;
const ll base = 311;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct pll{ll fi,se;};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}
const int MAX = 25;
ll n, x[MAX], y[MAX], z[MAX], u[MAX], v[MAX], h[MAX];
void input()
{
    cin >> n; fr(i, 1, n) cin >> x[i] >> y[i] >> z[i] >> u[i] >> v[i] >> h[i];
}
namespace sub1
{
    const int MAXN = 1e6 + 2;
    int dp[MAXN];
    void slv()
    {
        ll res = 0;
        REP(msk, 0, (1 << n)) {
            ll X = -inf, Y = -inf, Z = -inf;
            ll U = inf, V = inf, H = inf;
            fr(i, 1, n) if(msk&(1 << (i - 1))) {
                maxi(X, x[i]);
                mini(U, u[i]);
                maxi(Y, y[i]);
                mini(V, v[i]);
                maxi(Z, z[i]);
                mini(H, h[i]);
            }
            if(U > X && V > Y && H > Z && U != inf && V != inf && H != inf) {
                ll val = (U - X)*(V - Y)*(H - Z);
//                cout << val << el;
                if(c_bit(msk)&1) res+=val;
                else res-=val;
            }
        }

        cout << res;
    }
}
namespace sub2
{
    void slv()
    {

    }
}

main()
{
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".OUT", "w", stdout);
    }
    bool qs = 0;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    //    sub2::slv();
    }
}


