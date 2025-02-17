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

const ll sm = 1e9+7;
const long long inf = 1e18+7;
const ll base = 311;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct pll{ll fi,se;};
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

const int N = 1e5 + 2;
int n, K, a[N];
void input()
{
    cin >> n >> K; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    int bit[N];
    const int lim = 1e5;
    void upd(int x, int v)
    {
        for(; x <= n; x += x & -x) bit[x] ^= v;
    }
    int get(int x)
    {
        int ans = 0;
        for(; x >= 1; x -= x & -x) ans ^= bit[x];
        return ans;
    }
    int get(int l, int r)
    {
        return get(r) ^ get(l - 1);
    }
    void slv()
    {
        fr(i, 1, n) upd(i, a[i]);
        int ans = 0;
        fr(i, 1, n) {
            fr(j, i, n) {
                if(get(i, j) < K) {
//                    cout << i << " " << j << el;
                    ans++;
                }
            }
        }
        cout << ans;
    }
}
namespace sub2
{
    int T[N*35][2];
    ll ans = 0;
    ll s[N], f[N*35];
    int node = 1;


    void upd(ll x)
    {
        int r = 1;
        for(int i = 31; i >= 0; i--) {
            int j = (x >> i & 1);
            if(T[r][j] == 0) {
                T[r][j] = ++node;
            }
            r = T[r][j];
            f[r]++;
        }
    }

    void get(ll x)
    {
        int r = 1;
        for(int i = 31; i >= 0; i--) {
            int ok1 = x & (1 << i);
            int ok2 = K & (1 << i);

            if(!ok1 && ok2) {
                ans += f[T[r][0]];
                r = T[r][1];
            }
            else if(!ok1 && !ok2) {
                r = T[r][0];
            }
            else  if(ok1 && ok2) {
                ans += f[T[r][1]];
                r = T[r][0];
            }
            else  if(ok1 && !ok2) {
                r = T[r][1];
            }
        }
    }
    void slv()
    {
        upd(0);
        fr(i, 1, n) {
            s[i] = s[i - 1] ^ a[i];
            get(s[i]);
            upd(s[i]);
        }
        cout << ans;
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
        sub2::slv();
    //    sub2::slv();
    }
}


