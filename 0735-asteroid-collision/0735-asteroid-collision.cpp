/*
astroids[] = {index->size->('+': ->, '-': <-)}
collision:
    - smaller => (X)
    - same size =>  (X)
    - <-,<- or ->,-> => (--)

ex. asteroids = [5,10,-5]
    - (5->) [(10->) (<-5)] => [(5->) (10->)]
ex. asteroids = [10, 2, -5]
    - (10->) (2->) (-5) => (10->) [(2->) (-5)]
    => (10->) (<-5) => [(10->) (<-5)]
    => (10->)
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        // Ignore asteroids that are already moving away from the conflict zone
        int left = 0, right = n - 1;
        while (left < n && asteroids[left] > 0)
            left++;
        while (right >= 0 && asteroids[right] < 0)
            right--;

        for (int i = 0; i < n; i++) {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 &&
                   asteroids[i] < 0) { // Collision happens
                if (st.top() <
                    -asteroids[i]) { // Stack top is smaller, it explodes
                    st.pop();
                    continue;
                } else if (st.top() == -asteroids[i]) { // Both explode
                    st.pop();
                }
                destroyed = true;
                break;
            }

            if (!destroyed) {
                st.push(asteroids[i]);
            }
        }

        // Convert stack to output array
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};