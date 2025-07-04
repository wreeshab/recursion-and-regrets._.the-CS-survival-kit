class Solution {
private:
    int answer = 0;
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int right = mid + 1;
        int left = low;
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid)
            temp.push_back(nums[left++]);
        while (right <= high)
            temp.push_back(nums[right++]);

        for (int i = low; i <= high; ++i) {
            nums[i] = temp[i - low];
        }
    }

    void rp(vector<int>& nums, int low, int mid, int high) {
        int right = mid + 1;

        for (int i = low; i <= mid; ++i) {
            while (right <= high && (long long)nums[i] > 2LL * nums[right]) {
                right++;
            }
            answer += (right - (mid + 1));
        }
    }

    void mergeSort(vector<int>& nums, int low, int high) {
        if (high <= low)
            return;

        int mid = low + (high - low) / 2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        rp(nums, low, mid, high);
        merge(nums, low, mid, high);
    }

public:
    int reversePairs(vector<int>& nums) {
        // brute force n^2;
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return answer;
    }
};
