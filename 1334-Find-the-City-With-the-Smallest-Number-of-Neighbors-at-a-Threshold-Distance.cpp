#include <limits>

class Solution {
public:
    vector<vector<int>> floydWarshall(int n, const vector<vector<int>>& edges) {
        
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            dist[u][v] = weight;
            dist[v][u] = weight;
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        return dist;
    }

    int solve(int n, vector<vector<int>>& dist, int distanceThreshold) {
        int resultCity = -1;
        int minReachableCities = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int reachableCities = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] <= distanceThreshold) {
                    ++reachableCities;
                }
            }

            if (reachableCities <= minReachableCities) {
                minReachableCities = reachableCities;
                resultCity = i;
            }
        }

        return resultCity;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist = floydWarshall(n, edges);
        return solve(n, dist, distanceThreshold);
    }
};