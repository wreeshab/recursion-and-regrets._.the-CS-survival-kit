
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        int n = people.size();
        //[height , no. of people greater in height in the front.]
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b)
             {
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            return a[0] > b[0]; });

        vector<vector<int>> result;
        // so here the promise is that all the people before person i that has been processed is taller than him, this means we simply push him after ki members from the front.
        // also all the elements pushed before some elments are small than the ones next to it, so does not really affect the condition, hence the increasing order of sorting.
        for (int i = 0; i < n; i++)
        {

            result.insert(result.begin() + people[i][1], people[i]);
        }

        return result;
    }
};

/*
    segment tree + sorting in the reverse order.
    1. Process taller people first
If we place shorter people first, taller ones might invalidate their k values.

Taller people don’t care who is behind them — they only care about their position in the final queue.

So we place tallest people first, then slightly shorter ones, and so on.

This ensures:

When inserting a person, all people already placed are taller or equal.

2. Among people of same height, place smaller k first
If two people have the same height, the one with smaller k should appear first.

Because the one with a larger k expects more people in front, including the one with smaller k.

*/

class SegmentTree
{
public:
    vector<int> tree;
    int n;

    SegmentTree(int size)
    {
        n = size;
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void build(int node, int l, int r)
    {
        if (l == r)
        {
            tree[node] = 1; // 1 means empty
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    // Find k-th empty slot (0-based)
    int query(int node, int l, int r, int k)
    {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (tree[2 * node] > k)
        {
            return query(2 * node, l, mid, k);
        }
        else
        {
            return query(2 * node + 1, mid + 1, r, k - tree[2 * node]);
        }
    }

    void update(int node, int l, int r, int idx)
    {
        if (l == r)
        {
            tree[node] = 0;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node, l, mid, idx);
        else
            update(2 * node + 1, mid + 1, r, idx);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
};

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        int n = people.size();

        sort(people.begin(), people.end(), [](auto &a, auto &b)
             {
            if (a[0] == b[0])
                return a[1] > b[1]; // increasing height, decreasing k
            return a[0] < b[0]; });

        SegmentTree st(n);
        vector<vector<int>> res(n, {0, 0});
        // so here the promise is that, when the current person is being placed,
        // all previously placed people are shorter or equal in height (since we sorted by increasing height and decreasing k).
        // Thus, placing the current person at the k-th empty slot ensures there will be exactly k people
        // already positioned ahead who are taller or equal to this person, satisfying the condition.

        // If we had instead sorted by increasing k (rather than decreasing),
        // the earlier placed people might take up positions needed for those with larger k,
        // violating their constraints.
        // Hence, we sort by increasing height and decreasing k so that for any given height,
        // we first place the person with the highest tolerance (i.e., largest k),
        // allowing the more constrained ones (smaller k) to be placed later at precise positions.
        for (int i = 0; i < n; i++)
        {
            int pos = st.query(1, 0, n - 1, people[i][1]); // use 0-based k
            res[pos] = people[i];
            st.update(1, 0, n - 1, pos);

            // Print current state of res
            cout << "After placing person " << i << ": ";
            for (auto &p : res)
            {
                cout << "[" << p[0] << "," << p[1] << "] ";
            }
            cout << '\n';
        }

        return res;
    }
};