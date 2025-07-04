// this is essentially opposite of bellman ford algorithm.

// #include <bits/stdc++.h>
// using namespace std;

// #define FAST_IO              \
//     ios::sync_with_stdio(0); \
//     cin.tie(0);              \
//     cout.tie(0);

// using ll = long long;
// using ld = long double;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;
// using vi = vector<int>;
// using vll = vector<ll>;
// using vpii = vector<pii>;

// #define pb push_back
// #define mp make_pair
// #define fi first
// #define se second
// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define sz(x) (int)((x).size())

// #define FOR(i, a, b) for (int i = (a); i < (b); ++i)
// #define FORD(i, a, b) for (int i = (a); i >= (b); --i)
// #define REP(i, n) for (int i = 0; i < (n); ++i)
// #define REPD(i, n) for (int i = (n) - 1; i >= 0; --i)

// const ll MOD = 1e9 + 7;
// const ll INF = 1e18;

// ll mod_exp(ll base, ll exp, ll mod)
// {
//     ll res = 1;
//     while (exp > 0)
//     {
//         if (exp % 2 == 1)
//             res = (res * base) % mod;
//         base = (base * base) % mod;
//         exp /= 2;
//     }
//     return res;
// }

// template <typename T>
// void debug(T x)
// {
//     cerr << x << "\n";
// }

// template <typename T1, typename T2>
// void debug(pair<T1, T2> p)
// {
//     cerr << "(" << p.first << ", " << p.second << ")" << "\n";
// }
// ll n, m, q;

// bool dfs(int i, vector<vector<pair<ll, ll>>> &graph, vector<bool> &vis, vector<bool> &inCycle)
// {
//     vis[i] = true;
//     // cerr<< i << ' ';
//     if (i == n)
//         {
//             return true;
//         }
//     for (auto [v, w] : graph[i])
//     {
//         if (!vis[v])
//         {
//             if(dfs(v, graph, vis, inCycle)) return true;
//         }
//     }
//     // cout<< "hello" << i << ' ';
//     return false;
// }

// void solve()
// {
//     cin >> n >> m;
//     vector<vector<pair<ll, ll>>> graph(n + 1, vector<pair<ll, ll>>());
//     vector<vector<ll>> edgeList;
//     for (ll i = 0; i < m; i++)
//     {
//         ll x, y, w;
//         cin >> x >> y >> w;
//         graph[x].push_back({y, w});
//         edgeList.push_back({x, y, w});
//     }

//     vector<ll> dist(n + 1, -INF);

//     dist[1] = 0;
//     for (ll i = 1; i < n; i++)
//     {
//         for (auto &edge : edgeList)
//         {
//             ll u = edge[0];
//             ll v = edge[1];
//             ll w = edge[2];
//             // cout<< u << ' ' << v<<" " << w <<   endl;
//             // cout<< dist[u] << ' '<< dist[v] << ' ' << endl;
//             // return;
//             if (dist[v] < dist[u] + w && dist[u] != -INF)
//             {
//                 // cerr<< "yoo nigga" << endl;
//                 dist[v] = dist[u] + w;
//             }
//         }
//     }
//     vector<bool> inCycle(n + 1, false);
//     for (auto &edge : edgeList)
//     {
//         ll u = edge[0];
//         ll v = edge[1];
//         ll w = edge[2];
//         // cout<< u << ' ' << v<<" " << w <<   endl;
//         // cout<< dist[u] << ' '<< dist[v] << ' ' << endl;
//         // return;
//         if (dist[v] < dist[u] + w && dist[u] != -INF)
//         {
//             inCycle[u] = 1;
//             // inCycle[v] = 1;
//             // break;
//         }
//     }
//     vector<bool> vis(n + 1, false);
//     for (auto it : inCycle)
//         // cerr << it << " ";

//     for (int c = 1; c <= n; c++)
//     {
//         if (inCycle[c])
//         {
//             if (dfs(c, graph, vis, inCycle))
//             {
//                 cout << -1 << endl;
//                 return;
//             }
//         }
//     }

//     // for (auto it : dist)
//     //     cout << it << ' ';
//     cout << dist[n] << endl;
// }

// int main()
// {
//     FAST_IO;
//     int t = 1;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define FAST_IO              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)((x).size())

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPD(i, n) for (int i = (n) - 1; i >= 0; --i)
#define arrprint(a)       \
    for (auto &x : a)     \
        cout << x << " "; \
    cout << endl;
#define errarrprint(a)    \
    for (auto &x : a)     \
        cerr << x << " "; \
    cerr << endl;
#define arrinput(a)                      \
    for (int i = 0; i < (a.size()); ++i) \
        cin >> a[i];

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

ll mod_exp(ll base, ll exp, ll mod)
{
    ll res = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

template <typename T>
void debug(T x)
{
    cerr << x << "\n";
}

template <typename T1, typename T2>
void debug(pair<T1, T2> p)
{
    cerr << "(" << p.first << ", " << p.second << ")" << "\n";
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;
    vector<vector<pair<ll, ll>>> rev(n);

    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges.pb({u, v, w});
        rev[v].pb({u, w});
    }

    vector<ll> inCycle(n, 0);
    vector<ll> dist(n, -INF);
    dist[0] = 0;
    for (ll i = 0; i < n; i++)
    {
        for (auto edge : edges)
        {
            ll u = edge[0];
            ll v = edge[1];
            ll w = edge[2];

            if (dist[u] == -INF)
                continue;

            if (dist[u] + w > dist[v])
            {
                dist[v] = dist[u] + w;

                if (i == n - 1)
                {
                    inCycle[v] = 1;
                }
            }
        }
    }

    queue<ll> q;
    vector<ll> vis(n, 0);
    q.push(n - 1);
    vis[n - 1] = 1;

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();

        if (inCycle[node] == 1)
        {
            cout << -1;
            return;
        }

        for (auto nei : rev[node])
        {
            if (vis[nei.first])
                continue;

            q.push(nei.first);
            vis[nei.first] = 1;
        }
    }
    errarrprint(dist);
    cout << dist.back() << endl;
    return;
}

int main()
{
    FAST_IO;
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
