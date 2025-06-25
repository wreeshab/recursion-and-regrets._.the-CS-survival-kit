/*
Problem: Remove K Digits (Leetcode 402)
Given a non-negative integer `num` as a string and an integer `k`, 
remove `k` digits from the number so that the new number is the smallest possible.
Return the resulting number as a string. If empty, return "0".
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        // Greedily keep digits in increasing order in stack
        for (int i = 0; i < n; i++) {
            // Remove larger digits from top while current is smaller
            // here no more than k digits should be removed.
            while (!st.empty() && k > 0 && num[i] < st.top()) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // If k still remains, remove from the end
        while (k > 0) {
            st.pop();
            k--;
        }

        // Build result from stack
        string res = "";
        while (!st.empt
