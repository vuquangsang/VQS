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

const int MAX = 5e5 + 2;
const int N = 105;

struct car
{
    int s, f, c, r;
};
int n, m, x[N];
car a[MAX];
void input()
{
    cin >> n >> m;
    fr(i, 1, n) cin >> x[i];
    fr(i, 1, m) cin >> a[i].s >> a[i].f >> a[i].c >> a[i].r;
}
namespace sub1
{
    bool check(int v)
    {
        fr(i, 1, m) {
            int f = a[i].f;
            int s = a[i].s;
            int c = a[i].c;
            int r = a[i].r;

            int ans = v, number = 0;
            fr(ii, s + 1, f) {
                int val = (x[ii] - x[ii - 1])*c;
                if(val > v) return 0;
                if(val > ans) {
                    number++;
                    ans = v - val;
                }
                else ans = ans - val;
            }
//            cout << i << " " << number << el;
            if(number > r) return 0;
        }
        return 1;
    }
    ll cnp()
    {
        long long l = 0, r = inf, m, res;
        while(l <= r) {
            m = (r + l) >> 1;
            if(check(m)) res = m, r = m - 1;
            else l = m + 1;
        }
        return res;
    }
    void slv()
    {
        cout << cnp();
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


