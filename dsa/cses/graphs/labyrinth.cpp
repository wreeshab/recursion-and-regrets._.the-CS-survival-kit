// do a bfs from point a to point b and find the shortest route by maintaining a parent array.


int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
ll n, m;
vector<vector<char>> graph;
bool isValid(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < m;
}

void solve()
{
    cin >> n >> m;
    graph.resize(n, vector<char>(m));
    pll start, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'A')
                start = {i, j};
            if (graph[i][j] == 'B')
                end = {i, j};
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pll>> parent(n, vector<pll>(m, {-1, -1}));

    queue<pll> q;
    vis[start.first][start.second] = true;
    q.push(start);

    while (!q.empty())
    {
        auto [u, v] = q.front();
        q.pop();

        REP(k, 4)
        {
            ll nr = u + dr[k];
            ll nc = v + dc[k];

            if (isValid(nr, nc) && graph[nr][nc] != '#' && !vis[nr][nc])
            {
                vis[nr][nc] = true;
                q.push({nr, nc});
                parent[nr][nc] = {u, v};
            }
        }
    }

    if (vis[end.first][end.second] == false)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    string answer;

    pll curr = end;
    while (curr != start)
    {
        pll parentLocal = parent[curr.first][curr.second];
        if (parentLocal.first == curr.first - 1)
            answer += 'D';
        else if (parentLocal.first == curr.first + 1)
            answer += 'U';
        else if (parentLocal.second == curr.second - 1)
            answer += 'R';
        else if (parentLocal.second == curr.second + 1)
            answer += 'L';
        curr = parentLocal;
    }
    reverse(answer.begin(), answer.end());
    cout << answer.size() << endl << answer << endl;
}
