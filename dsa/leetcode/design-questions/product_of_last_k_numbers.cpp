class ProductOfNumbers {
public: 
    vector<int> a;
    ProductOfNumbers() {
        a.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
            a.clear();
            a.push_back(1);
        }else{
            a.push_back(a.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = a.size();
        if(k >= n){
            return 0;
        }
        return a[n-1] / a[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */