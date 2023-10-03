#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0)
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define all(s) s.begin(),s.end()
typedef long long ll;
const double pi = acos(-1),ef=1e-9;
const ll N=3e5+5,M=1e9+7,H=131;
ll par[N],sz[N],compp;
stack<ll>stk;
ll fnd(ll x)
{
	while(par[x]!=x)x=par[x];
	return x;
}
void merge(ll x,ll y)
{
	x=fnd(x);
	y=fnd(y);
	if(x==y)return ;
	if(sz[x]>sz[y])swap(x,y);
	par[x]=y;
	sz[y]+=sz[x];
	stk.push(x);
	compp--;
}
void rollback(ll siz)
{
	while(stk.size()>siz){
		ll x=stk.top();
		stk.pop();
		sz[par[x]]-=sz[x];
		par[x]=x;
		compp++;
	}
}
ll tr[N*4],ans[N*4];
vector<pair<ll,ll>>qry[N*4];

void update(ll l,ll r,ll inx,ll L,ll R,ll x,ll y)
{
	if(l>=L && r<=R){
		qry[inx].pb({x,y});
		return ;
	}
	if(l>r || l>R || r<L)return ;

	ll md=(l+r)>>1;
	update(l,md,inx*2,L,R,x,y);
	update(md+1,r,inx*2+1,L,R,x,y);
}
void dfs(ll l,ll r,ll inx)
{
	ll siz=stk.size();
	for(auto p:qry[inx])merge(p.ff,p.ss);



	if(l==r){
		if(ans[l])ans[l]=compp;
		rollback(siz);
		return ;
	}

	ll md=(l+r)>>1;
	dfs(l,md,inx*2);
	dfs(md+1,r,inx*2+1);
	rollback(siz);
}
void solve()
{
	ll n,q;
	cin>>n>>q;
	compp=n;
	for(ll i=1;i<=n;i++){
		par[i]=i;
		sz[i]=1;
	}
	ll tm=1;
	map<pair<ll,ll>,ll>mm;
	while(q--){
		char ch;cin>>ch;
		if(ch=='?'){
			ans[tm]=1;
			tm++;
			continue;
		}
		else if(ch=='+'){
			ll x,y;
			cin>>x>>y;
			if(y<x)swap(x,y);
			mm[{x,y}]=tm;
		}
		else{
			ll x,y;
			cin>>x>>y;
			if(y<x)swap(x,y);

			update(1,N,1,mm[{x,y}],tm,x,y);
			mm.erase(mm.find({x,y}));
		}
		tm++;
	}
	for(auto p:mm)update(1,N,1,p.ss,tm,p.ff.ff,p.ff.ss);

	dfs(1,N,1);
	for(ll i=1;i<N;i++)if(ans[i])cout<<ans[i]<<'\n';
}
int main()
{
	fast;
	freopen("connect.in", "r", stdin);
	freopen("connect.out", "w", stdout);
	ll t=1,tc=1;
	//cin>>tc;
	while(tc--){
    //    cout<<"Case "<<t++<<": ";
		solve();
        //cout<<"\n";
	}
}
