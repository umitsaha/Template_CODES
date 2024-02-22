
template<typename T> struct seg
{
    //max element with index
    
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
    inline void upd(ll l,ll r,ll inx,ll i,ll v)
    {
        if(l==r){
            tr[inx]={v,i};
            return ;
        }
        if(i<=md)upd(l,md,lf,i,v);
        else upd(md+1,r,rf,i,v);
        tr[inx]=op(tr[lf],tr[rf]);
    }
    
    inline T qry(ll l,ll r,ll inx,ll x,ll y)
    {
        if(l>=x && r<=y)return tr[inx];
        if(l>y || r<x )return {0,0};
        T ans=qry(l,md,lf,x,y);
        ans=op(ans,qry(md+1,r,rf,x,y));
        return ans;
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
