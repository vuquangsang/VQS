#include <bits/stdc++.h>
using namespace std;

//#define   ll int
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
#define     BIT(msk, i) (msk&(1 << i))

const ll MN = 1e9+7;
const ll MF = 1e6+7;
const long long inf = 1e18+7;
const ll N = 1005;
const ll base = 311;
const ll F = 1e5 + 2;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};
const short LO = 17;

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template<class X, class Y>
    bool mini(X &x, const Y &y)  {
        if(x > y) {
            x = y;
            return 1;
        }
        else return 0;
    }
template<class X, class Y>
    bool maxi(X &x, const Y &y)
    {
        if(x < y) {
            x = y;
            return 1;
        }
        else return 0;
    }
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

ll n, k, a[MF];
void input()
{
    cin >> n >> k; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    #define N 402
    // goi f[i][j] la so  diem bi tru it nhat khi ban toi tau i voi so lan thay doi muc nl la j
    // f[i][j] = f[k][j]
    ll f[N][N], rmq[N][10], pre[N];
    void build()
    {
        fr(i, 0, n - 1) rmq[i][0] = a[i + 1];
        for(int j = 1; (1 << j) < n; j++) {
            for(int i = 0; (i + (1 << j) - 1) < n; i++) {
                rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    ll get(ll l, ll r)
    {
        ll j = lg(r - l + 1);
        return max(rmq[l][j], rmq[r - (1 << j) + 1][j]);
    }
    ll cal(ll x, ll y)
    {
        ll ans = -inf;
        fr(i, x, y) maxi(ans, a[i]);
        ll res = 0;
        fr(i, x, y) res+=(ans - a[i]);
        return res;
    }

    void viu()
    {
        fr(i, 1, n) {
            fr(len, 0, k) {
                cout << f[i][len] << " ";
            } cout << el;
        } return;
    }
    void slv()
    {
        fr(i, 1, n) fr(j, 0, k) f[i][j] = inf;
        fr(i, 1, n) pre[i] = pre[i - 1] + a[i];
        build();
        f[1][0] = 0;
        f[1][1] = 0;
        fr(i, 1, n) {
            f[i][0] = get(0, i - 1)*i - pre[i];
            fr(j, 0, i - 1){
                fr(len, 0, k - 1){
                    ll value = get(j, i - 1)*(i - j) - pre[i] + pre[j];
                    mini(f[i][len + 1], f[j][len] + value);
                }
            }
        }
   //    viu(); return;
        ll res = inf;
        fr(i, 0, k) mini(res, f[n][i]);
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
