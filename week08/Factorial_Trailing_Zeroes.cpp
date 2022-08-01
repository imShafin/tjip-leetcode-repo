/// TC: O(Nlog5(N)) /// N is the parameter of the program
/// MC: O(1)

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
          int val = i;
          while(val % 5 == 0)
          {
            val /= 5;
            cnt++;
          }
        }
        return cnt;
    }
};
