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

ll n, a[MF];
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    ll pre[MF], suf[MF], s[MF];
    ll d[MF], c[MF];
    void slv()
    {
        fr(i, 1, n) s[i] = s[i - 1] + a[i];
        fr(i, 3, n) pre[i] = max(pre[i - 3] + s[i] - s[i - 3], s[i] - s[i - 3]);
        frd(i, n - 2, 1) suf[i] = max(suf[i + 3] + s[i + 2] - s[i - 1], s[i + 2] - s[i - 1]);
        d[1] = d[2] = c[n] = c[n - 1] = -inf;
        fr(i, 3, n) d[i] = max(d[i - 1], pre[i]);
        frd(i, n - 2, 1) c[i] = max(c[i + 1], suf[i]);
        ll res = -inf;
        fr(i, 3, n - 3) {
            maxi(res, d[i] + c[i + 1]);
        }
        cout << res;
    }
}
namespace sub2
{
    ll s[MF];
    void slv()
    {
        fr(i, 1, n) s[i] = s[i - 1] + a[i];
        ll res = -inf;
        fr(i, 1, n - 3) {
            fr(j, i + 1, n - 2) {
                if((j - i + 1)%3 == 0) {
                    fr(u, j + 1, n - 1) {
                        fr(v, u + 1, n){
                            if((v - u + 1)%3 == 0) {
                                maxi(res, s[j] - s[i - 1] + s[v] - s[u - 1]);
                            }
                        }
                    }
                }
            }
        }
        cout << res;
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


