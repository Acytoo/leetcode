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
  double trimMean(vector<int>& arr) {
    int n = arr.size(), r = n * 0.05;
    sort(arr.begin(), arr.end());
    double sum = .0;
    for (int i = r, stop = n - r; i < stop; ++i) sum += arr[i];
    return sum / (n - (r << 1));
  }
};

int main() {
  Solution s;
  
  return 0;
}
