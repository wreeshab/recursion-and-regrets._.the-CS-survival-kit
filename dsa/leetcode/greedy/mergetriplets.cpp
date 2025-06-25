/*
Problem: Merge Triplets to Form Target Triplet (Leetcode 1899)
You are given a list of triplets (a,b,c) and a target triplet (x,y,z).
You can pick any subset of triplets and merge them if for each index,
the max of that index in the subset ≤ target. Return true if you can 
merge to exactly get the target triplet.
*/

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<int> result = {0, 0, 0};  // Initialize merged triplet

        for (int i = 0; i < n; i++) {
            vector<int> ele = triplets[i];

            // Skip triplet if any value exceeds target, even by one value.
            if (ele[0] > target[0] || ele[1] > target[1] || ele[2] > target[2])
                continue;

            // Merge the triplet into result
            result = {
                max(result[0], ele[0]),
                max(result[1], ele[1]),
                max(result[2], ele[2])
            };

            // Early exit if target is reached
            if (result == target) return true;
        }

        return result == target;
    }
};
