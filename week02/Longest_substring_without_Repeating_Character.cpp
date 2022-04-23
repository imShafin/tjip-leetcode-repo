// TC: O(N)
// MC: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> aski(256, 0);
        int len = s.size(), L = 0, R = 0, cnt = 0, res = 0;
        while(R < len) {
            aski[s[R]]++;
            if(aski[s[R]] > 1) {
                cnt++;
            }
            R++;
            while(cnt > 0) {
                aski[s[L]]--;
                if(aski[s[L]] == 1) cnt--;
                L++;
            }
            res = max(res, R - L);
        }
        return res;
    }
};
