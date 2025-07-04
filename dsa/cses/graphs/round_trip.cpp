// find a simple cycle present in the grpah.


vector<bool> vis;
ll n, m;
vector<ll> parent;
vector<ll > cycle;
bool dfs(int i , ll par,  vector<vector<ll>> &graph){
    vis[i] = true;
    parent [i] = par;
    
    for(auto neighbour : graph[i]){
        if(neighbour == parent[i]){
            continue;
        }
        if(vis[neighbour]){
            // cycle.clear();
            // cycle.push_back(neighbour);
            // ll current = i;
            // while(current != neighbour){
            //     if(current == -1 ) break;
            //     cycle.push_back(current);
            //     current = parent[current];
            // }
            // cycle.push_back(neighbour);

            cycle.clear();
            for(int curr = i;curr != parent[neighbour]; curr= parent[curr]){
                cycle.pb(curr);
            }
            cycle.push_back(i);
            return true;

        }
        else{
            if(dfs(neighbour, i, graph)) return true;
        }
    }

    return false;
}

void solve()
{
    cin >> n >> m;
    vis.assign(n + 1, false);
    vector<vector<ll>> graph(n + 1, vector<ll>());
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cycle.clear();
    parent.assign(n +1, -1);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if(dfs(i , -1 , graph)){
                cout<< cycle.size() <<endl;;
                for(auto it : cycle){
                    cout<< it << " ";
                }
                return ;
            }
        }
    }
    cout << "IMPOSSIBLE\n";

}