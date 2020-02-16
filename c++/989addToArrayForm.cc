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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<int> addToArrayForm(vector<int>& A, int k) {
    vector<int> res;
    int n = A.size()-1;
    int carry = 0;
    while (n>=0 || k>0) {
      int digit = k % 10;
      k /= 10;
      int sum_digit = digit + carry;
      if (n >= 0) {
        sum_digit += A[n];
      }
      --n;
      if (sum_digit > 9) {
        sum_digit -= 10;
        carry = 1;
      } else {
        carry = 0;
      }
      res.emplace_back(sum_digit);
    }
    if (carry)
      res.emplace_back(1);
    std::reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
