class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for (int i = 0; i < expression.size(); ++i) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> a = diffWaysToCompute(expression.substr(0, i));
                vector<int> b = diffWaysToCompute(expression.substr(i + 1));
                for (auto x : a) {
                    for (auto y : b) {
                        if (expression[i] == '+') res.push_back(x + y);
                        else if (expression[i] == '-') res.push_back(x - y);
                        else if (expression[i] == '*') res.push_back(x * y);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(expression));
        return res;
    }
};
