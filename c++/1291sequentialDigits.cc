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
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 10 <= low <= high <= 10^9 (1,000,000,000), int max: 2,147,483,647
class Solution {
 public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> nums = {12,23,34,45,56,67,78,89,
                        123,234,345,456,567,678,789,
                        1234,2345,3456,4567,5678,6789,
                        12345,23456,34567,45678,56789,
                        123456,234567,345678,456789,
                        1234567,2345678,3456789,
                        12345678,23456789,
                        123456789};
    vector<int> res;
    for (const int i: nums)
      if (high < i)
        break;
      else if (low <= i)
        res.push_back(i);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
