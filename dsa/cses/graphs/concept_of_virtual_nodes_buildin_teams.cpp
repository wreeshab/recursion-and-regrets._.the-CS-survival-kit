// 2 sat with dsu

void solve() {
    ll n, m;
    cin >> n >> m;

    DSU dsu(2 * n);  // We'll use indices 1 to 2n

    vector<pll> edges;
    REP(i, m) {
        ll a, b;
        cin >> a >> b;
        edges.pb({a, b});
    }

    for (auto [a, b] : edges) {
        // since only 2 groups are present.
        // a and b's alter ego will be in one group
        // b and a's alter ego will be in one group.
        dsu.unionBySize(a, b + n);
        dsu.unionBySize(a + n, b);


        if (dsu.getParent(a) == dsu.getParent(a + n)) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }


    // Assign groups based on DSU parent relationships.
    // If node i's parent is "smaller" than its alter ego's parent, assign group 1, else group 2.
    for (ll i = 1; i <= n; ++i) {
        if (dsu.getParent(i) < dsu.getParent(i + n))
            cout << 1 << " ";
        else
            cout << 2 << " ";
    }
    cout << "\n";
}