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
int n, q, a[MAX];
void input()
{
    cin >> n >> q; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{


    void slv()
    {
        int p, x;
        while(q--) {
            cin >> p >> x;
            a[p] = x;
            ll res = 0;
            int pos = -1;
            fr(i, 1, n) {
                if(a[i] == res) {
                    pos = i;
                    break;
                }
                res+=a[i];
            }
            cout << pos << el;
        }
    }
}
namespace sub2
{
    ll bit[MAX];
    const int LOG = 21;
    void upd(ll x, ll v)
    {
        for(; x <= n; x+=x&(-x)) bit[x]+=v;
    }
    ll get(ll x)
    {
        ll res = 0;
        for(; x >= 1; x-=x&(-x)) res+=bit[x];
        return res;
    }
    int find_bit(ll v)
    {
        ll sum = 0, pos = 0;
        for(int i = LOG; i >= 0; i--) {
            if(pos + (1 << i) <= n && sum + bit[pos + (1 << i)] < v) {
                sum+=bit[pos + (1 << i)];
                pos+=(1 << i);
            }
        }
        return pos + 1;
    }
    ll cal()
    {
        ll sum = 0;
        while(1) {
            int id = find_bit(2*sum);
            cout << id << " " << sum << " ";
            if(id > n) return -1;
            sum = get(id);
            cout << sum << el;
            if(2*a[id] == sum) return id;
        }
    }
    void slv()
    {
        fr(i, 1, n) upd(i, a[i]);
        int p, x;
        while(q--) {
            cin >> p >> x;
            upd(p, x - a[p]);
            a[p] = x;
            cout << cal() << el;
        }
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


