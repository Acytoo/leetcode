import java.util.*;

public class J1234Template {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        if (guess(n) == 0)
            return n;
        if (guess(n) < 0) {
            int gap = 2;
            n -= gap;
            while (guess(n) < 0) {
                n -= gap;
                if (gap < 10e5)
                    gap <<= 2;
            }
            // System.out.println(gap);
        } else {
            int gap = 2;
            n += gap;
            while (0 < guess(n)) {
                n += gap;
                if (gap < 10e5);
                    gap <<= 2;
            }
            // System.out.println(gap);
        }
        return slowGuess(n);

    }
    private int slowGuess(int n) {
        if (guess(n) == 0)
            return n;
        if (guess(n) < 0)
            return slowGuess(n - 1);
        return slowGuess(n + 1);
    }
}
