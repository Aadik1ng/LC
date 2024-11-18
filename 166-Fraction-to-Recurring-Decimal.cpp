class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string result = (numerator < 0) ^ (denominator < 0) ? "-" : "";
        
        long long num = abs((long long)numerator);  
        long long denom = abs((long long)denominator);
        
        result += to_string(num / denom);
        
        long long remainder = num % denom;
        
        if (remainder == 0) return result;  
        
        result += ".";  
        
        unordered_map<long long, int> remainder_map;
        
        while (remainder != 0) {
            if (remainder_map.find(remainder) != remainder_map.end()) {
                result.insert(remainder_map[remainder], "(");
                result += ")";  
                break;
            }
            
            remainder_map[remainder] = result.length();
            
            remainder *= 10;
            result += to_string(remainder / denom);
            remainder %= denom;
        }
        
        return result;
    }
};
