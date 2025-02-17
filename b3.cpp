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

    int rmq_min[MAX][21], rmq_gcd[MAX][21];
    int pre[MAX], suf[MAX];
    stack<int> st;

    void build()
    {
        fr(i, 1, n) rmq_min[i][0] = rmq_gcd[i][0] = a[i];
        for(int j = 1; (1 << j) - 1 <= n; j++) {
            for(int i = 1; i + (1 << j) - 1 <= n; i++) {
                rmq_min[i][j] = min(rmq_min[i][j - 1], rmq_min[i + (1 << (j - 1))][j - 1]);
                rmq_gcd[i][j] = gcd(rmq_gcd[i][j - 1], rmq_gcd[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int get(int l, int r)
    {
        int j = lg(r - l + 1);
        return gcd(rmq_gcd[l][j], rmq_gcd[r - (1 << j) + 1][j]);
    }
    int get_min(int l, int r)
    {
        int j = lg(r - l + 1);
        return min(rmq_min[l][j], rmq_min[r - (1 << j) + 1][j]);
    }
    void slv()
    {
        build();
        fr(i, 1, n) {
            int l = 1, r = i, m, pos = i;
            while(l <= r) {
                m = (r + l) >> 1;
                if(get_min(m, i) == get(m, i)) {
                    pos = m;
                    r = m - 1;
                }
                else l = m + 1;
            }
            pre[i] = pos;
        }
        frd(i, n, 1) {
            int l = i, r = n, m, pos = i;
            while(l <= r) {
                m = (r + l) >> 1;
                if(get_min(i, m) == get(i, m)) {
                    pos = m;
                    l = m + 1;
                }
                else r = m - 1;
            }
            suf[i] = pos;
        }
//        fr(i, 1, n) cout << pre[i] << " "; cout << el;
//        fr(i, 1, n) cout << suf[i] << " "; cout << el;
        int res = 0;
        fr(i, 1, n) {
            res = max(res, max(i - pre[i], suf[i] - i));
            if(get_min(pre[i], suf[i]) == get(pre[i], suf[i])) maxi(res, suf[i] - pre[i]);
        }
        cout << res;
    }
}
namespace sub2
{
    int rmq_min[MAX][21], rmq_gcd[MAX][21];
    int pre[MAX], suf[MAX];
    stack<int> st;
    void build()
    {
        fr(i, 1, n) rmq_min[i][0] = rmq_gcd[i][0] = a[i];
        for(int j = 1; (1 << j) - 1 <= n; j++) {
            for(int i = 1; i + (1 << j) - 1 <= n; i++) {
                rmq_min[i][j] = min(rmq_min[i][j - 1], rmq_min[i + (1 << (j - 1))][j - 1]);
                rmq_gcd[i][j] = gcd(rmq_gcd[i][j - 1], rmq_gcd[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int get(int l, int r)
    {
        int j = lg(r - l + 1);
        return gcd(rmq_gcd[l][j], rmq_gcd[r - (1 << j) + 1][j]);
    }
    int get_min(int l, int r)
    {
        int j = lg(r - l + 1);
        return min(rmq_min[l][j], rmq_min[r - (1 << j) + 1][j]);
    }
    void slv()
    {
        build();
        int res = 0;
        fr(i, 1, n) {
            fr(j, 1, i) if(get_min(j, i) == get(j, i)) {
                maxi(res, i - j);
            }
        }
        cout << res;
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


