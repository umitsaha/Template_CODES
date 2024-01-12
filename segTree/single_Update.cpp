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
        T ans;
        ans=a;
        if(b.ff<a.ff)ans=b;
        if(a.ff==b.ff){
            ans.ss+=b.ss;
        }
        return ans;
    }
    
    void upd(ll l,ll r,ll inx,ll i,ll v)
    {
        if(l==r){
            tr[inx]={v,1};
            return ;
        }
        if(i<=md)upd(l,md,lf,i,v);
        else upd(md+1,r,rf,i,v);
        tr[inx]=op(tr[lf],tr[rf]);
    }
    
    
    T qry(ll l,ll r,ll inx,ll L,ll R)
    {
        if(l>R || r<L|| l>r)return {1e15,0};
        if(l>=L && r<=R)return tr[inx];
        return op(qry(l,md,lf,L,R),qry(md+1,r,rf,L,R));
    }
    
    
    void upd(ll i,ll v)
    {
        upd(1,n,1,i,v);
    }
    
    T qry(ll l,ll r)
    {
       return qry(1,n,1,l,r); 
    }
    
    
};
