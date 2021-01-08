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
  // Brute force
 public:
  int countStudents(vector<int>& students, vector<int>& sandwiches) {
    const int n = students.size();
    int want1 = accumulate(students.begin(), students.end(), 0),
        want0 = n - want1;
    deque<int> stu(students.begin(), students.end());
    deque<int> san(sandwiches.begin(), sandwiches.end());
    while (!stu.empty() && want1 && want0) {
      if (stu.front() == san.front()) {
        stu.front() == 1? --want1 : --want0;
        stu.pop_front();
        san.pop_front();
      } else {
        stu.push_back(stu.front());
        stu.pop_front();
      }
    }
    while (!stu.empty() && stu.front() == san.front()) {
      stu.pop_front();
      san.pop_front();
    }
    return stu.size();
  }
};

int main() {
  Solution s;
  
  return 0;
}
