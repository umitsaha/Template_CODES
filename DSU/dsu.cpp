struct dsu
{
    vector<ll>par,mn,mx,num;
    dsu(ll n=0){
        par.resize(n+1);
        mn.resize(n+1);
        mx.resize(n+1);
        num.resize(n+1);
        for(ll i=1;i<=n;i++){
            mn[i]=mx[i]=par[i]=i;
            num[i]=1;
        }
    }
    
    ll fnd(ll x)
    {
        return (par[x]==x?x:par[x]=fnd(par[x]));
    }
    bool mrg(ll x,ll y)
    {
        x=fnd(x);
        y=fnd(y);
        if(x==y)return 0;
        num[x]+=num[y];
        mn[x]=min(mn[x],mn[y]);
        mx[x]=max(mx[x],mx[y]);
        par[y]=x;
        return 1;
    }
    
    bool same(ll x,ll y)
    {
        return fnd(x)==fnd(y);
    }
};
