class Solution {
public:
    bool isPossible(vector<int>& time, long long mid, long long totalTrips) {
        long long trips = 0;
        for (int t : time) {
            trips += mid / t;
            if (trips >= totalTrips)
                return true; 
        }
        return false;
    }

    long long minimumTime(vector<int>& time, long long totalTrips) {
        long long low = 1,
                  high = (long long)*min_element(time.begin(), time.end()) *
                         totalTrips;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(time, mid, totalTrips)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};