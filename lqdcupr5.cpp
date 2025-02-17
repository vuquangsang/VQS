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
ll n, q, a[MAX];
bool check = 1;
void input()
{
    cin >> n >> q; fr(i, 1, n) cin >> a[i];
    fr(i, 1, n) if(a[i] != 1) check = 0;
}
namespace sub1
{


    void slv()
    {
        ll l, r;
        while(q--) {
            cin >> l >> r;
            cout << r - l + 1 << el;
        }
    }
}
namespace sub2
{
    ll cal(vector<ll> v)
    {
        if(v.size() == 0) return 0;
        if(v.size() == 1) return 1;
        if(v.size() == 2) {
            if(v[0] == v[1]) return 2;
            return 1;
        }
        ll check = 0;
        vector<ll> tmp = v;
        sort(all(tmp));
        fr(i, 0, tmp.size() - 2) if(tmp[i] == tmp[i + 1]) check = 1;
        if(!check) return 1;
        ll ans = 0;
        vector<ll> m1, m2;
        ll sz = v.size() - 1;
        for(int i = 0; i <= sz; i+=2) m1.pb(v[i]);
        for(int i = 1; i <= sz; i+=2) m2.pb(v[i]);
        return cal(m1) + cal(m2);

    }
    void slv()
    {
        ll l, r;
        while(q--){
            vector<ll> tmp;
            cin >> l >> r;
            fr(i, l, r) tmp.pb(a[i]);
            cout << cal(tmp) << el;
        }
    }
}

main()
{
    #define TASK "divgroup"
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
        if(check) sub1::slv();
        else sub2::slv();
    //    sub2::slv();
    }
}

