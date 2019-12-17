#include <stdio.h>

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

using namespace std;

// static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();


class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<char, int> dict;
    for (char c: s)
      if (dict.count(c) == 0)
        dict[c] = 1;
      else
        ++dict[c];
    vector<pair<int, int>> tmp;
    tmp.reserve(dict.size());
    for (auto i: dict)
      tmp.emplace_back(move(i));
    sort(tmp.begin(), tmp.end(), [=](pair<int, int>& a, pair<int, int>& b) {return a.second > b.second;});
    string res = "";
    for (auto i: tmp) {
      string t = "";
      for (int j=i.second; j>0; --j)
        t += i.first;
      res += t;
    }
    return res;
  }
};

int main() {
  Solution s;
  string a = "hello.";
  cout << s.frequencySort(a) << endl;
  return 0;
}
