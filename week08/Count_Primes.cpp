/// TC: O(sqrt(n) * log(n))
/// MC: O(N)
class Solution {
public:
    int countPrimes(int n) {
      vector<bool> primes(n + 5, true);
      primes[0] = primes[1] = false;
      for(int i = 2; i * i <= n; i++)
      {
        if (primes[i])
        {
           for(int j = i * i; j < n; j+=i)
           {
             primes[j] = false;
           }
        }
      }
      int primeCount = 0;
      for(int i = 0; i < n; i++)
      {
        if(primes[i]) primeCount++;
      }
      return primeCount;
    }
};
