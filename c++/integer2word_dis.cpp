#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    map<int, string> mp;
    vector<int> divisors = {1000000000, 1000000, 1000, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 1};
    
    string F(int n) {
        string t = "";
        
        if (n < 100 && mp.count(n)) {
            t += mp[n];
        }
        else {
            for (auto x : divisors) {
                int div = n / x;
                int mod = n % x;
                if (div > 0) {
                    if (x >= 100) {
                        t += F(div);
                        t += " ";
                    }
                    t += mp[x];
                    
                    if (mod > 0) {
                        t += " ";
                        t += F(mod);
                    }
                    break;
                }
            }
        }
        
        return t;
    }
    
    string numberToWords(int num) {
        mp[0] = "Zero";
        mp[1] = "One";
        mp[2] = "Two";
        mp[3] = "Three";
        mp[4] = "Four";
        mp[5] = "Five";
        mp[6] = "Six";
        mp[7] = "Seven";
        mp[8] = "Eight";
        mp[9] = "Nine";
        mp[10] = "Ten";
        mp[11] = "Eleven";
        mp[12] = "Twelve";
        mp[13] = "Thirteen";
        mp[14] = "Fourteen";
        mp[15] = "Fifteen";
        mp[16] = "Sixteen";
        mp[17] = "Seventeen";
        mp[18] = "Eighteen";
        mp[19] = "Nineteen";
        mp[20] = "Twenty";
        mp[30] = "Thirty";
        mp[40] = "Forty";
        mp[50] = "Fifty";
        mp[60] = "Sixty";
        mp[70] = "Seventy";
        mp[80] = "Eighty";
        mp[90] = "Ninety";
        mp[100] = "Hundred";
        mp[1000] = "Thousand";
        mp[1000000] = "Million";
        mp[1000000000] = "Billion";

        return F(num);
    }
};

int main() {

  int a = 100003;
  Solution s;
  cout << s.numberToWords(a) << endl;
  int b = 1235603;
  cout << s.numberToWords(b) << endl;
  return 0;
}
  
