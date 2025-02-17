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

const int MAX = 1e5 + 2;
int n, a[MAX];
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    void slv()
    {
        int res = 0;
        REP(msk, 0, Mask(n)) {
            int val = 0;
            int mi = MN;
            fr(i, 1, n) {
                if(msk&(1 << (i - 1))) {
                    mini(mi, a[i]);
                    val = gcd(val, a[i]);
                }
            }
            res = res + (val*mi);
        }
        cout << res;
    }
}
namespace sub2
{
    bool check()
    {
        fr(i, 1, n) fr(j, i + 1, n) {
            if(gcd(a[i], a[j]) != 1) return 0;
        }
        return 1;
    }
    int Pow(int a, int n)
    {
        if(!n) return 1;
        int res = Pow(a, n/2);
        res = mod(res, res);
        if(n&1) res = mod(res, a);
        return res;
    }
    void slv()
    {
        cout << Pow(2, n) - 1;
    }
}
main()
{
    #define TASK "creature"
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

//        else if(sub2::check()) sub2::slv();
    //    sub2::slv();
    }
}


