// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int n, int arr[]){
         unordered_map<int, int> ladders;
       unordered_map<int, int> snakes;
       for (int i = 0; i < 2 * n; i += 2) {
           if (arr[i] < arr[i + 1]) {
               ladders[arr[i]] = arr[i + 1];
           } else if (arr[i] > arr[i + 1]) {
               snakes[arr[i]] = arr[i + 1];
           }
       }
       int moves = 0;
       queue<int> queue;
       queue.push(1);
       vector<bool> visited(31, false);
       visited[1] = true;
       while (!queue.empty()) {
           int size = queue.size();
           moves++;
           while (size--) {
               int currentPosition = queue.front();
               queue.pop();
               for (int die = 1; die <= 6; die++) {
                   if (currentPosition + die > 30) break;
                   if (currentPosition + die == 30) return moves;
                   if (visited[currentPosition + die]) continue;
                   if (ladders.count(currentPosition + die) > 0 && !visited[ladders[currentPosition + die]]) {
                       visited[ladders[currentPosition + die]] = true;
                       queue.push(ladders[currentPosition + die]);
                       if (ladders[currentPosition + die] == 30) {
                           return moves;
                       }
                   } else if (snakes.count(currentPosition + die) > 0 && !visited[snakes[currentPosition + die]]) {
                       visited[snakes[currentPosition + die]] = true;
                       queue.push(snakes[currentPosition + die]);
                   } else {
                       visited[currentPosition + die] = true;
                       queue.push(currentPosition + die);
                   }
               }
           }
       }
       return -1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends