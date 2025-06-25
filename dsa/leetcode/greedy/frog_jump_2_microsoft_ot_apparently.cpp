/*
The cost of a path is the maximum length of a jump among all jumps in the path.

Return the minimum cost of a path for the frog.
*/

// taking alternate is the optimal solutino , as it would not shoot up the maxi path.

class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        if(n == 1) return 0;
        int ans = stones[1] - stones[0];

        for(int i = 2;i<n;i+=2) ans = max(ans, abs(stones[i] - stones[i-2]));
        for(int i = 3;i<n;i+=2) ans = max(ans, abs(stones[i] - stones[i-2]));
        return ans;

    }
};