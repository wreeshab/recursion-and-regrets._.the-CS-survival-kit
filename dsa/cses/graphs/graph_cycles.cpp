// you have to find the minimum no. of edges to traverse to find a node that has been visited already by some other node.

ll n ;
vll a;
vll res;

void dfs(int node, vector<int> &vis){
    // vis[node] =1;

    int curr= node;
    stack <int> st;
    while(vis[curr] == 0){
        vis[curr] = 1;
        st.push(curr);
        curr = a[curr];
    }

    vector<int> cycle;
    if(vis[curr]  ==1 ){
        while (!st.empty()) {
            int top = st.top(); st.pop();
            cycle.push_back(top);
            if (top == curr) break;
        }
    }
    for(auto  i: cycle){
        res[i] = cycle.size();
        vis[i] = 2;
    }

    while(!st.empty()){
        res[st.top()] = 1 + res[a[st.top()]];
        vis[st.top()] = 2;
        st.pop();
    }
}


void solve() {
    cin>> n;
    a.resize(n+1);
    for(int i = 1;i<=n;i++) cin>> a[i];
    res.resize(n+1);

    vector<int> vis(n+1, 0);

    for(int i = 1;i<=n;i++){
        if(vis[i] == 0){
            dfs(i , vis);
        }
    }

    for(int i = 1;i<=n;i++) cout<< res[i] << ' ';
}

int main() {
    FAST_IO;
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
