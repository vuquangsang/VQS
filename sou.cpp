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

const ll MN = 1e9+7;
const long long inf = 1e18+7;
const ll base = 311;
const ll F = 1e5 + 2;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};
const short LO = 17;

struct node{ll x,y;};
struct pll{ll fi,se;};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

int n;
void input()
{
    cin >> n;
}
namespace sub1
{

    const int MAX = 1e6 + 2;
    int prime[MAX];
    int cnt[MAX], f[MAX];
    void snt()
    {
        for(int i = 2; i*i <= 1e6; i++) if(!prime[i]) {
            for(int j = i*i; j <= 1e6; j+=i) if(!prime[j]) {
                prime[j] = i;
            }
        }
        fr(i, 1, 1e6) if(!prime[i]) prime[i] = i;
    }
    ll Pow(ll a, ll n) {
        if(!n) return 1;
        ll res=  Pow(a, n/2);
        res = res*res;
        if(n&1) res = res*a;
        return res;
    }
    void cal(ll x)
    {
        while(x != 1) {
            cnt[prime[x]]++;
            x/=prime[x];
        }
    }
    void slv()
    {
        snt();
        fr(x, 2, n) {
           cal(x);
        }
        ll res = 1;
        fr(i, 2, n) if(cnt[i] > 0) res = res*(cnt[i] + 1);
        ll ans = 1;
        fr(x, 2, n) if(cnt[x] > 0) ans = ans*(Pow(x, cnt[x] + 1) - 1)/(x - 1);
        cout << res << el << ans;
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
    #define TASK "sou"
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


