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
class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    if (n == 0) return tasks.size();
    // min: tasks.size(), max: (tasks.size()-1)*(n+1)+1
    vector<int> jobs('Z'+1);
    for (const char task: tasks) ++jobs[task];
    int most_n = *max_element(jobs.begin()+'A', jobs.end());
    int res = (most_n-1) * (n+1);
    res += count_if(jobs.begin()+'A', jobs.end(),
                    [=] (int cnt) { return cnt == most_n; });
    return max(res, static_cast<int>(tasks.size()));
  }
};


int main() {
  Solution s;
  
  return 0;
}
