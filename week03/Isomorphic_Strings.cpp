class Solution {
public:
    bool isIsomorphic(string s, string t, int interval = 0) {
        unordered_map<char, char> track;
        for (int i = 0; i < s.size(); i++) {
            if (track.count(s[i]) == 1 && track[s[i]] != t[i] ) {
                return false;
            }
            track[s[i]] = t[i];
        }
        if(interval == 0) return isIsomorphic(t, s, 1);
        return true;
    }
};
