ll mx,frq[N],frq_of_frq[N],a[N];

void add(ll x)
{
	x=a[x];
	if(frq[x]){
		frq_of_frq[frq[x]]--;
	}
	frq[x]++;
	mx=max(mx,frq[x]);
	frq_of_frq[frq[x]]++;
	
}
void del(ll x)
{
	x=a[x];
	frq_of_frq[frq[x]]--;
	if(frq_of_frq[frq[x]]==0 && mx==frq[x])mx--;
	frq[x]--;
	
	if(frq[x])frq_of_frq[frq[x]]++;
}

void solve()
{
	for(ll i=0;i<N;i++){
		
		frq[i]=0;
		frq_of_frq[i]=0;
	}
	mx=0;
	
	ll n,c,q;
	cin>>n>>c>>q;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ll k=355;
	vector<pair<ll,pair<ll,ll>>>v[k];
	
	ll ans[q+1];
	
	for(ll i=1;i<=q;i++){
		ll l,r;
		cin>>l>>r;
		v[l/k].pb({r,{l,i}});
	}
	
	
	
	ll l=1,r=0;
	for(ll i=0;i<k;i++){
		sort(all(v[i]));
		for(auto p:v[i])
		{
			ll left=p.ss.ff;
			ll id=p.ss.ss;
			ll right=p.ff;
			
			while(l>left)add(--l);
            while(r<right)add(++r);
                
            while(l<left)del(l++);
            while(r>right)del(r--);
			if(mx<0)mx=0;
			
			ans[id]=mx;
		}
		
		
	}	
	for(ll i=1;i<=q;i++)cout<<ans[i]<<"\n";
	
}
