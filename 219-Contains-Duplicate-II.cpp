class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> valueToLastIndex;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];

            if (valueToLastIndex.find(num) != valueToLastIndex.end()) {
                int lastIndex = valueToLastIndex[num];
                if (abs(i - lastIndex) <= k) {
                    return true; 
                }
            }

            valueToLastIndex[num] = i;
        }

        return false; 
    }
};