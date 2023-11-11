#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0)
#define file freopen("cases.in", "r", stdin);//freopen("output.txt", "w", stdout)
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define all(s) s.begin(),s.end()
typedef long long ll;
const double pi = acos(-1);
const ll N=1000+2,M=1e9+7,H=31;
ll inx;
vector<ll>g[N],rg[N],comp[N],tmp;

ll vis[N],comp_NO[N];

void dfs(ll x)
{
    vis[x]=1;
    for(auto p:g[x]){
        if(!vis[p]){
            dfs(p);
        }
    }
    tmp.pb(x);
}

void ulta(ll x)
{
    vis[x]=2;
    for(auto p:rg[x]){
        if(vis[p]==1){
            ulta(p);
        }
    }
    comp_NO[x]=inx;
    comp[inx].pb(x);
}

//new graph
vector<ll>ggr[N];

ll mm[N];
ll rec(ll x)
{
    ll &ans=mm[x];
    if(ans!=-1)return ans;
    ans=1;
    for(auto p:ggr[x]){
        ans=max(ans,1+rec(p));
    }
    return ans;
}

void solve()
{
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll k;
        cin>>k;
        while(k--){
            ll x,y;
            cin>>x>>y;
            g[x].pb(y);
            rg[y].pb(x);
        }
    }
    
    inx=1;
    for(ll i=1;i<=n;i++){
        if(vis[i])continue;
        tmp.clear();
        dfs(i);
        reverse(all(tmp));
        for(auto p:tmp){
            //cout<<p<<' ';
            if(vis[p]==2)continue;
            ulta(p);
            inx++;
        }
    }
    for(ll i=0;i<1000;i++){
        for(auto p:g[i]){
            
            ll x=comp_NO[i];
            ll y=comp_NO[p];
            if(x==y)continue;
            ggr[x].pb(y);
        }
    }
    
    /*
    memset(mm,-1,sizeof mm);
    cout<<rec(0)<<" ";
    if(rec(0)==inx-1){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
    */
    
    
    
    tmp.clear();
    for(ll i=0;i<=1000;i++){
        comp_NO[i]=0;
        vis[i]=0;
        g[i].clear();
        rg[i].clear();
        comp[i].clear();
        ggr[i].clear();
    }
}
int main()
{
    
    fast;
    int t,tc=1;
    cin>>t;
    while(t--){
        
        cout<<"Case "<<tc++<<": ";
        solve();
    }
    
    
}
