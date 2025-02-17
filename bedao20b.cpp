/* Vu Quang Sang from Le Khiet High School for Gifted */
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

ll qr[4], t[4][7], d[4][7], e[4][7], k[4];
vector<double> s[4][10];
void input()
{
    fr(ii, 1, 3){
        cin >> k[ii];
        fr(i, 1, k[ii]) {
           cin >> t[ii][i] >> d[ii][i] >> e[ii][i];
            fr(x, 1, e[ii][i]) {
                ll val; cin >> val;
                s[ii][i].pb(val);
            }
        }
    }

}
namespace sub1
{

    double f[200];
    double cal(double x, double value)
    {
        double res = (x*value)/100;
        return res;
    }
    void slv()
    {
        fr(i, 1, k[1]) {
            frd(x, 180, t[1][i]) {
                maxi(f[x], f[x - t[1][i]] + cal(d[1][i], 6));
            }
        }
        fr(ii, 2, 3) {
            fr(i, 1, k[ii]) {
                frd(x, 180, t[ii][i]) {
                    maxi(f[x], f[x - t[ii][i]] + cal(d[ii][i], 7));
                }
            }
        }
        double res = 0;
        fr(i, 0, 180) maxi(res, f[i]);
        cout << fixed << setprecision(2) << res ;
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



