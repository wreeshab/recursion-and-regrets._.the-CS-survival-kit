class Solution {
public:
    bool isValid(string s) {
        int bal = 0;
        for (char ch : s) {
            if (ch == '(')
                bal++;
            else if (ch == ')')
                bal--;
            if (bal < 0)
                return false;
        }
        return bal == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();

        set<string> vis;
        queue<string> q;
        vis.insert(s);
        q.push(s);

        bool found = false;
        int length = -1;
        vector<string> ans;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            if (isValid(curr)) {
                found = true;
                if (length == -1 || curr.size() == length) {
                    ans.push_back(curr);
                }
            }
            if (!found)

                for (int i = 0; i < curr.size(); i++) {
                    if (curr[i] != '(' && curr[i] != ')') {
                        continue;
                    }
                    string temp = curr.substr(0, i) + curr.substr(i + 1);

                    if (!vis.count(temp)) {
                        vis.insert(temp);
                        q.push(temp);
                    }
                }
        }
        return ans;
    }
};