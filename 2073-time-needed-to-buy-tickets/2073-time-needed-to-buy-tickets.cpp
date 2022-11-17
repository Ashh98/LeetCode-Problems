class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int lo = 0, hi = tickets.size()-1;
        int time = 0;
        while (tickets[lo+k] != 0) {
            tickets[lo]--;
            if (tickets[lo] == 0) {
                time++; lo++;
                if (tickets[lo+k-1] == 0) return time;
            } else {
                tickets.push_back(tickets[lo]);
                time++; lo++; hi++;
                if (tickets[lo+k-1] == 0) return time;
            }
            k--;
            if (k == -1) k = hi-lo;
            
        }
        return time;
    }
};