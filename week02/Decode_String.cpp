// TC : O(N)
// MC : O(N)
class Solution {
public:
    string decodeString(string s) {
        stack<string> strs; stack<int> nums; stack<char> bracket;
        string res, curr = "";
        int N = 0, cnt = 0;
        for (auto x : s) {
            if(x == '[') {
                if (bracket.empty() && !strs.empty()) {
                    res += strs.top();
                    strs.pop();
                }
                bracket.push(x);
                if(N > 0) nums.push(N);
                N = cnt = 0;
            }
            else if (x >= '0' && x <= '9') {
                N = (N*10) + (x - 48);
                if(++cnt == 1) strs.push(curr);
                curr = "";
            }
            else if (x >= 'a' && x <= 'z') curr += x;
            else if(x == ']') {
                bracket.pop();
                int lp = nums.top();
                if(bracket.empty()) {
                    for(int i = 0; i < lp; i++)  res += curr;
                    curr = "";

                } else {
                    string temp = "";
                    if (!strs.empty()) {
                        temp = strs.top();
                        strs.pop();
                    }
                    for(int i = 0; i < lp; i++) temp += curr;
                    curr = temp;
                }
                nums.pop();
            }
        }
        return res + curr;
    }
};
