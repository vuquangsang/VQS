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

const int MAX = 1e5;
int n, k;
string a[MAX];
void input()
{
    cin >> n >> k;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    int T[MAX][12], node = 0;
    void stander()
    {
        int lim = 0;
        fr(i, 1, n) {
            int sz = a[i].size();
            maxi(lim, sz);
        }
        fr(i, 1, n) {
            while(a[i].size() < lim) {
                a[i] = '0' + a[i];
            }
        }
    }
    void add(string s)
    {
        int r = 1;
        for(char c : s) {
            int j = c - '0';
            if(T[r][j] == -1) {
                node++;
                T[r][j] = node;
            }
            r = T[r][j];
        }
    }
    ll get(string s)
    {
        ll res = 1, r = 0;
        for(char c : s) {
            ll j = c - '0', ans = -1, id;
            fr(i, 0, 9) {
                ll val = (i + j)%10;
                if(T[r][i] != -1 && maxi(ans, val)) {
                    id = i;
                }
            }
            if(ans != -1) res = res*10 + ans;
            r = T[r][id];

        }
        return res;
    }
    string bor(string a, string b)
    {
        int sz = a.size() - 1;
        string ans = "";
        fr(i, 0, sz) {
            int val = a[i] + b[i] - 96;
            val%=10;
            ans = ans + char(val + 48);
        }
        return ans;
    }
    void slv()
    {
        stander();
        memset(T, -1, sizeof T);
        add(a[1]);
        ll res = 0;
        fr(i, 2 , n) {
            fr(j, i + 1, n) {
                string v = bor(a[i], a[j]);
                maxi(res, get(v));
            }
            add(a[i]);
        }
        cout << res;
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
        sub1::slv();
    //    sub2::slv();
    }
}


