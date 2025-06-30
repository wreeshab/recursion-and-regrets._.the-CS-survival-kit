#include <bits/stdc++.h>
using namespace std;

// Function to compute minimum reversals to make alternating string
int minimumReverse(string s) {
    int n = s.size();
    int count_00 = 0, count_11 = 0;
    int count0 = 0, count1 = 0;

    // Count adjacent identical pairs and total 0s and 1s
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') count0++;
        else count1++;

        if (i > 0 && s[i] == s[i - 1]) {
            if (s[i] == '0') count_00++;
            else count_11++;
        }
    }

    // Check if alternating is even possible
    if (abs(count0 - count1) > 1)
        return -1;

    // Minimum reversals needed to break all bad zones
    return max(count_00, count_11);
}

void test(const string& s) {
    cout << "Input:    " << s << endl;
    int res = minimumReverse(s);
    if (res == -1)
        cout << "Output:   Not possible to make alternating\n\n";
    else
        cout << "Output:   Minimum reversals = " << res << "\n\n";
}

int main() {
    test("10001");     // 2 consecutive 0s → needs 2 reversals
    test("1111");      // Too many 1s → not possible
    test("010101");    // Already alternating → 0
    test("00011");     // Difference in 0s and 1s is 1 → possible
    test("1100");      // 2 of each → possible, but has "11" and "00"
    test("1");         // Already alternating
    test("00");        // Not possible → both same, and only 0s

    return 0;
}
