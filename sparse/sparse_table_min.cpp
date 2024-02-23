ll a[N],lg[N];

for(ll i=2;i<N;i++)lg[i]=lg[i/2]+1;
template <typename T> struct Sparse_Table
{
    vector<vector<T>>sp;
    ll n,m;
    // cal lg[] out side
    void build_sparse(ll _n)
    {
        n=_n;
        sp.resize(n+1);
        m=lg[n]+1;
        for(ll i=1;i<=n;i++){
            sp[i].resize(m+1);
            sp[i][0]=a[i];
        }
        
        for(ll j=1;j<=m;j++){
            for(ll i=1;i+(1ll<<j)-1<=n;i++){
                
                sp[i][j]=min(sp[i][j-1],sp[i+(1ll<<(j-1))][j-1]);
            }
        }     
    }
    
    ll mnqry(ll l,ll r)
    {
        if(r<l)assert(0);
        ll d=r-l+1;
        d=lg[d];
        return min(sp[l][d],sp[r-(1ll<<d)+1][d]);
    }
};
