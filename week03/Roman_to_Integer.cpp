// TC: O(N)
// MC: O(1)
class Solution {
public:
    int romanToInt(string s) {
        int cnt = 0;
        unordered_map<char, int> romanCount = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000},
        };
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X') ) {
                cnt += (romanCount[s[i+1]] - romanCount[s[i]]);
                i++;
            }
            else if(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) {
                cnt += (romanCount[s[i+1]] - romanCount[s[i]]);
                i++;
            }
            else if(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')) {
                cnt += (romanCount[s[i+1]] - romanCount[s[i]]);
                i++;
            }
            else cnt += romanCount[s[i]];
        }
        return cnt;
    }
};
