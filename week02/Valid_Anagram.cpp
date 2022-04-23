// TC: O(N)
// MC: O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sc(26, 0), tc(26, 0);
        int s1 = s.size(), s2 = t.size();
        for (int i = 0; i < s1; i++) sc[s[i] - 'a']++;
        for (int i = 0; i < s2; i++) tc[t[i] - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (sc[i] != tc[i]) {
                return false;
            }
        }
        return true;
    }
};
