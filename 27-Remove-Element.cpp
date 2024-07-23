class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int cnt = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if ((nums[i] ^ val) == 0) {  
                nums[i] = INT_MAX;
                ++cnt;
            }
        }

        std::sort(nums.begin(), nums.end());

        return nums.size() - cnt;
    }
};