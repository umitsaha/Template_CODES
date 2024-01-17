template<typename T> struct seg
{
    
#define md (l+r)/2
#define lf inx*2
#define rf inx*2+1
    
    
    vector<T>tr;
    vector<ll>lz;
    ll n;
    seg(ll _n)
    {
        n=_n;
        tr.resize(4*n+4);
        lz.resize(4*n+4);
    }
    
    
    void pus(ll l,ll r,ll inx)
    {
        if(lz[inx]){
            tr[inx].ff+=lz[inx];
            if(l!=r){
                lz[lf]+=lz[inx];
                lz[rf]+=lz[inx];
            }
        }
        lz[inx]=0;
    }
    
    T op(T a,T b)
    {
        T ans;
        if(a.ff<b.ff)ans=a;
        else ans=b;
        return ans;
    }
    
    
    void build(ll l,ll r,ll inx,vector<ll>&a)
    {
        lz[inx]=0;
        if(l==r){
            tr[inx]={a[l],l};
            return ;
        }
        build(l,md,lf,a);
        build(md+1,r,rf,a);
        tr[inx]=op(tr[lf],tr[rf]);
    }
    
    void upd(ll l,ll r,ll inx,ll L,ll R,ll v)
    {
        pus(l,r,inx);
        if(l>=L && r<=R){
            lz[inx]+=v;
            pus(l,r,inx);
            return ;
        }
        if(l>r || r<L || l>R)return ;
        upd(l,md,lf,L,R,v);
        upd(md+1,r,rf,L,R,v);
        tr[inx]=op(tr[lf],tr[rf]);
    }
    
    
    T qry(ll l,ll r,ll inx)
    {
        pus(l,r,inx);
        if(l==r)return tr[inx];
        
        pus(l,md,lf);
        pus(md+1,r,rf);
        T ans;
        if(tr[lf].ff<tr[rf].ff)ans=qry(l,md,lf);
        else ans=qry(md+1,r,rf);
        
        tr[inx]=op(tr[lf],tr[rf]);
        return ans;
    }
    
    
    void upd(ll l,ll r,ll v)
    {
        upd(1,n,1,l,r,v);
    }
    
    T qry()
    {
       return qry(1,n,1); 
    }
    
    void prin(ll l,ll r,ll inx)
    {
        if(l==r){
            cout<<l<<' '<<tr[inx].ff<<' '<<tr[inx].ss<<"\n";
            return ;
        }
        prin(l,md,lf);
        prin(md+1,r,rf);
    }
    
};
