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
/*
// Employee info
class Employee {
public:
// It's the unique ID of each node.
// unique id of this employee
int id;
// the importance value of this employee
int importance;
// the id of direct subordinates
vector<int> subordinates;
};
*/

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, Employee*> m;
    m.reserve(employees.size());
    for (auto e: employees)
      m[e->id] = e;
    stack<int> total_subordinates;
    int res = m[id]->importance;
    for (auto e: m[id]->subordinates)
      total_subordinates.push(e);
    while (!total_subordinates.empty()) {
      int cur_id = total_subordinates.top();
      total_subordinates.pop();
      res += m[cur_id]->importance;
      for (int e: m[cur_id]->subordinates)
        total_subordinates.push(e);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
