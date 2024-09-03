class Solution {
public:
    int getLucky(std::string s, int k) {
        int sum = 0;
        for (char c : s) {
            int num = (c - 'a' + 1);  
            while (num > 0) {
                sum += num % 10;  
                num /= 10;
            }
        }

        while (--k > 0) {  
            int newSum = 0;
            while (sum > 0) {
                newSum += sum % 10;
                sum /= 10;
            }
            sum = newSum;
        }

        return sum;
    }
};