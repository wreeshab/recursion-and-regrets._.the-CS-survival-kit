Always insert the new number into minHeap first (the "larger half").

Move the smallest number from minHeap to maxHeap (to ensure order property: small half in maxHeap, large half in minHeap).

If maxHeap becomes larger, rebalance by moving the largest from maxHeap back to minHeap.

class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int , vector<int> , greater<>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minHeap.push(num);

        maxHeap.push(minHeap.top());
        minHeap.pop();

        if(minHeap.size() < maxHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()){
            return double(minHeap.top() + maxHeap.top())/2;
        } else {
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */