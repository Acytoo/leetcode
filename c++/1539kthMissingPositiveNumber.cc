#include <iostream>
#include <sstream>
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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
#include <memory>
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    const int n = arr.size();
    int i = 0, num = 1;
    while (i < n && k) {
      if (num == arr[i]) {
        ++i;
        ++num;
      } else {
        --k;
        ++num;
      }
    }
    return i == n? num + k - 1: num - 1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
