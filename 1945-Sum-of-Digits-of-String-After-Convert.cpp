class Solution {
public:
    int accumulateStack(stack<int> s) {
        int sum = 0;

        while (!s.empty()) {
            sum += s.top();
            s.pop();
        }

        return sum;
    }

    int getLucky(string s, int k) {
        map<char, int> mp{{'a', 1},  {'b', 2},  {'c', 3},  {'d', 4},  {'e', 5},
                          {'f', 6},  {'g', 7},  {'h', 8},  {'i', 9},  {'j', 10},
                          {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'o', 15},
                          {'p', 16}, {'q', 17}, {'r', 18}, {'s', 19}, {'t', 20},
                          {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24}, {'y', 25},
                          {'z', 26}};

        stack<int> st;
        for (char c : s) {
            int num = mp[c];
            while (num > 0) {
                st.push(num % 10);
                num /= 10;
            }
        }

        while (--k) {
            stack<int> temp;
            int sum = accumulateStack(st);
            while (sum > 0) {
                temp.push(sum % 10);
                sum /= 10;
            }
            st = temp;
        }

        int ans = accumulateStack(st);
        return ans;
    }
};