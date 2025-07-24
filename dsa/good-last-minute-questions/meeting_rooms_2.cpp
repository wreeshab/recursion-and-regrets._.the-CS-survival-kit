int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(intervals[0][1]);
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= minHeap.top())
            minHeap.pop();
        minHeap.push(intervals[i][1]);
    }
    return minHeap.size();
}

// two pointer appraoch
int minMeetingRooms(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<int> start(n), end(n);
    
    for (int i = 0; i < n; ++i) {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0, j = 0, rooms = 0, maxRooms = 0;

    while (i < n) {
        if (start[i] < end[j]) {
            rooms++;       // new meeting overlaps → need a new room
            i++;
        } else {
            rooms--;       // one meeting ended → free a room
            j++;
        }
        maxRooms = max(maxRooms, rooms);
    }

    return maxRooms;
}
