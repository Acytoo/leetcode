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
#include <sstream>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  string validIPAddress(string queryIP) {
    if (queryIP.size() == 0 || queryIP.back() == '.' || queryIP.back() == ':') return "Neither";
    istringstream ip(queryIP);
    string cur = "";
    int count = 0;

    auto ipv4 = [&] () {
      if (queryIP.find('.') == string::npos) return false;
      while (getline(ip, cur, '.')) {
        ++count;
        if (count > 4 || cur.empty() || cur.size() > 3 || (cur.size() > 1 && cur[0] == '0'))
          return false;
        int val = 0;
        for (const char c : cur) {
          const int digit = c - '0';
          if (digit > 9) return false;
          val = val * 10 + digit;
        }
        if (val > 255) return false;
      }
      return count == 4;
    };
    auto ipv6 = [&] () {
      if (queryIP.find(':') == string::npos) return false;
      while (getline(ip, cur, ':')) {
        ++count;
        if (count > 8 || cur.empty() || cur.size() > 4) return false;
        for (const char c : cur)
          if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
            return false;
      }
      return count == 8;
    };

    if (ipv4()) return "IPv4";
    if (ipv6()) return "IPv6";
    return "Neither";
  }
};

class Solution_OLD {
 public:
  string validIPAddress(string IP) {
    if (IP.empty() || IP.back()=='.' || IP.back()==':')
      return "Neither";
    istringstream ip (IP);
    int count = 0;
    string res = "Neither", tmp = "";
    if (IP.find(':') == string::npos) {
      while (getline(ip, tmp, '.')) {
        ++count;
        if (4<count || tmp.empty() || (1<tmp.size() && tmp[0]=='0') || 3<tmp.size())
          return res;
        int val = 0;
        for (char c: tmp) {
          int tmpp = c-'0';
          if (9<tmpp)
            return res;
          val = val*10 + tmpp;
        }
        if (val<0 || 255<val)
          return res;
      }
      res = count == 4? "IPv4": "Neither";
    } else {
      while (getline(ip, tmp, ':')) {
        ++count;
        if (8<count || tmp.empty() || 4<tmp.size())
          return res;
        for (char c: tmp)
          if (!(('0'<=c && c<='9') || ('a'<=c && c<='f') || ('A'<=c && c<='F')))
            return res;
      }
      res = count == 8? "IPv6": "Neither";
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
