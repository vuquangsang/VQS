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
ll n, a[MAX], b[MAX];
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i];
    fr(i, 1, n - 1) cin >> b[i];
}
namespace sub1
{

    ll t_a[5][MAX], t_b[MAX][5];
    ll mex(ll x, ll y)
    {
        if(x && y) return 0;
        ll res = max(x, y);
        if(res == 1) return 2;
        return 1;
    }
    void slv()
    {
        ll m1 = 0, m2 = 0, m3 = 0;
        fr(i, 1, n) t_a[1][i] = a[i];
        fr(i, 1, 2) t_a[i + 2][1] = b[i];
        fr(i, 1, n - 1) t_b[i + 1][1] = b[i];
        fr(i, 1, 3) t_b[1][i] = a[i];

        fr(k, 2, 3) fr(i, 2, n) {
            t_a[k][i] = mex(t_a[k - 1][i], t_a[k][i - 1]);
        }
        fr(i, 2, n) fr(k, 2, 3) {
            t_b[i][k] = mex(t_b[i - 1][k], t_b[i][k - 1]);
        }
        fr(i, 1, n) {
            fr(k, 1, 3 ){
                if(t_b[i][k] == 0) m1++;
                if(t_b[i][k] == 1) m2++;
                if(t_b[i][k] == 2) m3++;
            }
        }
        fr(i, 1, 3) fr(k, 1, n) {
            if(t_a[i][k] == 0) m1++;
            if(t_a[i][k] == 1) m2++;
            if(t_a[i][k] == 2) m3++;
        }
        fr(i, 1, 3) fr(k, 1, 3)  {
            if(t_a[i][k] == 0) m1--;
            if(t_a[i][k] == 1) m2--;
            if(t_a[i][k] == 2) m3--;
        }
        t_a[4][1] = b[3];
        fr(i, 2, n) {
            t_a[4][i] = mex(t_a[3][i], t_a[4][i - 1]);
            if(i > 4) {
                if(t_a[4][i] == 0) m1+=n - i + 1;
                if(t_a[4][i] == 1) m2+=n - i + 1;
                if(t_a[4][i] == 2) m3+=n - i + 1;
            }
        }
        if(t_a[4][4] == 0) m1+=n - 4 + 1;
        if(t_a[4][4] == 1) m2+=n - 4 + 1;
        if(t_a[4][4] == 2) m3+=n - 4 + 1;
        t_b[1][4] = a[4];
        fr(i, 2, n) {
            t_b[i][4] =  mex(t_b[i][3], t_b[i - 1][4]);
            if(i > 4) {
                if(t_b[i][4] == 0) m1+=n - i + 1;
                if(t_b[i][4] == 1) m2+=n - i + 1;
                if(t_b[i][4] == 2) m3+=n - i + 1;
            }
        }
        cout << m1 << " " << m2 << " " << m3;
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


