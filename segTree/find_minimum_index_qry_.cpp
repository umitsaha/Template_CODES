template<typename T> struct seg
{
    
#define md (l+r)/2
#define lf inx*2
#define rf inx*2+1
    
    
    vector<T>tr;
    ll n;
    seg(ll _n)
    {
        n=_n;
        tr.resize(4*n+4);
    }
    
    T op(T a,T b)
    {
        return max(a,b);
    }
    
    void upd(ll l,ll r,ll inx,ll i,ll v)
    {
        if(l==r){
            tr[inx]=v;
            return ;
        }
        if(i<=md)upd(l,md,lf,i,v);
        else upd(md+1,r,rf,i,v);
        tr[inx]=op(tr[lf],tr[rf]);
    }
    
    T qry_mx(ll l,ll r,ll inx,ll L,ll R)
    {
        if(l>r || l>R || r<L)return 0;
        if(l>=L && r<=R)return tr[inx];
        return op(qry_mx(l,md,lf,L,R),qry_mx(md+1,r,rf,L,R));
    }
    
    
    T qry(ll l,ll r,ll inx,ll x,ll y)
    {
        if(l>=y && l==r && tr[inx]>=x)return l;
        if(r<y || tr[inx]<x)return N;
        if(l>=y){
            if(tr[lf]>=x)return qry(l,md,lf,x,y);
            if(tr[rf]>=x)return qry(md+1,r,rf,x,y);
        }
        return min(qry(l,md,lf,x,y),qry(md+1,r,rf,x,y));
    }
    
    
    void upd(ll i,ll v)
    {
        upd(0,n-1,1,i,v);
    }
    
    T qry(ll x,ll y)
    {
        if(qry_mx(0,n-1,1,y,n-1)<x)return -1;
        return qry(0,n-1,1,x,y); 
    }
    
    
    void see(ll l,ll r,ll inx)
    {
        cout<<l<<' '<<r<<" : "<<tr[inx]<<'\n';
        if(l==r){
            return ;
        }
        see(l,md,lf);
        see(md+1,r,rf);
    }
    
};
