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
struct query
{
    char k;
    int val;
};
int n, q, a[MAX];
query Q[MAX];
void input()
{
    cin >> n >> q; fr(i, 1, n) cin >> a[i];
    fr(i, 1, q) cin >> Q[i].k >> Q[i].val;
}
namespace sub1
{


    void slv()
    {
        char x;
        int val;
        fr(t, 1, q){
            x = Q[t].k;
            val = Q[t].val;
            if(x == '>') {
                fr(i, 1, n) if(a[i] > val) a[i] = -a[i];
             }
             else  {
                fr(i, 1, n) if(a[i] < val) a[i] = -a[i];
             }
//             fr(i, 1, n) cout << a[i] << " "; cout << el;
        }
        fr(i, 1, n) cout << a[i] << " ";
    }
}
namespace sub2
{
    map<ll,ll> mp;
    vector<ll> v;
    void slv()
    {
        fr(i, 1, n) v.pb(a[i]);
        sort(all(v));
        int pos = n;
        char x;
        ll val;
        fr(i, 1, q) {
            x = Q[i].k;
            val = Q[i].val;
            int tmp = upper_bound(all(v), val) - v.begin();
            mini(pos, tmp);
        }
        frd(i, (ll)v.size() - 1, pos) mp[v[i]] = -v[i];
        frd(i, pos - 1, 0) mp[v[i]] = v[i];
        fr(i, 1, n) cout << mp[a[i]] << " ";
    }
}
main()
{
    #define TASK "switchsign"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".OUT", "w", stdout);
    }
    int sub;
    cin >> sub;
    bool qs = 0;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        if(sub == 2) sub2::slv();
        else sub1::slv();
    //    sub2::slv();
    }
}

