/// TC: O(NlogN)  N is the size of Vector
/// MC: O(N)      N is the size of Vector

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> track;
        int totalIntervals = intervals.size();
        for(auto x : intervals)
        {
          track[x[0]]++;
          track[x[1]]--;
        }
        int res = 0, curr = 0;
        for(auto x : track)
        {
          curr += x.second;
          res = max(curr, res);
        }
        return res;
    }
};
