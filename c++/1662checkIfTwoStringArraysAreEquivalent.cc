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
class Solution {  // 8ms, O(n) in c++ 20 and O(n^2) before: https://stackoverflow.com/questions/15347123/how-to-construct-a-stdstring-from-a-stdvectorstring
 public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    return accumulate(word1.begin(), word1.end(), string()) == accumulate(word2.begin(), word2.end(), string());
  }
};

class Solution1 {  // 4ms
 public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string w1, w2;
    for (string &a: word1) w1 += a;
    for (string &a: word2) w2 += a;
    return w1 == w2;
  }
};

int main() {
  Solution s;
  
  return 0;
}
