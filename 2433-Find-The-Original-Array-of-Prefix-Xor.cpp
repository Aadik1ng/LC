class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int a=0,b;
        for(auto &i:pref){
            b=a;
            a=i;
            i^=b;
        }
        return pref;
    }
};