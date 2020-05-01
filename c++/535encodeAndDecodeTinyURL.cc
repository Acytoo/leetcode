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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    if (en_.count(longUrl)) return en_[longUrl];
    nextString();
    en_[longUrl] = str_;
    de_[str_] = longUrl;
    return "http://tinyurl.com/" + str_;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    shortUrl = shortUrl.substr(shortUrl.find_last_of("/") + 1);
    if (de_.count(shortUrl))
      return de_[shortUrl];
    return "";
  }
 private:
  // string base_ = "http://tinyurl.com/";
  unordered_map<string, string> en_, de_;
  string str_ = "000000";
  int idx_ = 0;

  void nextString() {
    if (idx_ == 5 && str_[idx_] == 'z') {
      idx_ = 0;
      str_ = "000000";
    }
    switch (str_[idx_]) {
      case '9': str_[idx_] = 'A'; break;
      case 'Z': str_[idx_] = 'a'; break;
      case 'z': str_[idx_] = '0'; str_[++idx_] = '1'; break;
      default: ++str_[idx_];
    }
  }
};

int main() {
  Solution s;
  string a = "https://acytoo.com",
         b = "http://example.com",
         c = "https://acytoo.me";
  cout << s.encode(a) << endl <<
      s.encode(b) << endl <<
      s.encode(c) << endl;
  string tmp = "";
  while (cin >> tmp) {
    cout << s.decode(tmp) << endl;
  }
  return 0;
}
