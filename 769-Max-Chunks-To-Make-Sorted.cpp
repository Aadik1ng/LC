class Solution {
public:
    int solve(vector<int>& arr, int begin, int end, int cnt) {
        int max_val = arr[begin];

        for (int i = begin; i <= end; i++) {
            max_val = max(max_val, arr[i]);

            if (max_val == i) {
                cnt++;
                return solve(arr, i + 1, end, cnt);
            }
        }

        return cnt;  
    }

    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        return solve(arr, 0, n - 1, cnt);
    }
};
