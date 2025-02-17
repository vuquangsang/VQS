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

const int MAX = 5e5 + 2;
int c, n;
int v[MAX];
void input()
{
    cin >> c >> n; fr(i, 1, n) cin >> v[i];
}
namespace sub1
{

    bool ok[MAX];
    long long pre[MAX];
    int find_m(int x)
    {
        int l = 1, r = n, m, pos;
        while(l <= r) {
            m = (r + l) >> 1;
            if(v[m] < x) r = m - 1, pos = m;
            else l = m + 1;
        }
        return pos;
    }
    int find_max(int x, int p)
    {
        int l = p, r = n, m, pos;
        while(l <= r) {
            m = (r + l) >> 1;
            long long value = pre[m] - pre[p - 1];
            if(value <= x) pos = m, l = m + 1;
            else r = m - 1;
        }
        return pos;
    }
    void slv()
    {
        memset(ok, true, sizeof  ok);
        sort(v + 1, v + n + 1, [](int a, int b){return a > b;});
        fr(i, 1, n) pre[i] = pre[i - 1] + v[i];
        ok[0] = 0;
        fr(x, 1, c) {
            int pos = find_m(x);
            int m = find_max(x, pos);
            ok[x] = ok[x - pre[m] - pre[pos]];
            if(ok){
                cout << x << el;
                return;
            }
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
    #define TASK "changes"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".OUT", "w", stdout);
    }
    short subtask;
    cin >> subtask;
    bool qs = 1;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    //    sub2::slv();
    }
}


