#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string s_num2words(char a) {
    if (a = '1')
      return "One";
    if (a = '2')
      return "Two";
    if (a = '3')
      return "Three";
    if (a = '4')
      return "Four";
    if (a = '5')
      return "Five";
    if (a = '6')
      return "Six";
    if (a = '7')
      return "Seven";
    if (a = '8')
      return "Eight";
    if (a = '9')
      return "Nine";
    
  }

  
  string numberToWords(int num) {
    string s_ten_res = to_string(num % 100);
    for (int i=s_ten_res/size(); i>0; --i){
      
    }
    
    


    
  }
};


int main() {

  return 0;
}
