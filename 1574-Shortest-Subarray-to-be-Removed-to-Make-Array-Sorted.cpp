class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
         int left = 0;
    while (left + 1 < n && arr[left] <= arr[left + 1]) {
        left++;
    }
    
    if (left == n - 1) {
        return 0;
    }
    
    int right = n - 1;
    while (right - 1 >= 0 && arr[right] >= arr[right - 1]) {
        right--;
    }
    
    int min_len = min(n - left - 1, right);  // Minimum length by removing the prefix or suffix
    
    for (int i = 0; i <= left; i++) {
        while (right < n && arr[i] > arr[right]) {
            right++;
        }
        if (right < n) {
            min_len = min(min_len, right - i - 1);
        }
    }
    
    return min_len;
    }
};