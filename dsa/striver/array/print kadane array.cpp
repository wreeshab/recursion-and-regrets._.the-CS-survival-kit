#include <iostream>
#include <vector>
using namespace std;

void kadaneWithSubarray(const vector<int>& nums) {
    int maxSum = INT_MIN;
    int currSum = 0;
    int start = 0, end = 0;
    int tempStart = 0;

    for (int i = 0; i < nums.size(); ++i) {
        // If current sum is 0, assign potential start index
        if (currSum == 0) tempStart = i;

        // Add current element
        currSum += nums[i];

        // Update max sum and subarray indices
        if (currSum > maxSum) {
            maxSum = currSum;
            start = tempStart;
            end = i;
        }

        // Reset if sum becomes negative
        if (currSum < 0) currSum = 0;
    }

    // Output result
    cout << "Maximum Subarray Sum = " << maxSum << "\n";
    cout << "Subarray = [ ";
    for (int i = start; i <= end; ++i)
        cout << nums[i] << " ";
    cout << "]\n";
}

int main() {
