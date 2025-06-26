// good after logic.
// we need to find the new roads to be deployed as well to make it a single connected component.
// find all the master ultimate parents of all the comp in dsu then,
// randomly connect the parent 1 to all other parents .
void solve() {
    ll n , m ;
    cin>> n>> m;
    DSU ds(n);
    for(ll i = 0;i < m;i++){
        ll x, y;
        cin>> x >> y;
        ds.unionBySize(x, y);
    }
    ll count = 0;
    vector<ll> result;

    for(int i =1;i<= n;i++){
        if(i == ds.getParent(i)){
            count++;
            result.push_back(i);
        }
    }
    cout<< count-1<< endl;
    for(ll i = 1;i<result.size();i++){
        cout<< result[0] << ' ' << result[i] << endl;
    }
    return;
    
}


