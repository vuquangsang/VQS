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

const ll MN=1e9+7;
const ll MF=1e5+7;
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


int n, m, a[MF], b[MF];
bool vis[MF];
void input()
{
    cin >> n >> m;
    fr(i, 1, n ) cin >> a[i];
    fr(i, 1, m) cin >> b[i];
}
namespace sub1
{

    void slv()
    {
        sort(alla(a, n));
        sort(alla(b, m));
        ll res = 0;
        fr(i, 1, n){
            int index1 = lower_bound(alla(b, m), a[i]) - b - 1;
            int index2 = upper_bound(alla(b, m), a[i]) - b;
            if(index2 == m + 1 || index1 == m + 1) continue ;
            if(!index1) continue ;
            bool ok = 0, ok1 = 0;
            int vt = 0;
            frd(j, index1, 1){
                if(!vis[j]){
                    ok = 1;
                    vis[j] = 1;
                    vt = j;
                    break;
                }
            }
            if(!ok) continue ;
            fr(j, index2, m){
                if(!vis[j]){
                    ok1 = 1;
                    vis[j] = 1;
                    break;
                }
            }
            if(!ok1) vis[vt] = 0;
            if(ok && ok1) res++;
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
