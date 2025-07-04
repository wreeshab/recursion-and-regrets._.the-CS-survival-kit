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

ll n, m;

void solve()
{
    cin >> n >> m;
    vector<vector<ll>> edgeList;
    vector<vector<pair<ll, ll>>> graph(n);
    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        edgeList.push_back({x, y, w});
        graph[x].push_back({y, w});
    }

    // perform bellman to find a node affected by cycle.
    vector<bool> inCycle(n, false);
    vector<ll> dist(n, INF);
    vector<ll> parent(n, -1);

    dist[0] = 0;
    ll cycle_node = 0;
    bool found = false;
    for (ll i = 0; i < n; i++)
    {
        for (auto edge : edgeList)
        {
            ll u = edge[0];
            ll v = edge[1];
            ll w = edge[2];

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                // should do this even if i == n-1.
                parent[v] = u;

                if (i == n - 1)
                {
                    inCycle[v] = 1;
                    cycle_node = v;
                    found = true;
                    break;
                }
            }
        }
        if (found)
            break;
    }
    if (found == false)
    {
        cout << "NO" << endl;
        return;
    }
    // run n times from cycle node. this ensures that we're going inside the cycle for sure.
    for (ll i = 0; i < n; i++)
    {
        cycle_node = parent[cycle_node];
    }

    ll curr = cycle_node;
    vector<ll> cyc;
    do
    {
        cyc.push_back(curr);
        curr = parent[curr];
    } while (curr != cycle_node);
    cyc.push_back(curr);
    cout << "YES" << endl;
    reverse(all(cyc));
    for (auto it : parent)
        cerr << it << ' ';
    for (auto it : cyc)
        cout << it + 1 << ' ';
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
