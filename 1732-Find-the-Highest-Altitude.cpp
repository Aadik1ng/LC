class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int runningsum=0;
        int maxsum=0;
        for(auto x:gain){
            runningsum+=x;
            maxsum=max(runningsum,maxsum);

        }
        return maxsum;
    }
};