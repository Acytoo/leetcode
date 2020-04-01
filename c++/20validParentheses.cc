#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    if (s[0] == ')' || s[0] == ']' || s[0] == '}')
      return false;
    for (char& c : s )
      switch (c) {
      case '(':
      case '[':
      case '{':
	st.push(c);
	break;
      case ')':
	if (st.empty() || st.top() != '(')
	  return false;
	st.pop();
	break;
      case ']':
	if (st.empty() || st.top() != '[')
	  return false;
	st.pop();
	break;
      case '}':
	if (st.empty() || st.top() != '{')
	  return false;
	st.pop();
      default: ;
      }
    return st.empty();
  }
};


int main() {
  string a = "[](){}[[[)]][()]";
  Solution s;
  cout << s.isValid(a) << endl;
  return 0;
}
