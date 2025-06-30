vector<int> rearrange(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    int pos = 0, neg = 1;

    for (int x : nums) {
        if (x >= 0 && pos < n) {
            result[pos] = x;
            pos += 2;
        } else if (x < 0 && neg < n) {
            result[neg] = x;
            neg += 2;
        }
    }

    return result;
}
