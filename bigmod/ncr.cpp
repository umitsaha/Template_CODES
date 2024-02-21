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

ll fc[N],fc_inv[N];

ll ncr(ll n,ll r)
{
    if(r>n)assert(0);
    ll ans=fc[n];
    ans*=fc_inv[r];
    ans%=M;
    ans*=fc_inv[n-r];
    return ans%M;
}
fc[0]=fc_inv[0]=1;
for(ll i=1;i<N;i++)fc[i]=(fc[i-1]*i)%M;
fc_inv[N-1]=bg(fc[N-1],M-2,M);
for(ll i=N-2;i>=1;i--)fc_inv[i]=(fc_inv[i+1]*(i+1))%M;
      
