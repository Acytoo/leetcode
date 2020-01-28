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

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  string shiftingLetters(string S, vector<int>& shifts) {
    long num = 0;
    for (int i=shifts.size()-1; 0<=i; --i) {
      num += shifts[i];
      S[i] = (S[i]-'a'+num) % 26 + 'a';
    }
    return S;
  }
};

int main() {
  Solution s;
  
  return 0;
}
