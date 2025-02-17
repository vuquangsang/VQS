#include <bits/stdc++.h>
using namespace std;

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

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};

namespace sub
{

}

ll n, m, k;
void input()
{
    cin >> n >> m >> k;
}
void slv()
{
    if(k < n && m > k){
        cout << "YES" << el;
    }
    else {
        cout << "NO" << el;
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool qs = 1;
    ll ntest = 1;
    if(qs) cin >> ntest;
    fr(i, 1, ntest){
        input();
        slv();
    }
}




