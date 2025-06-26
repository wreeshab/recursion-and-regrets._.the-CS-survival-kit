// backtrachin solution sucks.
// a b c d 
// \ / \ /
//  x   y 
//   \ /
//   ans

// a b c d
// \ / / /
//  x / /
//   y /
//   \/
//    ans
// try these two possibilities for all the permulatiosn.

class Solution {
    vector<double> combine2(double a, double b) {
        return {a / b, b / a, a + b, a - b, b - a, a * b};
    }
    static constexpr double eps = 1e-4;
public:
    bool judgePoint24(vector<int>& nums) {
        vector<int> id ({0, 1, 2, 3});
        do {
            int a = nums[id[0]], b = nums[id[1]], c = nums[id[2]], d = nums[id[3]];
            for (auto x: combine2(a, b))
                for (auto y: combine2(c, d))
                    for (auto z: combine2(x, y)) 
                        if (abs(z - 24) < eps) return true;
            for (auto x: combine2(a, b))
                for (auto y: combine2(c, x))
                    for (auto z: combine2(d, y))
                        if (abs(z - 24) < eps) return true;
        } while (next_permutation(id.begin(), id.end()));
        return false;
    }
};
