d_dfs(1);
dfs(1,0,0);

vector<ll>g[N];
ll cnt[N],dep,frq;

ll sz[N],big[N],lvl[N];
void d_dfs(ll x,ll papa=-1)
{
    sz[x]=1;
    ll mx=-1;
    big[x]=-1;
    for(auto p:g[x]){
        if(p==papa)continue;
        lvl[p]=lvl[x]+1;
        d_dfs(p,x);
        sz[x]+=sz[p];
        
        if(sz[p]>mx){
            mx=sz[p];
            big[x]=p;
        }
    }
}

ll n,ans[N],now_bigg[N];

inline void add(ll x,ll papa,ll val)
{
    //adding section
    // if(val==1){
    //     cnt[lvl[x]]+=val;
    //     if(cnt[lvl[x]]>frq){
    //         frq=cnt[lvl[x]];
    //         dep=lvl[x];
    //     }
    //     else if(cnt[lvl[x]]==frq){
    //         dep=min(dep,lvl[x]);
    //     }
    // }
    // else {
    //     cnt[lvl[x]]+=val;
    // }
    
    
    for(auto p:g[x]){
        if(p==papa || now_bigg[p])continue;
        add(p,x,val);
    }
}


void dfs(ll x,ll papa,ll keep)
{
    
    for(auto p:g[x]){
        if(p==papa || p==big[x])continue;
        dfs(p,x,0);
    }
    if(big[x]!=-1){
        now_bigg[big[x]]=1;
        dfs(big[x],x,1);
    }
    add(x,papa,1);
    
    
   /*
   qry section
   */
    
    
    if(big[x]!=-1){
        now_bigg[big[x]]=0;
    }
    if(keep==0){
        // keeping or deleting all 
        add(x,papa,-1);
        //dep=frq=-1;
    }
}
