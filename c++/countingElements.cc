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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 1 <= arr.length <= 1000
// 0 <= arr[i] <= 1000
class Solution {
 public:
  int countElements(vector<int>& arr) {
    int res = 0;
    bitset<1002> has;
    for (const int i: arr) has[i] = 1;
    for (const int i: arr) res += has[i+1];
    return res;
  }
};


int main() {
  Solution s;
  
  return 0;
}
