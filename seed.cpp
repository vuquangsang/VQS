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


int n;
string s;
ll len;
const int MX=(1<<17)+200;
void input()
{

    cin >> n;
    cin >> s;
    s = ' '+s;
    len = s.size() - 1;
}
namespace sub1
{
    int dd[55][MX], t[MX][3], nxt[MX][3], ok[MX];
    long long  f[55][MX];
    int node = 0;
    ll cal(ll i, ll r)
    {
        if(i > n) return 1;
        if(dd[i][r]) return f[i][r];
        dd[i][r] = 1;
        ll sum = 0;
        sum+=cal(i + 1, nxt[r][0]);
        if(ok[nxt[r][1]] == 0) sum+=cal(i + 1, nxt[r][1]);
        f[i][r] = sum;
        return f[i][r];
    }
    void build(ll i, ll r)
    {
        if(i > len) {
            ok[r] = 1;
            return;
        }
        if(s[i] == '*') {
            if(t[r][0] == -1) t[r][0] = ++node;
            build(i + 1, t[r][0]);
        }
        if(t[r][1] == -1) t[r][1] = ++node;
        build(i + 1, t[r][1]);

    }
    void DFS(ll r, string s)
    {
        if(t[r][0] == -1) {
            nxt[r][0] = 1;
            string x = s + '0';
            while(!x.empty()) {
                x.erase(0, 1);
                int c = 1, ok = 1;
                fr(i, 0, x.size() - 1) {
                    char j = x[i] - '0';
                    if(t[c][j] == -1){
                        ok = 0;
                        break;
                    }
                    else{
                        c = t[c][j];
                    }
                }
                if(ok) {
                    nxt[r][0] = c;
                    break;
                }

            }
        }
        if(t[r][0] != -1){
           nxt[r][0] = t[r][0];
           DFS(t[r][0], s + '0');
        }
        if(t[r][1] != -1) {
            nxt[r][1] = t[r][1];
            DFS(t[r][1], s + '1');
        }
    }
    void slv()
    {
        memset(t,  -1, sizeof t);
        memset(nxt, -1, sizeof nxt);
        node = 1;
        build(1, 1);
        string x ="";
        DFS(1, x);
        ll ans = 1;
        fr(i, 1, n) ans*=2;
        cout << ans - cal(1, 1);
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


