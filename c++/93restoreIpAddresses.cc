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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    if (s.size() > 12) return {};
    vector<string> res;
    string ip = "";
    function<void(int, string, string)> dfs =
        [&] (int part, string ip, string s) {
          const int len = s.size();
          // if (part == 4 && l == 0) {res.push_back(ip); return ;}
          if (part == 4)
            if (len == 0) {res.push_back(ip); return ;}
          for (int i=1, stop=min(3, s[0]=='0'? 1: len); i<=stop; ++i) {
            string ss = s.substr(0, i);
            if (i==3 && stoi(ss)>255) return ;
            dfs(part+1, ip+(part==0?"":".")+ss, s.substr(i));
          }
        };
    dfs(0, ip, s);
    return res;
  }
};

class Solution_same {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string ip;
    dfs(0, s, ip, res);
    return res;
  }
 private:
  void dfs(int part, string s, string ip, vector<string> &res) {
    const int len = s.size();
    if (part == 4)
      if (len == 0) {res.push_back(ip); return ;}

    // if (part==4 && len==0) {res.push_back(ip); return ;}
    for (int i=1, stop=min(3, s[0]=='0'? 1: len); i<=stop; ++i) {
      string ss = s.substr(0, i);
      if (i==3 && stoi(ss)>255) return ;
      dfs(part+1, s.substr(i), ip+(part==0?"":".")+ss, res);
    }
  }
};


int main() {
  Solution s;
  
  return 0;
}
