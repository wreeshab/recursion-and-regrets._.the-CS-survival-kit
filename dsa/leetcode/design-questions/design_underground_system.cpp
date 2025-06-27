class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkin;
    map<pair<string, string>, pair<long long, int>> stats;

    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = checkin[id];
        checkin.erase(id);
        auto &entry = stats[{startStation, stationName}];
        entry.first += (t - startTime); // total time
        entry.second += 1;              // trip count
    }

    double getAverageTime(string startStation, string endStation) {
        auto &[total, count] = stats[{startStation, endStation}];
        return (double)total / count;
    }
};

