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
class Solution {
 public:
  vector<string> removeComments(vector<string>& source) {
    vector<string> res;
    bool comment = false;
    string s;

    for (auto &line : source) {
      const int n = line.size();
      for (int i = 0; i < n; ++i) {
        const char c = line[i];
        int j = i + 1;

        if (!comment && j < n && c == '/' && line[j] == '/') {
          break;
        } else if (!comment && j < n && c == '/' && line[j] == '*') {
          comment = true;
          i = j;
        } else if (comment && j < n && c == '*' && line[j] == '/') {
          comment = false;
          i = j;
        } else if (!comment) {
          s += c;
        }
      }
      if (!comment && !s.empty()) {
        res.emplace_back(std::move(s));
        s.clear();
      }
    }
    return res;
  }
};

class Solution_WRONG {
 public:
  vector<string> removeComments(vector<string>& source) {
    vector<string> res;
    bool comment = false, done = true;
    string left = "", line = "";
    int idx = -1, nn = source.size()-1;
    while (!done || idx < nn) {
      line = done? source[++idx]: line;
      const int n = line.size();
      cout << line << n << done << comment << endl;
      if (!comment) {
        int i = -1;
        while (++i < n) {
          if (line[i] == '/') {
            if (line[i + 1] == '*') {  // "/*"
              size_t sec = line.rfind("*/");
              if (sec == string::npos || sec == i + 1) {  // multiline comments
                comment = true;
                if (i != 0) left = line.substr(0, i);
              } else if (sec + 2 == n) {  // "... /* .... */"
                if (i != 0) res.emplace_back(line.substr(0, i));
              } else {  // "... /* ... */ int a = 1"
                res.emplace_back(line.substr(0, i) + line.substr(sec + 2));
              }
              break;                         // break while loop for current line
            } else if (line[i + 1] == '/') {  // "//"
              if (i != 0) res.emplace_back(line.substr(0, i));
              done = true;
              break;
            } else {  // int a = b / c;
              continue;
            }
          } // end if line[i] == '/'
        }   // end while loop for current line
        if (i == n) {
          res.emplace_back(move(line));
          done = true;
        }
      } else {    // in multiline comment
        size_t sec = line.find("*/");
        if (sec == string::npos) continue;
        comment = false;
        if (sec + 2 == n) {
          done = true;
          if (!left.empty())
            res.emplace_back(move(left));
          left.clear();
        } else {
          done = false;
          line = left + line.substr(sec + 2);
          left.clear();
        }
      }  // end comment
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
