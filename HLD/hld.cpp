//cses path qry 2
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0)
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define all(s) s.begin(),s.end()
typedef int ll;
const double pi = acos(-1),ef=1e-9;
const ll N=2e5+5,M=19,H=131;

template<typename T> struct seg
{
#define md (l+r)/2
#define lf inx*2
#define rf inx*2+1
    vector<T>tr;
    ll n;
    seg(){
    }
    seg(ll _n)
    {
        n=_n;
        tr.resize(4*n+4,0);
    }
    void baal(ll _n){
        n=_n;
        tr.clear();
        tr.resize(n*4,0);
    }

    inline T op(T a,T b)
    {
        return max(a,b);
    }

    inline void upd(ll l,ll r,ll inx,ll i,ll v)
    {
        if(l==r)
        {
            tr[inx]=v;
            return ;
        }
        if(i<=md)upd(l,md,lf,i,v);
        else upd(md+1,r,rf,i,v);
        tr[inx]=op(tr[lf],tr[rf]);
    }

    inline T qry(ll l,ll r,ll inx,ll L,ll R)
    {
        if(l>r || l>R || r<L)return -1e8;
        if(l>=L && r<=R)return tr[inx];
        return op(qry(l,md,lf,L,R),qry(md+1,r,rf,L,R));
    }

    inline void upd(ll i,ll v)
    {
        upd(1,n,1,i,v);
    }

    inline T qry(ll x,ll y)
    {
        return qry(1,n,1,x,y);
    }
};
seg<ll>t;

vector<ll>adj[N];
ll sz[N],dep[N],papas[N][M];
ll n,v[N];

int dfs_sz(int cur, int par) {
    sz[cur] = 1;
    for (int chi : adj[cur]) {
        if (chi == par) continue;
        dep[chi] = dep[cur] + 1;
        papas[chi][0] = cur;
        sz[cur] += dfs_sz(chi, cur);
    }
    return sz[cur];
}
void init_lca() {
    for (int d = 1; d < M; d++)
        for (int i = 1; i <=n; i++) papas[i][d] = papas[papas[i][d - 1]][d - 1];
}
ll ct = 1,id[N],tp[N];

void dfs_hld(int cur, int par, int top) {
    id[cur] = ct++;
    tp[cur] = top;
    t.upd(id[cur], v[cur]);
    int h_chi = -1, h_sz = -1;
    for (int chi : adj[cur]) {
        if (chi == par) continue;
        if (sz[chi] > h_sz) {
            h_sz = sz[chi];
            h_chi = chi;
        }
    }
    if (h_chi == -1) return;
    dfs_hld(h_chi, cur, top);
    for (int chi : adj[cur]) {
        if (chi == par || chi == h_chi) continue;
        dfs_hld(chi, cur, chi);
    }
}
int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int d = M - 1; d >= 0; d--){
        if (dep[a] - (1 << d) >= dep[b]){ 
            a = papas[a][d]; 
        }
    }
    if(a==b)return a;
    for (int d = M - 1; d >= 0; d--) {
        if (papas[a][d] != papas[b][d]) {
            a = papas[a][d];
            b = papas[b][d];
        }
    }
    return papas[a][0];
}

// from child to   par
int path(int chi, int par) {
    int ret = -1e8;
    while (chi != par) {
        if (tp[chi] == chi) {
            ret = max(ret, v[chi]);
            chi = papas[chi][0]; 
        }
        else if (dep[tp[chi]] > dep[par]) {
            ret = max(ret, t.qry(id[tp[chi]], id[chi]));
            chi = papas[tp[chi]][0];
        } else {
            ret = max(ret, t.qry(id[par] + 1, id[chi]));
            break;
        }
    }
    return ret;
}
void solve()
{
    ll q;cin>>n>>q;
    t.baal(n+1);
    for(ll i=1;i<=n;i++)cin>>v[i];
    
    for(ll i=1;i<n;i++){
        int x,y;cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs_sz(1,0);
    init_lca();
    dfs_hld(1,1,1);
    
    while(q--){
        ll typ,a,b;cin>>typ>>a>>b;
        if(typ==1){
            v[a]=b;
            t.upd(id[a],b);
        }
        else{
            ll lc=lca(a,b);
            ll ans=v[lc];
            
            ans=max(ans,path(a,lc));
            ans=max(ans,path(b,lc));
            cout<<ans<<" ";
        }
    }
    cout<<"\n";
}

int main()
{
    fast;
    ll t=1,tc=1;
    //cin>>tc;
    while(tc--)
    {
        //     cout<<"Case "<<t++<<": ";
        solve();//cout<<"\n";
        // cout.flush();
    }
    return 0;

}
