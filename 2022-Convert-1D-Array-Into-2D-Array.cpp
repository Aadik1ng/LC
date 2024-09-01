class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        vector<vector<int>> ans(m, vector<int>(n));
        if (original.size() != m * n) {
            return {};
        }

        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = original[i * n + j];
            }
        }

        return ans;
    }
};