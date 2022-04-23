//TC : O(N + M)
//MC : O(N + M)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int la = haystack.size(), lb = needle.size(), len = la + lb + 1;
        string S = needle + '#' + haystack;
        vector<int> pi(len);
        for (int R = 1; R < len; R++)
        {
            int L = pi[R-1];
            while(L > 0 && S[L] != S[R])  L = pi[L-1];
            pi[R] = L + (S[L] == S[R]);
            if (pi[R] == lb) return R - (lb + lb);
        }
        return -1;
    }
};
