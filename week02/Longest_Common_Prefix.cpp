// TC: O(N*min(M))
// MC: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size(), l = strs[0].size(), cnt = 0;
        for (int i = 0; i < len - 1; i++)
        {
            int s1 = strs[i].size();
            int s2 = strs[i+1].size();
            cnt = 0;
            for (int j = 0; j < l; j++)
            {
                if ( j < min(s1, s2) && (strs[i][j] == strs[i+1][j]) ) cnt++;
                else {
                    l = min(l, cnt);
                    break;
                }
            }
        }
        return strs[0].substr(0, l);
    }
};
