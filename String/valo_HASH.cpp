ll bg(ll a,ll b,ll mod)
{
    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
struct HASH
{
    
    vector<ll>hsh,po,po_inv; 
    
    HASH(string &s,const int &mod,const int &HH){
        int n=s.size();
        hsh.resize(n+1,0);
        po.resize(n+1,0);
        po_inv.resize(n+1,0);
        
        
        po[0]=po_inv[0]=1;
        for(ll i=1;i<=n;i++)po[i]=(po[i-1]*HH)%mod;
        po_inv[n-1]=bg(po[n-1],mod-2,mod);
        for(ll i=n-2;i>=1;i--)po_inv[i]=(po_inv[i+1]*HH)%mod;
        
        for(ll i=1;i<=n;i++){
            hsh[i]+=(s[i-1]-'a'+1)*po[i-1]+hsh[i-1];
            hsh[i]%=mod;
        }
    }
    
    inline ll qry(ll l,ll r,const int &M)
    {
        ll ans=(hsh[r]-hsh[l-1])%M;
        if(ans<0)ans+=M;
        ans*=po_inv[l-1];
        return ans%M;
    }
};
 
