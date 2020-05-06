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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Bidirectional BFS
class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    if (target == "0000") return 0;
    bitset<10000> dead;
    for (const string &d: deadends) dead[stoi(d)] = 1;
    if (dead[0]) return -1;
    constexpr int s = 0;
    const int t = stoi(target);

    queue<int> q1, q2;
    bitset<10000> v1, v2;
    v1[0] = 1; v2[t] = 1;
    constexpr int wheels[4] = {1000, 100, 10, 1};
    constexpr int turns[2][10] = {{1,1,1,1,1,1,1,1,1,-9},
                                  {9,-1,-1,-1,-1,-1,-1,-1,-1,-1}};
    int res1 = 0, res2 = 0;
    q1.push(s); q2.push(t);

    while (!q1.empty() && !q2.empty()) {
      ++res1;
      for (int i = 0, stop = q1.size(); i < stop; ++i) {
        const int cur = q1.front(); q1.pop();
        for (int j = 0; j < 4; ++j) {
          int cur_slot = (cur / wheels[j]) % 10;
          for (int k = 0; k < 2; ++k) {
            const int next = cur + wheels[j] * turns[k][cur_slot];
            if (v2[next]) return res1 + res2;
            if (v1[next] || dead[next]) continue;
            q1.push(next);
            v1[next] = 1;
          }
        }
      }
      swap(q1, q2);
      swap(v1, v2);
      swap(res1, res2);
    }
    return -1;
  }
};

// Bidirectional BFS
class Solution_same {
  // the only difference is how we get the next
 public:
  int openLock(vector<string>& deadends, string target) {
    if (target == "0000") return 0;
    bitset<10000> dead;
    for (const string &d: deadends) dead[stoi(d)] = 1;
    if (dead[0]) return -1;
    constexpr int s = 0;
    const int t = stoi(target);

    queue<int> q1, q2;
    bitset<10000> v1, v2;
    v1[0] = 1; v2[t] = 1;
    constexpr int wheels[4] = {1000, 100, 10, 1};
    int res1 = 0, res2 = 0;
    q1.push(s); q2.push(t);

    while (!q1.empty() && !q2.empty()) {
      ++res1;
      for (int i = 0, stop = q1.size(); i < stop; ++i) {
        const int cur = q1.front(); q1.pop();
        for (int j = 0; j < 4; ++j) {
          int cur_slot = (cur / wheels[j]) % 10;
          for (int k = -1; k <= 1; k += 2) {
            const int next = cur + wheels[j] * ((cur_slot + k + 10) % 10 - cur_slot);
            if (v2[next]) return res1 + res2;
            if (v1[next] || dead[next]) continue;
            q1.push(next);
            v1[next] = 1;
          }
        }
      }
      swap(q1, q2);
      swap(v1, v2);
      swap(res1, res2);
    }
    return -1;
  }
};

// Bidirectional BFS
class Solution2 {
 public:
  int openLock(vector<string>& deadends, string target) {
    constexpr char *start = "0000";
    if (target == start) return 0;
    bitset<10000> dead;
    for (const string &d: deadends) dead[stoi(d)] = 1;
    if (dead[0]) return -1;

    queue<string> q1, q2;
    bitset<10000> v1, v2;
    v1[0] = 1; v2[stoi(target)] = 1;
    constexpr char next_slot[2][10] = {{'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'},
                                       {'9', '0', '1', '2', '3', '4', '5', '6', '7', '8'}};
    int res1 = 0, res2 = 0;
    q1.push(start); q2.push(target);

    while (!q1.empty() && !q2.empty()) {
      ++res1;
      for (int i = 0, stop = q1.size(); i < stop; ++i) {
        const string cur = q1.front(); q1.pop();
        for (int j = 0; j < 4; ++j)
          for (int k = 0; k < 2; ++k) {
            string next = cur;
            next[j] = next_slot[k][next[j] - '0'];
            const int nextt = stoi(next);
            if (v2[nextt]) return res1 + res2;
            if (dead[nextt] || v1[nextt]) continue;
            q1.push(next);
            v1[nextt] = 1;
          }
      }
      swap(q1, q2);
      swap(v1, v2);
      swap(res1, res2);
    }
    return -1;
  }
};

// BFS
class Solution1 {
 public:
  int openLock(vector<string>& deadends, string target) {
    constexpr char *start = "0000";
    if (target == start) return 0;
    bitset<10000> dead;
    for (const string &d: deadends) dead[stoi(d)] = 1;
    if (dead[0]) return -1;

    queue<string> q;
    bitset<10000> visited;
    visited[0] = 1;
    constexpr char next_slot[2][10] = {{'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'},
                                       {'9', '0', '1', '2', '3', '4', '5', '6', '7', '8'}};
    int res = 0;
    q.push(start);

    while (!q.empty()) {
      ++res;
      for (int i = 0, stop = q.size(); i < stop; ++i) {
        const string cur = q.front(); q.pop();
        for (int j = 0; j < 4; ++j)
          for (int k = 0; k < 2; ++k) {
            string next = cur;
            next[j] = next_slot[k][next[j] - '0'];
            if (next == target) return res;
            const int nextt = stoi(next);
            if (dead[nextt] || visited[nextt]) continue;
            q.push(next);
            visited[nextt] = 1;
          }
      }
    }
    return -1;
  }
};

class Solution1_same {
 public:
  int openLock(vector<string>& deadends, string target) {
    constexpr char *start = "0000";
    if (target == start) return 0;
    unordered_set<string> dead (deadends.begin(), deadends.end());
    if (dead.count(start)) return -1;

    queue<string> q;
    unordered_set<string> visited {start};
    constexpr char next_slot[2][10] = {{'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'},
                                       {'9', '0', '1', '2', '3', '4', '5', '6', '7', '8'}};
    int res = 0;
    q.push(start);

    while (!q.empty()) {
      ++res;
      for (int i = 0, stop = q.size(); i < stop; ++i) {
        const string cur = q.front(); q.pop();
        for (int j = 0; j < 4; ++j)
          for (int k = 0; k < 2; ++k) {
            string next = cur;
            next[j] = next_slot[k][next[j] - '0'];
            if (next == target) return res;
            if (dead.count(next) || visited.count(next)) continue;
            q.push(next);
            visited.insert(next);
          }
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
