/*
Problem: Largest Number (Leetcode 179)
Given a list of non-negative integers, arrange them such that they form the largest number.
Return the result as a string. If the answer is just "0", return "0".
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        // Convert all integers to strings for custom sorting
        for (auto it : nums) {
            arr.push_back(to_string(it));
        }

        // Custom comparator:
        // For strings s1 and s2, compare s1+s2 and s2+s1.
        // Whichever forms the larger concatenated number should come first.
        // since everything is local , this is greedy.
        sort(arr.begin(), arr.end(),
             [](string& s1, string& s2) {
                 return s1 + s2 > s2 + s1;
             });

        string res;
        for (auto s : arr)
            res += s;

        // Remove leading zeros (e.g., [0,0] should return "0")
        while (res[0] == '0' && res.length() > 1)
            res.erase(0, 1);

        return res;
    }
};
