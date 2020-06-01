#include <iostream>
#include <sstream>
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
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// From huahua
class UndergroundSystem {
 public:
  UndergroundSystem() { }

  void checkIn(int id, string stationName, int t) {
    people_[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    const auto &[station, t1] = people_[id];
    string path = station + "#" + stationName;
    time_[path].first += t - t1;
    ++time_[path].second;
  }

  double getAverageTime(string startStation, string endStation) {
    const auto &[total, count] = time_[startStation + "#" + endStation];
    return static_cast<double> (total) / count;
  }
 private:
  unordered_map<int, pair<string, int>> people_;
  unordered_map<string, pair<int, int>> time_;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main() {
  Solution s;
  
  return 0;
}
