#include <bits/stdc++.h>
using namespace std;

#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll long long
#define     fi first
#define     se second
#define     fr(i,a,b) for(int i=a;i<=b;i++)
#define     frd(i,a,b) for(int i=a;i>=b;i--)
const ll MN=1e9+7;
const ll MF=1e6+7;
const ll inf=1e18+7;

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};

ll q,a[MF],b[MF];
void input()
{
    cin>>q;
}
void slv()
{
    ll n,m,k;
    while(q--){
        cin>>n>>m>>k;
        fr(i,1,n) cin>>a[i];
        fr(i,1,m) cin>>b[i];
        ll res=0;
        fr(i,1,n){
            fr(j,1,m){
                if(a[i]+b[j]<=k){
                    res++;
                }
            }
        }
        cout<<res<<el;
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool qs=0;
    ll ntest=1;
    if(qs) cin>>ntest;
    fr(i,1,ntest){
        input();
        slv();
    }
}


