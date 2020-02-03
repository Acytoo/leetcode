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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  string countOfAtoms(string formula) {
    string res;
    map<string, int> dict;
    int i=0;
    parseFormula(dict, formula, i );
    for (auto it: dict) {
      res += it.first;
      if (it.second > 1)
        res += to_string(it.second);
    }
    return res;
  }
 private:
  void parseFormula(map<string, int>& dict, const string& formula, int& i) {
    int n = formula.size();
    map<string, int> elements;
    while (i<n && formula[i] != ')') {
      parseElement(elements, formula, i);
    }
    mergeFormula(dict, elements, 1);
  }

  void parseElement(map<string, int>& elements, const string& formula, int& i) {
    // cout << "parseelement " << i << endl;
    int n = formula.size();
    if (formula[i] == '(') {
      map<string, int> fors;
      parseFormula(fors, formula, ++i);
      int num = parseNum(formula, ++i);
      mergeFormula(elements, fors, num);
    } else {
      string cur_formula;
      cur_formula.push_back(formula[i]);
      ++i;
      while ('a'<=formula[i] && formula[i]<='z') {
        cur_formula.push_back(formula[i]);
        ++i;
      }
      int num = parseNum(formula, i);
      elements[cur_formula] += num;
      // cout << cur_formula << " " << num << " " << i << endl;
    }

  }

  int parseNum(const string& formula, int& i) {
    int num = 0;
    int n = formula.size();
    while (i<n && '0'<=formula[i] && formula[i]<='9') {
      num = num * 10 + formula[i] - '0';
      ++i;
    }
    return num == 0? 1: num;
  }

  void mergeFormula(map<string, int>& target, map<string, int>& source, int num) {
    for (auto each_pair: source) {
      target[each_pair.first] += each_pair.second*num;
    }
  }

};

int main() {
  Solution s;
  string a = "H2O2(MgH)2";
  string res = s.countOfAtoms(a) ;
  cout << res << endl;
  return 0;
}
