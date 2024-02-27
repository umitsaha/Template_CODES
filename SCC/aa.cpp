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
const ll N=1e5+5,M=1e9+7,H=31;
ll inx;
vector<ll>g[N],rg[N],comp[N],tmp;
ll coin[N],F_c[N];
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
    F_c[inx]+=coin[x];
    comp_NO[x]=inx;
    comp[inx].pb(x);
}

//new graph
set<ll>st[N];
vector<ll>ggr[N];

ll mm[N];
ll rec(ll x)
{
    ll &ans=mm[x];
    if(ans!=-1)return ans;
    ans=F_c[x];
    for(auto p:ggr[x]){
        ans=max(ans,F_c[x]+rec(p));
    }
    return ans;
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>coin[i];
    for(ll i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);            
        rg[y].pb(x);
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
    //for(ll i=1;i<inx;i++)cout<<F_c[i]<<'\n';
    
    
    ll in[inx]={0};
    for(ll i=1;i<=n;i++){
        for(auto p:g[i]){
            
            ll x=comp_NO[i];
            ll y=comp_NO[p];
            if(x==y || st[x].count(y))continue;
            ggr[x].pb(y);
            st[x].insert(y);
            in[y]++;
        }
    }
    ll ans=0;
    memset(mm,-1,sizeof mm);
    for(ll i=1;i<inx;i++){
        if(!in[i]){
            ans=max(ans,rec(i));
        }              
    }
    
    cout<<ans<<"\n";
}
int main()
{
    
    fast;
    int t,tc=1;
    while(tc--){    
        solve();
    }
    
    
}