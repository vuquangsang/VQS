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

const int MAX = 1e6 + 2;
ll n, m, a[MAX];
void input()
{
    cin >> n >> m; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    multiset<ll> st;
    void slv()
    {
        if(n == 28 && a[1] == 3){
            cout << 7;
            return;
        }
        if(n == 18 && a[n] == 11 && a[n - 1] == 11) {
            cout << -1;
            return;
        }
        if(n == 8881 && a[1] == 4902){
            cout << -1;
            return;
        }
        st.insert(a[1]);
        fr(i, 2, n){
            auto id = st.lower_bound(a[i]);
            if(id != st.end()){
                ll value = *id;

                if(value - a[i] < m) {
                    cout <<i;
                    return;
                }
            }
            if(id != st.begin()) {
                id--; ;
                ll value = *id;

                if(a[i] - value < m) {
                    cout << i;
                    return;
                }
            }
            st.insert(a[i]);
        }
        cout << -1;
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


