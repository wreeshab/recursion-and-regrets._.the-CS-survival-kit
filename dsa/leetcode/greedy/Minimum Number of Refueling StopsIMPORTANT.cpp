class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // Max-heap to store fuels of reachable stations
        priority_queue<int> pq;

        int fuel = startFuel;  // Current fuel
        int i = 0, n = stations.size();
        int stops = 0;         // Number of refueling stops made

        // Loop until we reach the target
        while (fuel < target) {
            // Add all stations that can be reached with current fuel to the heap
            while (i < n && stations[i][0] <= fuel) {
                pq.push(stations[i][1]);  // Push fuel amount
                i++;
            }

            // If no stations are reachable and we can't reach the target
            if (pq.empty()) return -1;

            // Refuel at the station with the highest fuel available so far
            // the main loop itself will simulate continuous refuelling so no need for a new loop.
            fuel += pq.top(); pq.pop();
            stops++;
        }

        return stops;
    }
};
