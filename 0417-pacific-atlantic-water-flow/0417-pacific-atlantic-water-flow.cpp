class Solution {
public:
    /*
    heights = [
           0 1 2 3 4
        0 [1,2,2,3,5],
        1 [3,2,3,4,4],
        2 [2,4,5,3,1],
        3 [6,7,1,4,5],
        4 [5,1,1,2,4]]

    grids = [
        [0, 4],
        [1, 3], [1, 4],
        [2, 2],
        [3, 0], [3, 1],
        [4, 0]
    ]
    # Problem:
        - water flow: downhill OR reamin in same leve
        - pacific ocean: top + left; atlantic ocean: bootom + right
        - FIND: cells from where water can reach both the ocean

    # Appraoch
        - PA : water from pacific ocean -> atalntic ocean
            => traversal from P to A
            => top left to bottom right
        - AP : water from atlantic ocean -> pacific ocean
            => traversal from A to P
            => bottom right to top left
        - intersection point in (PA, AP) : water to both the ocean

    # Traversal : BFS

    # Complexity:
         m: rows; n: columns
        - TC:
            => O(m * n)
        - SC:
            => O(m * n)

    */

    //print the traversal
    void printTraversal(vector<vector<bool>>& V){
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout<<V[i][j]<<", ";
            }
            cout<<endl;
        }
    }

    int m, n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void bfs(vector<vector<int>>& H, vector<vector<bool>>& V,
             queue<pair<int, int>>& Q) {
        while (!Q.empty()) {
            auto [i, j] = Q.front();
            Q.pop();
            V[i][j] = true; // mark visited

            for (auto dir : directions) {
                int x = i + dir[0];
                int y = j + dir[1];

                if (x >= 0 && x < m && y >= 0 && y < n && !V[x][y] &&
                    H[x][y] >= H[i][j]) {
                    Q.push({x, y});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();    // rows
        n = heights[0].size(); // columns

        // visited
        vector<vector<bool>> pV(m, vector<bool>(n, false));
        vector<vector<bool>> aV(m, vector<bool>(n, false));

        // queue
        queue<pair<int, int>> pQ, aQ;

        // **Mark boundary cells for both oceans**
        for (int i = 0; i < m; i++) {
            pQ.push({i, 0});     // Left edge (Pacific)
            aQ.push({i, n - 1}); // Right edge (Atlantic)
        }
        for (int j = 0; j < n; j++) {
            pQ.push({0, j});     // Top edge (Pacific)
            aQ.push({m - 1, j}); // Bottom edge (Atlantic)
        }

        // bfs traversal
        bfs(heights, pV, pQ);
        bfs(heights, aV, aQ);

        cout << "rows: " << m << " & columns: " << n << endl;
        cout << "PA -> " << endl;
        printTraversal(pV);
        cout << "AP -> " << endl;
        printTraversal(aV);

        // common cells that can reach both the oceans
        vector<vector<int>> paC;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pV[i][j] && aV[i][j]) {
                    paC.push_back({i, j});
                }
            }
        }
        
        return paC;
    }
};