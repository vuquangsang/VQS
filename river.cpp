#include <bits/stdc++.h>
using namespace std;

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

const ll MN=1e9+7;
const ll MF=1e6+7;
const ll inf=1e18+7;
const ll N = 1005;
const ll H = 311;
const ll F = 1e5 + 3;

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
ll sum(ll a, ll b) {return (a + b)%MN;}


ll n, M, j;
void input()
{
    cin >> n >> M >> j;
}
namespace sub1
{
    ll a[MF];
    bool check(ll x)
    {
        ll res = 0, vt = 1;

    }
    void slv()
    {
        fr(i, 1, n) {
            ll value = (i - 1)*(i - 1);
            value%=M;
            a[i] = 1 + value;
        }
        a[0] = 0;
        fr(i, 1, n) a[i] = a[i - 1] + a[i];
        fr(i, 1, n) cout << a[i] << " " ; cout << el;
        ll l = 1, r = a[n], m;
        while(r - l > 1){
            m = (r + l) >> 1;
            if(check(m)) r = m;
            else l = m;
        }
        if(check(l)) cout << l;
        else cout << r;
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool qs = 0;
    ll ntest = 1;
    if(qs) cin >> ntest;
    fr(i, 1, ntest){
        input();
        sub1::slv();
    }
}







