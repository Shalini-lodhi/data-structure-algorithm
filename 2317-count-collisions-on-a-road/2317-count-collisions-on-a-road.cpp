/*
 directions[n] = directions[i] = {<-L, R->, S};
 collisions:
    - R-> / <-L (+2) => SS
    - R-> / S or S <-L (+1) => SS

ex. directions = "RLRSLL"
    0   |   RLRSLL  |   R->L    |   SSRSLL  |   +2
    1   |   SSRSLL  |   --      |   SSRSLL  |   0
    2   |   SSRSLL  |   R->S    |   SSSSLL  |   +1
    3   |   SSSSLL  |   --      |   SSSSLL  |   0
    4   |   SSSSLL  |   S<-L    |   SSSSSL  |   +1
    5   |   SSSSSL  |   S<-L    |   SSSSSS  |   +1

    totalCollision = 5

ex. "LLRR"
    0   |   LLRR    |   <-L     |   LLRR    |   0
    .
    .
    R   |   LLRR    |   R->     |   LLRR    |   0
    <-L & R->

#1. Iterating one by one for cars
    - checking every movement of cars & update their state
    - TC: O(N*N); SC: 0(N)

#2. Counting
    - find the first non - 'L' from the left ("R" / "S")
        - any 'L' will move to left & won't collide
    - find the first non - 'R" from right ("L" / "S")
        - any 'R' will move to right & won't collide
    - count all moving cars(R & L)  
        - will eventually collide
    
    "RLRSLL"
    - first non-L from left : index 0
    - last non-R from right : index 5
    - moving cars in this range -> 5 moving cars

    => collision = 5
*/


class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();

        int left = 0, right = n-1;

        while(left < n && directions[left] == 'L') left++; //left = 0
        while(right >= 0 && directions[right] == 'R') right--; //right = 0

        int collision = 0;
        for(int i = left; i <= right; i++){
            if(directions[i] != 'S') collision++;
        }
        return collision;
    }
};

/*
directions: "LLRR"
0   |   R   |   +1
1   |   L   |   +1
2   |   R   |   +1
3   |   S   |   0
4   |   L   |   +1
5   |   L   |   +1

*/