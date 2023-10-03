struct HASH
{
    vector<ll>hsh;
    ll n;
    HASH(string s){
        n=s.size();
        hsh.resize(n+1,0);
        for(ll i=1;i<=n;i++){
            hsh[i]+=s[i-1]*po[i-1]+hsh[i-1];
            hsh[i]%=M;
        }
    }
    ll qry(ll l,ll r)
    {
        ll ans=(hsh[r]-hsh[l-1])%M;
        if(ans<0)ans+=M;
        ans*=po_inv[l-1];
        return ans%M;
    }
    
};
