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
template<class X, class Y>
    bool mini(X &x, const Y &y)  {
        if(x > y) {
            x = y;
            return 1;
        }
        else return 0;
    }
template<class X, class Y>
    bool maxi(X &x, const Y &y)
    {
        if(x < y) {
            x = y;
            return 1;
        }
        else return 0;
    }
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

string a[MF];
ll n;
string s;
void input()
{
    fr(i, 1, 26) cin >> a[i];
    cin >> s;
    s = ' ' + s;
    n = s.size() - 1;
}
namespace sub1
{
    ll k[MF];
    string t[4*26 + 10];
    string cmp(string a, string b)
    {
        if(a.size() == b.size()) {
            if(a < b) return a;
            return b;
        }
        else if(a.size() > b.size()) return a;
        return b;
    }
    void upd(ll id, ll l, ll r, ll i, string val)
    {
        if(i > r || i < l) return;
        if(l == r) {
            t[id] = cmp(t[id], val);
            return ;
        }
        ll m = (r + l) >> 1;
        upd(id << 1, l, m, i, val);
        upd(id << 1 | 1, m + 1, r, i, val);
        t[id] = cmp(t[id << 1], t[id << 1 | 1]);
    }
    string get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return "";
        if(u <= l && r <= v) return  t[id];
        ll m = (r + l) >> 1;
        return cmp(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }
    string f[MF];
    void slv()
    {
        fr(i, 1, n) k[i] = s[i] - 'A' + 1;
        fr(i, 1, 4*26 + 1) t[i] = "";
        f[1] = s[1];
        upd(1, 1, 26, k[1], f[1]);
        fr(i, 2, n){
            f[i] = s[i];
            f[i] = cmp(f[i], get(1, 1, 26, 1, k[i]) + s[i]);
            upd(1, 1, 26, k[i], f[i]);
        }
        string res = "";
        fr(i, 1, n) res = cmp(res, f[i]);
        for(char c : res) cout << a[c - 'A' + 1] << " " ;
    }
}
namespace sub2
{
    string cmp(string a, string b)
    {
        if(a.size() == b.size()) {
            if(a < b) return a;
            return b;
        }
        if(a.size() > b.size()) return a;
        return b;
    }
    string f[MF];
    void slv()
    {
        f[1] = s[1];
        fr(i, 2, n) {
            f[i] = s[i];
            fr(j, 1, i - 1) {
                if(s[i] >= s[j]) {
                    f[i] = cmp(f[i], f[j] + s[i]);
                }
            }
        }
        string res = "";
        fr(i, 1, n) res = cmp(res, f[i]);
        for(char c : res) cout << a[c - 'A' + 1] << " " ;
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


