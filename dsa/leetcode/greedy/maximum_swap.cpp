class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> nextLarge(n);

        nextLarge[n-1] = n-1;
        for(int i = n-2;i>=0;i--){
            // should be strict (>) and not >=
            // because we want to swap with the **rightmost** largest digit
            // if we use >=, we may pick an earlier same digit and miss the optimal swap
            if(s[i] > s[nextLarge[i+1]]){
                nextLarge[i] = i;
            }else{
                nextLarge[i] = nextLarge[i+1];
            }
        }

        for(int i : nextLarge) cout<< i << ' ';
        for(int i = 0;i<n;i++){
            if(s[i]<s[nextLarge[i]]){
                swap(s[i], s[nextLarge[i]]);
                break;
            }
        }
        return stoi(s);
    }
};
