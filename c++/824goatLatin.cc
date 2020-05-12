#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  bool isVowel(char c) {
    if (c >= 'a')
      return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    else
      return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
  }

  string toGoatLatin(string S) {
    string res;
    int iThWord=1;
    char firstUn, lastChar = ' ';
    bool vowelFlag = false;

    for (int i=0, stop = S.size(); i != stop; ++i) {

      if (lastChar == ' ') {
        vowelFlag = isVowel(S[i]);
        if (vowelFlag) res += S[i];
        else firstUn = S[i];
      }


      else if (S[i] == ' ') {
        if (!vowelFlag)
          res += firstUn;
        res += "ma";

        int count = iThWord;
        while (count--)
          res += 'a';
        res += ' ';

        ++iThWord;
      }

      else
        res += S[i];

      lastChar = S[i];
    }

    if (!vowelFlag)
      res += firstUn;
    res += "ma";
    while (iThWord--)
      res += 'a';
    return res;
  }
};

int main() {
  Solution s;
  string a = "Each word consists of lowercase and uppercase letters only";
  //"The quick brown fox jumped over the lazy dog";//"I speak Goat Latin"; //"I am a bad man";
  cout << s.toGoatLatin(a) << endl;
  return 0;
}
