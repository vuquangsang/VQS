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

const int MAX = 2e5 + 2;
int n, m, a[MAX];
void input()
{
    cin >> n >> m; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    int tmp[MAX], bit[MAX];
    bool check(int l, int r)
    {
        int d = 0;
        fr(i, l, r) tmp[++d] = a[i];
        sort(alla(tmp, d));
        int sz = r - l + 1;
        return (tmp[sz/2 + (sz&1)] == m);
    }
    void upd(ll x, ll v)
    {
        for(; x <=n; x+=x&(-x)) bit[x]+=v;
    }
    ll get(ll x)
    {
        ll res = 0;
        for(; x >= 1; x-=x&(-x)) res+=bit[x];
    }
    void slv()
    {
        int pos = 0;
        fr(i, 1, n) if(a[i] == pos) pos = i;
        int res = 0;
        fr(i, 1, n) {
            bool ok = 0;
            if(pos < i) continue;
            memset(bit, 0, sizeof bit);
            fr(j, i, n) {
                upd(a[j], 1);
                if(pos < i) {
                    ok = 1;
                    break;
                }
                if(check(i, j)) res++;
            }
            if(ok) break;
        } cout << res;
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
    #define TASK "task"
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


