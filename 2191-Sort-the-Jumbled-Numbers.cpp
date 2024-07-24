#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> mappedPairs;
        
        for (int num : nums) {
            int mappedValue = 0;
            string numStr = to_string(num);
            for (char digit : numStr) {
                mappedValue = mappedValue * 10 + mapping[digit - '0'];
            }
            mappedPairs.push_back({mappedValue, num});
        }
        
        // Stable sort based on the mapped values
        stable_sort(mappedPairs.begin(), mappedPairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });
        
        // Extract the original numbers in the new sorted order
        vector<int> ans;
        for (const auto& p : mappedPairs) {
            ans.push_back(p.second);
        }
        
        return ans;
    }
};
