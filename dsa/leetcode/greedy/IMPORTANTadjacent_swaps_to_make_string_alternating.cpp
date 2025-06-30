#include <bits/stdc++.h>
using namespace std;

// Function to compute minimum swaps to form alternating string
int minSwaps(string s) {
    int n = s.size();
    int zeros = count(s.begin(), s.end(), '0');
    int ones = n - zeros;

    // Check feasibility
    if (abs(zeros - ones) > 1)
        return -1;

    auto getCost = [&](char start) {
        int cost = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (s[i] != start)
                continue;
            cost += abs(i - j);
            j += 2;
        }
        return cost;
    };

    if (zeros > ones) {
        return getCost('0');
    } else if (ones > zeros) {
        return getCost('1');
    } else {
        // Try both starting with '0' and starting with '1'
        return min(getCost('0'), getCost('1'));
    }
}

int main() {
    string s = "110100";
    int result = minSwaps(s);
    cout << result << endl;
    return 0;
}
