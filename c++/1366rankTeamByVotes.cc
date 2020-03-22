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
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  string rankTeams(vector<string>& votes) {
    const int n = votes.size(), m = votes[0].size();
    if (n == 1)
      return votes[0];
    vector<vector<int>> ballot ('Z'+1, vector<int> (m+1, 0));
    for (int i='A'; i<= 'Z'; ++i)
      ballot[i][m] = i;

    for (int i=0; i<n; ++i)
      for (int j=0; j<m; ++j)
        ++ballot[votes[i][j]][j];
    sort(ballot.begin()+'A', ballot.end(), [&] (const vector<int>& a, const vector<int>& b) {
                                         int i = -1;
                                         while (++i < m)
                                           if (a[i] != b[i])
                                             return a[i] > b[i];
                                         return a[i] < b[i];
                                       });
    string res = "";
    for (int i='A', stop='A'+m; i<stop; ++i)
      res += (char)ballot[i][m];
    return res;
  }
};

int main() {
  Solution s;
  vector<string> a = {"ABC", "ACB", "CBA"};
  cout << s.rankTeams(a) << endl;
  return 0;
}
