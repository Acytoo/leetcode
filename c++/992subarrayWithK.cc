#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>


using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& A, int K) {
    // number of subarrays with ***k or less*** distinct number
    auto subarrays = [&A] (int k) {
                       vector<int> count(A.size() + 1);
                       int res = 0;
                       int i = 0;
                       for (int j=0, stop=A.size(); j<stop; ++j) {
                         if (count[A[j]]++ == 0)
                           --k;
                         while (k < 0)
                           if (--count[A[i++]] == 0)
                             ++k;
                         res += j - i + 1;  // k or less, window
                       }
                       return res;
                     };
    return subarrays(K) - subarrays(K-1);
  }
};

int main() {
  Solution s;
  
  return 0;
}
