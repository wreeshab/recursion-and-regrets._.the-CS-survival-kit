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

ll n, l, k;
void solve()
{
    cin >> n >> l >> k; // n = number of cities, l = number of flights, k = number of shortest paths needed

    vector<vector<pair<ll, ll>>> graph(n + 1); // adjacency list: adj[u] = vector of {v, cost}

    for (ll i = 0; i < l; ++i)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c); // edge from a to b with cost c
    }

    priority_queue<pll, vector<pll>, greater<>> pq;
    pq.push({0, 1});
    vector<ll> ans;
    vector<ll> count(n + 1, 0);
    // count[0]--;
    while (!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();
        if (u == n)
        {
            ans.push_back(w);
            if (ans.size() == k)
            {
                break;
            }
        }
        // this is important because if a node is visited popped for more than k times , 
        // it is obvious that we're finding more than k shortest paths.
        if (count[u] >= k)
        {
            continue;
        }
        count[u]++;

        for (auto [v, weight] : graph[u])
        {
            pq.push({w + weight, v});
        }
    }
    for (ll i : ans)
        cout << i << ' ';
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
