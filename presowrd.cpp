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
#define     BIT(msk, i) (msk&(1 << i))

const ll MN = 1e9+7;
const ll MF = 1e6+7;
const long long inf = 1e18+7;
const ll N = 1005;
const ll base = 311;
const ll F = 1e5 + 2;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};
const short LO = 17;

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

ll n, S;
string s;
void input()
{
    cin >> n >> S;
    cin >> s;
    s = ' ' + s;

}
namespace sub1
{
    ll f[N][N];
    void slv()
    {
        ll res = 0;
        fr(i, 1, n) {
            map<char, ll> cnt;
            ll value = 0;
            fr(j, i, n) {
                value = value - cnt[s[j]]*cnt[s[j]];
                cnt[s[j]]++;
                ll tmp = cnt[s[j]];
                value = value + tmp*tmp;
                if(value <= S) res++;
            }
        }
        cout << res;
    }
}
namespace sub2
{
    #define sq(x) (1ll*(x)*(x))
    ll cnt[26], cur =  0;
    void add(char c)
    {
        int k = cnt[c - 'a']++;
        cur+=sq(k + 1) - sq(k);
    }
    void del(char c)
    {
        int k = cnt[c - 'a']--;
        cur-=sq(k) - sq(k - 1);
    }
    void slv()
    {
        add(s[1]);
        int r = 1;
        ll res = 0;
        fr(l, 1, n) {
            if(l > 1) del(s[l - 1]);
            while(r <= n && cur <= S) {
                r++;
                if(r <= n)add(s[r]);
            }
            res = res + r - l;
        }
        cout << res;
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



