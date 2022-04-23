class Solution {
public:
    bool isValid(string s) {
        stack<char> track;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') track.push(s[i]);
            else if (!track.empty()) {
                if (s[i] == ')' && (track.top() == '[' || track.top() == '{') ) return false;
                if (s[i] == '}' && (track.top() == '(' || track.top() == '[') ) return false;
                if (s[i] == ']' && (track.top() == '(' || track.top() == '{') ) return false;
                else track.pop();
            }
            else if(track.empty())
                if (s[i] == ')' || s[i] == '}' || s[i] == ']') return false;
        }
        if(!track.empty()) return false;
        return true;
    }
};