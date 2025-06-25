// sexy logic quesion.
class Solution {
public:
    bool checkValidString(string s) {
        // store all possible ranges using 2 variables.
        int maxi = 0; // should not get -ve
        int mini = 0; // no problem if it gets negative, since we're not gonna take that path anyways , we'll resetit to 0.
        for(char ch : s){
            if(ch == '('){
                mini++;
                maxi++;
            }else if(ch == ')'){
                mini--;
                maxi--;
            }else{
                maxi++;
                mini--;
            }
            if(maxi <0) return false; // even in the best case the parantheses strin is not valid.
            if(mini <0) mini = 0; // reset. 
        }
        return mini ==0;
    }   
};