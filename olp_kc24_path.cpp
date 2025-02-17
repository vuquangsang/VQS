/* Try to do something */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll,ll>  pll;
typedef vector<int> vi;
typedef vector<pii> vii;

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
#define     sz(a) (int)a.size()
#define     uni(V) sort(all(V)), V.resize(unique(all(V)) - V.begin())


const int N = 2e6 + 5, base = 311, sm = 1e9 + 7;
const long long inf  = 1e18 + 2;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}
void add(int &x, int y) {
    if((x += y) >= sm) x -= sm;
    else if(x < 0) x += sm;
}
int mod(int x, int y)
{
    return (1LL*x*y)%sm;
}
int n, m, k;
pii a[N];
void input()
{
    cin >> n >> m >> k;
    fr(i, 1, k) cin >> a[i].fi >> a[i].se;
}
namespace sub1
{
    int dp[N];
    int fac[N], inv_fac[N];
    int pw(int a, int n)
    {
        if(!n) return 1;
        int res = pw(a, n/2);
        res = mod(res, res);
        if(n&1) res = mod(res, a);
        return res;
    }
    int C(int k, int n)
    {
        return mod(mod(fac[n], inv_fac[k]), inv_fac[n - k]);
    }
    void prepare()
    {
        const int N1 = 2e5;
        fac[0] = inv_fac[0] = 1;
        fr(i, 1, N1) fac[i] = mod(fac[i - 1], i);
        inv_fac[N1] = pw(fac[N1], sm - 2);
        for(int i = N1 - 1; i >= 0; i--) {
            inv_fac[i] = mod(inv_fac[i + 1], i + 1);
        }
    }

    bool check(int i, int j)
    {
        return (a[i].fi >= a[j].fi && a[i].se >= a[j].se);
    }
    void slv()
    {
        prepare();
        sort(a + 1, a + k + 1, [](pii a, pii b){return a.fi + a.se < b.fi + b.se;});

        a[++k].fi = n;
        a[k].se = m;

        dp[1] = C(a[1].fi - 1, a[1].fi + a[1].se - 2);
        fr(i, 2, k) {
            dp[i] = C(a[i].fi - 1, a[i].fi + a[i].se - 2);
            dp[i]%=sm;
            frd(j, i - 1, 1){
                if(check(i, j)){
                    dp[i] = dp[i] - mod(dp[j], C(a[i].fi - a[j].fi, a[i].fi + a[i].se - a[j].fi - a[j].se)) + sm;
                    dp[i]%=sm;
                }
            }
        }
//        fr(i, 1, k) cout << dp[i] << " "; cout << el;
        cout << dp[k];
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
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #define TASK ""
    if(fopen(TASK".INP", "r")) {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }

    bool qs = 0;

    int tt = 1;
    if(qs) cin >> tt;
    while(tt--) {
        input();
        sub1::slv();
    }
    cerr << "\nTime" << 0.001 * clock() << "s "; return 0;


}



