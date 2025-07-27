class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> results;

        if (!dict.count(endWord)) return results;

        unordered_map<string, vector<string>> parents; // Track parents for backtracking
        unordered_set<string> currentLevel;            // Words in current BFS level
        currentLevel.insert(beginWord);

        bool found = false;

        while (!currentLevel.empty() && !found) {
            for (const string& word : currentLevel)
                dict.erase(word); // Avoid cycles

            unordered_set<string> nextLevel;

            for (const string& word : currentLevel) {
                string temp = word;

                for (int i = 0; i < temp.size(); ++i) {
                    char original = temp[i];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;

                        if (!dict.count(temp)) continue;

                        nextLevel.insert(temp);
                        parents[temp].push_back(word); // Build reverse graph
                        if (temp == endWord) found = true;
                    }
                    temp[i] = original; // Restore original char
                }
            }

            currentLevel = nextLevel;
        }

        if (!found) return results;

        vector<string> path = {endWord};
        backtrack(endWord, beginWord, parents, path, results);
        return results;
    }

    void backtrack(const string& word, const string& beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path, vector<vector<string>>& results) {

        if (word == beginWord) {
            vector<string> validPath = path;
            reverse(validPath.begin(), validPath.end());
            results.push_back(validPath);
            return;
        }

        for (const string& parent : parents[word]) {
            path.push_back(parent);
            backtrack(parent, beginWord, parents, path, results);
            path.pop_back();
        }
    }
};
