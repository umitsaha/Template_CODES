template<typename T> struct seg
{
    
    
    
    vector<T>tr,lz;
    ll n;
    seg(ll _n)
    {
        n=_n;
        tr.resize(4*n+4,{0,1});
        lz.resize(4*n+4,{0,1});
    }
    
    
    T op(T a,T b)
    {
        a.ff|=b.ff;
        a.ss=(a.ss*b.ss)%M;
        return a;
    }
    
    void pus(ll l,ll r,ll inx)
    {
        
        tr[inx]=op(tr[inx],{lz[inx].ff,bg(lz[inx].ss,r-l+1)});
        if(l!=r){
            lz[lf]=op(lz[lf],lz[inx]);
            lz[rf]=op(lz[rf],lz[inx]);
        
        }
        
        lz[inx]={0,1};
    }
    
    
    void upd(ll l,ll r,ll inx,ll L,ll R,T v)
    {
        pus(l,r,inx);
        if(l>=L && r<=R){
            lz[inx]=op(lz[inx],v);
            pus(l,r,inx);
            return ;
        }
        if(l>r || r<L || l>R)return ;
        upd(l,md,lf,L,R,v);
        upd(md+1,r,rf,L,R,v);
        tr[inx]=op(tr[lf],tr[rf]);
    }
    
    
    T qry(ll l,ll r,ll inx,ll L,ll R)
    {
        pus(l,r,inx);
      //  cout<<l<<' '<<r<<" + "<<tr[inx]<<"\n";
        if(l>=L && r<=R)return tr[inx];
        if(l>R || r<L ||l>r)return {0,1};
        T ans=qry(l,md,lf,L,R);
        ans=op(ans,qry(md+1,r,rf,L,R));


        tr[inx]=op(tr[lf],tr[rf]);
        return ans;
    }
    
    
    void upd(ll l,ll r,T v)
    {
        upd(1,n,1,l,r,v);
    }
    
    T qry(ll l,ll r)
    {
       return qry(1,n,1,l,r); 
    }
    
};
