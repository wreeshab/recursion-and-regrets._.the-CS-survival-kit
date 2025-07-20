// https://leetcode.com/problems/longest-repeating-character-replacement/

// You are given a string s and an integer k. You can choose any character of the string
//  and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int answer = 0;
        int maxFreq = 0;
        unordered_map<int, int> mpp;
        int l = 0;
        int r = 0;
        while (r < n)
        {
            mpp[s[r]]++;
            maxFreq = max(maxFreq, mpp[s[r]]);

            while (l < n && r - l + 1 - maxFreq > k)
            {
                mpp[s[l]]--;
                l++;
            }
            answer = max(answer, r - l + 1);

            r++;
        }
        return answer;
    }
};