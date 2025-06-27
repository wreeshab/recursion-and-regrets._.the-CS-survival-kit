/*

so here , this is the logic behind popping the pq after getting a prefix that matches the conditions.

that is because lets say we get an index i + 2  that satisfies the same condition but i satisfies the condition as well this means that the length for i will be considered so i is the local answer for it.

so we’re popping with the promise that this is the lowest size array with sum m.


*/


class Solution {
public:
    long long shortestSubarray(vector<int>& nums, long long k) {
        long long n = nums.size();
        // order of sum and index.
        priority_queue<pair<long long , long long >, vector<pair<long long , long long >>, greater<>> pq;
        long long runningSum = 0;
        long long ans = INT_MAX;
        for (long long i = 0; i < n; i++) {
            runningSum += nums[i];

            if (runningSum >= k) {
                ans = min(ans, i+1);
            }
            while (!pq.empty() && runningSum - pq.top().first >= k) {
                ans = min(ans, i - pq.top().second );
                //Valid subarray found: update answer and remove this prefix because it won’t be useful anymore (want minimal length).
                pq.pop();
            }

            pq.push({runningSum, i});
        }

        return ans == INT_MAX ? -1 : ans;
    }
};