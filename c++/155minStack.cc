#include <iostream>
#include <stack>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

// Idea from https://leetcode.com/problems/min-stack/discuss/49031/Share-my-Java-solution-with-ONLY-ONE-stack
// Then https://leetcode.com/problems/min-stack/discuss/49014/Java-accepted-solution-using-one-stack
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class MinStack {
 private:
  stack <int> st;
  int min = 2147483647;
 public:
  /** initialize your data structure here. */
  MinStack() {

  }
    
  void push(int x) {
    if(x <= min){          
      st.push(min);
      min=x;
    }
    st.push(x);
  }
    
  void pop() {
    if(st.top() == min) {
      st.pop();
      min=st.top();
    }
    st.pop();
  }
    
  int top() {
    return st.top();
  } 
    
  int getMin() {
    return min;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
