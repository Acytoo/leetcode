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
  vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    vector<string> res;
    vector<int> bcontains ('z'+1);

    for (const string &b: B) {
      vector<int> tmp ('z'+1);
      for (const char c: b) ++tmp[c];
      for (int i='a'; i<='z'; ++i)
        if (bcontains[i] < tmp[i])
          bcontains[i] = tmp[i];
    }

    for (const string &a: A) {
      vector<int> tmp ('z'+1);
      for (const char c: a) ++tmp[c];
      int i = 'a';
      for (; i<='z'; ++i)
        if (tmp[i] < bcontains[i])
          break;
      if ('z' < i)
        res.emplace_back(move(a));
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
