class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0); 
        
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return heights[a] > heights[b];
        });
        
        vector<string> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = names[indices[i]];
        }
        
        return result;
    }
};