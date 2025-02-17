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

const int MAX = 2e6 + 2;
struct query
{
    int k, l, r;
};
int n, a[MAX], q;
query Q[MAX];
void input()
{
    cin >> n >> q; fr(i, 1, n) cin >> a[i];
    fr(i, 1, q) cin >> Q[i].k >> Q[i].l >> Q[i].r;
}
namespace sub1
{

    bool check()
    {
        return (n <= 5000 && q <= 5000);
    }
    void slv()
    {
        fr(i, 1, q) {
            int k = Q[i].k;
            int l = Q[i].l;
            int r = Q[i].r;
            if(k == 1) a[l] = r;
            else {
                long long s = 0;
                fr(p, l, r) s+=a[p];
                ll ans = inf, val = 0;
                fr(p, l, r - 1) {
                    val+=a[p];
                    ll tmp = s - val;
                    mini(ans, abs(tmp - val));
                }
                if(l == r) cout << a[l] << el;
                else cout << ans << el;
            }
        }
    }
}
namespace sub2
{
    bool check() {
        fr(i, 1, q) {
            if(Q[i].k == 1) return 0;
        }
        return 1;
    }
    ll pre[MAX];
    ll cal(int x, int y)
    {
        int l = x, r = y, m;
        while(r - l > 1) {
            m = (r + l) >> 1;
            ll m1 = pre[m] - pre[x - 1];
            ll m2 = pre[y] - pre[m];
            if(m1 == m2) return 0;
            if(m1 < m2) l = m;
            else r = m;
        }
        ll m1 = abs((pre[y] - pre[l]) - (pre[l] - pre[x - 1]));
        ll m2 = abs((pre[y] - pre[r]) - (pre[r] - pre[x - 1]));
        return min(m1, m2);
    }
    void slv()
    {
        fr(i, 1, n) pre[i] = pre[i - 1] + a[i];
        fr(i, 1, q) {
            int l = Q[i].l;
            int r = Q[i].r;
            cout << cal(l, r) << el;
        }
    }
}
namespace sub3
{
    const int MAX = 2e6 + 2;
    ll bit[MAX];
    const short LOG = 21;
    void upd(int x, int v)
    {
        // increase a[x] v value
        for(; x <= n; x += x & -x) bit[x]+=v;
    }
    ll get(int x)
    {
        // sum 1- > x
        ll res = 0;
        for(; x >= 1; x&= x - 1) res+=bit[x];
        return res;
    }

    int binary_bit(ll v)
    {
        ll sum = 0;
        int pos = 0;

        for(int i = LOG; i>=0; i--)
        {
            if(pos + (1 << i) < n && sum + bit[pos + (1 << i)] < v)
            {
                sum += bit[pos + (1 << i)];
                pos += (1 << i);
            }
        }

        return pos + 1;
    }
    int max(int x, int y)
    {
        if(x > y) return x;
        return y;
    }
    int min(int x, int y)
    {
        if(x < y) return x;
        return y;
    }
    void slv()
    {
        fr(i, 1, n) upd(i, a[i]);
        fr(i, 1, q) {
            int k = Q[i].k;
            int x = Q[i].l;
            int y = Q[i].r;
            if(k&1)  {
                upd(x, y - a[x]);
                a[x] = y;
            }
            else {
                ll val = get(y) - get(x - 1);
                int pos = binary_bit(get(x - 1) + val/2);
                ll value, res = inf;
                value = abs((get(pos) - get(x - 1)) - (get(y) - get(pos)));
                mini(res, value);
                value = abs((get(max(1, pos - 1)) - get(x - 1)) - (get(y) - get(max(1, pos - 1))));
                mini(res, value);

                cout << res << el;
            }
        }
    }
}
main()
{
    #define TASK "TOY"
//    #define TASK "task"
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
//        sub3::slv(); return 0;
        if(sub1::check()) sub1::slv();
        else if(sub2::check()) sub2::slv();
        else sub3::slv();
    }
}

