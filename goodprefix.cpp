#include <bits/stdc++.h>
using namespace std;

#define     TASK ""
#define     lg(x) log2(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll long long
#define     fi first
#define     se second
#define     MASK(i) (1ll<<(i))
#define     c_bit(i) __builtin_popcountll(i)
#define     fr(i,a,b) for(int i=a;i<=b;i++)
#define     frd(i,a,b) for(int i=a;i>=b;i--)

const ll MN = 1e9+7;
const ll MF = 1e6+7;
const ll inf = 1e18+7;
const ll N = 1005;
const ll H = 311;
const ll F = 1e5 + 3;

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
ll sum(ll a, ll b) {return (a + b)%MN;}

ll n, a[MF];
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    ll pre[MF], ma[MF];
    ll cal()
    {
        if(n == 1 ){
            if(!a[1]) return 1;
            return 0;
        }
        pre[0] = 0;
        fr(i, 1, n) pre[i] = pre[i - 1] + a[i];
        ma[1] = a[1];
        fr(i, 2, n) ma[i] = max(ma[i - 1], a[i]);
        ll res = 0;
        fr(i, 1, n){
            if(pre[i] - ma[i] == ma[i]) res++;
        }
        return res;
    }
    void slv()
    {
        cout << cal() << el;
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".OUT", "w", stdout);
    }
    bool qs = 1;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    //    sub2::slv();
    }
}









