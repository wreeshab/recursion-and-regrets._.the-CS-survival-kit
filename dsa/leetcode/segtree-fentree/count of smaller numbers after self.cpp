// segtree approach 

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        int n  = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin() , sorted.end());
        unordered_map<int ,int> rank;

        int idx = 0;
        // coordinate compression , rank basically tells us which elements i smaller than which. whilst eliminating teh duplicates.
        for(int num : sorted){
            if(!rank.count(num)){

                rank[num] = idx++;
            }
        }

        SGT seg(idx);
        vector<int> result(n);

        for(int i = n-1;i >= 0;i--){
            int rnk = rank[nums[i]];
            result[i] = seg.query(0 , rnk-1);
            seg.update(rnk);
        }
        return result;
    }
};


// same question but with 1 based fenwick tree approach.

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        vector<int> sorted = nums;
        sort(sorted.begin() , sorted.end());

        unordered_map<int ,int> rank;
        int idx = 1;
        for(int num : sorted){
            if(!st.count( num)){
                rank[num] = idx++;
                st.insert(num);
            }
        }

        
        FenwickTree ft(idx);
        vector<int> res(n, 0);
        for(int i = n-1;i>=0;i--){
            int rnk  = rank[nums[i]];
            int temp = ft.rangeSum(1 , rnk-1);
            ft.update(rnk, 1);
            res[i] = temp;
        }
        return res;

    }
};

class FenwickTree {
public:
    vector<int>bit;
    int n;
    
    FenwickTree(int n) {
        this->n = n;
        this->bit.resize(n+1, 0);
    }
    
    void update(int i, int val) {
        while (i < bit.size()) {
            bit[i] += val;
            i += (i & (-i));
        }
    }
    
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & (-i));
        }
        return sum;
    }
    
    int rangeSum(int l, int r) {
        return query(r) - query(l - 1);
    }
    
};