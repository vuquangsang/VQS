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

ll q;
char c;
void input()
{

}
void slv()
{
    cin>>q;
    while(q--){
        ll n,m,x,r;
        set<ll> st;
        cin>>n>>m>>x;
        fr(i,1,m){
            cin>>r>>c;
            if(c=='0'){
                ll d=st.size();
                ll dem=0;
                for(auto it:st){
                    if(it+r<=n){
                        st.insert(it+r);
                    }
                    else{
                        st.insert((it+r)%n);
                    }
                    dem++;
                    if(dem==d){
                        break;
                    }
                }
                if(x+r<=n){
                    st.insert(x+r);
                }
                else{
                    st.insert((x+r)%n);
                }
            }
            else if(c=='1'){
                ll d=st.size();
                ll dem=0;
                for(auto it:st){
                    if(it-r<1){
                        st.insert(n-abs(it-r));
                    }
                    else{
                        st.insert(it-r);
                    }
                    dem++;
                    if(dem==d){
                        break;
                    }
                }
                if(x-r<1){
                    st.insert(n-abs(x-r));
                }
                else{
                    st.insert(x-r);
                }
            }
            else{
                ll d=st.size();
                ll dem=0;
                for(auto it:st){
                    if(it+r<=n){
                        st.insert(it+r);
                    }
                    else{
                        st.insert((it+r)%n);
                    }
                    dem++;
                    if(dem==d){
                        break;
                    }
                }
                if(x+r<=n){
                    st.insert(x+r);
                }
                else{
                    st.insert((x+r)%n);
                }
                d=st.size();
                dem=0;
                for(auto it:st){
                    if(it-r<1){
                        st.insert(n-abs(it-r));
                    }
                    else{
                        st.insert(it-r);
                    }
                    dem++;
                    if(dem==d){
                        break;
                    }
                }
                if(x-r<1){
                    st.insert(n-abs(x-r));
                }
                else{
                    st.insert(x-r);
                }
            }
        }
        cout<<st.size()<<el;
        for(auto x:st) cout<<x<<" ";
        cout<<el;
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

