class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xorr = 0;
        for (unsigned int x : nums) {
            xorr ^= x;
        }
        
        // Find the rightmost set bit
        unsigned int setbit = xorr & -xorr;  // Isolate the rightmost set bit
        
         int b1 = 0, b2 = 0;
        for ( int x : nums) {
            if (x & setbit) {
                b1 ^= x; 
            } else {
                b2 ^= x;  
            }
        }
        
        return {b1, b2};// The two unique numbers  
    }
};
