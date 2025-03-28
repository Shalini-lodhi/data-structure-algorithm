/*
I/P: cars[n], poisition[n], target
car[i] = {pos[i], speed[i]}

    index   |   position    |   speed   |   time to reach target
[(target-pos)/speed] 0   |       10      |   2       |       1 1   |       8 |
4       |       1 2   |       0       |   1       |       12 3   |       5 |   1
|       7 4   |       3       |   3       |       3


    10  |   8   |   5   |   3   |   0
    2   |   4   |   1   |   3   |   1
    1   |   1   |   7   |   3   |   12

#1. Approach
    - sort(pos) -> des order {process nearest to farthest}  |   {O(nlog)}
    - target time
    - count no. of fleets -> stack {group of fleet}     |   {O(n)}
            - if car takes longer than the top fleet, then create a new fleet
            - if it take less/ equal time, merge it with the fleet
    TC: O(nlogn)


*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars; // (position, time to reach target)

        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort cars by position in descending order (farthest to nearest)
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double last_time = 0;

        for (auto& car : cars) {
            double time = car.second;
            // Only count a new fleet if this car reaches later than the last
            // fleet
            if (time > last_time) {
                fleets++;
                last_time = time;
            }
        }

        return fleets;
    }
};