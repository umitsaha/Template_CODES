//sos
ll c[N],sos[N],sup[N];
void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        c[a[i]]++;
    }
    ll sz=(1ll<<M);
    
    for(ll i=0;i<sz;i++)sos[i]=c[i],sup[i]=c[i];
        
    for(ll j=0;j<M;j++){
        
        for(ll i=0;i<sz;i++){
            if(i>>j & 1){
                sos[i]+=sos[i^(1ll<<j)];//submask
            }
            else{
                sup[i]+=sup[i^(1ll<<j)];//supermask
            }
        }
    }    
    

    for(ll i=0;i<n;i++){
        
        ll x=sos[a[i]];
        ll y=sup[a[i]];
        ll flip=a[i]^((1ll<<M)-1);
        
        ll z=sos[flip];
        cout<<x<<' '<<y<<' '<<n-z<< '\n'; 
    }
 //cses bit problem   
}
