#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MyStack {
private:
  queue <int> fakeStack;
  //  vector <int> fakeStack;

  
public:
    /** Initialize your data structure here. */
    MyStack() {
      //      fakeStack;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
      fakeStack.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
      
      int len = fakeStack.size();
      for(int i=0; i<len-1; i++) {
        int tmp = fakeStack.front();
        fakeStack.pop();
        fakeStack.push(tmp);
      }
      int res = fakeStack.front();
      fakeStack.pop();
    
      return res;

      
    }
    
    /** Get the top element. */
    int top() {
      return fakeStack.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
      return fakeStack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */


int main() {

  return 0;
}
