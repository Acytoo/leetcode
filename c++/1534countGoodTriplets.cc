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
  int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int res = 0;
    for (int i = 0, stop = arr.size(); i < stop; ++i)
      for (int j = i + 1; j < stop; ++j)
        for (int k = j + 1; k < stop; ++k)
          if (abs(arr[i] - arr[j]) <= a &&
              abs(arr[j] - arr[k]) <= b &&
              abs(arr[i] - arr[k]) <= c)
            ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
