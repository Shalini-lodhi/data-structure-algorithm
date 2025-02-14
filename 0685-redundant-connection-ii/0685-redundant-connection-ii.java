class Solution {
    public int[] findRedundantDirectedConnection(int[][] edges) {
        int n = edges.length;
        // create a parent array of size n+1 since there are 1-n edges.
        int[] parent = new int[n + 1];
        // initialising every node as it's own parent
        for (int i = 0; i <= n; i++)
            parent[i] = i;

        // initialising conflict edge and cycle edge
        int conflictEdge = -1, cycleEdge = -1;
        DisjointSet ds = new DisjointSet(n + 1);

        for (int i = 0; i < n; i++) {

            int from = edges[i][0], to = edges[i][1];

            // if it is a conflicting edge
            if (parent[to] != to) {
                conflictEdge = i;
            } else {
                // not a conflicting edge
                parent[to] = from;
                // true if it is a cycle else false;
                if (ds.union(from, to)) {
                    cycleEdge = i;
                }
            }
        }

        // if only conflicting edge exist return it
        if (cycleEdge == -1) {
            return edges[conflictEdge];
        }
        // if only cycle exist
        if (conflictEdge == -1)
            return edges[cycleEdge];

        // if both exist
        int to = edges[conflictEdge][1];
        return new int[] { parent[to], to };
    }
}

class DisjointSet {
    int[] parent, size;

    public DisjointSet(int n) {
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    boolean union(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return true;
        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        return false;
    }
}