struct Node{
    Node* links[2];

    bool containsKey(int bit){
        return links[bit] != NULL;
    }
    Node* get(int bit ){
        return links[bit];
    }
    void put(int bit, Node* node){
        links[bit] = node;
    }
};

class Trie{
private:
    Node* head;

public:
    Trie(){
        head = new Node();
    }  
    void insert(int num){
        Node* node = head;

        for(int i = 31;i>=0;i--){
            int bit = (num>>i) &1;
            if(!node->containsKey(bit)){
                node->put (bit , new Node());
            }
            node = node->get(bit);
        }
    }  

    int getMaxi(int num){
        Node * node = head;
        int maxi = 0;

        for(int i = 31;i>=0;i--){
            int bit = (num >> i) & 1;
            if(node->containsKey(1 - bit)){
                maxi = maxi | (1<< i);
                node = node->get(1-bit);
            }else{
                node = node->get(bit);
            }
        }
        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie t = Trie();

        for(int i = 0;i<n;i++){
            t.insert(nums[i]);
        }
        int ans = 0;
        for(auto it: nums){
            ans = max(ans , t.getMaxi (it));
        }
        return ans;
    }
};