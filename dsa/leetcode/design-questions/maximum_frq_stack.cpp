class FreqStack {
public:
    // tuple - freq, time of insertion , element,
    int t;
    priority_queue<tuple<int ,int ,int>> pq;
    // element, freq
    unordered_map<int , int> freq;
    FreqStack() {
        t = 0;
    }
    
    void push(int val) {
        freq[val]++;
        pq.push({freq[val] , t++, val});
    }
    
    int pop() {
        auto [_, time, ele] = pq.top() ;
        pq.pop();
        freq[ele]--;
        return ele ;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */