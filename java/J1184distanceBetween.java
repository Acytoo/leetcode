import java.util.*;

public class J1184distanceBetween {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int distanceBetweenBusStops(int[] distance, int start, int destination) {
    if (start == destination)
      return 0;
    if (destination < start)
      return distanceBetweenBusStops(distance, destination, start);
    int before = 0;
    for (int i=0; i<start; ++i)
      before += distance[i];
    int exac = 0;
    for (int i=start; i<destination; ++i)
      exac += distance[i];
    if (exac < before)
      return exac;
    int after = 0;
    for (int i=destination, stop=distance.length; i<stop; ++i)
      after += distance[i];
    return Math.min(exac, before+after);
  }
}
