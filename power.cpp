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

const int MAX = 1e9 + 2;
int n, a[MAX];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    vector<ll> prime;
    bool dd[MAX];
    void snt()
    {
        memset(dd, 1, sizeof dd);
        dd[0] = dd[1] = 0;
        for(int i = 2; i*i <= 5e4; i++) {
            if(dd[i]) {
                for(int j = i*i; j <= 5e4; j+=i) {
                    dd[j] = 0;
                }
            }
        }
        fr(i, 1, 5e4) if(dd[i]) prime.pb(i);
    }
    map<ll,ll> trial_division3(long long n) {
        map<ll,ll> factorization;
        ll id = 0;
        while(1) {
            ll x = prime[id];
            if(x*x > n) break;
            while(n%x == 0) {
                factorization[x]++;
                n/=x;
            }
            id++;
        }
        if(n > 1) {
            factorization[n]++;
        }
        return factorization;
    }
    ll Pow(ll a, ll n)
    {
        if(!n) return 1;
        ll res = Pow(a, n/2);
        res = res*res;
        if(n&1) res = res*a;
        return res;
    }
    void slv()
    {
        snt();
//        fr(i, 0, 10) cout << prime[i] << " "; cout << el << el;
        fr(i, 1, n) {
                map<ll,ll> mp = trial_division3(a[i]);
                ll res = 1;
                for(auto x : mp) {
    //                    cout << x.fi << " " << x.se << el;
                    res = res*(Pow(x.fi, x.se + 1) - 1)/(x.fi - 1);
                }
                cout << res << " ";
        }
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


