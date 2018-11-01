#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
      if (x < 0){
	int absx = -1 * x, y = 0;
	int temp = 0;
	while ((int)absx){	
	  temp  = (int)absx % 10;
	  absx = absx / 10;
	  y = y * 10 + temp;
	}
	if (y > 0)
	  return 0;
	return y * -1;
      }
      else{
	int temp = 0;
	int y = 0;
    	while (x){	
	  temp  = x % 10;
	  x = x / 10;
	  y = y * 10 + temp;
	}
	if (y < 0)
	  return 0;
	return y;
      }
    }
};


int main(){
  Solution s;
  int a = 0;
  while (cin >> a){
    cout << s.reverse(a) << endl;
  }
  return 0;
}
