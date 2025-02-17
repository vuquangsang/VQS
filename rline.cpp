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

const int MAX = 3e5 + 2;
node a[MAX];
ll n;
void input()
{
    cin >> n;
    fr(i,1 , n) cin >> a[i].x >> a[i].y;
}
namespace sub1
{
    struct note
    {
        ll val, k, id;
        bool operator<(note const&a) const
        {
            return val < a.val;
        }
    };
    set<ll> st;
    ll f[MAX];
    note pos[2*MAX];
    void slv()
    {
        fr(i, 1, n) {
            ll u = a[i].x;
            ll v = a[i].y;
            pos[i] = {u, 1, i};
            pos[i + n] = {v, 2, i};
        }
        sort(pos + 1, pos + 2*n + 1);
        ll cnt = 0, res = 0;
        fr(i, 1, 2*n) {
            ll k = pos[i].k;
            if(k == 1) {
                if(cnt > 0) res+=pos[i].val - pos[i - 1].val;
                if(cnt == 1) f[*st.begin()] = pos[i].val - pos[i - 1].val;
                cnt++;
                st.insert(pos[i].id);
            }
            else {
                if(cnt > 0) res+=pos[i].val - pos[i - 1].val;
                if(cnt == 1) f[*st.begin()] = pos[i].val - pos[i - 1].val;
                cnt--;
                st.erase(pos[i].id);
            }
        }
        ll ans = -inf;
        fr(i, 1, n) maxi(ans, res - f[i]);
        cout << ans;
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
    #define TASK "rline"
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


