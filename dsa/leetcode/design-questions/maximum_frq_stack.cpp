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

// better solution
class FreqStack {
unordered_map<int, int> map;
unordered_map<int, stack<int>> stackMap;
int maxFreq = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        map[val]++;
        maxFreq = max(maxFreq, map[val]);
        stackMap[map[val]].push(val);
    }
    
    int pop() {
        if(maxFreq == 0)
            return -1;
        int element = stackMap[maxFreq].top();
        stackMap[maxFreq].pop();

        if(stackMap[maxFreq].empty())
            maxFreq--;
        map[element]--;
        return element;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */