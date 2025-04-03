class Solution {
public:
    bool canReachOnTime(const vector<int>& dist, int speed, double hour) {
    double totalTime = 0.0;
    int n = dist.size();
    
    for (int i = 0; i < n - 1; i++) {
        totalTime += ceil((double)dist[i] / speed);
    }
    
    totalTime += (double)dist[n - 1] / speed;  // Last train exact time

    return totalTime <= hour;
}

int minSpeedOnTime(vector<int>& dist, double hour) {
    int low = 1, high = 1e7, ans = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canReachOnTime(dist, mid, hour)) {
            ans = mid;
            high = mid - 1;  // Try for smaller speed
        } else {
            low = mid + 1;  // Increase speed
        }
    }
    
    return ans;
}
};