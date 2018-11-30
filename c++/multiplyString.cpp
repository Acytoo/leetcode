#include <iostream>
#include <vector>
#include <string>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Thanks to https://leetcode.com/problems/multiply-strings/discuss/17646/Brief-C%2B%2B-solution-using-only-strings-and-without-reversal
class Solution {
public:
  string multiply(string num1, string num2) {
    int l1 = num1.size(), l2 = num2.size();
    string ans(l1 + l2, '0');
    for (int i = l1 - 1; i >= 0; --i) {
      for (int j = l2 - 1; j >= 0; --j) {
	int temp = i + j, sum = (num1[i] - '0') * (num2[j] - '0') + (ans[temp + 1] - '0');
	ans[temp + 1] = sum % 10 + '0';
	ans[temp] += sum / 10;
      }
    }
    size_t startpos = ans.find_first_not_of("0");
    if (string::npos != startpos) {
      return ans.substr(startpos);
    }
    return "0";
  }
  
  string multiply1(string num1, string num2) {
    int l1 = num1.size(), l2 = num2.size();
    string sum(l1+l2, '0');
    
    for (int i = l1 - 1; 0 <= i; --i) {
      int carry = 0;
      for (int j = l2 - 1; 0 <= j; --j) {
	int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
	sum[i + j + 1] = tmp % 10 + '0';
	carry = tmp / 10;
      }
      sum[i] += carry;
    }
    
    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
      return sum.substr(startpos);
    }
    return "0";
  }
};

int main() {
  Solution s;
  string a = "123321847923749812374928137491283749812374981237498123749182374912837498123749845678912345678912312347234723941964342345";
  string b = "234567891213423452345181234123412341241234134123485723462836354263478623746548765746574657465475674657465823749812634";
  cout << s.multiply(a,b) << endl;
  return 0;
}
