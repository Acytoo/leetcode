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
// From huahua
class Solution {
 public:
  string largestMerge(string_view word1, string_view word2) {
    string res;
    const int m = word1.size(), n = word2.size();
    int i = 0, j = 0;
    while (i < m && j < n)
      res += word1.substr(i) > word2.substr(j) ? word1[i++] : word2[j++];
    res.append(word1.substr(i));
    res.append(word2.substr(j));
    return res;
  }
};

class Solutionnn {
 public:
  string largestMerge(string word1, string word2) {
    string res;
    const int m = word1.size(), n = word2.size();
    string_view w1(word1), w2(word2);
    int i = 0, j = 0;
    while (i < m && j < n)
      res += w1.substr(i) > w2.substr(j) ? w1[i++] : w2[j++];
    res.append(w1.substr(i));
    res.append(w2.substr(j));
    return res;
  }
};

class Solution1 {
 public:
  string largestMerge(string word1, string word2) {
    string res;
    const int m = word1.size(), n = word2.size();
    int i = 0, j = 0;
    while (i < m && j < n)
      res += word1.substr(i) > word2.substr(j) ? word1[i++] : word2[j++];
    res.append(word1.substr(i));
    res.append(word2.substr(j));
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
