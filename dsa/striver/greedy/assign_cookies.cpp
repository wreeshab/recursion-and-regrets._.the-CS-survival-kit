class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gs = g.size();
        int ss = s.size();

        sort(g.begin() , g.end());
        sort(s.begin() , s.end());

        int i = 0; // for g
        int j = 0; // fos 
        int cnt = 0;
        while(i < gs && j < ss){
            // cout<< i << ' '<< j<< ' '<< gs << ' '<< ss << endl;
             if(g[i] <= s[j]){
                cnt++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return cnt;
    }
};