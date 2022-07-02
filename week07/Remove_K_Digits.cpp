/// TC: O(N*M) /// N is the size string num and M is the size of stack
/// MC: O(N) /// N is size of string
class Solution {
public:
    string removeKdigits(string num, int k) {
      stack<char> check;

      for(auto &c : num)
      {
        while(k > 0 && !check.empty() && c < check.top())
        {
          check.pop();
          k--;
        }
        check.push(c);
      }

      while( k > 0 && !check.empty())
      {
        check.pop();
        k--;
      }

      string minNum;
      while(!check.empty())
      {
        minNum.push_back(check.top());
        check.pop();
      }
      while(!minNum.empty() && minNum.back() == '0')  minNum.pop_back();
      if(minNum.empty()) return "0";
      reverse(minNum.begin(), minNum.end());
      return minNum;
    }
};
