
// make a map of all the last indices, 
// pure implementation .
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> hash(26, 0);
        int n = s.size();
        for(int i = 0; i<n;i++){
            hash[s[i] - 'a'] = i;
        }
        int i = 0;
        int j = 0;
        int currEnd = 0;
        vector<int> ans;

        while(i < n){
            int templastindex = hash[s[i] - 'a'];

            int j = i;

            while(j < templastindex){
                templastindex = max(templastindex,hash[s[j] - 'a'] );
                j++;
            }

            ans.push_back(j - i + 1);
            i = j +1;
        
        }



        return ans;
    }
};