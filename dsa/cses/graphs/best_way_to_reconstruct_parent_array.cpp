// from my experience this is the best way to reconstruct the path using the parent arrya.
// make sure to keep parent[start] = -1;
void solve() {
    ll n, m;
    cin>> n>> m;
    vector<vector<ll >> graph (n +1, vector<ll > ());
    for(int i = 0;i< m;i++){
        ll x, y;
        cin>> x >> y ;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    ll start  =1;
    ll end= n;

    vector<bool> vis(n+1, false);
    queue<ll> q;
    vis[1]  = true;
    q.push(1);
    vll parent(n+1, -1);
    // parent[1] =    1;
    while (!q.empty())
    
    {
        ll u = q.front();
        q.pop();

        for(auto v: graph[u]){
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
                parent[v] = u;
            }
        }
    }

    if(!vis[end]){
        cout<< "IMPOSSIBLE"<< endl;
        return;
    }
    vll result;
    for(int at = end; at != -1 ; at = parent[at]){
        result.push_back(at);
    }
    // result.push_back(start);
    // cout<< parent[ start]<< endl;
    reverse(all(result));

    cout<< result.size() << endl;
    for(int i : result) cout<< i << ' ';
    

}