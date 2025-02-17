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

ll n;
void input()
{
    cin >> n;
}
namespace sub1
{
    const int MAX = 1e6 + 2;
    bool dd[MAX];
    vector<ll> prime;
    void snt()
    {
        memset(dd, 1, sizeof dd);
        dd[0] = dd[1] = 0;
        for(int i = 2; i*i <= 1e6; i++) {
            if(dd[i]) {
                for(int j= i*i; j <= 1e6; j+=i) dd[j] = 0;
            }
        }
        fr(i, 1, 1e6) if(dd[i]) prime.pb(i);
    }
    bool check(ll x)
    {
        for(int i = 2; i*i <= x; i++) {
            if(x%i == 0) return 0;
        }
        return 1;
    }
    ll cal(ll x)
    {
        while(1) {
            if(check(x)) {
                return x*x;
            }
            x++;
        }
    }
    void slv()
    {
        snt();
        ll sq = sqrt(n);
        cout << cal(sq); return;
        if(sq > 1e6) {
            cout << cal(sq);
            return ;
        }
        int l = 0, r = sz(prime) - 1, mid;
        ll pos = 0;
        while(l <= r) {
            mid = (r + l) >> 1;
            ll value = prime[mid]*prime[mid];
            if(value >= n) {
                r = mid - 1;
                pos = value;
            }
            else l = mid + 1;
        }
        cout << pos;
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



