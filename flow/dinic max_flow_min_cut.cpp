struct Dinic
{
    struct edge
    {
        int to, rev;
        long long flow, w;
    	int id;
    };
    int n, s, t,mxid;
    vector<int> d,done,flow_through;
    vector<vector<edge>> g;
    Dinic() {}
    Dinic(int _n)
    {
        n = _n + 2;
       	mxid = 0;
        g.resize(n);
    }
    void add_edge(int u, int v, long long w,int id=-1)
    {
        edge a = {v, (int)g[v].size(), 0, w, id};
        edge b = {u, (int)g[u].size(), 0, w, -2};//for bidirectional edges cap(b) = w
        g[u].emplace_back(a);
        g[v].emplace_back(b);
        mxid=max(mxid,id);
    }
    bool bfs()
    {
        d.assign(n, -1);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto &e : g[u])
            {
                int v = e.to;
                if (d[v] == -1 && e.flow < e.w)
                    d[v] = d[u] + 1, q.push(v);
            }
        }
        return d[t] != -1;
    }
    long long dfs(int u, long long flow)
    {
        if (u == t)
            return flow;
        for (int &i = done[u]; i < (int)g[u].size(); i++)
        {
            edge &e = g[u][i];
            if (e.w <= e.flow)
                continue;
            int v = e.to;
            if (d[v] == d[u] + 1)
            {
                long long nw = dfs(v, min(flow, e.w - e.flow));
                if (nw > 0)
                {
                    e.flow += nw;
                    g[v][e.rev].flow -= nw;
                    return nw;
                }
            }
        }
        return 0;
    }
    long long max_flow(int _s, int _t)
    {
        s = _s;
        t = _t;
        long long flow = 0;
        while (bfs())
        {
            done.assign(n, 0);
            while (long long nw = dfs(s, inf))
                flow += nw;
        }
        flow_through.resize(mxid+2,0);
        for(ll i=1;i<n;i++){
        	for(auto p:g[i]){
        		if(p.id>=0){
        			flow_through[p.id]=p.flow;
        		}
        	}
        }
        
        return flow;
    }
    vector<int>vis;
    void d_dfs(int x)
    {
    	vis[x]=1;
    	for(auto p:g[x]){
    		if(vis[p.to])continue;
    		if(p.flow<p.w)d_dfs(p.to);
    	}
    }
    vector<pair<int,int>> cut_egs(int strt){
    	vis.resize(n,0);
    	d_dfs(strt);

    	vector<pair<int,int>>ans;
    	for(int i=0;i<n;i++){
    		for(auto p:g[i]){
    			if(vis[i] && !vis[p.to] && p.w>0 && p.flow==p.w){
    				ans.pb({i,p.to});
    			}
    		}
    	}
    	return ans;
    }

};

