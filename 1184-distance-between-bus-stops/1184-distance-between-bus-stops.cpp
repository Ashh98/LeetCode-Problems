class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int clock = 0;
        int aclock = 0;
        bool cond;
        for (int i = 0; i < distance.size(); i++) {
            if (destination < start) {
                cond = i >= start || i <= destination-1;
            } else {
                cond = i >= start && i <= destination-1;
            }
            if (cond) {
                clock = clock + distance[i];
            } else {
                aclock = aclock + distance[i];
            }
        }
        if (clock > aclock) {
            return aclock;
        } else {
            return clock;
        }
    }
};