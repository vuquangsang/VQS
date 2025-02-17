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
    cin >> n; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    ll f[2][MF];
    void slv()
    {
        fr(i, 1, n) f[0][i] = (a[i] > 0);
     //   fr(i, 1, n) cout << f[0][i] << " " ; cout << el;
        fr(len, 2, 4) {
            fr(i, len, n) {
                fr(j, 1, i - 1) {
                    if(len == 2) {
                        if(a[i] > 0) continue;
                        if(a[j] > 0) f[1][i]+=f[0][j];
                    }
                    else if(len == 3) {
                        if(a[i] > 0) continue ;
                        if(a[j] < 0) f[1][i]+=f[0][j];
                    }
                    else{
                        if(a[i] < 0) continue ;
                        if(a[j] < 0) f[1][i]+=f[0][j];
                    }
                }
            }
    //       fr(i, 1, n) cout << f[1][i] << " "; cout << el;
            fr(i, 1, n) f[0][i] = f[1][i], f[1][i] = 0;
        }
        ll res = 0;
        fr(i, 1, n) {
            res+=f[0][i];
        }
     //   cout << res << " ";


        fr(len, 0, 1) fr(i, 1, n) f[len][i] = 0;
        fr(i, 1, n) f[0][i] = (a[i] < 0);
        fr(i, 1, n) cout << f[0][i] << " " ; cout << el;
        fr(len, 2, 4) {
            fr(i, len, n) {
                fr(j, 1, i - 1) {
                    if(len == 2) {
                        if(a[i] < 0) continue;
                        if(a[j] < 0) f[1][i]+=f[0][j];
                    }
                    else if(len == 3) {
                        if(a[i] < 0) continue ;
                        if(a[j] > 0) f[1][i]+=f[0][j];
                    }
                    else{
                        if(a[i] > 0) continue ;
                        if(a[j] > 0) f[1][i]+=f[0][j];
                    }
                }
            }
           fr(i, 1, n) cout << f[1][i] << " "; cout << el;
            fr(i, 1, n) f[0][i] = f[1][i], f[1][i] = 0;
        }
        res = 0;
        fr(i, 1, n) {
            res+=f[0][i];
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


