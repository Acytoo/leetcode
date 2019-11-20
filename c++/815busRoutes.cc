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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    if (S == T) return 0;

    unordered_map<int, vector<int>> m;  // stop , {buses}
    for (int i=0, len=routes.size(); i<len; ++i)
      for (int stop : routes[i])
        m[stop].push_back(i);

    queue<pair<int, int>> q;  // q { stop, buses-taken-number}
    q.push({S, 0});
    unordered_set<int> seen = {S};

    while (!q.empty()) {
      int stop = q.front().first, bus = q.front().second;
      q.pop();
      if (stop == T)
        return bus;
      for (int i : m[stop]) {
        for (int j : routes[i]) {
          if (seen.find(j) == seen.end()) {
            seen.insert(j);
            q.push({j, bus + 1});
          }
        }
        routes[i].clear();
      }
    }
    return -1;
  }
};

class Solution1 {  // Time Limit Exceeded
 public:
  int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    if (S == T) return 0;

    unordered_map<int, vector<int>> m;  // stop , {buses}
    for (int i=0, len=routes.size(); i<len; ++i)
      for (const int stop : routes[i])
        m[stop].push_back(i);

    vector<int> ride(routes.size(), 0);
    queue<int> q;
    q.push(S);
    int res = 0;

    while (!q.empty()) {
      int size = q.size();
      ++res;
      while (size--) {
        int curr = q.front();
        q.pop();
        for (const int bus: m[curr]) {
          if (ride[bus])
            continue;  // We have take this bus
          for (int stop: routes[bus]) {
            if (stop == T) return res;
            q.push(stop);
          }
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  [[7,12],[4,5,15],[6],[15,19],[9,12,13]]
      15
      12
  return 0;
}
