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

ll q,n,a[MF];
void input()
{
    cin>>q;
}
void slv()
{
    while(q--){
        cin>>n;
        fr(i,1,n){
            cin>>a[i];
        }
        fr(i,2,n-1){
            a[i]=a[i]-a[i-1]*2;
            a[i+1]=a[i+1]-a[i-1];
            a[i-1]=0;
            if(a[i]<0 || a[i+1]<0){
                break;
            }
        }
        bool b=0;
        fr(i,1,n){
            if(a[i]!=0){
                cout<< "NO"<<el;
                b=1;
                break;
            }
        }
        if(!b) cout<< "YES"<<el;
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


