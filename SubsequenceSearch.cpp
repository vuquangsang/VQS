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

namespace sub
{

}

ll q, n, m, k, a[MF], b[MF] , pre[MF];
map<ll, ll> mp , ma;
void input()
{
    cin >> q;
}
void slv()
{
    while(q--){
        cin >> n >> m >> k;
        fr(i, 1, n)  cin >> a[i];
        fr(i, 1, m) {
            cin >> b[i] ;
            mp[b[i]]++;
        }
        ll res = 0 , d = 0 , last = 0;
        fr(i, 1, m){
            ma[a[i]]++;
            if(mp[a[i]] && ma[a[i]] <= mp[a[i]]){
                d++;
            }
            else{
                last = -1;
            }
        }
        if(last!=-1){

        }
        fr(i, m + 1, n){
            ma[a[i]]++;
            ma[a[i - m]]--;
            if(mp[a[i - m]]){
                d--;
            }
            if(mp[a[i]] && ma[a[i]] <= mp[a[i]] && d >= k){
                res++;
            }
        }
        cout << res << el;
        mp.clear();
        ma.clear();
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


